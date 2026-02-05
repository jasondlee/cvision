//
// Created by Bob on 2/1/26.
//

#ifndef TVISION_CEDITORS_H
#define TVISION_CEDITORS_H

#include "ctypes.h"
#include "cobjects.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations for editor types */
typedef struct tv_Indicator tv_Indicator;
typedef struct tv_Editor tv_Editor;
typedef struct tv_Memo tv_Memo;
typedef struct tv_FileEditor tv_FileEditor;
typedef struct tv_EditWindow tv_EditWindow;

//// Editor update flags
//
// Flags used to control editor update behavior

extern const int tv_ufUpdate;
extern const int tv_ufLine;
extern const int tv_ufView;

//// Selection mode flags
//
// Flags used to control text selection behavior

extern const int tv_smExtend;
extern const int tv_smDouble;
extern const int tv_smTriple;

//// Search result constants
//
// Constants for search operation results

extern const tv_uint tv_sfSearchFailed;

//// Editor command codes
//
// Command codes for find/replace operations

extern const int tv_cmFind;
extern const int tv_cmReplace;
extern const int tv_cmSearchAgain;

//// Editor navigation and editing command codes
//
// Command codes for cursor movement and text editing operations

extern const int tv_cmCharLeft;
extern const int tv_cmCharRight;
extern const int tv_cmWordLeft;
extern const int tv_cmWordRight;
extern const int tv_cmLineStart;
extern const int tv_cmLineEnd;
extern const int tv_cmLineUp;
extern const int tv_cmLineDown;
extern const int tv_cmPageUp;
extern const int tv_cmPageDown;
extern const int tv_cmTextStart;
extern const int tv_cmTextEnd;
extern const int tv_cmNewLine;
extern const int tv_cmBackSpace;
extern const int tv_cmDelChar;
extern const int tv_cmDelWord;
extern const int tv_cmDelStart;
extern const int tv_cmDelEnd;
extern const int tv_cmDelLine;
extern const int tv_cmInsMode;
extern const int tv_cmStartSelect;
extern const int tv_cmHideSelect;
extern const int tv_cmIndentMode;
extern const int tv_cmUpdateTitle;
extern const int tv_cmSelectAll;
extern const int tv_cmDelWordLeft;
extern const int tv_cmEncoding;

//// Editor dialog constants
//
// Constants for editor dialog types

extern const int tv_edOutOfMemory;
extern const int tv_edReadError;
extern const int tv_edWriteError;
extern const int tv_edCreateError;
extern const int tv_edSaveModify;
extern const int tv_edSaveUntitled;
extern const int tv_edSaveAs;
extern const int tv_edFind;
extern const int tv_edSearchFailed;
extern const int tv_edReplace;
extern const int tv_edReplacePrompt;

//// Editor flag constants
//
// Flags for editor behavior and search/replace options

extern const int tv_efCaseSensitive;
extern const int tv_efWholeWordsOnly;
extern const int tv_efPromptOnReplace;
extern const int tv_efReplaceAll;
extern const int tv_efDoReplace;
extern const int tv_efBackupFiles;

//// Editor limits
//
// Maximum line length constant

extern const int tv_maxLineLength;


/* Line ending types */
typedef enum {
    eolCrLf, eolLf, eolCr
} tv_LineEndingType;

/* Encoding types */
typedef enum {
    encDefault, encSingleByte
} tv_Encoding;

/* TMemoData structure */
typedef struct tv_MemoData {
    tv_ushort length;
    char buffer[1];
} tv_MemoData;

/* TIndicator functions */
tv_Indicator* tv_indicator_create(tv_Rect bounds);
void tv_indicator_destroy(tv_Indicator* indicator);
void tv_indicator_set_value(tv_Indicator* indicator, tv_Point location, tv_bool modified);

/* TEditor functions */
tv_Editor* tv_editor_create(tv_Rect bounds, tv_ScrollBar* hscrollbar, 
                            tv_ScrollBar* vscrollbar, tv_Indicator* indicator, 
                            tv_uint buf_size);
