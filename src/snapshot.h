#ifndef SIDECOIN_SNAPSHOT_H
#define SIDECOIN_SNAPSHOT_H

#include <fstream>
#include <cmath>
#include <boost/filesystem/operations.hpp>
#include "core.h"
#include "util.h"
#include "chainparams.h"

#define GENESIS_SWITCH true

namespace Snapshot {

CTransaction CoinbaseTx(unsigned nBits);

void LoadGenesisBlock(CBlock& block);

CTransaction GenesisTx(const char* btcHash160, const char* btcBalance);

void HashGenesisBlock(CBlock& block);

CTransaction ClaimTx(const char* btcSig, const char* btcPubKey);

inline float FastLog(float val);

float Difficulty(unsigned bits);

} // Snapshot

#endif
