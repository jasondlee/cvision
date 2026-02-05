//
// Created by Bob on 2/2/26.
//

#include "cvision/cmsgbox.h"
#include "cvision/ctypes.h"
#include "cvision/cobjects.h"
#include <tvision/tv.h>

extern "C" {
    /* Message box constants */
    
    /* Message box classes */
    const int tv_mfWarning = mfWarning;
    const int tv_mfError = mfError;
    const int tv_mfInformation = mfInformation;
    const int tv_mfConfirmation = mfConfirmation;
    
    /* Message box button flags */
    const int tv_mfYesButton = mfYesButton;
    const int tv_mfNoButton = mfNoButton;
    const int tv_mfOKButton = mfOKButton;
    const int tv_mfCancelButton = mfCancelButton;
    const int tv_mfYesNoCancel = mfYesNoCancel;
    const int tv_mfOKCancel = mfOKCancel;
    
    /* Message box functions */
    
    tv_ushort tv_messagebox(const char *msg, tv_ushort options) {
        return messageBox(msg, options);
    }
    
    tv_ushort tv_messagebox_rect(tv_Rect r, const char *msg, tv_ushort options) {
        TRect rect(r.a.x, r.a.y, r.b.x, r.b.y);
        return messageBoxRect(rect, msg, options);
    }
    
    tv_ushort tv_inputbox(const char *title, const char *label, char *s, tv_uchar limit) {
        return inputBox(title, label, s, limit);
    }
    
    tv_ushort tv_inputbox_rect(tv_Rect bounds, const char *title, const char *label, char *s, tv_uchar limit) {
        TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
        return inputBoxRect(rect, title, label, s, limit);
    }
    
    /* MsgBoxText class wrappers - getters */
    
    const char *tv_msgboxtext_get_yes() {
        return MsgBoxText::yesText;
    }
    
    const char *tv_msgboxtext_get_no() {
        return MsgBoxText::noText;
    }
    
    const char *tv_msgboxtext_get_ok() {
        return MsgBoxText::okText;
    }
    
    const char *tv_msgboxtext_get_cancel() {
        return MsgBoxText::cancelText;
    }
    
    const char *tv_msgboxtext_get_warning() {
        return MsgBoxText::warningText;
    }
    
    const char *tv_msgboxtext_get_error() {
        return MsgBoxText::errorText;
    }
    
    const char *tv_msgboxtext_get_information() {
        return MsgBoxText::informationText;
    }
    
    const char *tv_msgboxtext_get_confirm() {
        return MsgBoxText::confirmText;
    }
    
    /* MsgBoxText class wrappers - setters */
    
    void tv_msgboxtext_set_yes(const char *text) {
        MsgBoxText::yesText = text;
    }
    
    void tv_msgboxtext_set_no(const char *text) {
        MsgBoxText::noText = text;
    }
    
    void tv_msgboxtext_set_ok(const char *text) {
        MsgBoxText::okText = text;
    }
    
    void tv_msgboxtext_set_cancel(const char *text) {
        MsgBoxText::cancelText = text;
    }
    
    void tv_msgboxtext_set_warning(const char *text) {
        MsgBoxText::warningText = text;
    }
    
    void tv_msgboxtext_set_error(const char *text) {
        MsgBoxText::errorText = text;
    }
    
    void tv_msgboxtext_set_information(const char *text) {
        MsgBoxText::informationText = text;
    }
    
    void tv_msgboxtext_set_confirm(const char *text) {
        MsgBoxText::confirmText = text;
    }
}
