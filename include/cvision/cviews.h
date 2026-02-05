//
// Created by Jason Lee on 2/2/26.
//

#ifndef TVISION_C2VIEWS_H
#define TVISION_C2VIEWS_H

#include "ctypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Command codes from views.h */
extern const tv_ushort tv_cmNew;
extern const tv_ushort tv_cmOpen;
extern const tv_ushort tv_cmSave;
extern const tv_ushort tv_cmSaveAs;
extern const tv_ushort tv_cmSaveAll;
extern const tv_ushort tv_cmChDir;
extern const tv_ushort tv_cmDosShell;
extern const tv_ushort tv_cmCloseAll;
extern const tv_ushort tv_cmCut;
extern const tv_ushort tv_cmCopy;
extern const tv_ushort tv_cmPaste;
extern const tv_ushort tv_cmUndo;
extern const tv_ushort tv_cmClear;
extern const tv_ushort tv_cmTile;
extern const tv_ushort tv_cmCascade;
extern const tv_ushort tv_cmRedo;
extern const tv_ushort tv_cmReceivedFocus;
extern const tv_ushort tv_cmReleasedFocus;
extern const tv_ushort tv_cmCommandSetChanged;
extern const tv_ushort tv_cmScrollBarChanged;
extern const tv_ushort tv_cmScrollBarClicked;
extern const tv_ushort tv_cmSelectWindowNum;
extern const tv_ushort tv_cmListItemSelected;
extern const tv_ushort tv_cmScreenChanged;
extern const tv_ushort tv_cmTimerExpired;

/* TView State masks */
extern const tv_ushort tv_sfVisible;
extern const tv_ushort tv_sfCursorVis;
extern const tv_ushort tv_sfCursorIns;
extern const tv_ushort tv_sfShadow;
extern const tv_ushort tv_sfActive;
extern const tv_ushort tv_sfSelected;
extern const tv_ushort tv_sfFocused;
extern const tv_ushort tv_sfDragging;
extern const tv_ushort tv_sfDisabled;
extern const tv_ushort tv_sfModal;
extern const tv_ushort tv_sfDefault;
extern const tv_ushort tv_sfExposed;

/* TView Option masks */
extern const tv_ushort tv_ofSelectable;
extern const tv_ushort tv_ofTopSelect;
extern const tv_ushort tv_ofFirstClick;
extern const tv_ushort tv_ofFramed;
extern const tv_ushort tv_ofPreProcess;
extern const tv_ushort tv_ofPostProcess;
extern const tv_ushort tv_ofBuffered;
extern const tv_ushort tv_ofTileable;
extern const tv_ushort tv_ofCenterX;
extern const tv_ushort tv_ofCenterY;
extern const tv_ushort tv_ofCentered;
extern const tv_ushort tv_ofValidate;

/* TView GrowMode masks */
extern const tv_uchar tv_gfGrowLoX;
extern const tv_uchar tv_gfGrowLoY;
extern const tv_uchar tv_gfGrowHiX;
extern const tv_uchar tv_gfGrowHiY;
extern const tv_uchar tv_gfGrowAll;
extern const tv_uchar tv_gfGrowRel;
extern const tv_uchar tv_gfFixed;

/* TView DragMode masks */
extern const tv_uchar tv_dmDragMove;
extern const tv_uchar tv_dmDragGrow;
extern const tv_uchar tv_dmDragGrowLeft;
extern const tv_uchar tv_dmLimitLoX;
extern const tv_uchar tv_dmLimitLoY;
extern const tv_uchar tv_dmLimitHiX;
extern const tv_uchar tv_dmLimitHiY;
extern const tv_uchar tv_dmLimitAll;

/* TView Help context codes */
extern const tv_ushort tv_hcNoContext;
extern const tv_ushort tv_hcDragging;

/* TScrollBar part codes */
extern const tv_int tv_sbLeftArrow;
extern const tv_int tv_sbRightArrow;
extern const tv_int tv_sbPageLeft;
extern const tv_int tv_sbPageRight;
extern const tv_int tv_sbUpArrow;
extern const tv_int tv_sbDownArrow;
extern const tv_int tv_sbPageUp;
extern const tv_int tv_sbPageDown;
extern const tv_int tv_sbIndicator;

