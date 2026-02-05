//
// Created by Bob on 2/1/26.
//
// C wrappers for TOutline and TOutlineViewer classes
//

#include "cvision/cobjects.h"
#include "cvision/csystem.h"
#include "cvision/coutline.h"
#include "cvision/cvision.h"
#include <tvision/tv.h>

extern "C" {

extern const int tv_ovExpanded = ovExpanded;
extern const int tv_ovChildren = ovChildren;
extern const int tv_ovLast = ovLast;
extern const int tv_cmOutlineItemSelected = cmOutlineItemSelected;

/* TNode functions */

tv_Node* tv_node_create(const char* text) {
    return reinterpret_cast<tv_Node*>(new TNode(text));
}

tv_Node* tv_node_create_full(const char* text, tv_Node* children, tv_Node* next, tv_bool initial_state) {
    return reinterpret_cast<tv_Node*>(
        new TNode(text, 
                  reinterpret_cast<TNode*>(children),
                  reinterpret_cast<TNode*>(next),
                  initial_state)
    );
}

void tv_node_destroy(tv_Node* node) {
    if (node) {
        delete reinterpret_cast<TNode*>(node);
    }
}

/* Node accessors */

tv_Node* tv_node_get_next(tv_Node* node) {
    if (!node) return nullptr;
    return reinterpret_cast<tv_Node*>(reinterpret_cast<TNode*>(node)->next);
}

void tv_node_set_next(tv_Node* node, tv_Node* next) {
    if (node) {
        reinterpret_cast<TNode*>(node)->next = reinterpret_cast<TNode*>(next);
    }
}

const char* tv_node_get_text(tv_Node* node) {
    if (!node) return nullptr;
    return reinterpret_cast<TNode*>(node)->text;
}

tv_Node* tv_node_get_child_list(tv_Node* node) {
    if (!node) return nullptr;
    return reinterpret_cast<tv_Node*>(reinterpret_cast<TNode*>(node)->childList);
}

void tv_node_set_child_list(tv_Node* node, tv_Node* child_list) {
    if (node) {
        reinterpret_cast<TNode*>(node)->childList = reinterpret_cast<TNode*>(child_list);
    }
}

tv_bool tv_node_is_expanded(tv_Node* node) {
    if (!node) return 0;
    return reinterpret_cast<TNode*>(node)->expanded;
}

void tv_node_set_expanded(tv_Node* node, tv_bool expanded) {
    if (node) {
        reinterpret_cast<TNode*>(node)->expanded = expanded;
    }
}

/* TOutlineViewer functions */

void tv_outlineviewer_draw(tv_OutlineViewer* viewer) {
    if (viewer) {
        reinterpret_cast<TOutlineViewer*>(viewer)->draw();
    }
}

void tv_outlineviewer_focused(tv_OutlineViewer* viewer, int i) {
    if (viewer) {
        reinterpret_cast<TOutlineViewer*>(viewer)->focused(i);
    }
}

tv_Node* tv_outlineviewer_get_node(tv_OutlineViewer* viewer, int i) {
    if (!viewer) return nullptr;
    return reinterpret_cast<tv_Node*>(
        reinterpret_cast<TOutlineViewer*>(viewer)->getNode(i)
    );
}

void tv_outlineviewer_handle_event(tv_OutlineViewer* viewer, tv_Event* event) {
    if (viewer && event) {
        TEvent& tEvent = *reinterpret_cast<TEvent*>(event);
        reinterpret_cast<TOutlineViewer*>(viewer)->handleEvent(tEvent);
    }
}

tv_bool tv_outlineviewer_is_selected(tv_OutlineViewer* viewer, int i) {
    if (!viewer) return 0;
    return reinterpret_cast<TOutlineViewer*>(viewer)->isSelected(i);
}

void tv_outlineviewer_selected(tv_OutlineViewer* viewer, int i) {
    if (viewer) {
        reinterpret_cast<TOutlineViewer*>(viewer)->selected(i);
    }
}

void tv_outlineviewer_set_state(tv_OutlineViewer* viewer, tv_ushort state, tv_bool enable) {
    if (viewer) {
        reinterpret_cast<TOutlineViewer*>(viewer)->setState(state, enable);
    }
}

void tv_outlineviewer_update(tv_OutlineViewer* viewer) {
    if (viewer) {
        reinterpret_cast<TOutlineViewer*>(viewer)->update();
    }
}

void tv_outlineviewer_expand_all(tv_OutlineViewer* viewer, tv_Node* node) {
    if (viewer) {
        reinterpret_cast<TOutlineViewer*>(viewer)->expandAll(
            reinterpret_cast<TNode*>(node)
        );
    }
}

tv_Node* tv_outlineviewer_first_that(tv_OutlineViewer* viewer, tv_OutlineVisitor test, void* arg) {
    if (!viewer) return nullptr;
    return reinterpret_cast<tv_Node*>(
        reinterpret_cast<TOutlineViewer*>(viewer)->firstThat(
            reinterpret_cast<TOutlineVisitor>(test),
            arg
        )
    );
}

tv_Node* tv_outlineviewer_first_that_no_arg(tv_OutlineViewer* viewer, tv_OutlineVisitorNoArg test) {
    if (!viewer) return nullptr;
    return reinterpret_cast<tv_Node*>(
        reinterpret_cast<TOutlineViewer*>(viewer)->firstThat(
            reinterpret_cast<TOutlineVisitorNoArg>(test)
        )
    );
}

tv_Node* tv_outlineviewer_for_each(tv_OutlineViewer* viewer, tv_OutlineVisitor action, void* arg) {
    if (!viewer) return nullptr;
    return reinterpret_cast<tv_Node*>(
        reinterpret_cast<TOutlineViewer*>(viewer)->forEach(
            reinterpret_cast<TOutlineVisitor>(action),
            arg
        )
    );
}

tv_Node* tv_outlineviewer_for_each_no_arg(tv_OutlineViewer* viewer, tv_OutlineVisitorNoArg action) {
    if (!viewer) return nullptr;
    return reinterpret_cast<tv_Node*>(
        reinterpret_cast<TOutlineViewer*>(viewer)->forEach(
            reinterpret_cast<TOutlineVisitorNoArg>(action)
        )
    );
}

char* tv_outlineviewer_get_graph(tv_OutlineViewer* viewer, int level, long lines, tv_ushort flags) {
    if (!viewer) return nullptr;
    return reinterpret_cast<TOutlineViewer*>(viewer)->getGraph(level, lines, flags);
}

char* tv_outlineviewer_create_graph(tv_OutlineViewer* viewer, int level, long lines, tv_ushort flags,
                                     int lev_width, int end_width, const char* chars) {
    if (!viewer) return nullptr;
    return reinterpret_cast<TOutlineViewer*>(viewer)->createGraph(
        level, lines, flags, lev_width, end_width, chars
    );
}

tv_Palette* tv_outlineviewer_get_palette(tv_OutlineViewer* viewer) {
    if (!viewer) return nullptr;
    return reinterpret_cast<tv_Palette*>(
        &(reinterpret_cast<TOutlineViewer*>(viewer)->getPalette())
    );
}

int tv_outlineviewer_get_foc(tv_OutlineViewer* viewer) {
    if (!viewer) return 0;
    return reinterpret_cast<TOutlineViewer*>(viewer)->foc;
}

/* TOutline functions */

tv_Outline* tv_outline_create(tv_Rect bounds, tv_ScrollBar* h_scrollbar, tv_ScrollBar* v_scrollbar, tv_Node* root) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Outline*>(
        new TOutline(rect,
                     reinterpret_cast<TScrollBar*>(h_scrollbar),
                     reinterpret_cast<TScrollBar*>(v_scrollbar),
                     reinterpret_cast<TNode*>(root))
    );
}

