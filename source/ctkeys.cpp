//
// Created by Jason Lee on 2/2/26.
//

/* TKeys helper functions and constants */

#include "cvision/ctkeys.h"
#include "cvision/ctypes.h"
#include "cvision/cvision.h"
#include <tvision/tv.h>
#include <tvision/tkeys.h>

extern "C" {

//// Key code constants

// Control keys
const tv_ushort tv_kbCtrlA = kbCtrlA;
const tv_ushort tv_kbCtrlB = kbCtrlB;
const tv_ushort tv_kbCtrlC = kbCtrlC;
const tv_ushort tv_kbCtrlD = kbCtrlD;
const tv_ushort tv_kbCtrlE = kbCtrlE;
const tv_ushort tv_kbCtrlF = kbCtrlF;
const tv_ushort tv_kbCtrlG = kbCtrlG;
const tv_ushort tv_kbCtrlH = kbCtrlH;
const tv_ushort tv_kbCtrlI = kbCtrlI;
const tv_ushort tv_kbCtrlJ = kbCtrlJ;
const tv_ushort tv_kbCtrlK = kbCtrlK;
const tv_ushort tv_kbCtrlL = kbCtrlL;
const tv_ushort tv_kbCtrlM = kbCtrlM;
const tv_ushort tv_kbCtrlN = kbCtrlN;
const tv_ushort tv_kbCtrlO = kbCtrlO;
const tv_ushort tv_kbCtrlP = kbCtrlP;
const tv_ushort tv_kbCtrlQ = kbCtrlQ;
const tv_ushort tv_kbCtrlR = kbCtrlR;
const tv_ushort tv_kbCtrlS = kbCtrlS;
const tv_ushort tv_kbCtrlT = kbCtrlT;
const tv_ushort tv_kbCtrlU = kbCtrlU;
const tv_ushort tv_kbCtrlV = kbCtrlV;
const tv_ushort tv_kbCtrlW = kbCtrlW;
const tv_ushort tv_kbCtrlX = kbCtrlX;
const tv_ushort tv_kbCtrlY = kbCtrlY;
const tv_ushort tv_kbCtrlZ = kbCtrlZ;

// Extended key codes
const tv_ushort tv_kbEsc = kbEsc;
const tv_ushort tv_kbAltSpace = kbAltSpace;
const tv_ushort tv_kbCtrlIns = kbCtrlIns;
const tv_ushort tv_kbShiftIns = kbShiftIns;
const tv_ushort tv_kbCtrlDel = kbCtrlDel;
const tv_ushort tv_kbShiftDel = kbShiftDel;
const tv_ushort tv_kbBack = kbBack;
const tv_ushort tv_kbCtrlBack = kbCtrlBack;
const tv_ushort tv_kbShiftTab = kbShiftTab;
const tv_ushort tv_kbTab = kbTab;
const tv_ushort tv_kbAltQ = kbAltQ;
const tv_ushort tv_kbAltW = kbAltW;
const tv_ushort tv_kbAltE = kbAltE;
const tv_ushort tv_kbAltR = kbAltR;
const tv_ushort tv_kbAltT = kbAltT;
const tv_ushort tv_kbAltY = kbAltY;
const tv_ushort tv_kbAltU = kbAltU;
const tv_ushort tv_kbAltI = kbAltI;
const tv_ushort tv_kbAltO = kbAltO;
const tv_ushort tv_kbAltP = kbAltP;
const tv_ushort tv_kbCtrlEnter = kbCtrlEnter;
const tv_ushort tv_kbEnter = kbEnter;
const tv_ushort tv_kbAltA = kbAltA;
const tv_ushort tv_kbAltS = kbAltS;
const tv_ushort tv_kbAltD = kbAltD;
const tv_ushort tv_kbAltF = kbAltF;
const tv_ushort tv_kbAltG = kbAltG;
const tv_ushort tv_kbAltH = kbAltH;
const tv_ushort tv_kbAltJ = kbAltJ;
const tv_ushort tv_kbAltK = kbAltK;
const tv_ushort tv_kbAltL = kbAltL;
const tv_ushort tv_kbAltZ = kbAltZ;
const tv_ushort tv_kbAltX = kbAltX;
const tv_ushort tv_kbAltC = kbAltC;
const tv_ushort tv_kbAltV = kbAltV;
const tv_ushort tv_kbAltB = kbAltB;
const tv_ushort tv_kbAltN = kbAltN;
const tv_ushort tv_kbAltM = kbAltM;
const tv_ushort tv_kbF1 = kbF1;
const tv_ushort tv_kbF2 = kbF2;
const tv_ushort tv_kbF3 = kbF3;
const tv_ushort tv_kbF4 = kbF4;
const tv_ushort tv_kbF5 = kbF5;
const tv_ushort tv_kbF6 = kbF6;
const tv_ushort tv_kbF7 = kbF7;
const tv_ushort tv_kbF8 = kbF8;
const tv_ushort tv_kbF9 = kbF9;
const tv_ushort tv_kbF10 = kbF10;
const tv_ushort tv_kbHome = kbHome;
const tv_ushort tv_kbUp = kbUp;
const tv_ushort tv_kbPgUp = kbPgUp;
const tv_ushort tv_kbGrayMinus = kbGrayMinus;
const tv_ushort tv_kbLeft = kbLeft;
const tv_ushort tv_kbRight = kbRight;
const tv_ushort tv_kbGrayPlus = kbGrayPlus;
const tv_ushort tv_kbEnd = kbEnd;
const tv_ushort tv_kbDown = kbDown;
const tv_ushort tv_kbPgDn = kbPgDn;
const tv_ushort tv_kbIns = kbIns;
const tv_ushort tv_kbDel = kbDel;
const tv_ushort tv_kbShiftF1 = kbShiftF1;
const tv_ushort tv_kbShiftF2 = kbShiftF2;
const tv_ushort tv_kbShiftF3 = kbShiftF3;
const tv_ushort tv_kbShiftF4 = kbShiftF4;
const tv_ushort tv_kbShiftF5 = kbShiftF5;
const tv_ushort tv_kbShiftF6 = kbShiftF6;
const tv_ushort tv_kbShiftF7 = kbShiftF7;
const tv_ushort tv_kbShiftF8 = kbShiftF8;
const tv_ushort tv_kbShiftF9 = kbShiftF9;
const tv_ushort tv_kbShiftF10 = kbShiftF10;
const tv_ushort tv_kbCtrlF1 = kbCtrlF1;
const tv_ushort tv_kbCtrlF2 = kbCtrlF2;
const tv_ushort tv_kbCtrlF3 = kbCtrlF3;
const tv_ushort tv_kbCtrlF4 = kbCtrlF4;
const tv_ushort tv_kbCtrlF5 = kbCtrlF5;
const tv_ushort tv_kbCtrlF6 = kbCtrlF6;
const tv_ushort tv_kbCtrlF7 = kbCtrlF7;
const tv_ushort tv_kbCtrlF8 = kbCtrlF8;
const tv_ushort tv_kbCtrlF9 = kbCtrlF9;
const tv_ushort tv_kbCtrlF10 = kbCtrlF10;
const tv_ushort tv_kbAltF1 = kbAltF1;
const tv_ushort tv_kbAltF2 = kbAltF2;
const tv_ushort tv_kbAltF3 = kbAltF3;
const tv_ushort tv_kbAltF4 = kbAltF4;
const tv_ushort tv_kbAltF5 = kbAltF5;
const tv_ushort tv_kbAltF6 = kbAltF6;
const tv_ushort tv_kbAltF7 = kbAltF7;
const tv_ushort tv_kbAltF8 = kbAltF8;
const tv_ushort tv_kbAltF9 = kbAltF9;
const tv_ushort tv_kbAltF10 = kbAltF10;
const tv_ushort tv_kbCtrlPrtSc = kbCtrlPrtSc;
const tv_ushort tv_kbCtrlLeft = kbCtrlLeft;
const tv_ushort tv_kbCtrlRight = kbCtrlRight;
const tv_ushort tv_kbCtrlEnd = kbCtrlEnd;
const tv_ushort tv_kbCtrlPgDn = kbCtrlPgDn;
const tv_ushort tv_kbCtrlHome = kbCtrlHome;
const tv_ushort tv_kbAlt1 = kbAlt1;
const tv_ushort tv_kbAlt2 = kbAlt2;
const tv_ushort tv_kbAlt3 = kbAlt3;
const tv_ushort tv_kbAlt4 = kbAlt4;
const tv_ushort tv_kbAlt5 = kbAlt5;
const tv_ushort tv_kbAlt6 = kbAlt6;
const tv_ushort tv_kbAlt7 = kbAlt7;
const tv_ushort tv_kbAlt8 = kbAlt8;
const tv_ushort tv_kbAlt9 = kbAlt9;
const tv_ushort tv_kbAlt0 = kbAlt0;
const tv_ushort tv_kbAltMinus = kbAltMinus;
const tv_ushort tv_kbAltEqual = kbAltEqual;
const tv_ushort tv_kbCtrlPgUp = kbCtrlPgUp;
const tv_ushort tv_kbNoKey = kbNoKey;

// Additional extended key codes
const tv_ushort tv_kbAltEsc = kbAltEsc;
const tv_ushort tv_kbAltBack = kbAltBack;
const tv_ushort tv_kbF11 = kbF11;
const tv_ushort tv_kbF12 = kbF12;
const tv_ushort tv_kbShiftF11 = kbShiftF11;
const tv_ushort tv_kbShiftF12 = kbShiftF12;
const tv_ushort tv_kbCtrlF11 = kbCtrlF11;
const tv_ushort tv_kbCtrlF12 = kbCtrlF12;
const tv_ushort tv_kbAltF11 = kbAltF11;
const tv_ushort tv_kbAltF12 = kbAltF12;
const tv_ushort tv_kbCtrlUp = kbCtrlUp;
const tv_ushort tv_kbCtrlDown = kbCtrlDown;
const tv_ushort tv_kbCtrlTab = kbCtrlTab;
const tv_ushort tv_kbAltHome = kbAltHome;
const tv_ushort tv_kbAltUp = kbAltUp;
const tv_ushort tv_kbAltPgUp = kbAltPgUp;
const tv_ushort tv_kbAltLeft = kbAltLeft;
const tv_ushort tv_kbAltRight = kbAltRight;
const tv_ushort tv_kbAltEnd = kbAltEnd;
const tv_ushort tv_kbAltDown = kbAltDown;
const tv_ushort tv_kbAltPgDn = kbAltPgDn;
const tv_ushort tv_kbAltIns = kbAltIns;
const tv_ushort tv_kbAltDel = kbAltDel;
const tv_ushort tv_kbAltTab = kbAltTab;
const tv_ushort tv_kbAltEnter = kbAltEnter;

//// Keyboard state and shift mask constants

const tv_ushort tv_kbLeftShift = kbLeftShift;
const tv_ushort tv_kbRightShift = kbRightShift;
const tv_ushort tv_kbShift = kbShift;
const tv_ushort tv_kbLeftCtrl = kbLeftCtrl;
const tv_ushort tv_kbRightCtrl = kbRightCtrl;
const tv_ushort tv_kbCtrlShift = kbCtrlShift;
const tv_ushort tv_kbLeftAlt = kbLeftAlt;
const tv_ushort tv_kbRightAlt = kbRightAlt;
const tv_ushort tv_kbAltShift = kbAltShift;
const tv_ushort tv_kbScrollState = kbScrollState;
const tv_ushort tv_kbNumState = kbNumState;
const tv_ushort tv_kbCapsState = kbCapsState;
const tv_ushort tv_kbInsState = kbInsState;
const tv_ushort tv_kbPaste = kbPaste;

#if defined(__FLAT__)
const tv_ushort tv_kbEnhanced = ENHANCED_KEY;
#endif

//// TKey class wrapper functions

tv_TKey* tv_tkey_create_default(void) {
    return reinterpret_cast<tv_TKey*>(new TKey());
}

tv_TKey* tv_tkey_create(tv_ushort key_code, tv_ushort shift_state) {
    return reinterpret_cast<tv_TKey*>(new TKey(key_code, shift_state));
}

void tv_tkey_destroy(tv_TKey* key) {
    if (key) {
        delete reinterpret_cast<TKey*>(key);
    }
}

tv_ushort tv_tkey_get_code(const tv_TKey* key) {
    if (key) {
        return reinterpret_cast<const TKey*>(key)->code;
    }
    return 0;
}

tv_ushort tv_tkey_get_mods(const tv_TKey* key) {
    if (key) {
        return reinterpret_cast<const TKey*>(key)->mods;
    }
    return 0;
}

void tv_tkey_set_code(tv_TKey* key, tv_ushort code) {
    if (key) {
        reinterpret_cast<TKey*>(key)->code = code;
    }
}

void tv_tkey_set_mods(tv_TKey* key, tv_ushort mods) {
    if (key) {
        reinterpret_cast<TKey*>(key)->mods = mods;
    }
}

tv_bool tv_tkey_equals(const tv_TKey* a, const tv_TKey* b) {
    if (a && b) {
        return (*reinterpret_cast<const TKey*>(a) == *reinterpret_cast<const TKey*>(b)) ? TV_TRUE : TV_FALSE;
    }
    return TV_FALSE;
}

tv_bool tv_tkey_not_equals(const tv_TKey* a, const tv_TKey* b) {
    if (a && b) {
        return (*reinterpret_cast<const TKey*>(a) != *reinterpret_cast<const TKey*>(b)) ? TV_TRUE : TV_FALSE;
    }
    return TV_TRUE;
}

} // extern "C"
