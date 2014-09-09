#ifndef __ROCKSWRAPPER_H_INCLUDED__
#define __ROCKSWRAPPER_H_INCLUDED__

#include <cstdio>
#include <string>
#include <assert.h>
#include "rocksdb/db.h"

#ifdef NDEBUG
#define DEBUG_PRINT(format, args...) ((void)0)
#else
#define DEBUG_PRINT printf
#endif

namespace RocksWrapper {

void connect();

} // RocksWrapper

#endif
