//
// Created by Bob on 2/2/26.
//

#ifndef TVISION_CMSGBOX_H
#define TVISION_CMSGBOX_H

#include "ctypes.h"
#include "cobjects.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Message box constants */

/* Message box classes */
extern const int tv_mfWarning;
extern const int tv_mfError;
extern const int tv_mfInformation;
extern const int tv_mfConfirmation;

/* Message box button flags */
extern const int tv_mfYesButton;
extern const int tv_mfNoButton;
extern const int tv_mfOKButton;
extern const int tv_mfCancelButton;
extern const int tv_mfYesNoCancel;
extern const int tv_mfOKCancel;

/* Message box functions */
tv_ushort tv_messagebox(const char *msg, tv_ushort options);
tv_ushort tv_messagebox_rect(tv_Rect r, const char *msg, tv_ushort options);
tv_ushort tv_inputbox(const char *title, const char *label, char *s, tv_uchar limit);
tv_ushort tv_inputbox_rect(tv_Rect bounds, const char *title, const char *label, char *s, tv_uchar limit);

/* MsgBoxText class wrappers */
const char *tv_msgboxtext_get_yes();
const char *tv_msgboxtext_get_no();
const char *tv_msgboxtext_get_ok();
const char *tv_msgboxtext_get_cancel();
const char *tv_msgboxtext_get_warning();
const char *tv_msgboxtext_get_error();
const char *tv_msgboxtext_get_information();
const char *tv_msgboxtext_get_confirm();

void tv_msgboxtext_set_yes(const char *text);
void tv_msgboxtext_set_no(const char *text);
void tv_msgboxtext_set_ok(const char *text);
void tv_msgboxtext_set_cancel(const char *text);
void tv_msgboxtext_set_warning(const char *text);
void tv_msgboxtext_set_error(const char *text);
void tv_msgboxtext_set_information(const char *text);
void tv_msgboxtext_set_confirm(const char *text);

#ifdef __cplusplus
}
#endif

#endif //TVISION_CMSGBOX_H
