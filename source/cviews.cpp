//
// Created by Jason Lee on 2/2/26.
//

#include "cvision/cviews.h"
#include "cvision/ctypes.h"
#include <tvision/tv.h>

extern "C" {

/* Command codes from views.h */
const tv_ushort tv_cmNew = cmNew;
const tv_ushort tv_cmOpen = cmOpen;
const tv_ushort tv_cmSave = cmSave;
const tv_ushort tv_cmSaveAs = cmSaveAs;
const tv_ushort tv_cmSaveAll = cmSaveAll;
const tv_ushort tv_cmChDir = cmChDir;
const tv_ushort tv_cmDosShell = cmDosShell;
const tv_ushort tv_cmCloseAll = cmCloseAll;
const tv_ushort tv_cmCut = cmCut;
const tv_ushort tv_cmCopy = cmCopy;
const tv_ushort tv_cmPaste = cmPaste;
const tv_ushort tv_cmUndo = cmUndo;
const tv_ushort tv_cmClear = cmClear;
const tv_ushort tv_cmTile = cmTile;
const tv_ushort tv_cmCascade = cmCascade;
const tv_ushort tv_cmRedo = cmRedo;
const tv_ushort tv_cmReceivedFocus = cmReceivedFocus;
const tv_ushort tv_cmReleasedFocus = cmReleasedFocus;
const tv_ushort tv_cmCommandSetChanged = cmCommandSetChanged;
const tv_ushort tv_cmScrollBarChanged = cmScrollBarChanged;
const tv_ushort tv_cmScrollBarClicked = cmScrollBarClicked;
const tv_ushort tv_cmSelectWindowNum = cmSelectWindowNum;
const tv_ushort tv_cmListItemSelected = cmListItemSelected;
const tv_ushort tv_cmScreenChanged = cmScreenChanged;
const tv_ushort tv_cmTimerExpired = cmTimerExpired;

/* TView State masks */
const tv_ushort tv_sfVisible = sfVisible;
const tv_ushort tv_sfCursorVis = sfCursorVis;
const tv_ushort tv_sfCursorIns = sfCursorIns;
const tv_ushort tv_sfShadow = sfShadow;
const tv_ushort tv_sfActive = sfActive;
const tv_ushort tv_sfSelected = sfSelected;
const tv_ushort tv_sfFocused = sfFocused;
const tv_ushort tv_sfDragging = sfDragging;
const tv_ushort tv_sfDisabled = sfDisabled;
const tv_ushort tv_sfModal = sfModal;
const tv_ushort tv_sfDefault = sfDefault;
const tv_ushort tv_sfExposed = sfExposed;

/* TView Option masks */
const tv_ushort tv_ofSelectable = ofSelectable;
const tv_ushort tv_ofTopSelect = ofTopSelect;
const tv_ushort tv_ofFirstClick = ofFirstClick;
const tv_ushort tv_ofFramed = ofFramed;
const tv_ushort tv_ofPreProcess = ofPreProcess;
const tv_ushort tv_ofPostProcess = ofPostProcess;
const tv_ushort tv_ofBuffered = ofBuffered;
const tv_ushort tv_ofTileable = ofTileable;
const tv_ushort tv_ofCenterX = ofCenterX;
const tv_ushort tv_ofCenterY = ofCenterY;
const tv_ushort tv_ofCentered = ofCentered;
const tv_ushort tv_ofValidate = ofValidate;

/* TView GrowMode masks */
const tv_uchar tv_gfGrowLoX = gfGrowLoX;
const tv_uchar tv_gfGrowLoY = gfGrowLoY;
const tv_uchar tv_gfGrowHiX = gfGrowHiX;
const tv_uchar tv_gfGrowHiY = gfGrowHiY;
const tv_uchar tv_gfGrowAll = gfGrowAll;
const tv_uchar tv_gfGrowRel = gfGrowRel;
const tv_uchar tv_gfFixed = gfFixed;

/* TView DragMode masks */
const tv_uchar tv_dmDragMove = dmDragMove;
const tv_uchar tv_dmDragGrow = dmDragGrow;
const tv_uchar tv_dmDragGrowLeft = dmDragGrowLeft;
const tv_uchar tv_dmLimitLoX = dmLimitLoX;
const tv_uchar tv_dmLimitLoY = dmLimitLoY;
const tv_uchar tv_dmLimitHiX = dmLimitHiX;
const tv_uchar tv_dmLimitHiY = dmLimitHiY;
const tv_uchar tv_dmLimitAll = dmLimitAll;

/* TView Help context codes */
const tv_ushort tv_hcNoContext = hcNoContext;
const tv_ushort tv_hcDragging = hcDragging;

/* TScrollBar part codes */
const tv_int tv_sbLeftArrow = sbLeftArrow;
const tv_int tv_sbRightArrow = sbRightArrow;
const tv_int tv_sbPageLeft = sbPageLeft;
const tv_int tv_sbPageRight = sbPageRight;
const tv_int tv_sbUpArrow = sbUpArrow;
const tv_int tv_sbDownArrow = sbDownArrow;
const tv_int tv_sbPageUp = sbPageUp;
const tv_int tv_sbPageDown = sbPageDown;
const tv_int tv_sbIndicator = sbIndicator;

/* TScrollBar options */
const tv_ushort tv_sbHorizontal = sbHorizontal;
const tv_ushort tv_sbVertical = sbVertical;
const tv_ushort tv_sbHandleKeyboard = sbHandleKeyboard;

/* TWindow Flags masks */
const tv_uchar tv_wfMove = wfMove;
const tv_uchar tv_wfGrow = wfGrow;
const tv_uchar tv_wfClose = wfClose;
const tv_uchar tv_wfZoom = wfZoom;

/* TView inhibit flags */
const tv_ushort tv_noMenuBar = noMenuBar;
const tv_ushort tv_noDeskTop = noDeskTop;
const tv_ushort tv_noStatusLine = noStatusLine;
const tv_ushort tv_noBackground = noBackground;
const tv_ushort tv_noFrame = noFrame;
const tv_ushort tv_noViewer = noViewer;
const tv_ushort tv_noHistory = noHistory;

/* TWindow number constants */
const tv_short tv_wnNoNumber = wnNoNumber;

/* TWindow palette entries */
const tv_short tv_wpBlueWindow = wpBlueWindow;
const tv_short tv_wpCyanWindow = wpCyanWindow;
const tv_short tv_wpGrayWindow = wpGrayWindow;

/* TCommandSet functions */
tv_CommandSet* tv_commandset_create(void) {
    return reinterpret_cast<tv_CommandSet*>(new TCommandSet());
}

void tv_commandset_destroy(tv_CommandSet* cs) {
    if (cs) {
        delete reinterpret_cast<TCommandSet*>(cs);
    }
}

tv_bool tv_commandset_has(tv_CommandSet* cs, tv_int cmd) {
    if (!cs) return 0;
    return reinterpret_cast<TCommandSet*>(cs)->has(cmd) ? 1 : 0;
}

void tv_commandset_disable_cmd(tv_CommandSet* cs, tv_int cmd) {
    if (cs) {
        reinterpret_cast<TCommandSet*>(cs)->disableCmd(cmd);
    }
}

void tv_commandset_enable_cmd(tv_CommandSet* cs, tv_int cmd) {
    if (cs) {
        reinterpret_cast<TCommandSet*>(cs)->enableCmd(cmd);
    }
}

tv_bool tv_commandset_is_empty(tv_CommandSet* cs) {
    if (!cs) return 1;
    return reinterpret_cast<TCommandSet*>(cs)->isEmpty() ? 1 : 0;
}

/* TPalette functions */
tv_Palette* tv_palette_create(const char* data, tv_ushort size) {
    return reinterpret_cast<tv_Palette*>(new TPalette(data, size));
}

void tv_palette_destroy(tv_Palette* palette) {
    if (palette) {
        delete reinterpret_cast<TPalette*>(palette);
    }
}

/* TView functions */
tv_View* tv_view_create(tv_Rect bounds) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_View*>(new TView(rect));
}

