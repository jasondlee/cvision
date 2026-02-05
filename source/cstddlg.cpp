//
// Created by Bob AI Assistant
// C wrappers for Turbo Vision standard dialog classes
//

#include "cvision/cobjects.h"
#include "cvision/csystem.h"
#include "cvision/ctypes.h"
#include "cvision/cstddlg.h"
#include <tvision/tv.h>

extern "C" {
    
const int tv_fdOKButton = fdOKButton;
const int tv_fdOpenButton = fdOpenButton;
const int tv_fdReplaceButton = fdReplaceButton;
const int tv_fdClearButton = fdClearButton;
const int tv_fdHelpButton = fdHelpButton;
const int tv_fdNoLoadDir = fdNoLoadDir;

/* TFileInputLine functions */

tv_FileInputLine* tv_fileinputline_create(tv_Rect bounds, short max_len) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_FileInputLine*>(new TFileInputLine(rect, max_len));
}

void tv_fileinputline_destroy(tv_FileInputLine* input) {
    if (input) {
        TObject::destroy(reinterpret_cast<TFileInputLine*>(input));
    }
}

void tv_fileinputline_handle_event(tv_FileInputLine* input, tv_Event* event) {
    if (input && event) {
        TEvent ev;
        ev.what = event->what;
        
        if (event->what == evMouseDown || event->what == evMouseUp || 
            event->what == evMouseMove || event->what == evMouseAuto) {
            ev.mouse.where.x = event->data.mouse.where.x;
            ev.mouse.where.y = event->data.mouse.where.y;
            ev.mouse.eventFlags = event->data.mouse.eventFlags;
            ev.mouse.controlKeyState = event->data.mouse.controlKeyState;
            ev.mouse.buttons = event->data.mouse.buttons;
            ev.mouse.wheel = event->data.mouse.wheel;
        } else if (event->what == evKeyDown) {
            ev.keyDown.keyCode = event->data.keyDown.keyCode;
            ev.keyDown.controlKeyState = event->data.keyDown.controlKeyState;
            for (int i = 0; i < event->data.keyDown.textLength && i < TV_MAX_CHAR_SIZE; i++) {
                ev.keyDown.text[i] = event->data.keyDown.text[i];
            }
            ev.keyDown.textLength = event->data.keyDown.textLength;
        } else if (event->what == evCommand || event->what == evBroadcast) {
            ev.message.command = event->data.message.command;
            ev.message.infoPtr = event->data.message.infoPtr;
        }
        
        reinterpret_cast<TFileInputLine*>(input)->handleEvent(ev);
        
        event->what = ev.what;
    }
}

/* TFileCollection functions */

tv_FileCollection* tv_filecollection_create(int limit, int delta) {
    return reinterpret_cast<tv_FileCollection*>(new TFileCollection(limit, delta));
}

void tv_filecollection_destroy(tv_FileCollection* collection) {
    if (collection) {
        TObject::destroy(reinterpret_cast<TFileCollection*>(collection));
    }
}

tv_SearchRec* tv_filecollection_at(tv_FileCollection* collection, int index) {
    if (collection) {
        return reinterpret_cast<tv_SearchRec*>(
            reinterpret_cast<TFileCollection*>(collection)->at(index)
        );
    }
    return nullptr;
}

int tv_filecollection_get_count(tv_FileCollection* collection) {
    if (collection) {
        return reinterpret_cast<TFileCollection*>(collection)->getCount();
    }
    return 0;
}

int tv_filecollection_insert(tv_FileCollection* collection, tv_SearchRec* item) {
    if (collection && item) {
        return reinterpret_cast<TFileCollection*>(collection)->insert(
            reinterpret_cast<TSearchRec*>(item)
        );
    }
    return -1;
}

void tv_filecollection_free_item(tv_FileCollection* collection, tv_SearchRec* item) {
    if (collection && item) {
        reinterpret_cast<TFileCollection*>(collection)->free(
            reinterpret_cast<TSearchRec*>(item)
        );
    }
}

/* TSortedListBox functions */

tv_SortedListBox* tv_sortedlistbox_create(tv_Rect bounds, tv_ushort num_cols, tv_ScrollBar* scrollbar) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_SortedListBox*>(
        new TSortedListBox(rect, num_cols, reinterpret_cast<TScrollBar*>(scrollbar))
    );
}

