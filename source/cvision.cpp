//
// Created by Jason Lee on 1/28/26.
//

#include "cvision/ctypes.h"
#include "cvision/cvision.h"
#include "cvision/cstddlg.h"
#include "cvision/csystem.h"
#include <tvision/tv.h>

TCApplication::TCApplication(TStatusLine *(*statusLineFunc)(TRect),
                  TMenuBar *(*menuBarFunc)(TRect),
                  void (*handleEventFunc)(TEvent)) :
    TProgInit( statusLineFunc,
               menuBarFunc,
               TCApplication::initDeskTop
             ),
    TApplication(),
    cHandleEvent(handleEventFunc) {

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

ushort TCApplication::execDialog( TDialog *d, void *data ) {
    TView *p = validView( d );
    if( p == nullptr ) {
        return cmCancel;
    } else {
        if( data != nullptr) {
            p->setData( data );
        }
        ushort result = execView( p );
        if( result != cmCancel && data != nullptr ) {
            p->getData( data );
        }
        destroy( p );
        return result;
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
        // Cast function pointers from C wrapper types to C++ types
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type-mismatch"
        auto statusLineFunc = reinterpret_cast<TStatusLine *(*)(TRect)>(cStatusLine);
        auto menuBarFunc = reinterpret_cast<TMenuBar *(*)(TRect)>(cMenuBar);
        auto eventFunc = reinterpret_cast<void (*)(TEvent)>(handleEventFunc);
#pragma GCC diagnostic pop

        return reinterpret_cast<tv_Application*>(
            new TCApplication(statusLineFunc, menuBarFunc, eventFunc)
        );
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
        return reinterpret_cast<TCApplication*>(app)->execDialog(reinterpret_cast<TDialog*>(d), data);
    }

    tv_EditWindow *tv_application_open_editor(tv_Application *app, const char *fileName, tv_bool visible) {
        return reinterpret_cast<tv_EditWindow*>(
            reinterpret_cast<TCApplication*>(app)->openEditor(fileName, visible)
        );
    }
}