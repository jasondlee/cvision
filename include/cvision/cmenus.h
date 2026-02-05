//
// Created by Jason Lee on 2/2/26.
//

#ifndef TVISION_CMENUS_H
#define TVISION_CMENUS_H

#ifdef __cplusplus
extern "C" {
#endif

    /* Menu item helper functions */
    tv_MenuItem *tv_menuitem_create(const char *name, tv_ushort command, tv_ushort key_code, tv_ushort *help_ctx,
                                    const char *p, tv_MenuItem *next);

    tv_SubMenu *tv_submenu_create(const char *name, tv_ushort key_code);

    tv_SubMenu *tv_submenu_add_next(tv_SubMenu *submenu, tv_SubMenu *next);

    tv_SubMenu *tv_submenu_add_menuitem(tv_SubMenu *submenu, tv_MenuItem *item);

    /* TMenuBar functions */
    tv_MenuBar *tv_menubar_create(tv_Rect bounds, tv_SubMenu *menu);
    void tv_menubar_destroy(tv_MenuBar *menubar);


    /* Status item helper functions */
    tv_StatusItem *tv_statusitem_create(const char *text, tv_ushort key_code, tv_ushort command, tv_StatusItem *next);
    void tv_statusitem_destroy(tv_StatusItem *item);

    /* TStatusLine functions */
    tv_StatusLine *tv_statusline_create(tv_Rect bounds, tv_StatusItem *items);
    void tv_statusline_destroy(tv_StatusLine *statusline);
#ifdef __cplusplus
}
#endif

#endif //TVISION_CMENUS_H