void tv_view_destroy(tv_View* view) {
    if (view) {
        TObject::destroy(reinterpret_cast<TView*>(view));
    }
}

tv_Rect tv_view_get_bounds(tv_View* view) {
    tv_Rect result = {{0, 0}, {0, 0}};
    if (view) {
        TRect bounds = reinterpret_cast<TView*>(view)->getBounds();
        result.a.x = bounds.a.x;
        result.a.y = bounds.a.y;
        result.b.x = bounds.b.x;
        result.b.y = bounds.b.y;
    }
    return result;
}

tv_Rect tv_view_get_extent(tv_View* view) {
    tv_Rect result = {{0, 0}, {0, 0}};
    if (view) {
        TRect extent = reinterpret_cast<TView*>(view)->getExtent();
        result.a.x = extent.a.x;
        result.a.y = extent.a.y;
        result.b.x = extent.b.x;
        result.b.y = extent.b.y;
    }
    return result;
}

tv_Rect tv_view_get_clip_rect(tv_View* view) {
    tv_Rect result = {{0, 0}, {0, 0}};
    if (view) {
        TRect clip = reinterpret_cast<TView*>(view)->getClipRect();
        result.a.x = clip.a.x;
        result.a.y = clip.a.y;
        result.b.x = clip.b.x;
        result.b.y = clip.b.y;
    }
    return result;
}

