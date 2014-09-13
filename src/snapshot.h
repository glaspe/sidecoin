#ifndef SIDECOIN_SNAPSHOT_H
#define SIDECOIN_SNAPSHOT_H

#include <fstream>
#include <cstdio>
#include "core.h"
#include "util.h"
#include "chainparams.h"

class CTransaction;

namespace snapshot {

const char* const SNAPSHOT_FILE = "balances/balances.txt";

CTransaction genesis_tx();

std::string bitcoin_signature(const std::string& bitclaim,
                              const std::string& sideaddr);


} // snapshot

#endif
