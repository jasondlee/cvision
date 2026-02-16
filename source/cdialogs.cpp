//
// Created by Bob on 2/1/26.
//

#include "cvision/cdialogs.h"
#include "cvision/ctypes.h"
#include <tvision/tv.h>
#include <cstdarg>

extern "C" {

/* TDialog functions */

tv_Dialog* tv_dialog_create(tv_Rect bounds, const char* title) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Dialog*>(new TDialog(rect, title));
}

void tv_dialog_destroy(tv_Dialog* dialog) {
    if (dialog) {
        TObject::destroy(reinterpret_cast<TDialog*>(dialog));
    }
}

/* TInputLine functions */

tv_InputLine* tv_inputline_create(tv_Rect bounds, int limit, tv_Validator* validator, tv_ushort limit_mode) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_InputLine*>(
        new TInputLine(rect, limit, reinterpret_cast<TValidator*>(validator), limit_mode)
    );
}

void tv_inputline_destroy(tv_InputLine* inputline) {
    if (inputline) {
        TObject::destroy(reinterpret_cast<TInputLine*>(inputline));
    }
}

void tv_inputline_get_data(tv_InputLine* inputline, void* rec) {
    if (inputline) {
        reinterpret_cast<TInputLine*>(inputline)->getData(rec);
    }
}

void tv_inputline_set_data(tv_InputLine* inputline, void* rec) {
    if (inputline) {
        reinterpret_cast<TInputLine*>(inputline)->setData(rec);
    }
}

void tv_inputline_select_all(tv_InputLine* inputline, tv_bool enable, tv_bool scroll) {
    if (inputline) {
        reinterpret_cast<TInputLine*>(inputline)->selectAll(enable, scroll);
    }
}

const char* tv_inputline_get_text(tv_InputLine* inputline) {
    if (inputline) {
        return reinterpret_cast<TInputLine*>(inputline)->data;
    }
    return nullptr;
}

void tv_inputline_set_validator(tv_InputLine* inputline, tv_Validator* validator) {
    if (inputline) {
        reinterpret_cast<TInputLine*>(inputline)->setValidator(reinterpret_cast<TValidator*>(validator));
    }
}

/* TButton functions */

tv_Button* tv_button_create(tv_Rect bounds, const char* title, tv_ushort command, tv_ushort flags) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Button*>(new TButton(rect, title, command, flags));
}

void tv_button_destroy(tv_Button* button) {
    if (button) {
        TObject::destroy(reinterpret_cast<TButton*>(button));
    }
}

void tv_button_make_default(tv_Button* button, tv_bool enable) {
    if (button) {
        reinterpret_cast<TButton*>(button)->makeDefault(enable);
    }
}

void tv_button_press(tv_Button* button) {
    if (button) {
        reinterpret_cast<TButton*>(button)->press();
    }
}

/* TSItem functions */

tv_SItem* tv_sitem_create(const char* value, tv_SItem* next) {
    return reinterpret_cast<tv_SItem*>(
        new TSItem(value, reinterpret_cast<TSItem*>(next))
    );
}

void tv_sitem_destroy(tv_SItem* item) {
    if (item) {
        delete reinterpret_cast<TSItem*>(item);
    }
}

/* TCluster functions */

tv_Cluster* tv_cluster_create(tv_Rect bounds, tv_SItem* strings) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Cluster*>(
        new TCluster(rect, reinterpret_cast<TSItem*>(strings))
    );
}

void tv_cluster_destroy(tv_Cluster* cluster) {
    if (cluster) {
        TObject::destroy(reinterpret_cast<TCluster*>(cluster));
    }
}

void tv_cluster_get_data(tv_Cluster* cluster, void* rec) {
    if (cluster) {
        reinterpret_cast<TCluster*>(cluster)->getData(rec);
    }
}

void tv_cluster_set_data(tv_Cluster* cluster, void* rec) {
    if (cluster) {
        reinterpret_cast<TCluster*>(cluster)->setData(rec);
    }
}

tv_bool tv_cluster_mark(tv_Cluster* cluster, int item) {
    if (cluster) {
        return reinterpret_cast<TCluster*>(cluster)->mark(item);
    }
    return TV_FALSE;
}

void tv_cluster_press(tv_Cluster* cluster, int item) {
    if (cluster) {
        reinterpret_cast<TCluster*>(cluster)->press(item);
    }
}

tv_bool tv_cluster_button_state(tv_Cluster* cluster, int item) {
    if (cluster) {
        return reinterpret_cast<TCluster*>(cluster)->buttonState(item);
    }
    return TV_FALSE;
}

