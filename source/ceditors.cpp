//
// Created by Bob on 2/1/26.
//

#include "cvision/ceditors.h"
#include "cvision/ctypes.h"
#include <tvision/tv.h>

extern "C" {
    
//// Editor update flags

const int tv_ufUpdate = ufUpdate;
const int tv_ufLine = ufLine;
const int tv_ufView = ufView;

//// Selection mode flags

const int tv_smExtend = smExtend;
const int tv_smDouble = smDouble;
const int tv_smTriple = smTriple;

//// Search result constants

const tv_uint tv_sfSearchFailed = sfSearchFailed;

//// Editor command codes - find/replace operations

const int tv_cmFind = cmFind;
const int tv_cmReplace = cmReplace;
const int tv_cmSearchAgain = cmSearchAgain;

//// Editor navigation and editing command codes

const int tv_cmCharLeft = cmCharLeft;
const int tv_cmCharRight = cmCharRight;
const int tv_cmWordLeft = cmWordLeft;
const int tv_cmWordRight = cmWordRight;
const int tv_cmLineStart = cmLineStart;
const int tv_cmLineEnd = cmLineEnd;
const int tv_cmLineUp = cmLineUp;
const int tv_cmLineDown = cmLineDown;
const int tv_cmPageUp = cmPageUp;
const int tv_cmPageDown = cmPageDown;
const int tv_cmTextStart = cmTextStart;
const int tv_cmTextEnd = cmTextEnd;
const int tv_cmNewLine = cmNewLine;
const int tv_cmBackSpace = cmBackSpace;
const int tv_cmDelChar = cmDelChar;
const int tv_cmDelWord = cmDelWord;
const int tv_cmDelStart = cmDelStart;
const int tv_cmDelEnd = cmDelEnd;
const int tv_cmDelLine = cmDelLine;
const int tv_cmInsMode = cmInsMode;
const int tv_cmStartSelect = cmStartSelect;
const int tv_cmHideSelect = cmHideSelect;
const int tv_cmIndentMode = cmIndentMode;
const int tv_cmUpdateTitle = cmUpdateTitle;
const int tv_cmSelectAll = cmSelectAll;
const int tv_cmDelWordLeft = cmDelWordLeft;
const int tv_cmEncoding = cmEncoding;

//// Editor dialog constants

const int tv_edOutOfMemory = edOutOfMemory;
const int tv_edReadError = edReadError;
const int tv_edWriteError = edWriteError;
const int tv_edCreateError = edCreateError;
const int tv_edSaveModify = edSaveModify;
const int tv_edSaveUntitled = edSaveUntitled;
const int tv_edSaveAs = edSaveAs;
const int tv_edFind = edFind;
const int tv_edSearchFailed = edSearchFailed;
const int tv_edReplace = edReplace;
const int tv_edReplacePrompt = edReplacePrompt;

//// Editor flag constants

const int tv_efCaseSensitive = efCaseSensitive;
const int tv_efWholeWordsOnly = efWholeWordsOnly;
const int tv_efPromptOnReplace = efPromptOnReplace;
const int tv_efReplaceAll = efReplaceAll;
const int tv_efDoReplace = efDoReplace;
const int tv_efBackupFiles = efBackupFiles;

//// Editor limits

const int tv_maxLineLength = maxLineLength;


/* TIndicator functions */

tv_Indicator* tv_indicator_create(tv_Rect bounds) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Indicator*>(new TIndicator(rect));
}

void tv_indicator_destroy(tv_Indicator* indicator) {
    if (indicator) {
        TObject::destroy(reinterpret_cast<TIndicator*>(indicator));
    }
}

void tv_indicator_set_value(tv_Indicator* indicator, tv_Point location, tv_bool modified) {
    if (indicator) {
        TPoint loc { location.x, location.y };
        reinterpret_cast<TIndicator*>(indicator)->setValue(loc, modified);
    }
}

/* TEditor functions */

tv_Editor* tv_editor_create(tv_Rect bounds, tv_ScrollBar* hscrollbar, 
                            tv_ScrollBar* vscrollbar, tv_Indicator* indicator, 
                            tv_uint buf_size) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Editor*>(
        new TEditor(rect, 
                   reinterpret_cast<TScrollBar*>(hscrollbar),
                   reinterpret_cast<TScrollBar*>(vscrollbar),
                   reinterpret_cast<TIndicator*>(indicator),
                   buf_size)
    );
}

void tv_editor_destroy(tv_Editor* editor) {
    if (editor) {
        TObject::destroy(reinterpret_cast<TEditor*>(editor));
    }
}

tv_bool tv_editor_set_buf_size(tv_Editor* editor, tv_uint new_size) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->setBufSize(new_size);
    }
    return TV_FALSE;
}

