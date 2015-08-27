//
//  MainFrame.h
//  testWxwdigets
//
//  Created by pizzaman on 15/1/25.
//  Copyright (c) 2015年 pizzaman. All rights reserved.
//

#ifndef __testWxwdigets__MainFrame__
#define __testWxwdigets__MainFrame__

#include <stdio.h>
#include "util/PSocketServer.h"
#include <wx/aui/framemanager.h>

class MainFrame:public wxFrame
{
public:
    MainFrame(const wxString& title,wxSize &size);
    void OnStartLog(wxCommandEvent& event);
    void OnStopLog(wxCommandEvent& event);
private:
    DECLARE_EVENT_TABLE();
    void createMenu();
    PSocketServer *pss;
    wxAuiManager auiMgr;
};

#endif /* defined(__testWxwdigets__MainFrame__) */
