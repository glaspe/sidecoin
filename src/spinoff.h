#ifndef __SPINOFF_H_INCLUDED__
#define __SPINOFF_H_INCLUDED__

#include <cstdio>
#include <fstream>
#include <cstring>
#include "json/json_spirit_value.h"
// #include "rpcserver.h"

namespace Snapshot {

bool verifymessage(const json_spirit::Array& params,
                   const bool test);

std::string bitcoin_signature(const std::string& bitclaim,
                              const std::string& sideaddr);

bool claim(const std::string& bitsig,
           const std::string& bitclaim,
           const std::string& sideaddr);

} // Snapshot

#endif