tv_bool tv_view_mouse_in_view(tv_View* view, tv_Point mouse) {
    if (!view) return 0;
    TPoint pt { mouse.x, mouse.y};
    return reinterpret_cast<TView*>(view)->mouseInView(pt) ? 1 : 0;
}

void tv_view_locate(tv_View* view, tv_Rect bounds) {
    if (view) {
        TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
        reinterpret_cast<TView*>(view)->locate(rect);
    }
}

void tv_view_grow_to(tv_View* view, tv_short x, tv_short y) {
    if (view) {
        reinterpret_cast<TView*>(view)->growTo(x, y);
    }
}

void tv_view_move_to(tv_View* view, tv_short x, tv_short y) {
    if (view) {
        reinterpret_cast<TView*>(view)->moveTo(x, y);
    }
}

void tv_view_set_bounds(tv_View* view, tv_Rect bounds) {
    if (view) {
        TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
        reinterpret_cast<TView*>(view)->setBounds(rect);
    }
}

tv_ushort tv_view_get_help_ctx(tv_View* view) {
    if (!view) return 0;
    return reinterpret_cast<TView*>(view)->getHelpCtx();
}

tv_bool tv_view_valid(tv_View* view, tv_ushort command) {
    if (!view) return 0;
    return reinterpret_cast<TView*>(view)->valid(command) ? 1 : 0;
}

void tv_view_hide(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->hide();
    }
}

void tv_view_show(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->show();
    }
}

void tv_view_draw(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->draw();
    }
}

void tv_view_draw_view(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->drawView();
    }
}

tv_bool tv_view_exposed(tv_View* view) {
    if (!view) return 0;
    return reinterpret_cast<TView*>(view)->exposed() ? 1 : 0;
}

tv_bool tv_view_focus(tv_View* view) {
    if (!view) return 0;
    return reinterpret_cast<TView*>(view)->focus() ? 1 : 0;
}

void tv_view_hide_cursor(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->hideCursor();
    }
}

tv_ushort tv_view_data_size(tv_View* view) {
    if (!view) return 0;
    return reinterpret_cast<TView*>(view)->dataSize();
}

void tv_view_get_data(tv_View* view, void* rec) {
    if (view && rec) {
        reinterpret_cast<TView*>(view)->getData(rec);
    }
}

void tv_view_set_data(tv_View* view, void* rec) {
    if (view && rec) {
        reinterpret_cast<TView*>(view)->setData(rec);
    }
}

void tv_view_awaken(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->awaken();
    }
}

void tv_view_block_cursor(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->blockCursor();
    }
}

void tv_view_normal_cursor(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->normalCursor();
    }
}

void tv_view_reset_cursor(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->resetCursor();
    }
}

void tv_view_set_cursor(tv_View* view, tv_int x, tv_int y) {
    if (view) {
        reinterpret_cast<TView*>(view)->setCursor(x, y);
    }
}