void tv_outline_destroy(tv_Outline* outline) {
    if (outline) {
        TObject::destroy(reinterpret_cast<TOutline*>(outline));
    }
}

void tv_outline_adjust(tv_Outline* outline, tv_Node* node, tv_bool expand) {
    if (outline) {
        reinterpret_cast<TOutline*>(outline)->adjust(
            reinterpret_cast<TNode*>(node),
            expand
        );
    }
}

tv_Node* tv_outline_get_root(tv_Outline* outline) {
    if (!outline) return nullptr;
    return reinterpret_cast<tv_Node*>(
        reinterpret_cast<TOutline*>(outline)->getRoot()
    );
}

int tv_outline_get_num_children(tv_Outline* outline, tv_Node* node) {
    if (!outline) return 0;
    return reinterpret_cast<TOutline*>(outline)->getNumChildren(
        reinterpret_cast<TNode*>(node)
    );
}

tv_Node* tv_outline_get_next(tv_Outline* outline, tv_Node* node) {
    if (!outline) return nullptr;
    return reinterpret_cast<tv_Node*>(
        reinterpret_cast<TOutline*>(outline)->getNext(
            reinterpret_cast<TNode*>(node)
        )
    );
}

tv_Node* tv_outline_get_child(tv_Outline* outline, tv_Node* node, int i) {
    if (!outline) return nullptr;
    return reinterpret_cast<tv_Node*>(
        reinterpret_cast<TOutline*>(outline)->getChild(
            reinterpret_cast<TNode*>(node),
            i
        )
    );
}

const char* tv_outline_get_text(tv_Outline* outline, tv_Node* node) {
    if (!outline) return nullptr;
    return reinterpret_cast<TOutline*>(outline)->getText(
        reinterpret_cast<TNode*>(node)
    );
}

tv_bool tv_outline_is_expanded(tv_Outline* outline, tv_Node* node) {
    if (!outline) return 0;
    return reinterpret_cast<TOutline*>(outline)->isExpanded(
        reinterpret_cast<TNode*>(node)
    );
}

tv_bool tv_outline_has_children(tv_Outline* outline, tv_Node* node) {
    if (!outline) return 0;
    return reinterpret_cast<TOutline*>(outline)->hasChildren(
        reinterpret_cast<TNode*>(node)
    );
}

} // extern "C"