/* TScrollBar options */
extern const tv_ushort tv_sbHorizontal;
extern const tv_ushort tv_sbVertical;
extern const tv_ushort tv_sbHandleKeyboard;

/* TWindow Flags masks */
extern const tv_uchar tv_wfMove;
extern const tv_uchar tv_wfGrow;
extern const tv_uchar tv_wfClose;
extern const tv_uchar tv_wfZoom;

/* TView inhibit flags */
extern const tv_ushort tv_noMenuBar;
extern const tv_ushort tv_noDeskTop;
extern const tv_ushort tv_noStatusLine;
extern const tv_ushort tv_noBackground;
extern const tv_ushort tv_noFrame;
extern const tv_ushort tv_noViewer;
extern const tv_ushort tv_noHistory;

/* TWindow number constants */
extern const tv_short tv_wnNoNumber;

/* TWindow palette entries */
extern const tv_short tv_wpBlueWindow;
extern const tv_short tv_wpCyanWindow;
extern const tv_short tv_wpGrayWindow;

/* TCommandSet functions */
tv_CommandSet* tv_commandset_create(void);
void tv_commandset_destroy(tv_CommandSet* cs);
tv_bool tv_commandset_has(tv_CommandSet* cs, tv_int cmd);
void tv_commandset_disable_cmd(tv_CommandSet* cs, tv_int cmd);
void tv_commandset_enable_cmd(tv_CommandSet* cs, tv_int cmd);
tv_bool tv_commandset_is_empty(tv_CommandSet* cs);

/* TPalette functions */
tv_Palette* tv_palette_create(const char* data, tv_ushort size);
void tv_palette_destroy(tv_Palette* palette);

/* TView functions */
tv_View* tv_view_create(tv_Rect bounds);
void tv_view_destroy(tv_View* view);
tv_Rect tv_view_get_bounds(tv_View* view);
tv_Rect tv_view_get_extent(tv_View* view);
tv_Rect tv_view_get_clip_rect(tv_View* view);
tv_bool tv_view_mouse_in_view(tv_View* view, tv_Point mouse);
void tv_view_locate(tv_View* view, tv_Rect bounds);
void tv_view_grow_to(tv_View* view, tv_short x, tv_short y);
void tv_view_move_to(tv_View* view, tv_short x, tv_short y);
void tv_view_set_bounds(tv_View* view, tv_Rect bounds);
tv_ushort tv_view_get_help_ctx(tv_View* view);
tv_bool tv_view_valid(tv_View* view, tv_ushort command);
void tv_view_hide(tv_View* view);
void tv_view_show(tv_View* view);
void tv_view_draw(tv_View* view);
void tv_view_draw_view(tv_View* view);
tv_bool tv_view_exposed(tv_View* view);
tv_bool tv_view_focus(tv_View* view);
void tv_view_hide_cursor(tv_View* view);
tv_ushort tv_view_data_size(tv_View* view);
void tv_view_get_data(tv_View* view, void* rec);
void tv_view_set_data(tv_View* view, void* rec);
void tv_view_awaken(tv_View* view);
void tv_view_block_cursor(tv_View* view);
void tv_view_normal_cursor(tv_View* view);
void tv_view_reset_cursor(tv_View* view);
void tv_view_set_cursor(tv_View* view, tv_int x, tv_int y);
void tv_view_show_cursor(tv_View* view);
void tv_view_draw_cursor(tv_View* view);
void tv_view_clear_event(tv_View* view, tv_Event* event);
tv_bool tv_view_event_avail(tv_View* view);
void tv_view_get_event(tv_View* view, tv_Event* event);
void tv_view_handle_event(tv_View* view, tv_Event* event);
void tv_view_put_event(tv_View* view, tv_Event* event);
tv_bool tv_view_command_enabled(tv_ushort command);
void tv_view_disable_commands(tv_CommandSet* commands);
void tv_view_enable_commands(tv_CommandSet* commands);
void tv_view_disable_command(tv_ushort command);
void tv_view_enable_command(tv_ushort command);
void tv_view_get_commands(tv_CommandSet* commands);
void tv_view_set_commands(tv_CommandSet* commands);
void tv_view_end_modal(tv_View* view, tv_ushort command);
tv_ushort tv_view_execute(tv_View* view);
tv_bool tv_view_get_state(tv_View* view, tv_ushort state);
void tv_view_select(tv_View* view);
void tv_view_set_state(tv_View* view, tv_ushort state, tv_bool enable);
tv_Point tv_view_make_global(tv_View* view, tv_Point source);
tv_Point tv_view_make_local(tv_View* view, tv_Point source);
tv_View* tv_view_next_view(tv_View* view);
tv_View* tv_view_prev_view(tv_View* view);
tv_View* tv_view_prev(tv_View* view);
void tv_view_make_first(tv_View* view);
void tv_view_put_in_front_of(tv_View* view, tv_View* target);
tv_View* tv_view_top_view(tv_View* view);
void tv_view_write_char(tv_View* view, tv_short x, tv_short y, char c, tv_uchar color, tv_short count);
void tv_view_write_str(tv_View* view, tv_short x, tv_short y, const char* str, tv_uchar color);

