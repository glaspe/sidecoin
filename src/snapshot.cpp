#include "snapshot.h"

namespace Snapshot {

CTransaction genesis_tx()
{
    CTransaction tx;
    const char* pszTimestamp = "Larger Apple iPhones shipments delayed amid record orders";
    
    tx.vin.resize(1);
    tx.vin[0].scriptSig = CScript() << 486604799
                                    << CBigNum(4)
                                    << vector<unsigned char>(
                                           (const unsigned char*)pszTimestamp,
                                           (const unsigned char*)pszTimestamp + strlen(pszTimestamp)
                                       );
    std::ifstream snapshot;
    snapshot.open("balances/balances.txt");
    if (snapshot.good()) {
        do {
            char buffer[1024];
            const char* btc_balance = 0;
            const char* btc_hash160 = 0;
            snapshot.getline(buffer, 1024);
            btc_balance = strtok(buffer, " ");
            if (btc_balance) {
                btc_hash160 = strtok(0, " ");
                if (btc_hash160) {
                    printf("%s\t%s\n", btc_hash160, btc_balance);
                    CTxOut output;
                    output.nValue = atoi64(btc_balance) * COIN;
                    output.scriptPubKey = CScript() << OP_DUP
                                                    << OP_HASH160
                                                    << ParseHex(btc_hash160)
                                                    << OP_EQUALVERIFY
                                                    << OP_CHECKSIG;
                    tx.vout.push_back(output);
                }
            }
        } while (!snapshot.eof());
    }
    return tx;
}

} // Snapshot
