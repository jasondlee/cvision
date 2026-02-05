//
// Created by Bob AI Assistant
// C wrappers for Turbo Vision standard dialog classes
//

#ifndef TVISION_CSTDDLG_H
#define TVISION_CSTDDLG_H

#include "ctypes.h"
#include "cobjects.h"
#include "csystem.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Opaque type definitions for classes not already in ctypes.h */
typedef struct tv_FileInputLine tv_FileInputLine;
typedef struct tv_FileCollection tv_FileCollection;
typedef struct tv_SortedListBox tv_SortedListBox;
typedef struct tv_FileList tv_FileList;
typedef struct tv_FileInfoPane tv_FileInfoPane;
typedef struct tv_FileDialog tv_FileDialog;
typedef struct tv_DirEntry tv_DirEntry;
typedef struct tv_DirCollection tv_DirCollection;
typedef struct tv_DirListBox tv_DirListBox;
typedef struct tv_ChDirDialog tv_ChDirDialog;
typedef struct tv_SearchRec tv_SearchRec;

/* TSearchRec structure */
struct tv_SearchRec {
    tv_uchar attr;
    int time;
    int size;
    char name[256];
};

extern const int tv_fdOKButton;
extern const int tv_fdOpenButton;
extern const int tv_fdReplaceButton;
extern const int tv_fdClearButton;
extern const int tv_fdHelpButton;
extern const int tv_fdNoLoadDir;

/* TFileInputLine functions */
tv_FileInputLine* tv_fileinputline_create(tv_Rect bounds, short max_len);
void tv_fileinputline_destroy(tv_FileInputLine* input);
void tv_fileinputline_handle_event(tv_FileInputLine* input, tv_Event* event);

/* TFileCollection functions */
tv_FileCollection* tv_filecollection_create(int limit, int delta);
void tv_filecollection_destroy(tv_FileCollection* collection);
tv_SearchRec* tv_filecollection_at(tv_FileCollection* collection, int index);
int tv_filecollection_get_count(tv_FileCollection* collection);
int tv_filecollection_insert(tv_FileCollection* collection, tv_SearchRec* item);
void tv_filecollection_free_item(tv_FileCollection* collection, tv_SearchRec* item);

/* TSortedListBox functions */
tv_SortedListBox* tv_sortedlistbox_create(tv_Rect bounds, tv_ushort num_cols, tv_ScrollBar* scrollbar);
void tv_sortedlistbox_destroy(tv_SortedListBox* listbox);
void tv_sortedlistbox_handle_event(tv_SortedListBox* listbox, tv_Event* event);
void tv_sortedlistbox_new_list(tv_SortedListBox* listbox, tv_Collection* list);
tv_Collection* tv_sortedlistbox_get_list(tv_SortedListBox* listbox);

/* TFileList functions */
tv_FileList* tv_filelist_create(tv_Rect bounds, tv_ScrollBar* scrollbar);
void tv_filelist_destroy(tv_FileList* filelist);
void tv_filelist_focus_item(tv_FileList* filelist, short item);
void tv_filelist_select_item(tv_FileList* filelist, short item);
void tv_filelist_get_text(tv_FileList* filelist, char* dest, short item, short max_len);
void tv_filelist_new_list(tv_FileList* filelist, tv_FileCollection* list);
void tv_filelist_read_directory(tv_FileList* filelist, const char* dir, const char* wildcard);
void tv_filelist_read_directory_simple(tv_FileList* filelist, const char* wildcard);
tv_ushort tv_filelist_data_size(tv_FileList* filelist);
void tv_filelist_get_data(tv_FileList* filelist, void* rec);
void tv_filelist_set_data(tv_FileList* filelist, void* rec);
tv_FileCollection* tv_filelist_get_list(tv_FileList* filelist);

/* TFileInfoPane functions */
tv_FileInfoPane* tv_fileinfopane_create(tv_Rect bounds);
void tv_fileinfopane_destroy(tv_FileInfoPane* pane);
void tv_fileinfopane_draw(tv_FileInfoPane* pane);
void tv_fileinfopane_handle_event(tv_FileInfoPane* pane, tv_Event* event);

