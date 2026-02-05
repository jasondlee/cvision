//
// Created by Jason Lee on 1/28/26.
//

#ifndef TVISION_CVISION_H
#define TVISION_CVISION_H
#include "ceditors.h"

#include "cstddlg.h"
#include "ctypes.h"
#include "csystem.h"
#include "cobjects.h"

#ifdef __cplusplus
#include <tvision/tv.h>

class TCApplication : public TApplication {
public:
    // Constructor with custom callbacks for status line, menu bar, and event handling
    TCApplication(TStatusLine * (*statusLineFunc)(TRect),
                  TMenuBar * (*menuBarFunc)(TRect),
                  void (*handleEventFunc)(TEvent));

    void handleEvent(TEvent &event) override;
    virtual ushort execDialog( TDialog *d, void *data );
    TEditWindow *openEditor( const char *fileName, Boolean visible );
private:
    void (*cHandleEvent)(TEvent);
};

extern "C" {
#endif

/* TApplication functions
 *
 * Note: tv_application_create() uses TCApplication internally, a minimal
 * subclass that exposes TApplication's protected constructor. This is
 * transparent to C wrapper users and maintains full TApplication compatibility.
 */
tv_Application *tv_application_create(tv_StatusLine *(*cStatusLine)(tv_Rect),
                                      tv_MenuBar *(*cMenuBar)(tv_Rect),
                                      void (*handleEventFunc)(tv_Event));

void tv_application_destroy(tv_Application *app);
void tv_application_run(tv_Application *app);
ushort tv_application_exec_dialog(tv_Application *app, tv_FileDialog *d, void *data);
tv_EditWindow *tv_application_open_editor(tv_Application *app, const char *fileName, tv_bool visible);

#endif //TVISION_CVISION_H

#ifdef __cplusplus
}
#endif
