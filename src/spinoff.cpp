#include "spinoff.h"

namespace Snapshot {

bool verifymessage(const json_spirit::Array& params, const bool test)
{
    // placeholder for rpcserver
    return true;
}

std::string bitcoin_signature(const std::string& bitclaim,
                              const std::string& sideaddr)
{
    // Bitcoin signature (over Sidecoin address):
    // bitcoind signmessage <bitcoin address> <sidecoin address>
    char buffer[1024];
    std::string signmessage = "bitcoind signmessage " + bitclaim + " " + sideaddr;

    FILE *bitcoind_p = popen(signmessage.c_str(), "r");
    if (!bitcoind_p) {
        return "-1";
    }
    char *bitsig_p = fgets(buffer, sizeof(buffer), bitcoind_p);
    pclose(bitcoind_p);

    std::string bitsig(bitsig_p);
    return bitsig;
}

bool claim(const std::string& bitsig,
           const std::string& bitclaim,
           const std::string& sideaddr)
{
    std::ifstream snapshot;
    bool verified = false;
    snapshot.open("balances/balances.txt");

    if (snapshot.good()) {
        do {
            char buffer[256];
            const char* bitcoins = 0;
            const char* bitaddr = 0;

            snapshot.getline(buffer, 256);
            bitcoins = strtok(buffer, " ");
            if (bitcoins) {
                strtok(0, " ");
                bitaddr = strtok(0, " ");
                if (bitaddr && !strcmp(bitaddr, bitclaim.c_str())) {
                    // sidecoind verifymessage <sidecoin address> <bitcoin signature over sidecoin address> <bitcoin address>
                    std::string bitaddr_str(bitaddr);
                    json_spirit::Array params;
                    params[0] = sideaddr;
                    params[1] = bitsig;
                    params[2] = bitaddr_str;
                    verified = verifymessage(params, false);
                    if (verified) {
                        // 1. Award Sidecoins to "sideaddr" address
                        // 2. Broadcast to Sidecoin blockchain as spent
                        break;
                    }
                }
            }
            break;
        } while (!snapshot.eof());
    }
    return verified;
}

} // Snapshot

int main()
{
    bool verified_claim;
    const std::string bitclaim = "1HB5Qnjyiw7FYuF8AM3XD37vzsDAphc1Hw";
    const std::string sideaddr = "SIDECOINADDRESS";
    std::string bitsig;

    bitsig = Snapshot::bitcoin_signature(bitclaim, sideaddr);
    if (bitsig == "-1") {
        return -1;
    }
    printf("Signature: %s", bitsig.c_str());

    verified_claim = Snapshot::claim(bitsig, bitclaim, sideaddr);
    return 0;
}