void tv_cluster_set_button_state(tv_Cluster* cluster, tv_uint mask, tv_bool enable) {
    if (cluster) {
        reinterpret_cast<TCluster*>(cluster)->setButtonState(mask, enable);
    }
}

/* TRadioButtons functions */

tv_RadioButtons* tv_radiobuttons_create(tv_Rect bounds, tv_SItem* strings) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_RadioButtons*>(
        new TRadioButtons(rect, reinterpret_cast<TSItem*>(strings))
    );
}

void tv_radiobuttons_destroy(tv_RadioButtons* radiobuttons) {
    if (radiobuttons) {
        TObject::destroy(reinterpret_cast<TRadioButtons*>(radiobuttons));
    }
}

void tv_radiobuttons_get_data(tv_RadioButtons* radiobuttons, void* rec) {
    if (radiobuttons) {
        reinterpret_cast<TRadioButtons*>(radiobuttons)->getData(rec);
    }
}

void tv_radiobuttons_set_data(tv_RadioButtons* radiobuttons, void* rec) {
    if (radiobuttons) {
        reinterpret_cast<TRadioButtons*>(radiobuttons)->setData(rec);
    }
}

/* TCheckBoxes functions */

tv_CheckBoxes* tv_checkboxes_create(tv_Rect bounds, tv_SItem* strings) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_CheckBoxes*>(
        new TCheckBoxes(rect, reinterpret_cast<TSItem*>(strings))
    );
}

void tv_checkboxes_destroy(tv_CheckBoxes* checkboxes) {
    if (checkboxes) {
        TObject::destroy(reinterpret_cast<TCheckBoxes*>(checkboxes));
    }
}

void tv_checkboxes_get_data(tv_CheckBoxes* checkboxes, void* rec) {
    if (checkboxes) {
        reinterpret_cast<TCheckBoxes*>(checkboxes)->getData(rec);
    }
}

void tv_checkboxes_set_data(tv_CheckBoxes* checkboxes, void* rec) {
    if (checkboxes) {
        reinterpret_cast<TCheckBoxes*>(checkboxes)->setData(rec);
    }
}

/* TMultiCheckBoxes functions */

tv_MultiCheckBoxes* tv_multicheckboxes_create(tv_Rect bounds, tv_SItem* strings, 
                                               tv_uchar sel_range, tv_ushort flags, 
                                               const char* states) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_MultiCheckBoxes*>(
        new TMultiCheckBoxes(rect, reinterpret_cast<TSItem*>(strings), sel_range, flags, states)
    );
}

void tv_multicheckboxes_destroy(tv_MultiCheckBoxes* multicheckboxes) {
    if (multicheckboxes) {
        TObject::destroy(reinterpret_cast<TMultiCheckBoxes*>(multicheckboxes));
    }
}

void tv_multicheckboxes_get_data(tv_MultiCheckBoxes* multicheckboxes, void* rec) {
    if (multicheckboxes) {
        reinterpret_cast<TMultiCheckBoxes*>(multicheckboxes)->getData(rec);
    }
}

void tv_multicheckboxes_set_data(tv_MultiCheckBoxes* multicheckboxes, void* rec) {
    if (multicheckboxes) {
        reinterpret_cast<TMultiCheckBoxes*>(multicheckboxes)->setData(rec);
    }
}

/* TListBox functions */

tv_ListBox* tv_listbox_create(tv_Rect bounds, tv_ushort num_cols, tv_ScrollBar* scrollbar) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_ListBox*>(
        new TListBox(rect, num_cols, reinterpret_cast<TScrollBar*>(scrollbar))
    );
}

void tv_listbox_destroy(tv_ListBox* listbox) {
    if (listbox) {
        TObject::destroy(reinterpret_cast<TListBox*>(listbox));
    }
}

void tv_listbox_new_list(tv_ListBox* listbox, tv_Collection* list) {
    if (listbox) {
        reinterpret_cast<TListBox*>(listbox)->newList(reinterpret_cast<TCollection*>(list));
    }
}

void tv_listbox_get_data(tv_ListBox* listbox, void* rec) {
    if (listbox) {
        reinterpret_cast<TListBox*>(listbox)->getData(rec);
    }
}

void tv_listbox_set_data(tv_ListBox* listbox, void* rec) {
    if (listbox) {
        reinterpret_cast<TListBox*>(listbox)->setData(rec);
    }
}

