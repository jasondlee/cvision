//
// Created by Jason Lee on 2/2/26.
//

#ifndef CVISION_CTKEYS_H
#define CVISION_CTKEYS_H

#include "ctypes.h"

#ifdef __cplusplus
extern "C" {
#endif

//// Key codes
//
// The following constants can be used to define menu hotkeys and to
// examine the 'keyCode' field of 'evKeyDown' event records.

// Control keys
extern const tv_ushort tv_kbCtrlA;
extern const tv_ushort tv_kbCtrlB;
extern const tv_ushort tv_kbCtrlC;
extern const tv_ushort tv_kbCtrlD;
extern const tv_ushort tv_kbCtrlE;
extern const tv_ushort tv_kbCtrlF;
extern const tv_ushort tv_kbCtrlG;
extern const tv_ushort tv_kbCtrlH;
extern const tv_ushort tv_kbCtrlI;
extern const tv_ushort tv_kbCtrlJ;
extern const tv_ushort tv_kbCtrlK;
extern const tv_ushort tv_kbCtrlL;
extern const tv_ushort tv_kbCtrlM;
extern const tv_ushort tv_kbCtrlN;
extern const tv_ushort tv_kbCtrlO;
extern const tv_ushort tv_kbCtrlP;
extern const tv_ushort tv_kbCtrlQ;
extern const tv_ushort tv_kbCtrlR;
extern const tv_ushort tv_kbCtrlS;
extern const tv_ushort tv_kbCtrlT;
extern const tv_ushort tv_kbCtrlU;
extern const tv_ushort tv_kbCtrlV;
extern const tv_ushort tv_kbCtrlW;
extern const tv_ushort tv_kbCtrlX;
extern const tv_ushort tv_kbCtrlY;
extern const tv_ushort tv_kbCtrlZ;

// Extended key codes
extern const tv_ushort tv_kbEsc;
extern const tv_ushort tv_kbAltSpace;
extern const tv_ushort tv_kbCtrlIns;
extern const tv_ushort tv_kbShiftIns;
extern const tv_ushort tv_kbCtrlDel;
extern const tv_ushort tv_kbShiftDel;
extern const tv_ushort tv_kbBack;
extern const tv_ushort tv_kbCtrlBack;
extern const tv_ushort tv_kbShiftTab;
extern const tv_ushort tv_kbTab;
extern const tv_ushort tv_kbAltQ;
extern const tv_ushort tv_kbAltW;
extern const tv_ushort tv_kbAltE;
extern const tv_ushort tv_kbAltR;
extern const tv_ushort tv_kbAltT;
extern const tv_ushort tv_kbAltY;
extern const tv_ushort tv_kbAltU;
extern const tv_ushort tv_kbAltI;
extern const tv_ushort tv_kbAltO;
extern const tv_ushort tv_kbAltP;
extern const tv_ushort tv_kbCtrlEnter;
extern const tv_ushort tv_kbEnter;
extern const tv_ushort tv_kbAltA;
extern const tv_ushort tv_kbAltS;
extern const tv_ushort tv_kbAltD;
extern const tv_ushort tv_kbAltF;
extern const tv_ushort tv_kbAltG;
extern const tv_ushort tv_kbAltH;
extern const tv_ushort tv_kbAltJ;
extern const tv_ushort tv_kbAltK;
extern const tv_ushort tv_kbAltL;
extern const tv_ushort tv_kbAltZ;
extern const tv_ushort tv_kbAltX;
extern const tv_ushort tv_kbAltC;
extern const tv_ushort tv_kbAltV;
extern const tv_ushort tv_kbAltB;
extern const tv_ushort tv_kbAltN;
extern const tv_ushort tv_kbAltM;
extern const tv_ushort tv_kbF1;
extern const tv_ushort tv_kbF2;
extern const tv_ushort tv_kbF3;
extern const tv_ushort tv_kbF4;
extern const tv_ushort tv_kbF5;
extern const tv_ushort tv_kbF6;
extern const tv_ushort tv_kbF7;
extern const tv_ushort tv_kbF8;
extern const tv_ushort tv_kbF9;
extern const tv_ushort tv_kbF10;
extern const tv_ushort tv_kbHome;
extern const tv_ushort tv_kbUp;
extern const tv_ushort tv_kbPgUp;
extern const tv_ushort tv_kbGrayMinus;
extern const tv_ushort tv_kbLeft;
extern const tv_ushort tv_kbRight;
extern const tv_ushort tv_kbGrayPlus;
extern const tv_ushort tv_kbEnd;
extern const tv_ushort tv_kbDown;
extern const tv_ushort tv_kbPgDn;
extern const tv_ushort tv_kbIns;
extern const tv_ushort tv_kbDel;
extern const tv_ushort tv_kbShiftF1;
extern const tv_ushort tv_kbShiftF2;
extern const tv_ushort tv_kbShiftF3;
extern const tv_ushort tv_kbShiftF4;
extern const tv_ushort tv_kbShiftF5;
extern const tv_ushort tv_kbShiftF6;
extern const tv_ushort tv_kbShiftF7;
extern const tv_ushort tv_kbShiftF8;
extern const tv_ushort tv_kbShiftF9;
extern const tv_ushort tv_kbShiftF10;
extern const tv_ushort tv_kbCtrlF1;
extern const tv_ushort tv_kbCtrlF2;
extern const tv_ushort tv_kbCtrlF3;
extern const tv_ushort tv_kbCtrlF4;
extern const tv_ushort tv_kbCtrlF5;
extern const tv_ushort tv_kbCtrlF6;
extern const tv_ushort tv_kbCtrlF7;
extern const tv_ushort tv_kbCtrlF8;
extern const tv_ushort tv_kbCtrlF9;
extern const tv_ushort tv_kbCtrlF10;
extern const tv_ushort tv_kbAltF1;
extern const tv_ushort tv_kbAltF2;
extern const tv_ushort tv_kbAltF3;
extern const tv_ushort tv_kbAltF4;
extern const tv_ushort tv_kbAltF5;
extern const tv_ushort tv_kbAltF6;
extern const tv_ushort tv_kbAltF7;
extern const tv_ushort tv_kbAltF8;
extern const tv_ushort tv_kbAltF9;
extern const tv_ushort tv_kbAltF10;
extern const tv_ushort tv_kbCtrlPrtSc;
extern const tv_ushort tv_kbCtrlLeft;
extern const tv_ushort tv_kbCtrlRight;
extern const tv_ushort tv_kbCtrlEnd;
extern const tv_ushort tv_kbCtrlPgDn;
extern const tv_ushort tv_kbCtrlHome;
extern const tv_ushort tv_kbAlt1;
extern const tv_ushort tv_kbAlt2;
extern const tv_ushort tv_kbAlt3;
extern const tv_ushort tv_kbAlt4;
extern const tv_ushort tv_kbAlt5;
extern const tv_ushort tv_kbAlt6;
extern const tv_ushort tv_kbAlt7;
extern const tv_ushort tv_kbAlt8;
extern const tv_ushort tv_kbAlt9;
extern const tv_ushort tv_kbAlt0;
extern const tv_ushort tv_kbAltMinus;
extern const tv_ushort tv_kbAltEqual;
extern const tv_ushort tv_kbCtrlPgUp;
extern const tv_ushort tv_kbNoKey;

// Additional extended key codes
extern const tv_ushort tv_kbAltEsc;
extern const tv_ushort tv_kbAltBack;
extern const tv_ushort tv_kbF11;
extern const tv_ushort tv_kbF12;
extern const tv_ushort tv_kbShiftF11;
extern const tv_ushort tv_kbShiftF12;
extern const tv_ushort tv_kbCtrlF11;
extern const tv_ushort tv_kbCtrlF12;
extern const tv_ushort tv_kbAltF11;
extern const tv_ushort tv_kbAltF12;
extern const tv_ushort tv_kbCtrlUp;
extern const tv_ushort tv_kbCtrlDown;
extern const tv_ushort tv_kbCtrlTab;
extern const tv_ushort tv_kbAltHome;
extern const tv_ushort tv_kbAltUp;
extern const tv_ushort tv_kbAltPgUp;
extern const tv_ushort tv_kbAltLeft;
extern const tv_ushort tv_kbAltRight;
extern const tv_ushort tv_kbAltEnd;
extern const tv_ushort tv_kbAltDown;
extern const tv_ushort tv_kbAltPgDn;
extern const tv_ushort tv_kbAltIns;
extern const tv_ushort tv_kbAltDel;
extern const tv_ushort tv_kbAltTab;
extern const tv_ushort tv_kbAltEnter;

//// Keyboard state and shift masks
//
// The following constants can be used when examining the 'controlKeyState'
// field of an 'evKeyDown' event record.

extern const tv_ushort tv_kbLeftShift;
extern const tv_ushort tv_kbRightShift;
extern const tv_ushort tv_kbShift;
extern const tv_ushort tv_kbLeftCtrl;
extern const tv_ushort tv_kbRightCtrl;
extern const tv_ushort tv_kbCtrlShift;
extern const tv_ushort tv_kbLeftAlt;
extern const tv_ushort tv_kbRightAlt;
extern const tv_ushort tv_kbAltShift;
extern const tv_ushort tv_kbScrollState;
extern const tv_ushort tv_kbNumState;
extern const tv_ushort tv_kbCapsState;
extern const tv_ushort tv_kbInsState;
extern const tv_ushort tv_kbPaste;

#if defined(__FLAT__)
extern const tv_ushort tv_kbEnhanced;
#endif

//// TKey class wrapper
//
// This provides C wrappers for the TKey class which allows defining
// new key combinations by specifying a key code and a mask of key modifiers.

typedef struct tv_TKey tv_TKey;

/* Create a new TKey with default values (code=0, mods=0) */
tv_TKey* tv_tkey_create_default(void);

/* Create a new TKey with specified key code and shift state */
tv_TKey* tv_tkey_create(tv_ushort key_code, tv_ushort shift_state);

/* Destroy a TKey instance */
void tv_tkey_destroy(tv_TKey* key);

/* Get the key code from a TKey */
tv_ushort tv_tkey_get_code(const tv_TKey* key);

/* Get the modifiers from a TKey */
tv_ushort tv_tkey_get_mods(const tv_TKey* key);

/* Set the key code in a TKey */
void tv_tkey_set_code(tv_TKey* key, tv_ushort code);

/* Set the modifiers in a TKey */
void tv_tkey_set_mods(tv_TKey* key, tv_ushort mods);

/* Compare two TKey instances for equality */
tv_bool tv_tkey_equals(const tv_TKey* a, const tv_TKey* b);

/* Compare two TKey instances for inequality */
tv_bool tv_tkey_not_equals(const tv_TKey* a, const tv_TKey* b);

#ifdef __cplusplus
}
#endif

#endif // CVISION_CTKEYS_H
