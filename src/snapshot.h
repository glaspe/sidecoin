// Copyright (c) 2014 Dyffy, Inc.
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SIDECOIN_SNAPSHOT_H
#define SIDECOIN_SNAPSHOT_H

#include "chainparams.h"
#include "core.h"
#include "util.h"

#include <fstream>
#include <cmath>

#include <boost/filesystem/operations.hpp>

#define GENESIS_SWITCH  true
#define SNAPSHOT_LOAD   false

namespace snapshot {

CTransaction CoinbaseTx();

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
