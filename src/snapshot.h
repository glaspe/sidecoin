// Copyright (c) 2014 Dyffy, Inc.
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SIDECOIN_SNAPSHOT_H
#define SIDECOIN_SNAPSHOT_H

#include "core.h"
#include "util.h"

#include <vector>
#include <fstream>
#include <cmath>

#include <boost/filesystem/operations.hpp>

#define GENESIS_SWITCH  true
#define SNAPSHOT_LOAD   false

class Snapshot
{
public:
    Snapshot() {}
    void LoadGenesisBlockFile(CBlock& block);
    void LoadGenesisBlock(CBlock& block);
    void HashGenesisBlock(CBlock& block, bool verbose);
    CTransaction CoinbaseTx();
    CTransaction GenesisTx(CBlock& block,
                           const char* btcHash160,
                           const char* btcBalance);
    CTransaction ClaimTx(const char* btcSig,
                         const char* btcHash160);
    inline float FastLog(float val);
    float Difficulty(unsigned bits);
};

#endif // SIDECOIN_SNAPSHOT_H