void tv_view_show_cursor(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->showCursor();
    }
}

void tv_view_draw_cursor(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->drawCursor();
    }
}

void tv_view_clear_event(tv_View* view, tv_Event* event) {
    if (view && event) {
        reinterpret_cast<TView*>(view)->clearEvent(*reinterpret_cast<TEvent*>(event));
    }
}

tv_bool tv_view_event_avail(tv_View* view) {
    if (!view) return 0;
    return reinterpret_cast<TView*>(view)->eventAvail() ? 1 : 0;
}

void tv_view_get_event(tv_View* view, tv_Event* event) {
    if (view && event) {
        reinterpret_cast<TView*>(view)->getEvent(*reinterpret_cast<TEvent*>(event));
    }
}

void tv_view_handle_event(tv_View* view, tv_Event* event) {
    if (view && event) {
        reinterpret_cast<TView*>(view)->handleEvent(*reinterpret_cast<TEvent*>(event));
    }
}

void tv_view_put_event(tv_View* view, tv_Event* event) {
    if (view && event) {
        reinterpret_cast<TView*>(view)->putEvent(*reinterpret_cast<TEvent*>(event));
    }
}

tv_bool tv_view_command_enabled(tv_ushort command) {
    return TView::commandEnabled(command) ? 1 : 0;
}

void tv_view_disable_commands(tv_CommandSet* commands) {
    if (commands) {
        TView::disableCommands(*reinterpret_cast<TCommandSet*>(commands));
    }
}

void tv_view_enable_commands(tv_CommandSet* commands) {
    if (commands) {
        TView::enableCommands(*reinterpret_cast<TCommandSet*>(commands));
    }
}

void tv_view_disable_command(tv_ushort command) {
    TView::disableCommand(command);
}

void tv_view_enable_command(tv_ushort command) {
    TView::enableCommand(command);
}

void tv_view_get_commands(tv_CommandSet* commands) {
    if (commands) {
        TView::getCommands(*reinterpret_cast<TCommandSet*>(commands));
    }
}

void tv_view_set_commands(tv_CommandSet* commands) {
    if (commands) {
        TView::setCommands(*reinterpret_cast<TCommandSet*>(commands));
    }
}

void tv_view_end_modal(tv_View* view, tv_ushort command) {
    if (view) {
        reinterpret_cast<TView*>(view)->endModal(command);
    }
}

tv_ushort tv_view_execute(tv_View* view) {
    if (!view) return 0;
    return reinterpret_cast<TView*>(view)->execute();
}

tv_bool tv_view_get_state(tv_View* view, tv_ushort state) {
    if (!view) return 0;
    return reinterpret_cast<TView*>(view)->getState(state) ? 1 : 0;
}

void tv_view_select(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->select();
    }
}

void tv_view_set_state(tv_View* view, tv_ushort state, tv_bool enable) {
    if (view) {
        reinterpret_cast<TView*>(view)->setState(state, enable != 0);
    }
}

tv_Point tv_view_make_global(tv_View* view, tv_Point source) {
    tv_Point result = {0, 0};
    if (view) {
        TPoint pt {source.x, source.y};
        TPoint global = reinterpret_cast<TView*>(view)->makeGlobal(pt);
        result.x = global.x;
        result.y = global.y;
    }
    return result;
}

tv_Point tv_view_make_local(tv_View* view, tv_Point source) {
    tv_Point result = {0, 0};
    if (view) {
        TPoint pt {source.x, source.y};
        TPoint local = reinterpret_cast<TView*>(view)->makeLocal(pt);
        result.x = local.x;
        result.y = local.y;
    }
    return result;
}

tv_View* tv_view_next_view(tv_View* view) {
    if (!view) return nullptr;
    return reinterpret_cast<tv_View*>(reinterpret_cast<TView*>(view)->nextView());
}

tv_View* tv_view_prev_view(tv_View* view) {
    if (!view) return nullptr;
    return reinterpret_cast<tv_View*>(reinterpret_cast<TView*>(view)->prevView());
}

tv_View* tv_view_prev(tv_View* view) {
    if (!view) return nullptr;
    return reinterpret_cast<tv_View*>(reinterpret_cast<TView*>(view)->prev());
}

