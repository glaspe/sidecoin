#ifndef SIDECOIN_SNAPSHOT_H
#define SIDECOIN_SNAPSHOT_H

#include <fstream>
#include <cstdio>
#include "core.h"
#include "util.h"
#include "chainparams.h"

class CTransaction;

namespace Snapshot {

CTransaction genesis_tx();

} // Snapshot

#endif
