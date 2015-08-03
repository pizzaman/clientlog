//
//  PSocketServer.h
//  testWxwdigets
//
//  Created by pizzaman on 15/6/18.
//  Copyright (c) 2015年 pizzaman. All rights reserved.
//

#ifndef __testWxwdigets__PSocketServer__
#define __testWxwdigets__PSocketServer__

#include "wx/socket.h"

enum
{
    // menu items
    SERVER_UDPTEST = 10,
    SERVER_WAITFORACCEPT,
    SERVER_QUIT = wxID_EXIT,
    SERVER_ABOUT = wxID_ABOUT,
    
    // id for sockets
    SERVER_ID = 100,
    SOCKET_ID
};

class PSocketServer:public wxWindow
{
public:
    PSocketServer(wxWindow *parent, const wxWindowID id,const wxPoint& pos,const wxSize& size);
    ~PSocketServer();
    void start();
    void stop();
private:
    DECLARE_EVENT_TABLE();
    wxSocketServer *socketServer;
    wxTextCtrl *text;
    void OnServerEvent(wxSocketEvent& event);
    void OnSocketEvent(wxSocketEvent& event);
};

#endif /* defined(__testWxwdigets__PSocketServer__) */