/* TFrame functions */
tv_Frame* tv_frame_create(tv_Rect bounds);
void tv_frame_destroy(tv_Frame* frame);
void tv_frame_draw(tv_Frame* frame);
void tv_frame_handle_event(tv_Frame* frame, tv_Event* event);
void tv_frame_set_state(tv_Frame* frame, tv_ushort state, tv_bool enable);

/* TScrollBar functions */
tv_ScrollBar* tv_scrollbar_create(tv_Rect bounds);
void tv_scrollbar_destroy(tv_ScrollBar* scrollbar);
void tv_scrollbar_draw(tv_ScrollBar* scrollbar);
void tv_scrollbar_handle_event(tv_ScrollBar* scrollbar, tv_Event* event);
void tv_scrollbar_scroll_draw(tv_ScrollBar* scrollbar);
tv_int tv_scrollbar_scroll_step(tv_ScrollBar* scrollbar, tv_int part);
void tv_scrollbar_set_params(tv_ScrollBar* scrollbar, tv_int value, tv_int min, tv_int max, tv_int pg_step, tv_int ar_step);
void tv_scrollbar_set_range(tv_ScrollBar* scrollbar, tv_int min, tv_int max);
void tv_scrollbar_set_step(tv_ScrollBar* scrollbar, tv_int pg_step, tv_int ar_step);
void tv_scrollbar_set_value(tv_ScrollBar* scrollbar, tv_int value);
void tv_scrollbar_draw_pos(tv_ScrollBar* scrollbar, tv_int pos);
tv_int tv_scrollbar_get_pos(tv_ScrollBar* scrollbar);
tv_int tv_scrollbar_get_size(tv_ScrollBar* scrollbar);

/* TScroller functions */
tv_Scroller* tv_scroller_create(tv_Rect bounds, tv_ScrollBar* h_scrollbar, tv_ScrollBar* v_scrollbar);
void tv_scroller_destroy(tv_Scroller* scroller);
void tv_scroller_change_bounds(tv_Scroller* scroller, tv_Rect bounds);
void tv_scroller_handle_event(tv_Scroller* scroller, tv_Event* event);
void tv_scroller_scroll_draw(tv_Scroller* scroller);
void tv_scroller_scroll_to(tv_Scroller* scroller, tv_int x, tv_int y);
void tv_scroller_set_limit(tv_Scroller* scroller, tv_int x, tv_int y);
void tv_scroller_set_state(tv_Scroller* scroller, tv_ushort state, tv_bool enable);
void tv_scroller_check_draw(tv_Scroller* scroller);
void tv_scroller_shutdown(tv_Scroller* scroller);

