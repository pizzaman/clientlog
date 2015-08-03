//
//  CodeEditor.cpp
//  testWxwdigets
//
//  Created by pizzaman on 15/4/12.
//  Copyright (c) 2015年 pizzaman. All rights reserved.
//

#include "CodeEditor.h"
#include "wx/wx.h"
#include "wx/stc/stc.h"

enum
{
    MARGIN_LINE_NUMBERS,
    MARGIN_FOLD
};

const char* source = "<a>\n"
"<b foo=\"y\">\n"
"<c>\n"
"<d bar=\"x\">\n"
"<e>\n"
"<f>\n"
"<g foobar=\"z\">\n"
"<h>\n"
"<i>\n"
"<j foo=\"w\">\n";

CodeEditor::CodeEditor(wxWindow *parent, const  wxWindowID id):wxWindow(parent,id)
{
    
}

CodeEditor::~CodeEditor()
{
    
}

void CodeEditor::initComponent()
{
    textctrl = new wxStyledTextCtrl(this,wxID_ANY);
    textctrl->StyleClearAll();
    textctrl->SetLexer(wxSTC_LEX_CPP);
    
    textctrl->SetMarginWidth (MARGIN_LINE_NUMBERS, 50);
    textctrl->StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour (75, 75, 75) );
    textctrl->StyleSetBackground (wxSTC_STYLE_LINENUMBER, wxColour (220, 220, 220));
    textctrl->SetMarginType (MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);
    
    
    // ---- Enable code folding
    textctrl->SetMarginType (MARGIN_FOLD, wxSTC_MARGIN_SYMBOL);
    textctrl->SetMarginWidth(MARGIN_FOLD, 15);
    textctrl->SetMarginMask (MARGIN_FOLD, wxSTC_MASK_FOLDERS);
    textctrl->StyleSetBackground(MARGIN_FOLD, wxColor(200, 200, 200) );
    textctrl->SetMarginSensitive(MARGIN_FOLD, true);
    
    // Properties found from http://www.scintilla.org/SciTEDoc.html
    textctrl->SetProperty (wxT("fold"),         wxT("1") );
    textctrl->SetProperty (wxT("fold.comment"), wxT("1") );
    textctrl->SetProperty (wxT("fold.compact"), wxT("1") );
    
    wxColor grey( 100, 100, 100 );
    textctrl->MarkerDefine (wxSTC_MARKNUM_FOLDER, wxSTC_MARK_ARROW );
    textctrl->MarkerSetForeground (wxSTC_MARKNUM_FOLDER, grey);
    textctrl->MarkerSetBackground (wxSTC_MARKNUM_FOLDER, grey);
    
    textctrl->MarkerDefine (wxSTC_MARKNUM_FOLDEROPEN,    wxSTC_MARK_ARROWDOWN);
    textctrl->MarkerSetForeground (wxSTC_MARKNUM_FOLDEROPEN, grey);
    textctrl->MarkerSetBackground (wxSTC_MARKNUM_FOLDEROPEN, grey);
    
    textctrl->MarkerDefine (wxSTC_MARKNUM_FOLDERSUB,     wxSTC_MARK_EMPTY);
    textctrl->MarkerSetForeground (wxSTC_MARKNUM_FOLDERSUB, grey);
    textctrl->MarkerSetBackground (wxSTC_MARKNUM_FOLDERSUB, grey);
    
    textctrl->MarkerDefine (wxSTC_MARKNUM_FOLDEREND,     wxSTC_MARK_ARROW);
    textctrl->MarkerSetForeground (wxSTC_MARKNUM_FOLDEREND, grey);
    textctrl->MarkerSetBackground (wxSTC_MARKNUM_FOLDEREND, _T("WHITE"));
    
    textctrl->MarkerDefine (wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN);
    textctrl->MarkerSetForeground (wxSTC_MARKNUM_FOLDEROPENMID, grey);
    textctrl->MarkerSetBackground (wxSTC_MARKNUM_FOLDEROPENMID, _T("WHITE"));
    
    textctrl->MarkerDefine (wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY);
    textctrl->MarkerSetForeground (wxSTC_MARKNUM_FOLDERMIDTAIL, grey);
    textctrl->MarkerSetBackground (wxSTC_MARKNUM_FOLDERMIDTAIL, grey);
    
    textctrl->MarkerDefine (wxSTC_MARKNUM_FOLDERTAIL,    wxSTC_MARK_EMPTY);
    textctrl->MarkerSetForeground (wxSTC_MARKNUM_FOLDERTAIL, grey);
    textctrl->MarkerSetBackground (wxSTC_MARKNUM_FOLDERTAIL, grey);
    // ---- End of code folding part
    
    textctrl->SetWrapMode (wxSTC_WRAP_WORD); // other choice is wxSCI_WRAP_NONE
    
    textctrl->SetText(source);
    
    textctrl->StyleSetForeground (wxSTC_C_STRING,            wxColour(150,0,0));
    textctrl->StyleSetForeground (wxSTC_C_PREPROCESSOR,      wxColour(165,105,0));
    textctrl->StyleSetForeground (wxSTC_C_IDENTIFIER,        wxColour(40,0,60));
    textctrl->StyleSetForeground (wxSTC_C_NUMBER,            wxColour(0,150,0));
    textctrl->StyleSetForeground (wxSTC_C_CHARACTER,         wxColour(150,0,0));
    textctrl->StyleSetForeground (wxSTC_C_WORD,              wxColour(0,0,150));
    textctrl->StyleSetForeground (wxSTC_C_WORD2,             wxColour(0,150,0));
    textctrl->StyleSetForeground (wxSTC_C_COMMENT,           wxColour(150,150,150));
    textctrl->StyleSetForeground (wxSTC_C_COMMENTLINE,       wxColour(150,150,150));
    textctrl->StyleSetForeground (wxSTC_C_COMMENTDOC,        wxColour(150,150,150));
    textctrl->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORD, wxColour(0,0,200));
    textctrl->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(0,0,200));
    textctrl->StyleSetBold(wxSTC_C_WORD, true);
    textctrl->StyleSetBold(wxSTC_C_WORD2, true);
    textctrl->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);
    
    // a sample list of keywords, I haven't included them all to keep it short...
    textctrl->SetKeyWords(0, wxT("return for while break continue"));
    textctrl->SetKeyWords(1, wxT("const int float void char double"));
    
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(textctrl, 1, wxEXPAND);
    SetSizer(sizer);
    
    textctrl->Connect(wxEVT_STC_MARGINCLICK, wxStyledTextEventHandler(CodeEditor::onFolderClick), NULL, this);
}

/** Event callback when a margin is clicked, used here for code folding */
void CodeEditor::onFolderClick(wxStyledTextEvent &event)
{
    if (event.GetMargin() == MARGIN_FOLD)
    {
        int lineClick = textctrl->LineFromPosition(event.GetPosition());
        int levelClick = textctrl->GetFoldLevel(lineClick);
        
        if ((levelClick & wxSTC_FOLDLEVELHEADERFLAG) > 0)
        {
            textctrl->ToggleFold(lineClick);
        }
    }
}

