//
// Created by Jason Lee on 2/2/26.
//

#ifndef TVISION_CSYSTEM_H
#define TVISION_CSYSTEM_H

#include "ctypes.h"
#include "cobjects.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Event codes */
extern const int tv_evMouseDown;
extern const int tv_evMouseUp;
extern const int tv_evMouseMove;
extern const int tv_evMouseAuto;
extern const int tv_evMouseWheel;
extern const int tv_evKeyDown;
extern const int tv_evCommand;
extern const int tv_evBroadcast;

/* Event masks */
extern const int tv_evNothing;
extern const int tv_evMouse;
extern const int tv_evKeyboard;
extern const int tv_evMessage;

/* Mouse button state masks */
extern const int tv_mbLeftButton;
extern const int tv_mbRightButton;
extern const int tv_mbMiddleButton;

/* Mouse wheel state masks */
extern const int tv_mwUp;
extern const int tv_mwDown;
extern const int tv_mwLeft;
extern const int tv_mwRight;

/* Mouse event flags */
extern const int tv_meMouseMoved;
extern const int tv_meDoubleClick;
extern const int tv_meTripleClick;

/* CharScanType structure */
typedef struct {
    unsigned char charCode;
    unsigned char scanCode;
} tv_CharScanType;

/* TMouse functions */
tv_TMouse *tv_mouse_create(void);
void tv_mouse_destroy(tv_TMouse *mouse);
void tv_mouse_show(void);
void tv_mouse_hide(void);
void tv_mouse_set_range(tv_ushort rx, tv_ushort ry);
void tv_mouse_get_event(tv_MouseEventType *event);
tv_bool tv_mouse_present(void);
void tv_mouse_suspend(void);
void tv_mouse_resume(void);

/* TEventQueue functions */
tv_TEventQueue *tv_eventqueue_create(void);
void tv_eventqueue_destroy(tv_TEventQueue *queue);
void tv_eventqueue_get_mouse_event(tv_Event *event);
void tv_eventqueue_get_key_event(tv_Event *event);
void tv_eventqueue_suspend(void);
void tv_eventqueue_resume(void);
void tv_eventqueue_wait_for_events(int timeoutMs);
void tv_eventqueue_wake_up(void);
void tv_eventqueue_set_paste_text(const char *text, int length);

/* TEventQueue static variables accessors */
tv_ushort tv_eventqueue_get_double_delay(void);
void tv_eventqueue_set_double_delay(tv_ushort delay);
tv_bool tv_eventqueue_get_mouse_reverse(void);
void tv_eventqueue_set_mouse_reverse(tv_bool reverse);

// /* TTimerQueue functions */
// tv_TTimerQueue *tv_timerqueue_create(void);
// void tv_timerqueue_destroy(tv_TTimerQueue *queue);
// tv_TimerId tv_timerqueue_set_timer(tv_TTimerQueue *queue, unsigned int timeoutMs, int periodMs);
// void tv_timerqueue_kill_timer(tv_TTimerQueue *queue, tv_TimerId id);
// int tv_timerqueue_time_until_next_timeout(tv_TTimerQueue *queue);

/* TClipboard functions */
void tv_clipboard_set_text(const char *text, int length);
void tv_clipboard_request_text(void);

/* TDisplay video modes */
extern const int tv_smBW80;
extern const int tv_smCO80;
extern const int tv_smMono;
extern const int tv_smFont8x8;
extern const int tv_smColor256;
extern const int tv_smColorHigh;
extern const int tv_smUpdate;

/* TDisplay functions */
void tv_display_clear_screen(unsigned char row, unsigned char col);
void tv_display_set_cursor_type(tv_ushort cursorType);
tv_ushort tv_display_get_cursor_type(void);
tv_ushort tv_display_get_rows(void);
tv_ushort tv_display_get_cols(void);
void tv_display_set_crt_mode(tv_ushort mode);
tv_ushort tv_display_get_crt_mode(void);

/* TScreen functions */
tv_TScreen *tv_screen_create(void);
void tv_screen_destroy(tv_TScreen *screen);
void tv_screen_set_video_mode(tv_ushort mode);
void tv_screen_clear_screen(void);
void tv_screen_flush_screen(void);
void tv_screen_set_crt_data(void);
tv_ushort tv_screen_fix_crt_mode(tv_ushort mode);
void tv_screen_suspend(void);
void tv_screen_resume(void);

/* TScreen static variables accessors */
tv_ushort tv_screen_get_startup_mode(void);
tv_ushort tv_screen_get_startup_cursor(void);
tv_ushort tv_screen_get_screen_mode(void);
tv_ushort tv_screen_get_screen_width(void);
tv_ushort tv_screen_get_screen_height(void);
tv_bool tv_screen_get_hi_res_screen(void);
tv_bool tv_screen_get_check_snow(void);
tv_ushort tv_screen_get_cursor_lines(void);
tv_bool tv_screen_get_clear_on_suspend(void);
void tv_screen_set_clear_on_suspend(tv_bool value);

/* TSystemError functions */
tv_TSystemError *tv_systemerror_create(void);
void tv_systemerror_destroy(tv_TSystemError *error);
void tv_systemerror_suspend(void);
void tv_systemerror_resume(void);

/* TSystemError static variables accessors */
tv_bool tv_systemerror_get_ctrl_break_hit(void);
void tv_systemerror_set_ctrl_break_hit(tv_bool value);

#ifdef __cplusplus
}
#endif

#endif //TVISION_CSYSTEM_H