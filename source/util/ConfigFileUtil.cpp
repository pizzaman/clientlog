//
//  ConfigFileUtil.cpp
//  testWxwdigets
//
//  Created by pizzaman on 15/4/24.
//  Copyright (c) 2015年 pizzaman. All rights reserved.
//

#include "ConfigFileUtil.h"
#include <wx/file.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/fileconf.h>

ConfigFileUtil::ConfigFileUtil()
{
    
}

ConfigFileUtil::~ConfigFileUtil()
{
    
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