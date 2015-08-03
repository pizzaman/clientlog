//
//  CodeEditor.h
//  testWxwdigets
//
//  Created by pizzaman on 15/4/12.
//  Copyright (c) 2015年 pizzaman. All rights reserved.
//

#ifndef __testWxwdigets__CodeEditor__
#define __testWxwdigets__CodeEditor__

#include <stdio.h>
#include "wx/stc/stc.h"

#endif /* defined(__testWxwdigets__CodeEditor__) */

class CodeEditor:public wxWindow
{
public:
    CodeEditor(wxWindow *parent, const wxWindowID id);
    ~CodeEditor();
    void initComponent();
private:
    
    void onFolderClick(wxStyledTextEvent &event);
    wxStyledTextCtrl *textctrl;
};