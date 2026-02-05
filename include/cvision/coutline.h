//
// Created by Bob on 2/1/26.
//
// C wrappers for TOutline and TOutlineViewer classes
//

#ifndef TVISION_COUTLINE_H
#define TVISION_COUTLINE_H

#include "ctypes.h"
#include "cobjects.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const int tv_ovExpanded;
extern const int tv_ovChildren;
extern const int tv_ovLast;
extern const int tv_cmOutlineItemSelected;
    
/* Callback types for traverse functions */
typedef tv_bool (*tv_OutlineVisitor)(tv_OutlineViewer*, tv_Node*, int, int, long, tv_ushort, void*);
typedef tv_bool (*tv_OutlineVisitorNoArg)(tv_OutlineViewer*, tv_Node*, int, int, long, tv_ushort);

/* TNode functions */
tv_Node* tv_node_create(const char* text);
tv_Node* tv_node_create_full(const char* text, tv_Node* children, tv_Node* next, tv_bool initial_state);
void tv_node_destroy(tv_Node* node);

/* Node accessors */
tv_Node* tv_node_get_next(tv_Node* node);
void tv_node_set_next(tv_Node* node, tv_Node* next);
const char* tv_node_get_text(tv_Node* node);
tv_Node* tv_node_get_child_list(tv_Node* node);
void tv_node_set_child_list(tv_Node* node, tv_Node* child_list);
tv_bool tv_node_is_expanded(tv_Node* node);
void tv_node_set_expanded(tv_Node* node, tv_bool expanded);

/* TOutlineViewer functions */
void tv_outlineviewer_draw(tv_OutlineViewer* viewer);
void tv_outlineviewer_focused(tv_OutlineViewer* viewer, int i);
tv_Node* tv_outlineviewer_get_node(tv_OutlineViewer* viewer, int i);
void tv_outlineviewer_handle_event(tv_OutlineViewer* viewer, tv_Event* event);
tv_bool tv_outlineviewer_is_selected(tv_OutlineViewer* viewer, int i);
void tv_outlineviewer_selected(tv_OutlineViewer* viewer, int i);
void tv_outlineviewer_set_state(tv_OutlineViewer* viewer, tv_ushort state, tv_bool enable);
void tv_outlineviewer_update(tv_OutlineViewer* viewer);
void tv_outlineviewer_expand_all(tv_OutlineViewer* viewer, tv_Node* node);
tv_Node* tv_outlineviewer_first_that(tv_OutlineViewer* viewer, tv_OutlineVisitor test, void* arg);
tv_Node* tv_outlineviewer_first_that_no_arg(tv_OutlineViewer* viewer, tv_OutlineVisitorNoArg test);
tv_Node* tv_outlineviewer_for_each(tv_OutlineViewer* viewer, tv_OutlineVisitor action, void* arg);
tv_Node* tv_outlineviewer_for_each_no_arg(tv_OutlineViewer* viewer, tv_OutlineVisitorNoArg action);
char* tv_outlineviewer_get_graph(tv_OutlineViewer* viewer, int level, long lines, tv_ushort flags);
char* tv_outlineviewer_create_graph(tv_OutlineViewer* viewer, int level, long lines, tv_ushort flags,
                                     int lev_width, int end_width, const char* chars);
tv_Palette* tv_outlineviewer_get_palette(tv_OutlineViewer* viewer);
int tv_outlineviewer_get_foc(tv_OutlineViewer* viewer);

/* TOutline functions */
tv_Outline* tv_outline_create(tv_Rect bounds, tv_ScrollBar* h_scrollbar, tv_ScrollBar* v_scrollbar, tv_Node* root);
void tv_outline_destroy(tv_Outline* outline);
void tv_outline_adjust(tv_Outline* outline, tv_Node* node, tv_bool expand);
tv_Node* tv_outline_get_root(tv_Outline* outline);
int tv_outline_get_num_children(tv_Outline* outline, tv_Node* node);
tv_Node* tv_outline_get_next(tv_Outline* outline, tv_Node* node);
tv_Node* tv_outline_get_child(tv_Outline* outline, tv_Node* node, int i);
const char* tv_outline_get_text(tv_Outline* outline, tv_Node* node);
tv_bool tv_outline_is_expanded(tv_Outline* outline, tv_Node* node);
tv_bool tv_outline_has_children(tv_Outline* outline, tv_Node* node);

#ifdef __cplusplus
}
#endif

#endif //TVISION_COUTLINE_H
