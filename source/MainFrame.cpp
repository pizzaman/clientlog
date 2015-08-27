//
//  MainFrame.cpp
//  testWxwdigets
//
//  Created by pizzaman on 15/1/25.
//  Copyright (c) 2015年 pizzaman. All rights reserved.
//

#include "wx/aui/auibook.h"
#include "MainFrame.h"
#include "CodeEditor.h"
#include "util/ConfigFileUtil.h"
#include "util/PSocketServer.h"

enum ClientLog
{
    wxID_StartLog = 10000,
    wxID_StopLog
};


BEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(wxID_StartLog, MainFrame::OnStartLog)
EVT_MENU(wxID_StopLog, MainFrame::OnStopLog)
END_EVENT_TABLE()


MainFrame::MainFrame(const wxString &title,wxSize &size)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition,size)
{
    auiMgr.SetManagedWindow(this);
    createMenu();
    ConfigFileUtil::getInstance();
//    FileUtil::readIniFile(wxT("Resources/config/init.ini"));
    
    wxPuts(wxT("a test widgets console"));
    
//    CodeEditor *code = new CodeEditor(this,1);
//    code->initComponent();
    wxSize sz = wxSize(800, 600);
    wxAuiNotebook* ctrl = new wxAuiNotebook(this, wxID_ANY,
                                            wxDefaultPosition,
                                           sz);
    pss = new PSocketServer(ctrl,1,wxDefaultPosition,sz);
    ctrl->AddPage(pss, wxT("Error Message"));
    
    auiMgr.Update();
}

void MainFrame::createMenu()
{
    wxMenu *fileMenu = new wxMenu();
//    wxMenu *aboutMenu = new wxMenu();
//    wxMenu *starMenu = new wxMenu();
    fileMenu->Append(wxID_StartLog,wxT("&StartLog"),wxT("start server log"));
    fileMenu->Append(wxID_StopLog,wxT("&StopLog"),wxT("stop server log"));
    
    wxMenuBar *bar = new wxMenuBar();
//    bar->Append(aboutMenu, wxT("&About"));
    bar->Append(fileMenu, wxT("&File"));
    
    SetMenuBar(bar);
    CreateStatusBar(2);
}

void MainFrame::OnStartLog(wxCommandEvent &event)
{
    pss->start();
    SetStatusText("Clientlog is start to work readey to receive data");
}

void MainFrame::OnStopLog(wxCommandEvent &event)
{
    pss->stop();
    SetStatusText("");
}
