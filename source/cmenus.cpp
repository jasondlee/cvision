//
// Created by Jason Lee on 2/1/26.
//

/* Menu item helper functions */

#include "cvision/ctypes.h"
#include "cvision/cvision.h"
#include <tvision/tv.h>

extern "C" {
    tv_MenuItem *tv_menuitem_create(const char *name, tv_ushort command, tv_ushort key_code,
                                    tv_ushort help_ctx, const char *p, tv_MenuItem *next) {
        return reinterpret_cast<tv_MenuItem *>(
            new TMenuItem(name, command, key_code, help_ctx, p, reinterpret_cast<TMenuItem *>(next))
        );
    }

    tv_SubMenu *tv_submenu_create(const char *name, tv_ushort key_code) {
        return reinterpret_cast<tv_SubMenu *>(new TSubMenu(name, key_code));
    }

    tv_SubMenu *tv_submenu_add_next(tv_SubMenu *submenu, tv_SubMenu *next) {
        *reinterpret_cast<TSubMenu *>(submenu) + *reinterpret_cast<TSubMenu *>(next);
        return submenu;
    }

    tv_SubMenu *tv_submenu_add_menuitem(tv_SubMenu *submenu, tv_MenuItem *item) {
        *reinterpret_cast<TSubMenu *>(submenu) + *reinterpret_cast<TMenuItem *>(item);
        return submenu;
    }

    /* TMenuBar functions */
    tv_MenuBar *tv_menubar_create(tv_Rect bounds, tv_SubMenu *menu) {
        TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
        TMenu *tmenu = new TMenu(*reinterpret_cast<TSubMenu *>(menu));
        return reinterpret_cast<tv_MenuBar *>(new TMenuBar(rect, tmenu));
    }

    void tv_menubar_destroy(tv_MenuBar *menubar) {
        if (menubar) {
            TObject::destroy(reinterpret_cast<TMenuBar *>(menubar));
        }
    }

    /* Status item helper functions */

    tv_StatusItem* tv_statusitem_create(const char* text, tv_ushort key_code, tv_ushort command,
                                         tv_StatusItem* next) {
        return reinterpret_cast<tv_StatusItem*>(
            new TStatusItem(text, key_code, command, reinterpret_cast<TStatusItem*>(next))
        );
    }

    void tv_statusitem_destroy(tv_StatusItem* item) {
        if (item) {
            delete reinterpret_cast<TStatusItem*>(item);
        }
    }

    /* TStatusLine functions */

    tv_StatusLine* tv_statusline_create(tv_Rect bounds, tv_StatusItem* items) {
        TRect rect(bounds.a.x, bounds.a.y, bounds.b.x, bounds.b.y);
        TStatusDef* def = new TStatusDef(0, 0xFFFF, reinterpret_cast<TStatusItem*>(items));
        return reinterpret_cast<tv_StatusLine*>(new TStatusLine(rect, *def));
    }

    void tv_statusline_destroy(tv_StatusLine* statusline) {
        if (statusline) {
            TObject::destroy(reinterpret_cast<TStatusLine*>(statusline));
        }
    }
}
