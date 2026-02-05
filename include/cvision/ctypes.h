//
// Created by Jason Lee on 1/28/26.
//

#ifndef TVISION_CTYPES_H
#define TVISION_CTYPES_H

#define Uses_EventCodes
#define Uses_fpbase
#define Uses_fpstream
#define Uses_ifpstream
#define Uses_iopstream
#define Uses_ipstream
#define Uses_MsgBox
#define Uses_ofpstream
#define Uses_opstream
#define Uses_otstream
#define Uses_pstream
#define Uses_TApplication
#define Uses_TBackground
#define Uses_TButton
#define Uses_TChDirDialog
#define Uses_TCheckBoxes
#define Uses_TClipboard
#define Uses_TCluster
#define Uses_TCollection
#define Uses_TColorAttr
#define Uses_TColorDialog
#define Uses_TColorDisplay
#define Uses_TColorGroup
#define Uses_TColorGroupList
#define Uses_TColorItem
#define Uses_TColorItemList
#define Uses_TColorSelector
#define Uses_TCommandSet
#define Uses_TDeskTop
#define Uses_TDialog
#define Uses_TDirCollection
#define Uses_TDirEntry
#define Uses_TDirListBox
#define Uses_TDrawBuffer
#define Uses_TDrawSurface
#define Uses_TEditor
#define Uses_TEditWindow
#define Uses_TEvent
#define Uses_TEventQueue
#define Uses_TFileCollection
#define Uses_TFileDialog
#define Uses_TFileEditor
#define Uses_TFileInfoPane
#define Uses_TFileInputLine
#define Uses_TFileList
#define Uses_TFindDialogRec
#define Uses_TFrame
#define Uses_TGroup
#define Uses_THardwareInfo
#define Uses_THistory
#define Uses_THistoryViewer
#define Uses_THistoryWindow
#define Uses_TIndicator
#define Uses_TInputLine
#define Uses_TKeys
#define Uses_TLabel
#define Uses_TListBox
#define Uses_TListViewer
#define Uses_TMemo
#define Uses_TMenu
#define Uses_TMenuBar
#define Uses_TMenuBox
#define Uses_TMenuItem
#define Uses_TMenuPopup
#define Uses_TMenuView
#define Uses_TMonoSelector
#define Uses_TMultiCheckBoxes
#define Uses_TNSCollection
#define Uses_TNSSortedCollection
#define Uses_TObject
#define Uses_TOutline
#define Uses_TOutlineViewer
#define Uses_TPalette
#define Uses_TParamText
#define Uses_TPoint
#define Uses_TPReadObjects
#define Uses_TProgram
#define Uses_TPWrittenObjects
#define Uses_TRadioButtons
#define Uses_TRect
#define Uses_TReplaceDialogRec
#define Uses_TResourceCollection
#define Uses_TResourceFile
#define Uses_TResourceItem
#define Uses_TScreen
#define Uses_TScreenCell
#define Uses_TScrollBar
#define Uses_TScroller
#define Uses_TSearchRec
#define Uses_TSItem
#define Uses_TSortedCollection
#define Uses_TSortedListBox
#define Uses_TStaticText
#define Uses_TStatusDef
#define Uses_TStatusItem
#define Uses_TStatusLine
#define Uses_TStreamable
#define Uses_TStreamableClass
#define Uses_TStreamableTypes
#define Uses_TStrIndexRec
#define Uses_TStringCollection
#define Uses_TStringList
#define Uses_TStrListMaker
#define Uses_TSubMenu
#define Uses_TSurfaceView
#define Uses_TSystemError
#define Uses_TTerminal
#define Uses_TText
#define Uses_TTextDevice
#define Uses_TTimerQueue
#define Uses_TView
#define Uses_TVMemMgr
#define Uses_TWindow
#define Uses_ViewCommands

typedef unsigned short ushort;

#include "cconsts.h"

/* Maximum text size for key events */
#define TV_MAX_CHAR_SIZE    4

#define TV_FALSE 0
#define TV_TRUE 1

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tv_Application tv_Application;
typedef struct tv_Button tv_Button;
typedef struct tv_CheckBoxes tv_CheckBoxes;
typedef struct tv_Cluster tv_Cluster;
typedef struct tv_CommandSet tv_CommandSet;
typedef struct tv_Collection tv_Collection;
typedef struct tv_Dialog tv_Dialog;
typedef struct tv_Frame tv_Frame;
typedef struct tv_Group tv_Group;
typedef struct tv_History tv_History;
typedef struct tv_HistoryViewer tv_HistoryViewer;
typedef struct tv_HistoryWindow tv_HistoryWindow;
typedef struct tv_InputLine tv_InputLine;
typedef struct tv_Label tv_Label;
typedef struct tv_ListBox tv_ListBox;
typedef struct tv_ListViewer tv_ListViewer;
typedef struct tv_MenuBar tv_MenuBar;
typedef struct tv_MenuItem tv_MenuItem;
typedef struct tv_MultiCheckBoxes tv_MultiCheckBoxes;
typedef struct tv_Node tv_Node;
typedef struct tv_Outline tv_Outline;
typedef struct tv_OutlineViewer tv_OutlineViewer;
typedef struct tv_Palette tv_Palette;
typedef struct tv_ParamText tv_ParamText;
typedef struct tv_RadioButtons tv_RadioButtons;
typedef struct tv_SItem tv_SItem;
typedef struct tv_ScrollBar tv_ScrollBar;
typedef struct tv_Scroller tv_Scroller;
typedef struct tv_StaticText tv_StaticText;
typedef struct tv_StatusItem tv_StatusItem;
typedef struct tv_StatusLine tv_StatusLine;
typedef struct tv_SubMenu tv_SubMenu;
typedef struct tv_Validator tv_Validator;
typedef struct tv_View tv_View;
typedef struct tv_Window tv_Window;
typedef struct tv_TMouse tv_TMouse;
typedef struct tv_TEventQueue tv_TEventQueue;
typedef struct tv_TTimerQueue tv_TTimerQueue;
typedef struct tv_TScreen tv_TScreen;
typedef struct tv_TSystemError tv_TSystemError;

/* Basic type definitions */
typedef unsigned int tv_TimerId;
typedef unsigned short tv_ushort;
typedef unsigned char tv_uchar;
typedef unsigned int tv_uint;
typedef short tv_short;
typedef int tv_int;
typedef int tv_bool;

/* TPoint structure - defined here to avoid circular dependency */
typedef struct tv_Point {
    int x;
    int y;
} tv_Point;

/* TRect structure - defined here to avoid circular dependency */
typedef struct tv_Rect {
    tv_Point a;
    tv_Point b;
} tv_Rect;

/* KeyDownEvent structure */
typedef struct {
    tv_ushort keyCode;
    tv_ushort controlKeyState;
    char text[4];  /* maxCharSize */
    unsigned char textLength;
} tv_KeyDownEvent;

/* MessageEvent structure */
typedef struct {
    tv_ushort command;
    void *infoPtr;
} tv_MessageEvent;

/* MouseEventType structure */
typedef struct {
    tv_Point where;
    tv_ushort eventFlags;
    tv_ushort controlKeyState;
    unsigned char buttons;
    unsigned char wheel;
} tv_MouseEventType;

/* TEvent structure */
typedef struct {
    tv_ushort what;
    union {
        tv_MouseEventType mouse;
        tv_KeyDownEvent keyDown;
        tv_MessageEvent message;
    } data;
} tv_Event;


#ifdef __cplusplus
}
#endif

#endif //TVISION_CTYPES_H
