//
//  ConfigFileUtil.cpp
//  testWxwdigets
//
//  Created by pizzaman on 15/4/24.
//  Copyright (c) 2015年 pizzaman. All rights reserved.
//

#include "ConfigFileUtil.h"
#include "wx/file.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"
#include "wx/fileconf.h"
#include "wx/wfstream.h"

ConfigFileUtil::ConfigFileUtil()
{
    
}

ConfigFileUtil::~ConfigFileUtil()
{
    
}


ConfigFileUtil* ConfigFileUtil::m_instance = NULL;

ConfigFileUtil* ConfigFileUtil::getInstance()
{
    if(!m_instance)
    {
        m_instance = new ConfigFileUtil;
        m_instance->init();
    }
    return m_instance;
}

void ConfigFileUtil::init()
{
    wxFileInputStream is(FileUtil::getResourcePath()+"Resources/config/config.ini");
    wxFileConfig* config = new wxFileConfig(is);
    wxConfigBase::Set(config);
}

void ConfigFileUtil::setPort(int value)
{
    this->port = value;
}

int ConfigFileUtil::getPort()
{
    return this->port;
}

void ConfigFileUtil::syncLoadConfig(wxString fileName, configType wxConfigIniFile)
{
    
}




void FileUtil::readIniFile(wxString filename)
{
    wxString path = FileUtil::getResourcePath();
    wxString name = path + filename;
    if (!wxFile::Exists(name))
    {
        return;
    }
    wxFile file(name);
    if (!file.IsOpened()) {
        return;
    }
    
    wxFileOffset nSize = file.Length();
    if (nSize == wxInvalidOffset) {
        return;
    }

    
}


wxString FileUtil::getWorkSpacePath()
{
    wxString strAppPath ;
    wxStandardPathsBase& stdp = wxStandardPaths::Get();
    wxFileName exeFile(stdp.GetExecutablePath());
    strAppPath = exeFile.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
    
    return strAppPath ;
}

wxString FileUtil::getResourcePath()
{
    wxString strAppPath ;
    wxStandardPathsBase& stdp = wxStandardPaths::Get();
    wxFileName exeFile(stdp.GetResourcesDir());
    strAppPath = exeFile.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
    
    return strAppPath ;
}