#include "spinoff.h"

namespace snapshot {

bool verifymessage(const json_spirit::Array& params, const bool test)
{
    // placeholder for rpcserver
    return true;
}

bool claim(const std::string& bitsig,
           const std::string& bitclaim,
           const std::string& sideaddr)
{
    std::ifstream snapshot;
    bool verified = false;
    snapshot.open(SNAPSHOT_FILE);

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

} // snapshot

int main()
{
    bool verified_claim;
    const std::string bitclaim = "1HB5Qnjyiw7FYuF8AM3XD37vzsDAphc1Hw";
    const std::string sideaddr = "SIDECOINADDRESS";
    std::string bitsig;

    bitsig = snapshot::bitcoin_signature(bitclaim, sideaddr);
    if (bitsig == "-1") {
        return -1;
    }
    printf("Signature: %s", bitsig.c_str());

    verified_claim = snapshot::claim(bitsig, bitclaim, sideaddr);
    return 0;
}
