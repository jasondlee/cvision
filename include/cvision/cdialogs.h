//
// Created by Bob on 2/1/26.
//

#ifndef TVISION_CDIALOGS_H
#define TVISION_CDIALOGS_H

#include "ctypes.h"
#include "cobjects.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations for dialog types */

/* Button flags */
#define TV_BF_NORMAL     0x00
#define TV_BF_DEFAULT    0x01
#define TV_BF_LEFTJUST   0x02
#define TV_BF_BROADCAST  0x04
#define TV_BF_GRABFOCUS  0x08

/* Multi-checkbox flags */
#define TV_CF_ONEBIT     0x0101
#define TV_CF_TWOBITS    0x0203
#define TV_CF_FOURBITS   0x040F
#define TV_CF_EIGHTBITS  0x08FF

/* Input line limit modes */
#define TV_IL_MAXBYTES   0
#define TV_IL_MAXWIDTH   1
#define TV_IL_MAXCHARS   2

/* TDialog functions */
tv_Dialog* tv_dialog_create(tv_Rect bounds, const char* title);
void tv_dialog_destroy(tv_Dialog* dialog);

/* TInputLine functions */
tv_InputLine* tv_inputline_create(tv_Rect bounds, int limit, tv_Validator* validator, tv_ushort limit_mode);
void tv_inputline_destroy(tv_InputLine* inputline);
void tv_inputline_get_data(tv_InputLine* inputline, void* rec);
void tv_inputline_set_data(tv_InputLine* inputline, void* rec);
void tv_inputline_select_all(tv_InputLine* inputline, tv_bool enable, tv_bool scroll);
const char* tv_inputline_get_text(tv_InputLine* inputline);
void tv_inputline_set_validator(tv_InputLine* inputline, tv_Validator* validator);

/* TButton functions */
tv_Button* tv_button_create(tv_Rect bounds, const char* title, tv_ushort command, tv_ushort flags);
void tv_button_destroy(tv_Button* button);
void tv_button_make_default(tv_Button* button, tv_bool enable);
void tv_button_press(tv_Button* button);

/* TSItem functions (for cluster items) */
tv_SItem* tv_sitem_create(const char* value, tv_SItem* next);
void tv_sitem_destroy(tv_SItem* item);

/* TCluster functions */
tv_Cluster* tv_cluster_create(tv_Rect bounds, tv_SItem* strings);
void tv_cluster_destroy(tv_Cluster* cluster);
void tv_cluster_get_data(tv_Cluster* cluster, void* rec);
void tv_cluster_set_data(tv_Cluster* cluster, void* rec);
tv_bool tv_cluster_mark(tv_Cluster* cluster, int item);
void tv_cluster_press(tv_Cluster* cluster, int item);
tv_bool tv_cluster_button_state(tv_Cluster* cluster, int item);
void tv_cluster_set_button_state(tv_Cluster* cluster, tv_uint mask, tv_bool enable);

/* TRadioButtons functions */
tv_RadioButtons* tv_radiobuttons_create(tv_Rect bounds, tv_SItem* strings);
void tv_radiobuttons_destroy(tv_RadioButtons* radiobuttons);
void tv_radiobuttons_get_data(tv_RadioButtons* radiobuttons, void* rec);
void tv_radiobuttons_set_data(tv_RadioButtons* radiobuttons, void* rec);

/* TCheckBoxes functions */
tv_CheckBoxes* tv_checkboxes_create(tv_Rect bounds, tv_SItem* strings);
void tv_checkboxes_destroy(tv_CheckBoxes* checkboxes);
void tv_checkboxes_get_data(tv_CheckBoxes* checkboxes, void* rec);
void tv_checkboxes_set_data(tv_CheckBoxes* checkboxes, void* rec);

/* TMultiCheckBoxes functions */
tv_MultiCheckBoxes* tv_multicheckboxes_create(tv_Rect bounds, tv_SItem* strings, 
                                               tv_uchar sel_range, tv_ushort flags, 
                                               const char* states);
void tv_multicheckboxes_destroy(tv_MultiCheckBoxes* multicheckboxes);
void tv_multicheckboxes_get_data(tv_MultiCheckBoxes* multicheckboxes, void* rec);
void tv_multicheckboxes_set_data(tv_MultiCheckBoxes* multicheckboxes, void* rec);

/* TListBox functions */
tv_ListBox* tv_listbox_create(tv_Rect bounds, tv_ushort num_cols, tv_ScrollBar* scrollbar);
void tv_listbox_destroy(tv_ListBox* listbox);
void tv_listbox_new_list(tv_ListBox* listbox, tv_Collection* list);
void tv_listbox_get_data(tv_ListBox* listbox, void* rec);
void tv_listbox_set_data(tv_ListBox* listbox, void* rec);
tv_Collection* tv_listbox_get_list(tv_ListBox* listbox);

/* TStaticText functions */
tv_StaticText* tv_statictext_create(tv_Rect bounds, const char* text);
void tv_statictext_destroy(tv_StaticText* statictext);
void tv_statictext_get_text(tv_StaticText* statictext, char* dest);

/* TParamText functions */
tv_ParamText* tv_paramtext_create(tv_Rect bounds);
void tv_paramtext_destroy(tv_ParamText* paramtext);
void tv_paramtext_set_text(tv_ParamText* paramtext, const char* fmt, ...);
void tv_paramtext_get_text(tv_ParamText* paramtext, char* dest);
int tv_paramtext_get_text_len(tv_ParamText* paramtext);

/* TLabel functions */
tv_Label* tv_label_create(tv_Rect bounds, const char* text, tv_View* link);
void tv_label_destroy(tv_Label* label);

/* THistory functions */
tv_History* tv_history_create(tv_Rect bounds, tv_InputLine* link, tv_ushort history_id);
void tv_history_destroy(tv_History* history);
void tv_history_record(tv_History* history, const char* s);

/* THistoryViewer functions */
tv_HistoryViewer* tv_historyviewer_create(tv_Rect bounds, tv_ScrollBar* hscrollbar,
                                          tv_ScrollBar* vscrollbar, tv_ushort history_id);
void tv_historyviewer_destroy(tv_HistoryViewer* viewer);
int tv_historyviewer_history_width(tv_HistoryViewer* viewer);

/* THistoryWindow functions */
tv_HistoryWindow* tv_historywindow_create(tv_Rect bounds, tv_ushort history_id);
void tv_historywindow_destroy(tv_HistoryWindow* window);
void tv_historywindow_get_selection(tv_HistoryWindow* window, char* dest);

#ifdef __cplusplus
}
#endif

#endif //TVISION_CDIALOGS_H

// Made with Bob