void tv_view_make_first(tv_View* view) {
    if (view) {
        reinterpret_cast<TView*>(view)->makeFirst();
    }
}

void tv_view_put_in_front_of(tv_View* view, tv_View* target) {
    if (view) {
        reinterpret_cast<TView*>(view)->putInFrontOf(reinterpret_cast<TView*>(target));
    }
}

tv_View* tv_view_top_view(tv_View* view) {
    if (!view) return nullptr;
    return reinterpret_cast<tv_View*>(reinterpret_cast<TView*>(view)->TopView());
}

void tv_view_write_char(tv_View* view, tv_short x, tv_short y, char c, tv_uchar color, tv_short count) {
    if (view) {
        reinterpret_cast<TView*>(view)->writeChar(x, y, c, color, count);
    }
}

void tv_view_write_str(tv_View* view, tv_short x, tv_short y, const char* str, tv_uchar color) {
    if (view && str) {
        reinterpret_cast<TView*>(view)->writeStr(x, y, str, color);
    }
}

/* TFrame functions */
tv_Frame* tv_frame_create(tv_Rect bounds) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Frame*>(new TFrame(rect));
}

void tv_frame_destroy(tv_Frame* frame) {
    if (frame) {
        TObject::destroy(reinterpret_cast<TFrame*>(frame));
    }
}

void tv_frame_draw(tv_Frame* frame) {
    if (frame) {
        reinterpret_cast<TFrame*>(frame)->draw();
    }
}

void tv_frame_handle_event(tv_Frame* frame, tv_Event* event) {
    if (frame && event) {
        reinterpret_cast<TFrame*>(frame)->handleEvent(*reinterpret_cast<TEvent*>(event));
    }
}

void tv_frame_set_state(tv_Frame* frame, tv_ushort state, tv_bool enable) {
    if (frame) {
        reinterpret_cast<TFrame*>(frame)->setState(state, enable != 0);
    }
}

/* TScrollBar functions */
tv_ScrollBar* tv_scrollbar_create(tv_Rect bounds) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_ScrollBar*>(new TScrollBar(rect));
}

void tv_scrollbar_destroy(tv_ScrollBar* scrollbar) {
    if (scrollbar) {
        TObject::destroy(reinterpret_cast<TScrollBar*>(scrollbar));
    }
}

void tv_scrollbar_draw(tv_ScrollBar* scrollbar) {
    if (scrollbar) {
        reinterpret_cast<TScrollBar*>(scrollbar)->draw();
    }
}

void tv_scrollbar_handle_event(tv_ScrollBar* scrollbar, tv_Event* event) {
    if (scrollbar && event) {
        reinterpret_cast<TScrollBar*>(scrollbar)->handleEvent(*reinterpret_cast<TEvent*>(event));
    }
}

void tv_scrollbar_scroll_draw(tv_ScrollBar* scrollbar) {
    if (scrollbar) {
        reinterpret_cast<TScrollBar*>(scrollbar)->scrollDraw();
    }
}

tv_int tv_scrollbar_scroll_step(tv_ScrollBar* scrollbar, tv_int part) {
    if (!scrollbar) return 0;
    return reinterpret_cast<TScrollBar*>(scrollbar)->scrollStep(part);
}

void tv_scrollbar_set_params(tv_ScrollBar* scrollbar, tv_int value, tv_int min, tv_int max, tv_int pg_step, tv_int ar_step) {
    if (scrollbar) {
        reinterpret_cast<TScrollBar*>(scrollbar)->setParams(value, min, max, pg_step, ar_step);
    }
}

void tv_scrollbar_set_range(tv_ScrollBar* scrollbar, tv_int min, tv_int max) {
    if (scrollbar) {
        reinterpret_cast<TScrollBar*>(scrollbar)->setRange(min, max);
    }
}

void tv_scrollbar_set_step(tv_ScrollBar* scrollbar, tv_int pg_step, tv_int ar_step) {
    if (scrollbar) {
        reinterpret_cast<TScrollBar*>(scrollbar)->setStep(pg_step, ar_step);
    }
}

