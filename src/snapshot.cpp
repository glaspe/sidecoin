#include "snapshot.h"

namespace Snapshot {

CBlock HashGenesisBlock()
{
    CBlock block;
    uint256 hashTarget = CBigNum().SetCompact(block.nBits).getuint256();
    uint256 thash;
    loop {
        thash = block.GetHash();
        if (thash <= hashTarget) {
            puts("Genesis block found!");
            break;
        }
        if ((block.nNonce & 0xFFF) == 0) {
            printf("Nonce %08X: hash = %s (target = %s)\n", block.nNonce, 
                                                            thash.ToString().c_str(),
                                                            hashTarget.ToString().c_str());
        }
        ++block.nNonce;
        if (block.nNonce == 0) {
            puts("Nonce wrapped, incrementing time");
            ++block.nTime;
        }
    }
    printf("block.nTime: %u\n", block.nTime);
    printf("block.nNonce: %u\n", block.nNonce);
    printf("block.GetHash: %s\n", block.GetHash().ToString().c_str());
    return block;
}

/**
 * Reads in Bitcoin balances and accounts (as hash-160 strings) from a snapshot
 * file.  A transaction output is created for each (account, balance) pair: the
 * output's value (nValue) is equal to the balance, and its P2PKH validation
 * script (scriptPubKey) is set up using the account string.
 *
 * Q: is it possible to override the genesis block size limit, or will this
 * need to be sent out to several smaller blocks?  (~2 million transactions
 * total)
 */
CBlock LoadGenesisBlock(CBlock& block)
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
    // printf("hashGenesisBlock: %s\n", block.GetHash().ToString().c_str());
    // printf("hashMerkleRoot: %s\n", block.BuildMerkleTree().ToString().c_str());
    return block;
}

/**
 * Construct "snapshot" transactions and load into the genesis block.
 */
CTransaction GenesisTx(const char* btcHash160, const char* btcBalance)
{
    const char* pszTimestamp = "Larger Apple iPhones shipments delayed amid record orders";
    CTransaction tx;
    tx.vin.resize(1);
    tx.vin[0].scriptSig = CScript() << 486604799
                                    << CBigNum(4)
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
    // printf("%s\t%s\t%s\n", btcHash160, btcBalance, tx.GetHash().ToString().c_str());
    return tx;
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

} // Snapshot
