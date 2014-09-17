#include "snapshot.h"

namespace Snapshot {

/**
 * Build the genesis block's coinbase transaction.
 */
CTransaction CoinbaseTx()
{
    const char* pszTimestamp = "Boeing wins role in next U.S. space chapter";
    CTransaction coinbaseTx;
    coinbaseTx.vin.resize(1);
    // coinbaseTx.vin[0].scriptSig = CScript() << 486604799    // nBits
    //                                         << CBigNum(4)   // 0x1d, 0x00, 0xff, 0xff
    coinbaseTx.vin[0].scriptSig = CScript() << 487587839    // nBits
                                            << CBigNum(4)   // 0x1d, 0x0f, 0xff, 0xff
                                            << vector<unsigned char>(
                                                   (const unsigned char*)pszTimestamp,
                                                   (const unsigned char*)pszTimestamp + strlen(pszTimestamp)
                                               );
    coinbaseTx.vout.resize(1);
    coinbaseTx.vout[0].nValue = 50 * COIN;
    coinbaseTx.vout[0].scriptPubKey = CScript() << OP_DUP
                                                << OP_HASH160
                                                << ParseHex("6fc51f2a519d341392c2231faec5e91881250b5a")
                                                << OP_EQUALVERIFY
                                                << OP_CHECKSIG;
    return coinbaseTx;
}

/**
 * Read in Bitcoin balances and accounts (as hash-160 strings) from a snapshot
 * file.  A transaction output is created for each (account, balance) pair: the
 * output's value (nValue) is equal to the balance, and its P2PKH validation
 * script (scriptPubKey) is set up using the account string.
 */
void LoadGenesisBlock(CBlock& block)
{
    std::ifstream snapshot;
    snapshot.open(SNAPSHOT_FILE);
    if (snapshot.good()) {
        while (!snapshot.eof()) {
            char buffer[1024];
            const char* btcBalance = 0;
            const char* btcHash160 = 0;
            snapshot.getline(buffer, 1024);
            btcBalance = strtok(buffer, " ");
            if (btcBalance) {
                btcHash160 = strtok(0, " ");
                if (btcHash160) {
                    block.vtx.push_back(GenesisTx(btcHash160, btcBalance));
                }
            }
        }
    }
}

/**
 * Construct "snapshot" transactions and load into the genesis block.
 */
CTransaction GenesisTx(const char* btcHash160, const char* btcBalance)
{
    const char* pszTimestamp = "Boeing wins role in next U.S. space chapter";
    CTransaction tx;
    tx.vin.resize(1);
    tx.vin[0].scriptSig = CScript() << 487587839    // genesis.nBits
                                    << CBigNum(4)   // 4 nBits: 0x1d, 0x00, 0xff, 0xff
                                    << vector<unsigned char>(
                                           (const unsigned char*)pszTimestamp,
                                           (const unsigned char*)pszTimestamp + strlen(pszTimestamp)
                                       );
    tx.vout.resize(1);
    tx.vout[0].nValue = atoi64(btcBalance) * COIN;
    tx.vout[0].scriptPubKey = CScript() << OP_DUP
                                        << OP_HASH160
                                        << ParseHex(btcHash160)
                                        << OP_EQUALVERIFY
                                        << OP_CHECKSIG;
    printf("%s\t%s\t%s\n", btcHash160, btcBalance, tx.GetHash().ToString().c_str());
    return tx;
}

/**
 * Mine the genesis block.
 */
void HashGenesisBlock(CBlock& block)
{
    // block.nBits = 0x1d00ffff; // difficulty = 1 (max target value)
    block.nBits = 0x1d0fffff; // difficulty < 1 (easier; for testing)
    block.nNonce = 0;
    uint256 hashTarget = CBigNum().SetCompact(block.nBits).getuint256();
    uint256 testHash = block.GetHash();
    uint256 smallHash = testHash;
    printf("Difficulty: %f\n", Difficulty(block.nBits));
    printf("Target:               %s\n", hashTarget.ToString().c_str());
    while (testHash > hashTarget) {
        ++block.nNonce;
        if (block.nNonce == 0) {
            ++block.nTime;
        }
        if ((block.nNonce & 0xFFF) == 0) {
            printf("Nonce: %08x\tHash: %s\r", block.nNonce,
                                              testHash.ToString().c_str());
        }
        testHash = block.GetHash();
        if (testHash < smallHash) {
            smallHash = testHash;
            printf("Nonce: %08x\tHash: %s\n", block.nNonce,
                                              smallHash.ToString().c_str());
        }
    }
    puts("Genesis block found.");
    printf("- nTime: %u\n", block.nTime);
    printf("- nNonce: %u\n", block.nNonce);
    printf("- Hash: %s\n", block.GetHash().ToString().c_str());
    printf("- hashMerkelRoot: %s\n", block.hashMerkleRoot.ToString().c_str());
    printf("- nBits: %08x\n", block.nBits);
}

/**
 * Claim unspent outputs from the genesis block.
 */
CTransaction ClaimTx(const char* btcSig, const char* btcPubKey, const char* txHash)
{
    CTransaction tx;
    unsigned nOut = 1;
    unsigned nSequence = 1;
    COutPoint prevOut(uint256(txHash), nOut);
    CScript scriptSig = CScript() << ParseHex(btcSig)
                                  << ParseHex(btcPubKey);
    CTxIn txInput(prevOut, scriptSig, nSequence);
    return tx;
}

/**
 * Difficulty calculation and fast log taken from:
 * https://en.bitcoin.it/wiki/Difficulty
 */
inline float FastLog(float val)
{
   int* const exp_ptr = reinterpret_cast<int *>(&val);
   int x = *exp_ptr;
   const int log_2 = ((x >> 23) & 255) - 128;
   x &= ~(255 << 23);
   x += 127 << 23;
   *exp_ptr = x;
   val = ((-1.0f/3) * val + 2) * val - 2.0f/3;
   return ((val + log_2) * 0.69314718f);
} 

float Difficulty(unsigned bits)
{
    static double max_body = FastLog(0x00ffff);
    static double scaland = FastLog(256);
    return exp(max_body - FastLog(bits & 0x00ffffff) + scaland * (0x1d - ((bits & 0xff000000) >> 24)));
}

} // Snapshot