void tv_scrollbar_set_value(tv_ScrollBar* scrollbar, tv_int value) {
    if (scrollbar) {
        reinterpret_cast<TScrollBar*>(scrollbar)->setValue(value);
    }
}

void tv_scrollbar_draw_pos(tv_ScrollBar* scrollbar, tv_int pos) {
    if (scrollbar) {
        reinterpret_cast<TScrollBar*>(scrollbar)->drawPos(pos);
    }
}

tv_int tv_scrollbar_get_pos(tv_ScrollBar* scrollbar) {
    if (!scrollbar) return 0;
    return reinterpret_cast<TScrollBar*>(scrollbar)->getPos();
}

tv_int tv_scrollbar_get_size(tv_ScrollBar* scrollbar) {
    if (!scrollbar) return 0;
    return reinterpret_cast<TScrollBar*>(scrollbar)->getSize();
}

/* TScroller functions */
tv_Scroller* tv_scroller_create(tv_Rect bounds, tv_ScrollBar* h_scrollbar, tv_ScrollBar* v_scrollbar) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Scroller*>(
        new TScroller(rect, 
                     reinterpret_cast<TScrollBar*>(h_scrollbar),
                     reinterpret_cast<TScrollBar*>(v_scrollbar))
    );
}

void tv_scroller_destroy(tv_Scroller* scroller) {
    if (scroller) {
        TObject::destroy(reinterpret_cast<TScroller*>(scroller));
    }
}

void tv_scroller_change_bounds(tv_Scroller* scroller, tv_Rect bounds) {
    if (scroller) {
        TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
        reinterpret_cast<TScroller*>(scroller)->changeBounds(rect);
    }
}

void tv_scroller_handle_event(tv_Scroller* scroller, tv_Event* event) {
    if (scroller && event) {
        reinterpret_cast<TScroller*>(scroller)->handleEvent(*reinterpret_cast<TEvent*>(event));
    }
}

void tv_scroller_scroll_draw(tv_Scroller* scroller) {
    if (scroller) {
        reinterpret_cast<TScroller*>(scroller)->scrollDraw();
    }
}

void tv_scroller_scroll_to(tv_Scroller* scroller, tv_int x, tv_int y) {
    if (scroller) {
        reinterpret_cast<TScroller*>(scroller)->scrollTo(x, y);
    }
}

void tv_scroller_set_limit(tv_Scroller* scroller, tv_int x, tv_int y) {
    if (scroller) {
        reinterpret_cast<TScroller*>(scroller)->setLimit(x, y);
    }
}

void tv_scroller_set_state(tv_Scroller* scroller, tv_ushort state, tv_bool enable) {
    if (scroller) {
        reinterpret_cast<TScroller*>(scroller)->setState(state, enable != 0);
    }
}

void tv_scroller_check_draw(tv_Scroller* scroller) {
    if (scroller) {
        reinterpret_cast<TScroller*>(scroller)->checkDraw();
    }
}

void tv_scroller_shutdown(tv_Scroller* scroller) {
    if (scroller) {
        reinterpret_cast<TScroller*>(scroller)->shutDown();
    }
}

/* TListViewer functions */
tv_ListViewer* tv_listviewer_create(tv_Rect bounds, tv_ushort num_cols, tv_ScrollBar* h_scrollbar, tv_ScrollBar* v_scrollbar) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_ListViewer*>(
        new TListViewer(rect, num_cols,
                       reinterpret_cast<TScrollBar*>(h_scrollbar),
                       reinterpret_cast<TScrollBar*>(v_scrollbar))
    );
}

void tv_listviewer_destroy(tv_ListViewer* listviewer) {
    if (listviewer) {
        TObject::destroy(reinterpret_cast<TListViewer*>(listviewer));
    }
}

void tv_listviewer_change_bounds(tv_ListViewer* listviewer, tv_Rect bounds) {
    if (listviewer) {
        TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
        reinterpret_cast<TListViewer*>(listviewer)->changeBounds(rect);
    }
}

void tv_listviewer_draw(tv_ListViewer* listviewer) {
    if (listviewer) {
        reinterpret_cast<TListViewer*>(listviewer)->draw();
    }
}

