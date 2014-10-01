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
#define SNAPSHOT_LOAD   true

class Snapshot
{
public:
    Snapshot() {}
    void LoadGenesisBlock(CBlock& genesis);
    void HashGenesisBlock(CBlock& block, bool verbose);
    void CoinbaseTx(CBlock& genesis);
    CTransaction GenesisTx(CBlock& genesis,
                           const char* btcHash160,
                           const char* btcBalance);
    CTransaction ClaimTx(const char* btcSig,
                         const char* btcHash160);
};

#endif // SIDECOIN_SNAPSHOT_H
