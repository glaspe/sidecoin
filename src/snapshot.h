#ifndef SIDECOIN_SNAPSHOT_H
#define SIDECOIN_SNAPSHOT_H

#include <fstream>
#include <cstdio>
#include <cmath>
#include "core.h"
#include "util.h"
#include "chainparams.h"

namespace Snapshot {

const char* const SNAPSHOT_FILE = "balances/balances.txt";

CBlock HashGenesisBlock();

CBlock LoadGenesisBlock(CBlock& block);

CTransaction GenesisTx(const char* btcHash160, const char* btcBalance);

CTransaction ClaimTx(const char* btcSig, const char* btcPubKey);

inline float fast_log(float val);

float difficulty(unsigned bits);

} // Snapshot

#endif