tv_Collection* tv_listbox_get_list(tv_ListBox* listbox) {
    if (listbox) {
        return reinterpret_cast<tv_Collection*>(reinterpret_cast<TListBox*>(listbox)->list());
    }
    return nullptr;
}

/* TStaticText functions */

tv_StaticText* tv_statictext_create(tv_Rect bounds, const char* text) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_StaticText*>(new TStaticText(rect, text));
}

void tv_statictext_destroy(tv_StaticText* statictext) {
    if (statictext) {
        TObject::destroy(reinterpret_cast<TStaticText*>(statictext));
    }
}

void tv_statictext_get_text(tv_StaticText* statictext, char* dest) {
    if (statictext) {
        reinterpret_cast<TStaticText*>(statictext)->getText(dest);
    }
}

/* TParamText functions */

tv_ParamText* tv_paramtext_create(tv_Rect bounds) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_ParamText*>(new TParamText(rect));
}

void tv_paramtext_destroy(tv_ParamText* paramtext) {
    if (paramtext) {
        TObject::destroy(reinterpret_cast<TParamText*>(paramtext));
    }
}

void tv_paramtext_set_text(tv_ParamText* paramtext, const char* fmt, ...) {
    if (paramtext) {
        va_list args;
        va_start(args, fmt);
        
        // Calculate required buffer size
        va_list args_copy;
        va_copy(args_copy, args);
        int size = vsnprintf(nullptr, 0, fmt, args_copy);
        va_end(args_copy);
        
        if (size > 0) {
            char* buffer = new char[size + 1];
            vsnprintf(buffer, size + 1, fmt, args);
            reinterpret_cast<TParamText*>(paramtext)->setText("%s", buffer);
            delete[] buffer;
        }
        
        va_end(args);
    }
}

void tv_paramtext_get_text(tv_ParamText* paramtext, char* dest) {
    if (paramtext) {
        reinterpret_cast<TParamText*>(paramtext)->getText(dest);
    }
}

int tv_paramtext_get_text_len(tv_ParamText* paramtext) {
    if (paramtext) {
        return reinterpret_cast<TParamText*>(paramtext)->getTextLen();
    }
    return 0;
}

/* TLabel functions */

tv_Label* tv_label_create(tv_Rect bounds, const char* text, tv_View* link) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Label*>(
        new TLabel(rect, text, reinterpret_cast<TView*>(link))
    );
}

void tv_label_destroy(tv_Label* label) {
    if (label) {
        TObject::destroy(reinterpret_cast<TLabel*>(label));
    }
}

/* THistory functions */

tv_History* tv_history_create(tv_Rect bounds, tv_InputLine* link, tv_ushort history_id) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_History*>(
        new THistory(rect, reinterpret_cast<TInputLine*>(link), history_id)
    );
}

void tv_history_destroy(tv_History* history) {
    if (history) {
        TObject::destroy(reinterpret_cast<THistory*>(history));
    }
}

void tv_history_record(tv_History* history, const char* s) {
    if (history) {
        reinterpret_cast<THistory*>(history)->recordHistory(s);
    }
}

/* THistoryViewer functions */

tv_HistoryViewer* tv_historyviewer_create(tv_Rect bounds, tv_ScrollBar* hscrollbar,
                                          tv_ScrollBar* vscrollbar, tv_ushort history_id) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_HistoryViewer*>(
        new THistoryViewer(rect, reinterpret_cast<TScrollBar*>(hscrollbar),
                          reinterpret_cast<TScrollBar*>(vscrollbar), history_id)
    );
}

void tv_historyviewer_destroy(tv_HistoryViewer* viewer) {
    if (viewer) {
        TObject::destroy(reinterpret_cast<THistoryViewer*>(viewer));
    }
}

int tv_historyviewer_history_width(tv_HistoryViewer* viewer) {
    if (viewer) {
        return reinterpret_cast<THistoryViewer*>(viewer)->historyWidth();
    }
    return 0;
}

/* THistoryWindow functions */

tv_HistoryWindow* tv_historywindow_create(tv_Rect bounds, tv_ushort history_id) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_HistoryWindow*>(new THistoryWindow(rect, history_id));
}

void tv_historywindow_destroy(tv_HistoryWindow* window) {
    if (window) {
        TObject::destroy(reinterpret_cast<THistoryWindow*>(window));
    }
}

void tv_historywindow_get_selection(tv_HistoryWindow* window, char* dest) {
    if (window) {
        reinterpret_cast<THistoryWindow*>(window)->getSelection(dest);
    }
}

} // extern "C"

// Made with Bob