void tv_sortedlistbox_destroy(tv_SortedListBox* listbox) {
    if (listbox) {
        TObject::destroy(reinterpret_cast<TSortedListBox*>(listbox));
    }
}

void tv_sortedlistbox_handle_event(tv_SortedListBox* listbox, tv_Event* event) {
    if (listbox && event) {
        TEvent ev;
        ev.what = event->what;
        
        if (event->what == evMouseDown || event->what == evMouseUp || 
            event->what == evMouseMove || event->what == evMouseAuto) {
            ev.mouse.where.x = event->data.mouse.where.x;
            ev.mouse.where.y = event->data.mouse.where.y;
            ev.mouse.eventFlags = event->data.mouse.eventFlags;
            ev.mouse.controlKeyState = event->data.mouse.controlKeyState;
            ev.mouse.buttons = event->data.mouse.buttons;
            ev.mouse.wheel = event->data.mouse.wheel;
        } else if (event->what == evKeyDown) {
            ev.keyDown.keyCode = event->data.keyDown.keyCode;
            ev.keyDown.controlKeyState = event->data.keyDown.controlKeyState;
            for (int i = 0; i < event->data.keyDown.textLength && i < TV_MAX_CHAR_SIZE; i++) {
                ev.keyDown.text[i] = event->data.keyDown.text[i];
            }
            ev.keyDown.textLength = event->data.keyDown.textLength;
        } else if (event->what == evCommand || event->what == evBroadcast) {
            ev.message.command = event->data.message.command;
            ev.message.infoPtr = event->data.message.infoPtr;
        }
        
        reinterpret_cast<TSortedListBox*>(listbox)->handleEvent(ev);
        
        event->what = ev.what;
    }
}

void tv_sortedlistbox_new_list(tv_SortedListBox* listbox, tv_Collection* list) {
    if (listbox) {
        reinterpret_cast<TSortedListBox*>(listbox)->newList(
            reinterpret_cast<TSortedCollection*>(list)
        );
    }
}

tv_Collection* tv_sortedlistbox_get_list(tv_SortedListBox* listbox) {
    if (listbox) {
        return reinterpret_cast<tv_Collection*>(
            reinterpret_cast<TSortedListBox*>(listbox)->list()
        );
    }
    return nullptr;
}

/* TFileList functions */

tv_FileList* tv_filelist_create(tv_Rect bounds, tv_ScrollBar* scrollbar) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_FileList*>(
        new TFileList(rect, reinterpret_cast<TScrollBar*>(scrollbar))
    );
}

void tv_filelist_destroy(tv_FileList* filelist) {
    if (filelist) {
        TObject::destroy(reinterpret_cast<TFileList*>(filelist));
    }
}

void tv_filelist_focus_item(tv_FileList* filelist, short item) {
    if (filelist) {
        reinterpret_cast<TFileList*>(filelist)->focusItem(item);
    }
}

void tv_filelist_select_item(tv_FileList* filelist, short item) {
    if (filelist) {
        reinterpret_cast<TFileList*>(filelist)->selectItem(item);
    }
}

void tv_filelist_get_text(tv_FileList* filelist, char* dest, short item, short max_len) {
    if (filelist && dest) {
        reinterpret_cast<TFileList*>(filelist)->getText(dest, item, max_len);
    }
}

void tv_filelist_new_list(tv_FileList* filelist, tv_FileCollection* list) {
    if (filelist) {
        reinterpret_cast<TFileList*>(filelist)->newList(
            reinterpret_cast<TFileCollection*>(list)
        );
    }
}

void tv_filelist_read_directory(tv_FileList* filelist, const char* dir, const char* wildcard) {
    if (filelist && dir && wildcard) {
        reinterpret_cast<TFileList*>(filelist)->readDirectory(dir, wildcard);
    }
}

void tv_filelist_read_directory_simple(tv_FileList* filelist, const char* wildcard) {
    if (filelist && wildcard) {
        reinterpret_cast<TFileList*>(filelist)->readDirectory(wildcard);
    }
}

tv_ushort tv_filelist_data_size(tv_FileList* filelist) {
    if (filelist) {
        return reinterpret_cast<TFileList*>(filelist)->dataSize();
    }
    return 0;
}

void tv_filelist_get_data(tv_FileList* filelist, void* rec) {
    if (filelist && rec) {
        reinterpret_cast<TFileList*>(filelist)->getData(rec);
    }
}

