#ifndef __CONSENSUS_H_INCLUDED__
#define __CONSENSUS_H_INCLUDED__

#include <cstdio>
#include <itpp/itbase.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>

#ifdef NDEBUG
#define DEBUG_PRINT(format, args...) ((void)0)
#else
#define DEBUG_PRINT printf
#endif

namespace Consensus {

struct SVDOutput {
    itpp::mat U;
    itpp::vec s;    
    itpp::mat V;
    itpp::mat S;
};

SVDOutput test_svd();

} // Consensus

#endif
