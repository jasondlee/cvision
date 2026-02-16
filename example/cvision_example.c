//
// Created by Jason Lee on 1/28/26.
//

#include "cvision_example.h"
#include "cvision/ctypes.h"
#include "cvision/cvision.h"
#include "cvision/cobjects.h"
#include "cvision/cmenus.h"
#include "cvision/ceditors.h"
#include "cvision/ctkeys.h"
#include "cvision/cstddlg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tv_StatusLine *createStatusLine(const tv_Rect r) {
    tv_StatusItem *items =
            tv_statusitem_create(
             0, tv_kbAltX, cmQuit,
        tv_statusitem_create("~F2~ Save", tv_kbF2, cmSave,
        tv_statusitem_create("~F3~ Open", tv_kbF3, cmOpen,
        tv_statusitem_create("~Ctrl-W~ Close", tv_kbAltF3, cmClose,
        tv_statusitem_create("~F5~ Zoom", tv_kbF5, cmZoom,
        tv_statusitem_create("~F6~ Next", tv_kbF6, cmNext,
        tv_statusitem_create("~F10~ Menu", tv_kbF10, cmMenu,
        tv_statusitem_create(0, tv_kbShiftDel, cmCut,
        tv_statusitem_create(0, tv_kbCtrlIns, cmCopy,
        tv_statusitem_create(0, tv_kbShiftIns, cmPaste,
        tv_statusitem_create(0, tv_kbCtrlF5, cmResize ,
            NULL )))))))))));

    return tv_statusline_create(tv_rect_create(r.a.x, r.b.y - 1, r.b.x, r.b.y), items);
}

tv_MenuBar *createMenuBar(tv_Rect r) {
    tv_SubMenu *sub1 = tv_submenu_create ( "~F~ile", tv_kbAltF);
    tv_submenu_add_menuitem(sub1, tv_menuitem_create("~O~pen", cmOpen, tv_kbF3, hcNoContext, "F3",
  tv_menuitem_create("~N~ew", cmNew, tv_kbCtrlN, hcNoContext, "Ctrl-N",
  tv_menuitem_create("~S~ave", cmSave, tv_kbF2, hcNoContext, "F2",
  tv_menuitem_create("S~a~ve as...", cmSaveAs, tv_kbNoKey, hcNoContext, NULL,
       // newLine() +
  tv_menuitem_create("~C~hange dir...", cmChangeDrct, tv_kbNoKey, hcNoContext, NULL,
  tv_menuitem_create("~D~OS shell", cmDosShell, tv_kbNoKey, hcNoContext, NULL,
  tv_menuitem_create("E~x~it", cmQuit, tv_kbCtrlQ, hcNoContext, NULL, NULL))))))));
      //, "Ctrl-Q" );

    tv_SubMenu *sub2 = tv_submenu_create ( "~E~dit", tv_kbAltE);
      tv_submenu_add_menuitem(sub2,
          tv_menuitem_create( "~U~ndo", cmUndo, tv_kbCtrlU, hcNoContext, "Ctrl-U",
           // newLine() +
      tv_menuitem_create( "Cu~t~", cmCut, tv_kbShiftDel, hcNoContext, "Shift-Del",
      tv_menuitem_create( "~C~opy", cmCopy, tv_kbCtrlIns, hcNoContext, "Ctrl-Ins" ,
      tv_menuitem_create( "~P~aste", cmPaste, tv_kbShiftIns, hcNoContext, "Shift-Ins",
           //newLine() +
      tv_menuitem_create( "~C~lear", cmClear, tv_kbCtrlDel, hcNoContext, NULL, NULL))))));
          //, "Ctrl-Del" );

    tv_SubMenu *sub3 = tv_submenu_create ( "~S~earch", tv_kbAltS);
    tv_submenu_add_menuitem(sub3,
        tv_menuitem_create( "~F~ind...", tv_cmFind, tv_kbNoKey, hcNoContext, NULL,
            tv_menuitem_create( "~R~eplace...", tv_cmReplace, tv_kbNoKey, hcNoContext, NULL,
            tv_menuitem_create( "~S~earch again", tv_cmSearchAgain, tv_kbNoKey, hcNoContext, NULL, NULL ))));

    tv_SubMenu *sub4 = tv_submenu_create ( "~W~indows", tv_kbAltW);
    tv_submenu_add_menuitem(sub4,
      tv_menuitem_create( "~S~ize/move",cmResize, tv_kbCtrlF5, hcNoContext, "Ctrl-F5",
      tv_menuitem_create( "~Z~oom", cmZoom, tv_kbF5, hcNoContext, "F5",
      tv_menuitem_create( "~T~ile", cmTile, tv_kbNoKey, hcNoContext, NULL,
      tv_menuitem_create( "C~a~scade", cmCascade, tv_kbNoKey, hcNoContext, NULL,
      tv_menuitem_create( "~N~ext", cmNext, tv_kbF6, hcNoContext, "F6",
      tv_menuitem_create( "~P~revious", cmPrev, tv_kbShiftF6, hcNoContext, "Shift-F6",
      tv_menuitem_create( "~C~lose", cmClose, tv_kbCtrlW, hcNoContext, NULL, NULL))))))));
          //, "Ctrl+W" );

    tv_submenu_add_next(sub1, sub2);
    tv_submenu_add_next(sub1, sub3);
    tv_submenu_add_next(sub1, sub4);
    /* Create menubar */
    return tv_menubar_create(tv_rect_create(r.a.x, r.a.y, r.b.x, r.a.y + 1), sub1);
}

void handleEvent(tv_Event event) {
    if (event.what == cmQuit) {
        tv_application_destroy(example_app);
    }

    if( event.what != evCommand ) {
        return;
    } else {
        switch( event.data.message.command ) {
            case cmOpen:
                fileOpen();
                break;
            case cmNew:
                fileNew();
                break;
            case cmChangeDrct:
                // changeDir();
                break;
            default:
                return ;
        }
    }

    event.what = evNothing;

    // switch (event.data.message.command) {
    //     case cmNewWindow:
    //     case cmListDemo:
    //     case cmEditorDemo:
    //         break;
    //     case cmAbout:
    //         tv_messagebox("This is a demo application of the C wrapper for magiblot's Turbo Vision library.",
    //                       0x0001 | 0x0400);
    //         break;
    //     default:
    //         return;
    // }
}

void fileOpen() {
    char fileName[260];
    strcpy( fileName, "*.*" );

    tv_FileDialog* fd = tv_filedialog_create( "*.*", "Open file", "~N~ame",
        tv_fdOpenButton, 100 );

    if( tv_application_exec_dialog( example_app, fd, fileName ) != cmCancel ) {
        tv_application_open_editor( example_app, fileName, 1 );
    }
}

void fileNew()
{
    tv_application_open_editor( example_app, 0, 1 );
}

int main(void) {
    example_app = tv_application_create(createStatusLine, createMenuBar, handleEvent);

    if (!example_app) {
        fprintf(stderr, "Failed to create application\n");
        return 1;
    }

    tv_application_run(example_app);

    /* Clean up application */
    tv_application_destroy(example_app);

    return 0;
}
