//
// Created by Jason Lee on 2/2/26.
//

#ifndef TVISION_CVISION_EXAMPLE_H
#define TVISION_CVISION_EXAMPLE_H

#include "cvision/ctypes.h"

tv_Application *app;

/* Command constants */
const ushort
        cmNewWindow = 100,
        cmListDemo = 101,
        cmEditorDemo = 102,
        cmAbout = 103;
const int
        cmChangeDrct = 102;

void handleEvent(tv_Event event);
tv_MenuBar *createMenuBar(tv_Rect r);
tv_StatusLine *createStatusLine(tv_Rect r);
void fileNew();
void fileOpen();

#endif //TVISION_CVISION_EXAMPLE_H