void tv_editor_scroll_to(tv_Editor* editor, int x, int y) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->scrollTo(x, y);
    }
}

tv_bool tv_editor_search(tv_Editor* editor, const char* text, tv_ushort flags) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->search(text, flags);
    }
    return TV_FALSE;
}

tv_bool tv_editor_insert_text(tv_Editor* editor, const void* text, tv_uint length, tv_bool select) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->insertText(text, length, select);
    }
    return TV_FALSE;
}

void tv_editor_delete_select(tv_Editor* editor) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->deleteSelect();
    }
}

void tv_editor_set_select(tv_Editor* editor, tv_uint start, tv_uint end, tv_bool cursor_at_start) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->setSelect(start, end, cursor_at_start);
    }
}

tv_bool tv_editor_has_selection(tv_Editor* editor) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->hasSelection();
    }
    return TV_FALSE;
}

void tv_editor_undo(tv_Editor* editor) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->undo();
    }
}

tv_bool tv_editor_clip_copy(tv_Editor* editor) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->clipCopy();
    }
    return TV_FALSE;
}

void tv_editor_clip_cut(tv_Editor* editor) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->clipCut();
    }
}

void tv_editor_clip_paste(tv_Editor* editor) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->clipPaste();
    }
}

void tv_editor_find(tv_Editor* editor) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->find();
    }
}

void tv_editor_replace(tv_Editor* editor) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->replace();
    }
}

tv_bool tv_editor_is_clipboard(tv_Editor* editor) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->isClipboard();
    }
    return TV_FALSE;
}

tv_bool tv_editor_cursor_visible(tv_Editor* editor) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->cursorVisible();
    }
    return TV_FALSE;
}

void tv_editor_track_cursor(tv_Editor* editor, tv_bool center) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->trackCursor(center);
    }
}

void tv_editor_start_select(tv_Editor* editor) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->startSelect();
    }
}

void tv_editor_hide_select(tv_Editor* editor) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->hideSelect();
    }
}

void tv_editor_toggle_ins_mode(tv_Editor* editor) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->toggleInsMode();
    }
}

void tv_editor_toggle_encoding(tv_Editor* editor) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->toggleEncoding();
    }
}

/* TEditor accessors */

tv_uint tv_editor_get_buf_len(tv_Editor* editor) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->bufLen;
    }
    return 0;
}

tv_uint tv_editor_get_sel_start(tv_Editor* editor) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->selStart;
    }
    return 0;
}

tv_uint tv_editor_get_sel_end(tv_Editor* editor) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->selEnd;
    }
    return 0;
}

tv_uint tv_editor_get_cur_ptr(tv_Editor* editor) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->curPtr;
    }
    return 0;
}

tv_Point tv_editor_get_cur_pos(tv_Editor* editor) {
    tv_Point result = {0, 0};
    if (editor) {
        TPoint pos = reinterpret_cast<TEditor*>(editor)->curPos;
        result.x = pos.x;
        result.y = pos.y;
    }
    return result;
}

tv_bool tv_editor_get_modified(tv_Editor* editor) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->modified;
    }
    return TV_FALSE;
}

void tv_editor_set_modified(tv_Editor* editor, tv_bool modified) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->modified = modified;
    }
}

tv_bool tv_editor_get_overwrite(tv_Editor* editor) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->overwrite;
    }
    return TV_FALSE;
}

void tv_editor_set_overwrite(tv_Editor* editor, tv_bool overwrite) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->overwrite = overwrite;
    }
}

tv_bool tv_editor_get_auto_indent(tv_Editor* editor) {
    if (editor) {
        return reinterpret_cast<TEditor*>(editor)->autoIndent;
    }
    return TV_FALSE;
}

void tv_editor_set_auto_indent(tv_Editor* editor, tv_bool auto_indent) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->autoIndent = auto_indent;
    }
}

tv_LineEndingType tv_editor_get_line_ending_type(tv_Editor* editor) {
    if (editor) {
        return static_cast<tv_LineEndingType>(reinterpret_cast<TEditor*>(editor)->lineEndingType);
    }
    return eolCrLf;
}

void tv_editor_set_line_ending_type(tv_Editor* editor, tv_LineEndingType type) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->lineEndingType = static_cast<TEditor::LineEndingType>(type);
    }
}

tv_Encoding tv_editor_get_encoding(tv_Editor* editor) {
    if (editor) {
        return static_cast<tv_Encoding>(reinterpret_cast<TEditor*>(editor)->encoding);
    }
    return encDefault;
}

