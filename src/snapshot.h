// Copyright (c) 2014 Dyffy, Inc.
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SIDECOIN_SNAPSHOT_H
#define SIDECOIN_SNAPSHOT_H

#include "chainparams.h"
#include "core.h"
#include "util.h"
#include "main.h"
#include "sync.h"

#include <fstream>
#include <cmath>
#include <stdint.h>

// #include <utility>

// #include "rpcserver.h"
// #include "rpcclient.h"

// #include "base58.h"
// #include "json/json_spirit_writer_template.h"

#include <boost/filesystem/operations.hpp>
#include <boost/algorithm/string.hpp>

#define GENESIS_SWITCH true

namespace snapshot {

CTransaction CoinbaseTx(unsigned nBits);

void LoadGenesisBlockFile(CBlock& block);

void LoadGenesisBlock(CBlock& block);

CTransaction GenesisTx(CBlock& block,
                       const char* btcHash160,
                       const char* btcBalance);

void HashGenesisBlock(CBlock& block, bool verbose);

inline float FastLog(float val);

float Difficulty(unsigned bits);

} // snapshot

#endif // SIDECOIN_SNAPSHOT_H