/* TListViewer functions */
tv_ListViewer* tv_listviewer_create(tv_Rect bounds, tv_ushort num_cols, tv_ScrollBar* h_scrollbar, tv_ScrollBar* v_scrollbar);
void tv_listviewer_destroy(tv_ListViewer* listviewer);
void tv_listviewer_change_bounds(tv_ListViewer* listviewer, tv_Rect bounds);
void tv_listviewer_draw(tv_ListViewer* listviewer);
void tv_listviewer_focus_item(tv_ListViewer* listviewer, tv_short item);
void tv_listviewer_handle_event(tv_ListViewer* listviewer, tv_Event* event);
void tv_listviewer_select_item(tv_ListViewer* listviewer, tv_short item);
void tv_listviewer_set_range(tv_ListViewer* listviewer, tv_short range);
void tv_listviewer_set_state(tv_ListViewer* listviewer, tv_ushort state, tv_bool enable);
void tv_listviewer_focus_item_num(tv_ListViewer* listviewer, tv_short item);
void tv_listviewer_shutdown(tv_ListViewer* listviewer);

/* TGroup functions */
tv_Group* tv_group_create(tv_Rect bounds);
void tv_group_destroy(tv_Group* group);
void tv_group_shutdown(tv_Group* group);
tv_ushort tv_group_exec_view(tv_Group* group, tv_View* view);
tv_ushort tv_group_execute(tv_Group* group);
void tv_group_awaken(tv_Group* group);
void tv_group_insert_view(tv_Group* group, tv_View* view, tv_View* target);
void tv_group_remove(tv_Group* group, tv_View* view);
void tv_group_remove_view(tv_Group* group, tv_View* view);
void tv_group_reset_current(tv_Group* group);
void tv_group_select_next(tv_Group* group, tv_bool forwards);
tv_bool tv_group_focus_next(tv_Group* group, tv_bool forwards);
void tv_group_insert(tv_Group* group, tv_View* view);
void tv_group_insert_before(tv_Group* group, tv_View* view, tv_View* target);
tv_View* tv_group_at(tv_Group* group, tv_short index);
tv_View* tv_group_first_match(tv_Group* group, tv_ushort state, tv_ushort options);
tv_short tv_group_index_of(tv_Group* group, tv_View* view);
tv_View* tv_group_first(tv_Group* group);
void tv_group_set_state(tv_Group* group, tv_ushort state, tv_bool enable);
void tv_group_handle_event(tv_Group* group, tv_Event* event);
void tv_group_change_bounds(tv_Group* group, tv_Rect bounds);
tv_ushort tv_group_data_size(tv_Group* group);
void tv_group_get_data(tv_Group* group, void* rec);
void tv_group_set_data(tv_Group* group, void* rec);
void tv_group_draw(tv_Group* group);
void tv_group_redraw(tv_Group* group);
void tv_group_lock(tv_Group* group);
void tv_group_unlock(tv_Group* group);
void tv_group_reset_cursor(tv_Group* group);
void tv_group_end_modal(tv_Group* group, tv_ushort command);
tv_ushort tv_group_get_help_ctx(tv_Group* group);
tv_bool tv_group_valid(tv_Group* group, tv_ushort command);
void tv_group_free_buffer(tv_Group* group);
void tv_group_get_buffer(tv_Group* group);

/* TWindow functions */
tv_Window* tv_window_create(tv_Rect bounds, const char* title, tv_short number);
void tv_window_destroy(tv_Window* window);
void tv_window_close(tv_Window* window);
const char* tv_window_get_title(tv_Window* window, tv_short max_size);
void tv_window_handle_event(tv_Window* window, tv_Event* event);
void tv_window_set_state(tv_Window* window, tv_ushort state, tv_bool enable);
tv_ScrollBar* tv_window_standard_scrollbar(tv_Window* window, tv_ushort options);
void tv_window_zoom(tv_Window* window);
void tv_window_shutdown(tv_Window* window);

#ifdef __cplusplus
}
#endif

#endif //TVISION_C2VIEWS_H