void tv_editor_set_encoding(tv_Editor* editor, tv_Encoding encoding) {
    if (editor) {
        reinterpret_cast<TEditor*>(editor)->encoding = static_cast<TEditor::Encoding>(encoding);
    }
}

/* TMemo functions */

tv_Memo* tv_memo_create(tv_Rect bounds, tv_ScrollBar* hscrollbar,
                        tv_ScrollBar* vscrollbar, tv_Indicator* indicator,
                        tv_ushort buf_size) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_Memo*>(
        new TMemo(rect,
                 reinterpret_cast<TScrollBar*>(hscrollbar),
                 reinterpret_cast<TScrollBar*>(vscrollbar),
                 reinterpret_cast<TIndicator*>(indicator),
                 buf_size)
    );
}

void tv_memo_destroy(tv_Memo* memo) {
    if (memo) {
        TObject::destroy(reinterpret_cast<TMemo*>(memo));
    }
}

void tv_memo_get_data(tv_Memo* memo, void* rec) {
    if (memo) {
        reinterpret_cast<TMemo*>(memo)->getData(rec);
    }
}

void tv_memo_set_data(tv_Memo* memo, void* rec) {
    if (memo) {
        reinterpret_cast<TMemo*>(memo)->setData(rec);
    }
}

tv_ushort tv_memo_data_size(tv_Memo* memo) {
    if (memo) {
        return reinterpret_cast<TMemo*>(memo)->dataSize();
    }
    return 0;
}

/* TFileEditor functions */

tv_FileEditor* tv_fileeditor_create(tv_Rect bounds, tv_ScrollBar* hscrollbar,
                                    tv_ScrollBar* vscrollbar, tv_Indicator* indicator,
                                    const char* filename) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_FileEditor*>(
        new TFileEditor(rect,
                       reinterpret_cast<TScrollBar*>(hscrollbar),
                       reinterpret_cast<TScrollBar*>(vscrollbar),
                       reinterpret_cast<TIndicator*>(indicator),
                       filename ? filename : "")
    );
}

void tv_fileeditor_destroy(tv_FileEditor* fileeditor) {
    if (fileeditor) {
        TObject::destroy(reinterpret_cast<TFileEditor*>(fileeditor));
    }
}

tv_bool tv_fileeditor_load_file(tv_FileEditor* fileeditor) {
    if (fileeditor) {
        return reinterpret_cast<TFileEditor*>(fileeditor)->loadFile();
    }
    return TV_FALSE;
}

tv_bool tv_fileeditor_save(tv_FileEditor* fileeditor) {
    if (fileeditor) {
        return reinterpret_cast<TFileEditor*>(fileeditor)->save();
    }
    return TV_FALSE;
}

tv_bool tv_fileeditor_save_as(tv_FileEditor* fileeditor) {
    if (fileeditor) {
        return reinterpret_cast<TFileEditor*>(fileeditor)->saveAs();
    }
    return TV_FALSE;
}

tv_bool tv_fileeditor_save_file(tv_FileEditor* fileeditor) {
    if (fileeditor) {
        return reinterpret_cast<TFileEditor*>(fileeditor)->saveFile();
    }
    return TV_FALSE;
}

const char* tv_fileeditor_get_filename(tv_FileEditor* fileeditor) {
    if (fileeditor) {
        return reinterpret_cast<TFileEditor*>(fileeditor)->fileName;
    }
    return nullptr;
}

void tv_fileeditor_set_filename(tv_FileEditor* fileeditor, const char* filename) {
    if (fileeditor && filename) {
        strncpy(reinterpret_cast<TFileEditor*>(fileeditor)->fileName, filename, MAXPATH - 1);
        reinterpret_cast<TFileEditor*>(fileeditor)->fileName[MAXPATH - 1] = '\0';
    }
}

/* TEditWindow functions */

tv_EditWindow* tv_editwindow_create(tv_Rect bounds, const char* filename, int number) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_EditWindow*>(
        new TEditWindow(rect, filename ? filename : "", number)
    );
}

void tv_editwindow_destroy(tv_EditWindow* editwindow) {
    if (editwindow) {
        TObject::destroy(reinterpret_cast<TEditWindow*>(editwindow));
    }
}

tv_FileEditor* tv_editwindow_get_editor(tv_EditWindow* editwindow) {
    if (editwindow) {
        return reinterpret_cast<tv_FileEditor*>(reinterpret_cast<TEditWindow*>(editwindow)->editor);
    }
    return nullptr;
}

const char* tv_editwindow_get_title(tv_EditWindow* editwindow, short max_size) {
    if (editwindow) {
        return reinterpret_cast<TEditWindow*>(editwindow)->getTitle(max_size);
    }
    return nullptr;
}

} // extern "C"

// Made with Bob