void tv_filelist_set_data(tv_FileList* filelist, void* rec) {
    if (filelist && rec) {
        reinterpret_cast<TFileList*>(filelist)->setData(rec);
    }
}

tv_FileCollection* tv_filelist_get_list(tv_FileList* filelist) {
    if (filelist) {
        return reinterpret_cast<tv_FileCollection*>(
            reinterpret_cast<TFileList*>(filelist)->list()
        );
    }
    return nullptr;
}

/* TFileInfoPane functions */

tv_FileInfoPane* tv_fileinfopane_create(tv_Rect bounds) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_FileInfoPane*>(new TFileInfoPane(rect));
}

void tv_fileinfopane_destroy(tv_FileInfoPane* pane) {
    if (pane) {
        TObject::destroy(reinterpret_cast<TFileInfoPane*>(pane));
    }
}

void tv_fileinfopane_draw(tv_FileInfoPane* pane) {
    if (pane) {
        reinterpret_cast<TFileInfoPane*>(pane)->draw();
    }
}

void tv_fileinfopane_handle_event(tv_FileInfoPane* pane, tv_Event* event) {
    if (pane && event) {
        TEvent ev;
        ev.what = event->what;
        
        if (event->what == evMouseDown || event->what == evMouseUp || 
            event->what == evMouseMove || event->what == evMouseAuto) {
            ev.mouse.where.x = event->data.mouse.where.x;
            ev.mouse.where.y = event->data.mouse.where.y;
            ev.mouse.eventFlags = event->data.mouse.eventFlags;
            ev.mouse.controlKeyState = event->data.mouse.controlKeyState;
            ev.mouse.buttons = event->data.mouse.buttons;
            ev.mouse.wheel = event->data.mouse.wheel;
        } else if (event->what == evKeyDown) {
            ev.keyDown.keyCode = event->data.keyDown.keyCode;
            ev.keyDown.controlKeyState = event->data.keyDown.controlKeyState;
            for (int i = 0; i < event->data.keyDown.textLength && i < TV_MAX_CHAR_SIZE; i++) {
                ev.keyDown.text[i] = event->data.keyDown.text[i];
            }
            ev.keyDown.textLength = event->data.keyDown.textLength;
        } else if (event->what == evCommand || event->what == evBroadcast) {
            ev.message.command = event->data.message.command;
            ev.message.infoPtr = event->data.message.infoPtr;
        }
        
        reinterpret_cast<TFileInfoPane*>(pane)->handleEvent(ev);
        
        event->what = ev.what;
    }
}

/* TFileDialog functions */

tv_FileDialog* tv_filedialog_create(const char* wildcard, const char* title, 
                                     const char* input_name, tv_ushort options, tv_uchar hist_id) {
    return reinterpret_cast<tv_FileDialog*>(
        new TFileDialog(wildcard, title, input_name, options, hist_id)
    );
}

void tv_filedialog_destroy(tv_FileDialog* dialog) {
    if (dialog) {
        TObject::destroy(reinterpret_cast<TFileDialog*>(dialog));
    }
}

void tv_filedialog_get_data(tv_FileDialog* dialog, void* rec) {
    if (dialog && rec) {
        reinterpret_cast<TFileDialog*>(dialog)->getData(rec);
    }
}

void tv_filedialog_get_filename(tv_FileDialog* dialog, char* s) {
    if (dialog && s) {
        reinterpret_cast<TFileDialog*>(dialog)->getFileName(s);
    }
}

void tv_filedialog_handle_event(tv_FileDialog* dialog, tv_Event* event) {
    if (dialog && event) {
        TEvent ev;
        ev.what = event->what;
        
        if (event->what == evMouseDown || event->what == evMouseUp || 
            event->what == evMouseMove || event->what == evMouseAuto) {
            ev.mouse.where.x = event->data.mouse.where.x;
            ev.mouse.where.y = event->data.mouse.where.y;
            ev.mouse.eventFlags = event->data.mouse.eventFlags;
            ev.mouse.controlKeyState = event->data.mouse.controlKeyState;
            ev.mouse.buttons = event->data.mouse.buttons;
            ev.mouse.wheel = event->data.mouse.wheel;
        } else if (event->what == evKeyDown) {
            ev.keyDown.keyCode = event->data.keyDown.keyCode;
            ev.keyDown.controlKeyState = event->data.keyDown.controlKeyState;
            for (int i = 0; i < event->data.keyDown.textLength && i < TV_MAX_CHAR_SIZE; i++) {
                ev.keyDown.text[i] = event->data.keyDown.text[i];
            }
            ev.keyDown.textLength = event->data.keyDown.textLength;
        } else if (event->what == evCommand || event->what == evBroadcast) {
            ev.message.command = event->data.message.command;
            ev.message.infoPtr = event->data.message.infoPtr;
        }
        
        reinterpret_cast<TFileDialog*>(dialog)->handleEvent(ev);
        
        event->what = ev.what;
    }
}

