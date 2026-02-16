//
// Created by Jason Lee on 1/28/26.
//

#include "cvision/ctypes.h"
#include "cvision/cvision.h"
#include "cvision/cstddlg.h"
#include <tvision/tv.h>
#include <strstream>

tv_Application *tv_app;
typedef char *charPtr;
typedef TPoint *PPoint;

TCApplication::TCApplication(TStatusLine *(*statusLineFunc)(TRect),
                  TMenuBar *(*menuBarFunc)(TRect),
                  void (*handleEventFunc)(TEvent)) :
    TProgInit( statusLineFunc,
               menuBarFunc,
               TCApplication::initDeskTop
             ),
    TApplication(),
    cHandleEvent(handleEventFunc) {

    TEditor::editorDialog = doEditDialog;

}

void TCApplication::handleEvent(TEvent& event) {
    TApplication::handleEvent(event);

    if( event.what != evCommand ) {
        return;
    } else {
        if (cHandleEvent) {
            cHandleEvent(event);
        }
    }
}


TEditWindow *TCApplication::openEditor( const char *fileName, Boolean visible )
{
    TRect r = deskTop->getExtent();
    TView *p = validView( new TEditWindow( r, fileName, wnNoNumber ) );
    if( !visible )
        p->hide();
    deskTop->insert( p );
    return (TEditWindow *)p;
}

ushort execDialog( TDialog *d, void *data )
{
    TView *p = TProgram::application->validView( d );
    if( p == 0 )
        return cmCancel;
    else
    {
        if( data != 0 ) {
            p->setData( data );
        }
        ushort result = TProgram::deskTop->execView( p );
        if( result != cmCancel && data != 0 ) {
            p->getData( data );
        }
        TObject::destroy( p );
        return result;
    }
}

TDialog *createFindDialog() {
    TDialog *d = new TDialog( TRect( 0, 0, 38, 12 ), "Find" );

    d->options |= ofCentered;

    TInputLine *control = new TInputLine( TRect( 3, 3, 32, 4 ), 80 );
    d->insert( control );
    d->insert(new TLabel( TRect( 2, 2, 15, 3 ), "~T~ext to find", control ) );
    d->insert(new THistory( TRect( 32, 3, 35, 4 ), control, 10 ) );

    d->insert( new TCheckBoxes( TRect( 3, 5, 35, 7 ),
        new TSItem( "~C~ase sensitive",
        new TSItem( "~W~hole words only", 0 ))));

    d->insert(new TButton( TRect( 14, 9, 24, 11 ), "O~K~", cmOK, bfDefault ) );
    d->insert(new TButton( TRect( 26, 9, 36, 11 ), "Cancel", cmCancel, bfNormal ) );

    d->selectNext( False );
    return d;
}

TDialog *createReplaceDialog() {
    TDialog *d = new TDialog( TRect( 0, 0, 40, 16 ), "Replace" );

    d->options |= ofCentered;

    TInputLine *control = new TInputLine( TRect( 3, 3, 34, 4 ), 80 );
    d->insert( control );
    d->insert(new TLabel( TRect( 2, 2, 15, 3 ), "~T~ext to find", control ) );
    d->insert(new THistory( TRect( 34, 3, 37, 4 ), control, 10 ) );

    control = new TInputLine( TRect( 3, 6, 34, 7 ), 80 );
    d->insert( control );
    d->insert( new TLabel( TRect( 2, 5, 12, 6 ), "~N~ew text", control ) );
    d->insert( new THistory( TRect( 34, 6, 37, 7 ), control, 11 ) );

    d->insert( new TCheckBoxes( TRect( 3, 8, 37, 12 ),
        new TSItem("~C~ase sensitive",
        new TSItem("~W~hole words only",
        new TSItem("~P~rompt on replace",
        new TSItem("~R~eplace all", 0 ))))));

    d->insert(new TButton( TRect( 17, 13, 27, 15 ), "O~K~", cmOK, bfDefault ) );
    d->insert(new TButton( TRect( 28, 13, 38, 15 ),
                            "Cancel", cmCancel, bfNormal ) );

    d->selectNext( False );

    return d;
}

