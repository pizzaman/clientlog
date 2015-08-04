//
//  ConfigFileUtil.h
//  testWxwdigets
//
//  Created by pizzaman on 15/4/24.
//  Copyright (c) 2015年 pizzaman. All rights reserved.
//

#ifndef __testWxwdigets__ConfigFileUtil__
#define __testWxwdigets__ConfigFileUtil__

#include <stdio.h>

enum configType{
    wxConfigIniFile,
    wxConfigXmlFile,
    wxConfigJsonFile
};

class ConfigFileUtil
{
public:
    ~ConfigFileUtil();
    static ConfigFileUtil* getInstance();
    void init();
    void syncLoadConfig(wxString fileName, configType wxConfigIniFile);
    int getPort();
    void setPort(int value);
private:
    ConfigFileUtil();
    static ConfigFileUtil *m_instance;
    wxString language;
    int port;
};



class FileUtil
{
public:
    static void readIniFile(wxString path);
    static wxString getWorkSpacePath();
    static wxString getResourcePath();
    
};


#endif /* defined(__testWxwdigets__ConfigFileUtil__) */