void tv_filedialog_set_data(tv_FileDialog* dialog, void* rec) {
    if (dialog && rec) {
        reinterpret_cast<TFileDialog*>(dialog)->setData(rec);
    }
}

tv_bool tv_filedialog_valid(tv_FileDialog* dialog, tv_ushort command) {
    if (dialog) {
        return reinterpret_cast<TFileDialog*>(dialog)->valid(command) ? TV_TRUE : TV_FALSE;
    }
    return TV_FALSE;
}

void tv_filedialog_shutdown(tv_FileDialog* dialog) {
    if (dialog) {
        reinterpret_cast<TFileDialog*>(dialog)->shutDown();
    }
}

/* TDirEntry functions */

tv_DirEntry* tv_direntry_create(const char* text, const char* dir) {
    if (text && dir) {
        return reinterpret_cast<tv_DirEntry*>(new TDirEntry(text, dir));
    }
    return nullptr;
}

void tv_direntry_destroy(tv_DirEntry* entry) {
    if (entry) {
        delete reinterpret_cast<TDirEntry*>(entry);
    }
}

char* tv_direntry_get_dir(tv_DirEntry* entry) {
    if (entry) {
        return reinterpret_cast<TDirEntry*>(entry)->dir();
    }
    return nullptr;
}

char* tv_direntry_get_text(tv_DirEntry* entry) {
    if (entry) {
        return reinterpret_cast<TDirEntry*>(entry)->text();
    }
    return nullptr;
}

/* TDirCollection functions */

tv_DirCollection* tv_dircollection_create(int limit, int delta) {
    return reinterpret_cast<tv_DirCollection*>(new TDirCollection(limit, delta));
}

void tv_dircollection_destroy(tv_DirCollection* collection) {
    if (collection) {
        TObject::destroy(reinterpret_cast<TDirCollection*>(collection));
    }
}

tv_DirEntry* tv_dircollection_at(tv_DirCollection* collection, int index) {
    if (collection) {
        return reinterpret_cast<tv_DirEntry*>(
            reinterpret_cast<TDirCollection*>(collection)->at(index)
        );
    }
    return nullptr;
}

int tv_dircollection_get_count(tv_DirCollection* collection) {
    if (collection) {
        return reinterpret_cast<TDirCollection*>(collection)->getCount();
    }
    return 0;
}

int tv_dircollection_insert(tv_DirCollection* collection, tv_DirEntry* item) {
    if (collection && item) {
        return reinterpret_cast<TDirCollection*>(collection)->insert(
            reinterpret_cast<TDirEntry*>(item)
        );
    }
    return -1;
}

void tv_dircollection_free_item(tv_DirCollection* collection, tv_DirEntry* item) {
    if (collection && item) {
        reinterpret_cast<TDirCollection*>(collection)->free(
            reinterpret_cast<TDirEntry*>(item)
        );
    }
}

/* TDirListBox functions */

tv_DirListBox* tv_dirlistbox_create(tv_Rect bounds, tv_ScrollBar* scrollbar) {
    TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
    return reinterpret_cast<tv_DirListBox*>(
        new TDirListBox(rect, reinterpret_cast<TScrollBar*>(scrollbar))
    );
}

void tv_dirlistbox_destroy(tv_DirListBox* listbox) {
    if (listbox) {
        TObject::destroy(reinterpret_cast<TDirListBox*>(listbox));
    }
}

void tv_dirlistbox_get_text(tv_DirListBox* listbox, char* dest, short item, short max_len) {
    if (listbox && dest) {
        reinterpret_cast<TDirListBox*>(listbox)->getText(dest, item, max_len);
    }
}