ushort doEditDialog(int dialog, ...) {
    va_list arg;

    char buf[256] = {0};
    std::ostrstream os(buf, sizeof(buf) - 1);
    switch (dialog) {
        case edOutOfMemory:
            return messageBox("Not enough memory for this operation",
                              mfError | mfOKButton);
        case edReadError: {
            va_start(arg, dialog);
            os << "Error reading file " << va_arg(arg, charPtr)
                    << "." << std::ends;
            va_end(arg);
            return messageBox(buf, mfError | mfOKButton);
        }
        case edWriteError: {
            va_start(arg, dialog);
            os << "Error writing file " << va_arg(arg, charPtr)
                    << "." << std::ends;
            va_end(arg);
            return messageBox(buf, mfError | mfOKButton);
        }
        case edCreateError: {
            va_start(arg, dialog);
            os << "Error creating file " << va_arg(arg, charPtr)
                    << "." << std::ends;
            va_end(arg);
            return messageBox(buf, mfError | mfOKButton);
        }
        case edSaveModify: {
            va_start(arg, dialog);
            os << va_arg(arg, charPtr)
                    << " has been modified. Save?" << std::ends;
            va_end(arg);
            return messageBox(buf, mfInformation | mfYesNoCancel);
        }
        case edSaveUntitled:
            return messageBox("Save untitled file?",
                              mfInformation | mfYesNoCancel);
        case edSaveAs: {
            va_start(arg, dialog);
            return execDialog(new TFileDialog("*.*",
                                              "Save file as",
                                              "~N~ame",
                                              fdOKButton,
                                              101), va_arg(arg, charPtr));
        }

        case edFind: {
            va_start(arg, dialog);
            return execDialog(createFindDialog(), va_arg(arg, charPtr));
        }

        case edSearchFailed:
            return messageBox("Search string not found.",
                              mfError | mfOKButton);
        case edReplace: {
            va_start(arg, dialog);
            return execDialog(createReplaceDialog(), va_arg(arg, charPtr));
        }

        case edReplacePrompt:
            //  Avoid placing the dialog on the same line as the cursor
            TRect r(0, 1, 40, 8);
            r.move((TProgram::deskTop->size.x - r.b.x) / 2, 0);
            TPoint t = TProgram::deskTop->makeGlobal(r.b);
            t.y++;
            va_start(arg, dialog);
            TPoint *pt = va_arg(arg, PPoint);
            if (pt->y <= t.y)
                r.move(0, TProgram::deskTop->size.y - r.b.y - 2);
            va_end(arg);
            return messageBoxRect(r, "Replace this occurence?",
                                  mfYesNoCancel | mfInformation);
    }
    return cmCancel;
}

extern "C" {
    /* TApplication functions */

    /* Create a new TApplication instance using TCApplication subclass.
     *
     * Note: TApplication has a protected constructor in the original Turbo Vision
     * library. To work around this, we use TCApplication, a minimal subclass that
     * exposes a public constructor. This allows the C wrapper to instantiate the
     * application object while maintaining full compatibility with TApplication's
     * interface and behavior.
     *
     * The function pointers are cast from C wrapper types to C++ types using
     * reinterpret_cast. This is safe because the wrapper types (tv_StatusLine*,
     * tv_MenuBar*, tv_Rect, tv_Event) are binary-compatible with their C++
     * counterparts (TStatusLine*, TMenuBar*, TRect, TEvent).
     */
    tv_Application* tv_application_create(tv_StatusLine *(*cStatusLine)(tv_Rect),
                                          tv_MenuBar *(*cMenuBar)(tv_Rect),
                                          void (*handleEventFunc)(tv_Event)) {
        if (tv_app == nullptr) {
            // Cast function pointers from C wrapper types to C++ types
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type-mismatch"
            auto statusLineFunc = reinterpret_cast<TStatusLine *(*)(TRect)>(cStatusLine);
            auto menuBarFunc = reinterpret_cast<TMenuBar *(*)(TRect)>(cMenuBar);
            auto eventFunc = reinterpret_cast<void (*)(TEvent)>(handleEventFunc);
#pragma GCC diagnostic pop
            tv_app = reinterpret_cast<tv_Application*>(new TCApplication(statusLineFunc, menuBarFunc, eventFunc));
        }

        return tv_app;
    }

    void tv_application_destroy(tv_Application* app) {
        if (app) {
            delete reinterpret_cast<TCApplication*>(app);
        }
    }

    void tv_application_run(tv_Application* app) {
        reinterpret_cast<TApplication*>(app)->run();
    }

    ushort tv_application_exec_dialog(tv_Application *app, tv_FileDialog *d, void *data) {
        return execDialog(reinterpret_cast<TDialog*>(d), data);
    }

    tv_EditWindow *tv_application_open_editor(tv_Application *app, const char *fileName, tv_bool visible) {
        return reinterpret_cast<tv_EditWindow*>(
            reinterpret_cast<TCApplication*>(app)->openEditor(fileName, visible)
        );
    }
}