void tv_listviewer_focus_item(tv_ListViewer* listviewer, tv_short item) {
    if (listviewer) {
        reinterpret_cast<TListViewer*>(listviewer)->focusItem(item);
    }
}

void tv_listviewer_handle_event(tv_ListViewer* listviewer, tv_Event* event) {
    if (listviewer && event) {
        reinterpret_cast<TListViewer*>(listviewer)->handleEvent(*reinterpret_cast<TEvent*>(event));
    }
}

void tv_listviewer_select_item(tv_ListViewer* listviewer, tv_short item) {
    if (listviewer) {
        reinterpret_cast<TListViewer*>(listviewer)->selectItem(item);
    }
}

void tv_listviewer_set_range(tv_ListViewer* listviewer, tv_short range) {
    if (listviewer) {
        reinterpret_cast<TListViewer*>(listviewer)->setRange(range);
    }
}

void tv_listviewer_set_state(tv_ListViewer* listviewer, tv_ushort state, tv_bool enable) {
    if (listviewer) {
        reinterpret_cast<TListViewer*>(listviewer)->setState(state, enable != 0);
    }
}

void tv_listviewer_focus_item_num(tv_ListViewer* listviewer, tv_short item) {
    if (listviewer) {
        reinterpret_cast<TListViewer*>(listviewer)->focusItemNum(item);
    }
}

void tv_listviewer_shutdown(tv_ListViewer* listviewer) {
    if (listviewer) {
        reinterpret_cast<TListViewer*>(listviewer)->shutDown();
    }
}

/* TGroup functions */
tv_Group* tv_group_create(tv_Rect bounds) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Group*>(new TGroup(rect));
}

void tv_group_destroy(tv_Group* group) {
    if (group) {
        TObject::destroy(reinterpret_cast<TGroup*>(group));
    }
}

void tv_group_shutdown(tv_Group* group) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->shutDown();
    }
}

tv_ushort tv_group_exec_view(tv_Group* group, tv_View* view) {
    if (!group) return 0;
    return reinterpret_cast<TGroup*>(group)->execView(reinterpret_cast<TView*>(view));
}

tv_ushort tv_group_execute(tv_Group* group) {
    if (!group) return 0;
    return reinterpret_cast<TGroup*>(group)->execute();
}

void tv_group_awaken(tv_Group* group) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->awaken();
    }
}

void tv_group_insert_view(tv_Group* group, tv_View* view, tv_View* target) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->insertView(
            reinterpret_cast<TView*>(view),
            reinterpret_cast<TView*>(target)
        );
    }
}

void tv_group_remove(tv_Group* group, tv_View* view) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->remove(reinterpret_cast<TView*>(view));
    }
}

void tv_group_remove_view(tv_Group* group, tv_View* view) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->removeView(reinterpret_cast<TView*>(view));
    }
}

void tv_group_reset_current(tv_Group* group) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->resetCurrent();
    }
}

void tv_group_select_next(tv_Group* group, tv_bool forwards) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->selectNext(forwards != 0);
    }
}

tv_bool tv_group_focus_next(tv_Group* group, tv_bool forwards) {
    if (!group) return 0;
    return reinterpret_cast<TGroup*>(group)->focusNext(forwards != 0) ? 1 : 0;
}

void tv_group_insert(tv_Group* group, tv_View* view) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->insert(reinterpret_cast<TView*>(view));
    }
}

void tv_group_insert_before(tv_Group* group, tv_View* view, tv_View* target) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->insertBefore(
            reinterpret_cast<TView*>(view),
            reinterpret_cast<TView*>(target)
        );
    }
}

tv_View* tv_group_at(tv_Group* group, tv_short index) {
    if (!group) return nullptr;
    return reinterpret_cast<tv_View*>(reinterpret_cast<TGroup*>(group)->at(index));
}

tv_View* tv_group_first_match(tv_Group* group, tv_ushort state, tv_ushort options) {
    if (!group) return nullptr;
    return reinterpret_cast<tv_View*>(reinterpret_cast<TGroup*>(group)->firstMatch(state, options));
}