tv_bool tv_dirlistbox_is_selected(tv_DirListBox* listbox, short item) {
    if (listbox) {
        return reinterpret_cast<TDirListBox*>(listbox)->isSelected(item) ? TV_TRUE : TV_FALSE;
    }
    return TV_FALSE;
}

void tv_dirlistbox_select_item(tv_DirListBox* listbox, short item) {
    if (listbox) {
        reinterpret_cast<TDirListBox*>(listbox)->selectItem(item);
    }
}

void tv_dirlistbox_new_directory(tv_DirListBox* listbox, const char* dir) {
    if (listbox && dir) {
        reinterpret_cast<TDirListBox*>(listbox)->newDirectory(dir);
    }
}

void tv_dirlistbox_set_state(tv_DirListBox* listbox, tv_ushort state, tv_bool enable) {
    if (listbox) {
        reinterpret_cast<TDirListBox*>(listbox)->setState(state, enable != TV_FALSE);
    }
}

tv_DirCollection* tv_dirlistbox_get_list(tv_DirListBox* listbox) {
    if (listbox) {
        return reinterpret_cast<tv_DirCollection*>(
            reinterpret_cast<TDirListBox*>(listbox)->list()
        );
    }
    return nullptr;
}

/* TChDirDialog functions */

tv_ChDirDialog* tv_chdirdialog_create(tv_ushort options, tv_ushort hist_id) {
    return reinterpret_cast<tv_ChDirDialog*>(new TChDirDialog(options, hist_id));
}

void tv_chdirdialog_destroy(tv_ChDirDialog* dialog) {
    if (dialog) {
        TObject::destroy(reinterpret_cast<TChDirDialog*>(dialog));
    }
}

tv_ushort tv_chdirdialog_data_size(tv_ChDirDialog* dialog) {
    if (dialog) {
        return reinterpret_cast<TChDirDialog*>(dialog)->dataSize();
    }
    return 0;
}

void tv_chdirdialog_get_data(tv_ChDirDialog* dialog, void* rec) {
    if (dialog && rec) {
        reinterpret_cast<TChDirDialog*>(dialog)->getData(rec);
    }
}

void tv_chdirdialog_handle_event(tv_ChDirDialog* dialog, tv_Event* event) {
    if (dialog && event) {
        TEvent ev;
        ev.what = event->what;
        
        if (event->what == evMouseDown || event->what == evMouseUp || 
            event->what == evMouseMove || event->what == evMouseAuto) {
            ev.mouse.where.x = event->data.mouse.where.x;
            ev.mouse.where.y = event->data.mouse.where.y;
            ev.mouse.eventFlags = event->data.mouse.eventFlags;
            ev.mouse.controlKeyState = event->data.mouse.controlKeyState;
            ev.mouse.buttons = event->data.mouse.buttons;
            ev.mouse.wheel = event->data.mouse.wheel;
        } else if (event->what == evKeyDown) {
            ev.keyDown.keyCode = event->data.keyDown.keyCode;
            ev.keyDown.controlKeyState = event->data.keyDown.controlKeyState;
            for (int i = 0; i < event->data.keyDown.textLength && i < TV_MAX_CHAR_SIZE; i++) {
                ev.keyDown.text[i] = event->data.keyDown.text[i];
            }
            ev.keyDown.textLength = event->data.keyDown.textLength;
        } else if (event->what == evCommand || event->what == evBroadcast) {
            ev.message.command = event->data.message.command;
            ev.message.infoPtr = event->data.message.infoPtr;
        }
        
        reinterpret_cast<TChDirDialog*>(dialog)->handleEvent(ev);
        
        event->what = ev.what;
    }
}

void tv_chdirdialog_set_data(tv_ChDirDialog* dialog, void* rec) {
    if (dialog && rec) {
        reinterpret_cast<TChDirDialog*>(dialog)->setData(rec);
    }
}

tv_bool tv_chdirdialog_valid(tv_ChDirDialog* dialog, tv_ushort command) {
    if (dialog) {
        return reinterpret_cast<TChDirDialog*>(dialog)->valid(command) ? TV_TRUE : TV_FALSE;
    }
    return TV_FALSE;
}

void tv_chdirdialog_shutdown(tv_ChDirDialog* dialog) {
    if (dialog) {
        reinterpret_cast<TChDirDialog*>(dialog)->shutDown();
    }
}

} // extern "C"
