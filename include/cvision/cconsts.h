/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   CCONSTS.H                                                             */
/*                                                                         */
/*   C wrappers for Turbo Vision key code constants                       */
/*                                                                         */
/* ------------------------------------------------------------------------*/

#ifndef __CCONSTS_H
#define __CCONSTS_H

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------*/
/*   Command codes and constants from views.h                             */
/* ------------------------------------------------------------------------*/

/* Standard command codes */
#define cmValid         0
#define cmQuit          1
#define cmError         2
#define cmMenu          3
#define cmClose         4
#define cmZoom          5
#define cmResize        6
#define cmNext          7
#define cmPrev          8
#define cmHelp          9

/* TDialog standard commands */
#define cmOK            10
#define cmCancel        11
#define cmYes           12
#define cmNo            13
#define cmDefault       14

/* Standard application commands */
#define cmNew           30
#define cmOpen          31
#define cmSave          32
#define cmSaveAs        33
#define cmSaveAll       34
#define cmChDir         35
#define cmDosShell      36
#define cmCloseAll      37

/* TView State masks */
#define sfVisible       0x001
#define sfCursorVis     0x002
#define sfCursorIns     0x004
#define sfShadow        0x008
#define sfActive        0x010
#define sfSelected      0x020
#define sfFocused       0x040
#define sfDragging      0x080
#define sfDisabled      0x100
#define sfModal         0x200
#define sfDefault       0x400
#define sfExposed       0x800

/* TView Option masks */
#define ofSelectable    0x001
#define ofTopSelect     0x002
#define ofFirstClick    0x004
#define ofFramed        0x008
#define ofPreProcess    0x010
#define ofPostProcess   0x020
#define ofBuffered      0x040
#define ofTileable      0x080
#define ofCenterX       0x100
#define ofCenterY       0x200
#define ofCentered      0x300
#define ofValidate      0x400

/* TView GrowMode masks */
#define gfGrowLoX       0x01
#define gfGrowLoY       0x02
#define gfGrowHiX       0x04
#define gfGrowHiY       0x08
#define gfGrowAll       0x0f
#define gfGrowRel       0x10
#define gfFixed         0x20

/* TView DragMode masks */
#define dmDragMove      0x01
#define dmDragGrow      0x02
#define dmDragGrowLeft  0x04
#define dmLimitLoX      0x10
#define dmLimitLoY      0x20
#define dmLimitHiX      0x40
#define dmLimitHiY      0x80
#define dmLimitAll      (dmLimitLoX | dmLimitLoY | dmLimitHiX | dmLimitHiY)

/* TView Help context codes */
#define hcNoContext     0
#define hcDragging      1

/* TScrollBar part codes */
#define sbLeftArrow     0
#define sbRightArrow    1
#define sbPageLeft      2
#define sbPageRight     3
#define sbUpArrow       4
#define sbDownArrow     5
#define sbPageUp        6
#define sbPageDown      7
#define sbIndicator     8

/* TScrollBar options for TWindow.StandardScrollBar */
#define sbHorizontal    0x000
#define sbVertical      0x001
#define sbHandleKeyboard 0x002

/* TWindow Flags masks */
#define wfMove          0x01
#define wfGrow          0x02
#define wfClose         0x04
#define wfZoom          0x08

/* TView inhibit flags */
#define noMenuBar       0x0001
#define noDeskTop       0x0002
#define noStatusLine    0x0004
#define noBackground    0x0008
#define noFrame         0x0010
#define noViewer        0x0020
#define noHistory       0x0040

/* TWindow number constants */
#define wnNoNumber      0

/* TWindow palette entries */
#define wpBlueWindow    0
#define wpCyanWindow    1
#define wpGrayWindow    2

#if !defined( __COMMAND_CODES )
#define __COMMAND_CODES
/* Application command codes */
#define cmCut           20
#define cmCopy          21
#define cmPaste         22
#define cmUndo          23
#define cmClear         24
#define cmTile          25
#define cmCascade       26
#define cmRedo          27

/* Standard messages */
#define cmReceivedFocus     50
#define cmReleasedFocus     51
#define cmCommandSetChanged 52
#define cmTimerExpired      58

/* TScrollBar messages */
#define cmScrollBarChanged  53
#define cmScrollBarClicked  54

/* TWindow select messages */
#define cmSelectWindowNum   55

/* TListViewer messages */
#define cmListItemSelected  56

/* TProgram messages */
#define cmScreenChanged     57
#endif


/* Event masks */
#define positionalEvents    (evMouse & ~evMouseWheel)
#define focusedEvents       (evKeyboard | evCommand)

#if !defined( __EVENT_CODES )
#define __EVENT_CODES
    /* Event codes */

#define evMouseDown  0x0001
#define evMouseUp    0x0002
#define evMouseMove  0x0004
#define evMouseAuto  0x0008
#define evMouseWheel 0x0020
#define evKeyDown    0x0010
#define evCommand    0x0100
#define evBroadcast  0x0200

    /* Event masks */

#define evNothing    0x0000
#define evMouse      0x002f
#define evKeyboard   0x0010
#define evMessage    0xFF00

    /* Mouse button state masks */

#define mbLeftButton   0x01
#define mbRightButton  0x02
#define mbMiddleButton 0x04

    /* Mouse wheel state masks */

#define mwUp      0x01
#define mwDown    0x02
#define mwLeft    0x04
#define mwRight   0x08

    /* Mouse event flags */

#define meMouseMoved   0x01
#define meDoubleClick  0x02
#define meTripleClick  0x04
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CCONSTS_H */