tv_short tv_group_index_of(tv_Group* group, tv_View* view) {
    if (!group) return -1;
    return reinterpret_cast<TGroup*>(group)->indexOf(reinterpret_cast<TView*>(view));
}

tv_View* tv_group_first(tv_Group* group) {
    if (!group) return nullptr;
    return reinterpret_cast<tv_View*>(reinterpret_cast<TGroup*>(group)->first());
}

void tv_group_set_state(tv_Group* group, tv_ushort state, tv_bool enable) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->setState(state, enable != 0);
    }
}

void tv_group_handle_event(tv_Group* group, tv_Event* event) {
    if (group && event) {
        reinterpret_cast<TGroup*>(group)->handleEvent(*reinterpret_cast<TEvent*>(event));
    }
}

void tv_group_change_bounds(tv_Group* group, tv_Rect bounds) {
    if (group) {
        TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
        reinterpret_cast<TGroup*>(group)->changeBounds(rect);
    }
}

tv_ushort tv_group_data_size(tv_Group* group) {
    if (!group) return 0;
    return reinterpret_cast<TGroup*>(group)->dataSize();
}

void tv_group_get_data(tv_Group* group, void* rec) {
    if (group && rec) {
        reinterpret_cast<TGroup*>(group)->getData(rec);
    }
}

void tv_group_set_data(tv_Group* group, void* rec) {
    if (group && rec) {
        reinterpret_cast<TGroup*>(group)->setData(rec);
    }
}

void tv_group_draw(tv_Group* group) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->draw();
    }
}

void tv_group_redraw(tv_Group* group) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->redraw();
    }
}

void tv_group_lock(tv_Group* group) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->lock();
    }
}

void tv_group_unlock(tv_Group* group) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->unlock();
    }
}

void tv_group_reset_cursor(tv_Group* group) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->resetCursor();
    }
}

void tv_group_end_modal(tv_Group* group, tv_ushort command) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->endModal(command);
    }
}

tv_ushort tv_group_get_help_ctx(tv_Group* group) {
    if (!group) return 0;
    return reinterpret_cast<TGroup*>(group)->getHelpCtx();
}

tv_bool tv_group_valid(tv_Group* group, tv_ushort command) {
    if (!group) return 0;
    return reinterpret_cast<TGroup*>(group)->valid(command) ? 1 : 0;
}

void tv_group_free_buffer(tv_Group* group) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->freeBuffer();
    }
}

void tv_group_get_buffer(tv_Group* group) {
    if (group) {
        reinterpret_cast<TGroup*>(group)->getBuffer();
    }
}

/* TWindow functions */
tv_Window* tv_window_create(tv_Rect bounds, const char* title, tv_short number) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Window*>(new TWindow(rect, title, number));
}

void tv_window_destroy(tv_Window* window) {
    if (window) {
        TObject::destroy(reinterpret_cast<TWindow*>(window));
    }
}

void tv_window_close(tv_Window* window) {
    if (window) {
        reinterpret_cast<TWindow*>(window)->close();
    }
}

const char* tv_window_get_title(tv_Window* window, tv_short max_size) {
    if (!window) return nullptr;
    return reinterpret_cast<TWindow*>(window)->getTitle(max_size);
}

void tv_window_handle_event(tv_Window* window, tv_Event* event) {
    if (window && event) {
        reinterpret_cast<TWindow*>(window)->handleEvent(*reinterpret_cast<TEvent*>(event));
    }
}

void tv_window_set_state(tv_Window* window, tv_ushort state, tv_bool enable) {
    if (window) {
        reinterpret_cast<TWindow*>(window)->setState(state, enable != 0);
    }
}

tv_ScrollBar* tv_window_standard_scrollbar(tv_Window* window, tv_ushort options) {
    if (!window) return nullptr;
    return reinterpret_cast<tv_ScrollBar*>(reinterpret_cast<TWindow*>(window)->standardScrollBar(options));
}

void tv_window_zoom(tv_Window* window) {
    if (window) {
        reinterpret_cast<TWindow*>(window)->zoom();
    }
}

void tv_window_shutdown(tv_Window* window) {
    if (window) {
        reinterpret_cast<TWindow*>(window)->shutDown();
    }
}

}
    