#ifndef __SPINOFF_H_INCLUDED__
#define __SPINOFF_H_INCLUDED__

#include <cstdio>
#include <fstream>
#include <cstring>
#include "json/json_spirit_value.h"
// #include "rpcserver.h"

namespace Spinoff {

bool verifymessage(const json_spirit::Array&, const bool);

std::string bitcoin_signature(const std::string&, const std::string&);

bool process_claim(const std::string&, const std::string&, const std::string&);

} // Spinoff

#endif