void tv_editor_destroy(tv_Editor* editor);
tv_bool tv_editor_set_buf_size(tv_Editor* editor, tv_uint new_size);
void tv_editor_scroll_to(tv_Editor* editor, int x, int y);
tv_bool tv_editor_search(tv_Editor* editor, const char* text, tv_ushort flags);
tv_bool tv_editor_insert_text(tv_Editor* editor, const void* text, tv_uint length, tv_bool select);
void tv_editor_delete_select(tv_Editor* editor);
void tv_editor_set_select(tv_Editor* editor, tv_uint start, tv_uint end, tv_bool cursor_at_start);
tv_bool tv_editor_has_selection(tv_Editor* editor);
void tv_editor_undo(tv_Editor* editor);
tv_bool tv_editor_clip_copy(tv_Editor* editor);
void tv_editor_clip_cut(tv_Editor* editor);
void tv_editor_clip_paste(tv_Editor* editor);
void tv_editor_find(tv_Editor* editor);
void tv_editor_replace(tv_Editor* editor);
tv_bool tv_editor_is_clipboard(tv_Editor* editor);
tv_bool tv_editor_cursor_visible(tv_Editor* editor);
void tv_editor_track_cursor(tv_Editor* editor, tv_bool center);
void tv_editor_start_select(tv_Editor* editor);
void tv_editor_hide_select(tv_Editor* editor);
void tv_editor_toggle_ins_mode(tv_Editor* editor);
void tv_editor_toggle_encoding(tv_Editor* editor);

/* TEditor accessors */
tv_uint tv_editor_get_buf_len(tv_Editor* editor);
tv_uint tv_editor_get_sel_start(tv_Editor* editor);
tv_uint tv_editor_get_sel_end(tv_Editor* editor);
tv_uint tv_editor_get_cur_ptr(tv_Editor* editor);
tv_Point tv_editor_get_cur_pos(tv_Editor* editor);
tv_bool tv_editor_get_modified(tv_Editor* editor);
void tv_editor_set_modified(tv_Editor* editor, tv_bool modified);
tv_bool tv_editor_get_overwrite(tv_Editor* editor);
void tv_editor_set_overwrite(tv_Editor* editor, tv_bool overwrite);
tv_bool tv_editor_get_auto_indent(tv_Editor* editor);
void tv_editor_set_auto_indent(tv_Editor* editor, tv_bool auto_indent);
tv_LineEndingType tv_editor_get_line_ending_type(tv_Editor* editor);
void tv_editor_set_line_ending_type(tv_Editor* editor, tv_LineEndingType type);
tv_Encoding tv_editor_get_encoding(tv_Editor* editor);
void tv_editor_set_encoding(tv_Editor* editor, tv_Encoding encoding);

/* TMemo functions */
tv_Memo* tv_memo_create(tv_Rect bounds, tv_ScrollBar* hscrollbar,
                        tv_ScrollBar* vscrollbar, tv_Indicator* indicator,
                        tv_ushort buf_size);
void tv_memo_destroy(tv_Memo* memo);
void tv_memo_get_data(tv_Memo* memo, void* rec);
void tv_memo_set_data(tv_Memo* memo, void* rec);
tv_ushort tv_memo_data_size(tv_Memo* memo);

/* TFileEditor functions */
tv_FileEditor* tv_fileeditor_create(tv_Rect bounds, tv_ScrollBar* hscrollbar,
                                    tv_ScrollBar* vscrollbar, tv_Indicator* indicator,
                                    const char* filename);
void tv_fileeditor_destroy(tv_FileEditor* fileeditor);
tv_bool tv_fileeditor_load_file(tv_FileEditor* fileeditor);
tv_bool tv_fileeditor_save(tv_FileEditor* fileeditor);
tv_bool tv_fileeditor_save_as(tv_FileEditor* fileeditor);
tv_bool tv_fileeditor_save_file(tv_FileEditor* fileeditor);
const char* tv_fileeditor_get_filename(tv_FileEditor* fileeditor);
void tv_fileeditor_set_filename(tv_FileEditor* fileeditor, const char* filename);

/* TEditWindow functions */
tv_EditWindow* tv_editwindow_create(tv_Rect bounds, const char* filename, int number);
void tv_editwindow_destroy(tv_EditWindow* editwindow);
tv_FileEditor* tv_editwindow_get_editor(tv_EditWindow* editwindow);
const char* tv_editwindow_get_title(tv_EditWindow* editwindow, short max_size);

#ifdef __cplusplus
}
#endif

#endif //TVISION_CEDITORS_H

// Made with Bob