/* TFileDialog functions */
tv_FileDialog* tv_filedialog_create(const char* wildcard, const char* title, 
                                     const char* input_name, tv_ushort options, tv_uchar hist_id);
void tv_filedialog_destroy(tv_FileDialog* dialog);
void tv_filedialog_get_data(tv_FileDialog* dialog, void* rec);
void tv_filedialog_get_filename(tv_FileDialog* dialog, char* s);
void tv_filedialog_handle_event(tv_FileDialog* dialog, tv_Event* event);
void tv_filedialog_set_data(tv_FileDialog* dialog, void* rec);
tv_bool tv_filedialog_valid(tv_FileDialog* dialog, tv_ushort command);
void tv_filedialog_shutdown(tv_FileDialog* dialog);

/* TDirEntry functions */
tv_DirEntry* tv_direntry_create(const char* text, const char* dir);
void tv_direntry_destroy(tv_DirEntry* entry);
char* tv_direntry_get_dir(tv_DirEntry* entry);
char* tv_direntry_get_text(tv_DirEntry* entry);

/* TDirCollection functions */
tv_DirCollection* tv_dircollection_create(int limit, int delta);
void tv_dircollection_destroy(tv_DirCollection* collection);
tv_DirEntry* tv_dircollection_at(tv_DirCollection* collection, int index);
int tv_dircollection_get_count(tv_DirCollection* collection);
int tv_dircollection_insert(tv_DirCollection* collection, tv_DirEntry* item);
void tv_dircollection_free_item(tv_DirCollection* collection, tv_DirEntry* item);

/* TDirListBox functions */
tv_DirListBox* tv_dirlistbox_create(tv_Rect bounds, tv_ScrollBar* scrollbar);
void tv_dirlistbox_destroy(tv_DirListBox* listbox);
void tv_dirlistbox_get_text(tv_DirListBox* listbox, char* dest, short item, short max_len);
tv_bool tv_dirlistbox_is_selected(tv_DirListBox* listbox, short item);
void tv_dirlistbox_select_item(tv_DirListBox* listbox, short item);
void tv_dirlistbox_new_directory(tv_DirListBox* listbox, const char* dir);
void tv_dirlistbox_set_state(tv_DirListBox* listbox, tv_ushort state, tv_bool enable);
tv_DirCollection* tv_dirlistbox_get_list(tv_DirListBox* listbox);

/* TChDirDialog functions */
tv_ChDirDialog* tv_chdirdialog_create(tv_ushort options, tv_ushort hist_id);
void tv_chdirdialog_destroy(tv_ChDirDialog* dialog);
tv_ushort tv_chdirdialog_data_size(tv_ChDirDialog* dialog);
void tv_chdirdialog_get_data(tv_ChDirDialog* dialog, void* rec);
void tv_chdirdialog_handle_event(tv_ChDirDialog* dialog, tv_Event* event);
void tv_chdirdialog_set_data(tv_ChDirDialog* dialog, void* rec);
tv_bool tv_chdirdialog_valid(tv_ChDirDialog* dialog, tv_ushort command);
void tv_chdirdialog_shutdown(tv_ChDirDialog* dialog);

/* File dialog option flags */
#define TV_FD_OK_BUTTON       0x0001
#define TV_FD_OPEN_BUTTON     0x0002
#define TV_FD_REPLACE_BUTTON  0x0004
#define TV_FD_CLEAR_BUTTON    0x0008
#define TV_FD_HELP_BUTTON     0x0010
#define TV_FD_NO_LOAD_DIR     0x0100

/* Change directory dialog option flags */
#define TV_CD_NORMAL          0x0000
#define TV_CD_NO_LOAD_DIR     0x0001
#define TV_CD_HELP_BUTTON     0x0002

/* File commands */
#define TV_CM_FILE_OPEN            1001
#define TV_CM_FILE_REPLACE         1002
#define TV_CM_FILE_CLEAR           1003
#define TV_CM_FILE_INIT            1004
#define TV_CM_CHANGE_DIR           1005
#define TV_CM_REVERT               1006
#define TV_CM_FILE_FOCUSED         102
#define TV_CM_FILE_DOUBLE_CLICKED  103

#ifdef __cplusplus
}
#endif

#endif /* TVISION_CSTDDLG_H */
