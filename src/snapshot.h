#ifndef SIDECOIN_SNAPSHOT_H
#define SIDECOIN_SNAPSHOT_H

#include <fstream>
#include <cstdio>
#include <cmath>
#include "core.h"
#include "util.h"
#include "chainparams.h"

#define GENESIS_SWITCH false

namespace Snapshot {

const char* const SNAPSHOT_FILE = "balances/balances.txt";

CTransaction CoinbaseTx();

void LoadGenesisBlock(CBlock& block);

CTransaction GenesisTx(const char* btcHash160, const char* btcBalance);

void HashGenesisBlock(CBlock& block);

CTransaction ClaimTx(const char* btcSig, const char* btcPubKey);

inline float FastLog(float val);

float Difficulty(unsigned bits);

} // Snapshot

#endif
