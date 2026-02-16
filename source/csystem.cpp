//
// Created by Jason Lee on 2/2/26.
//

#include "cvision/csystem.h"
#include "cvision/cvision.h"
#include <tvision/tv.h>

extern "C" {

/* Event codes */
const int tv_evMouseDown = evMouseDown;
const int tv_evMouseUp = evMouseUp;
const int tv_evMouseMove = evMouseMove;
const int tv_evMouseAuto = evMouseAuto;
const int tv_evMouseWheel = evMouseWheel;
const int tv_evKeyDown = evKeyDown;
const int tv_evCommand = evCommand;
const int tv_evBroadcast = evBroadcast;

/* Event masks */
const int tv_evNothing = evNothing;
const int tv_evMouse = evMouse;
const int tv_evKeyboard = evKeyboard;
const int tv_evMessage = evMessage;

/* Mouse button state masks */
const int tv_mbLeftButton = mbLeftButton;
const int tv_mbRightButton = mbRightButton;
const int tv_mbMiddleButton = mbMiddleButton;

/* Mouse wheel state masks */
const int tv_mwUp = mwUp;
const int tv_mwDown = mwDown;
const int tv_mwLeft = mwLeft;
const int tv_mwRight = mwRight;

/* Mouse event flags */
const int tv_meMouseMoved = meMouseMoved;
const int tv_meDoubleClick = meDoubleClick;
const int tv_meTripleClick = meTripleClick;

/* TMouse functions */
tv_TMouse *tv_mouse_create(void) {
    return reinterpret_cast<tv_TMouse *>(new TMouse());
}

void tv_mouse_destroy(tv_TMouse *mouse) {
    if (mouse) {
        delete reinterpret_cast<TMouse *>(mouse);
    }
}

void tv_mouse_show(void) {
    TMouse::show();
}

void tv_mouse_hide(void) {
    TMouse::hide();
}

void tv_mouse_set_range(tv_ushort rx, tv_ushort ry) {
    TMouse::setRange(rx, ry);
}

void tv_mouse_get_event(tv_MouseEventType *event) {
    if (event) {
        MouseEventType me;
        TMouse::getEvent(me);
        event->where.x = me.where.x;
        event->where.y = me.where.y;
        event->eventFlags = me.eventFlags;
        event->controlKeyState = me.controlKeyState;
        event->buttons = me.buttons;
        event->wheel = me.wheel;
    }
}

tv_bool tv_mouse_present(void) {
    return TMouse::present(); // ? tv_True : tv_False;
}

void tv_mouse_suspend(void) {
    TMouse::suspend();
}

void tv_mouse_resume(void) {
    TMouse::resume();
}

/* TEventQueue functions */
tv_TEventQueue *tv_eventqueue_create(void) {
    return reinterpret_cast<tv_TEventQueue *>(new TEventQueue());
}

void tv_eventqueue_destroy(tv_TEventQueue *queue) {
    if (queue) {
        delete reinterpret_cast<TEventQueue *>(queue);
    }
}

void tv_eventqueue_get_mouse_event(tv_Event *event) {
    if (event) {
        TEvent ev;
        TEventQueue::getMouseEvent(ev);
        event->what = ev.what;
        if (ev.what & evMouse) {
            event->data.mouse.where.x = ev.mouse.where.x;
            event->data.mouse.where.y = ev.mouse.where.y;
            event->data.mouse.eventFlags = ev.mouse.eventFlags;
            event->data.mouse.controlKeyState = ev.mouse.controlKeyState;
            event->data.mouse.buttons = ev.mouse.buttons;
            event->data.mouse.wheel = ev.mouse.wheel;
        }
    }
}

void tv_eventqueue_get_key_event(tv_Event *event) {
    if (event) {
        TEvent ev;
        TEventQueue::getKeyEvent(ev);
        event->what = ev.what;
        if (ev.what & evKeyboard) {
            event->data.keyDown.keyCode = ev.keyDown.keyCode;
            event->data.keyDown.controlKeyState = ev.keyDown.controlKeyState;
            event->data.keyDown.textLength = ev.keyDown.textLength;
            for (int i = 0; i < ev.keyDown.textLength && i < 4; i++) {
                event->data.keyDown.text[i] = ev.keyDown.text[i];
            }
        }
    }
}

void tv_eventqueue_suspend(void) {
    TEventQueue::suspend();
}

void tv_eventqueue_resume(void) {
    TEventQueue::resume();
}

void tv_eventqueue_wait_for_events(int timeoutMs) {
    TEventQueue::waitForEvents(timeoutMs);
}

void tv_eventqueue_wake_up(void) {
    TEventQueue::wakeUp();
}

void tv_eventqueue_set_paste_text(const char *text, int length) {
    if (text) {
        TEventQueue::setPasteText(TStringView(text, length));
    }
}

/* TEventQueue static variables accessors */
tv_ushort tv_eventqueue_get_double_delay(void) {
    return TEventQueue::doubleDelay;
}

void tv_eventqueue_set_double_delay(tv_ushort delay) {
    TEventQueue::doubleDelay = delay;
}

tv_bool tv_eventqueue_get_mouse_reverse(void) {
    return TEventQueue::mouseReverse;
}

void tv_eventqueue_set_mouse_reverse(tv_bool reverse) {
    TEventQueue::mouseReverse = (reverse == 1);
}

// /* TTimerQueue functions */
// tv_TTimerQueue *tv_timerqueue_create(void) {
//     return reinterpret_cast<tv_TTimerQueue *>(new TTimerQueue());
// }
//
// void tv_timerqueue_destroy(tv_TTimerQueue *queue) {
//     if (queue) {
//         delete reinterpret_cast<TTimerQueue *>(queue);
//     }
// }
//
// tv_TimerId tv_timerqueue_set_timer(tv_TTimerQueue *queue, unsigned int timeoutMs, int periodMs) {
//     if (queue) {
//         auto timerId = reinterpret_cast<TTimerQueue *>(queue)->setTimer(timeoutMs, periodMs);
//         return reinterpret_cast<tv_TimerId>(timerId);
//     }
//     return 0;
// }
//
// void tv_timerqueue_kill_timer(tv_TTimerQueue *queue, tv_TimerId id) {
//     if (queue) {
//         reinterpret_cast<TTimerQueue *>(queue)->killTimer(id);
//     }
// }
//
// int tv_timerqueue_time_until_next_timeout(tv_TTimerQueue *queue) {
//     if (queue) {
//         return reinterpret_cast<TTimerQueue *>(queue)->timeUntilNextTimeout();
//     }
//     return -1;
// }

/* TClipboard functions */
void tv_clipboard_set_text(const char *text, int length) {
    if (text) {
        TClipboard::setText(TStringView(text, length));
    }
}

void tv_clipboard_request_text(void) {
    TClipboard::requestText();
}

/* TDisplay video modes */
const int tv_smBW80 = TDisplay::smBW80;
const int tv_smCO80 = TDisplay::smCO80;
const int tv_smMono = TDisplay::smMono;
const int tv_smFont8x8 = TDisplay::smFont8x8;
const int tv_smColor256 = TDisplay::smColor256;
const int tv_smColorHigh = TDisplay::smColorHigh;
const int tv_smUpdate = TDisplay::smUpdate;

/* TDisplay functions */
void tv_display_clear_screen(unsigned char row, unsigned char col) {
    TDisplay::clearScreen(row, col);
}

void tv_display_set_cursor_type(tv_ushort cursorType) {
    TDisplay::setCursorType(cursorType);
}

tv_ushort tv_display_get_cursor_type(void) {
    return TDisplay::getCursorType();
}

tv_ushort tv_display_get_rows(void) {
    return TDisplay::getRows();
}

tv_ushort tv_display_get_cols(void) {
    return TDisplay::getCols();
}

void tv_display_set_crt_mode(tv_ushort mode) {
    TDisplay::setCrtMode(mode);
}

tv_ushort tv_display_get_crt_mode(void) {
    return TDisplay::getCrtMode();
}

/* TScreen functions */
tv_TScreen *tv_screen_create(void) {
    return reinterpret_cast<tv_TScreen *>(new TScreen());
}

void tv_screen_destroy(tv_TScreen *screen) {
    if (screen) {
        delete reinterpret_cast<TScreen *>(screen);
    }
}

void tv_screen_set_video_mode(tv_ushort mode) {
    TScreen::setVideoMode(mode);
}

void tv_screen_clear_screen(void) {
    TScreen::clearScreen();
}

void tv_screen_flush_screen(void) {
    TScreen::flushScreen();
}

void tv_screen_set_crt_data(void) {
    TScreen::setCrtData();
}

tv_ushort tv_screen_fix_crt_mode(tv_ushort mode) {
    return TScreen::fixCrtMode(mode);
}

void tv_screen_suspend(void) {
    TScreen::suspend();
}

void tv_screen_resume(void) {
    TScreen::resume();
}

/* TScreen static variables accessors */
tv_ushort tv_screen_get_startup_mode(void) {
    return TScreen::startupMode;
}

tv_ushort tv_screen_get_startup_cursor(void) {
    return TScreen::startupCursor;
}

tv_ushort tv_screen_get_screen_mode(void) {
    return TScreen::screenMode;
}

tv_ushort tv_screen_get_screen_width(void) {
    return TScreen::screenWidth;
}

tv_ushort tv_screen_get_screen_height(void) {
    return TScreen::screenHeight;
}

tv_bool tv_screen_get_hi_res_screen(void) {
    return TScreen::hiResScreen;
}

tv_bool tv_screen_get_check_snow(void) {
    return TScreen::checkSnow;
}

tv_ushort tv_screen_get_cursor_lines(void) {
    return TScreen::cursorLines;
}

tv_bool tv_screen_get_clear_on_suspend(void) {
    return TScreen::clearOnSuspend;
}

void tv_screen_set_clear_on_suspend(tv_bool value) {
    TScreen::clearOnSuspend = (value == 1);
}

/* TSystemError functions */
tv_TSystemError *tv_systemerror_create(void) {
    return reinterpret_cast<tv_TSystemError *>(new TSystemError());
}

void tv_systemerror_destroy(tv_TSystemError *error) {
    if (error) {
        delete reinterpret_cast<TSystemError *>(error);
    }
}

void tv_systemerror_suspend(void) {
    TSystemError::suspend();
}

void tv_systemerror_resume(void) {
    TSystemError::resume();
}

/* TSystemError static variables accessors */
tv_bool tv_systemerror_get_ctrl_break_hit(void) {
    return TSystemError::ctrlBreakHit;
}

void tv_systemerror_set_ctrl_break_hit(tv_bool value) {
    TSystemError::ctrlBreakHit = (value == 1);
}

} // extern "C"