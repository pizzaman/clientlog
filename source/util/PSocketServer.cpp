//
//  PSocketServer.cpp
//  testWxwdigets
//
//  Created by pizzaman on 15/6/18.
//  Copyright (c) 2015年 pizzaman. All rights reserved.
//

#include "PSocketServer.h"
#include "wx/sckaddr.h"


wxBEGIN_EVENT_TABLE(PSocketServer, wxWindow)
EVT_SOCKET(SERVER_ID,  PSocketServer::OnServerEvent)
EVT_SOCKET(SOCKET_ID,  PSocketServer::OnSocketEvent)
wxEND_EVENT_TABLE()


PSocketServer::PSocketServer(wxWindow *parent, const  wxWindowID id,const wxPoint& pos,const wxSize& size):wxWindow(parent,id)
{
    text = new wxTextCtrl(this,wxID_ANY,"",pos,size,wxTE_MULTILINE|wxTE_READONLY);
    delete wxLog::SetActiveTarget(new wxLogTextCtrl(text));
}

PSocketServer::~PSocketServer()
{
    
}

void PSocketServer::start()
{
    wxIPV4address addr;
    
    addr.Service(3000);
    socketServer = new wxSocketServer(addr);
    if (! socketServer->Ok())
    {
        this->stop();
        wxLogMessage("Could not listen at the specified port !");
        return;
    }
    else
    {
         wxLogMessage("Log Server was listen");
    }
    socketServer->SetEventHandler(*this, SERVER_ID);
    socketServer->SetNotify(wxSOCKET_CONNECTION_FLAG);
    socketServer->Notify(true);
}

void PSocketServer::OnServerEvent(wxSocketEvent &event)
{
    wxSocketBase *sock = socketServer->Accept(false);
    sock->SetEventHandler(*this,SOCKET_ID);
    sock->SetNotify(wxSOCKET_INPUT_FLAG|wxSOCKET_LOST_FLAG);
    sock->Notify(true);
}

void PSocketServer::OnSocketEvent(wxSocketEvent &event)
{
    wxCharBuffer buf(32*1024);
    wxSocketBase *sock = event.GetSocket();
    switch (event.GetSocketEvent()) {
        case wxSOCKET_INPUT:
            sock->Read(buf.data(), 32*1024);
            sock->Write(buf, 32*1024);
            wxLogMessage(buf);
            text->AppendText(buf);
            text->AppendText("\n");
//            sock->Destroy();
            break;
        case wxSOCKET_LOST:
            wxLogMessage("socket lost!");
            sock->Destroy();
            break;
            
        default:
            break;
    }
}

void PSocketServer::stop()
{
    if (socketServer != NULL) {
        socketServer->Destroy();
        socketServer = NULL;
    }
}

