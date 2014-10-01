// Copyright (c) 2014 Dyffy, Inc.
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "snapshot.h"

/**
 * Build the genesis block's coinbase transaction.
 */
void Snapshot::CoinbaseTx(CBlock& genesis)
{
    const char* pszTimestamp = "Boeing wins role in next U.S. space chapter";
    CTransaction coinbaseTx;
    coinbaseTx.vin.resize(1);
    coinbaseTx.vout.resize(1);
    coinbaseTx.vin[0].scriptSig = CScript() << CBigNum(genesis.nBits).getint()
                                            << CBigNum(4)   // 0x1d, 0x00, 0xff, 0xff
                                            << std::vector<unsigned char>(
                                                   (const unsigned char*)pszTimestamp,
                                                   (const unsigned char*)pszTimestamp + strlen(pszTimestamp)
                                               );
    coinbaseTx.vout[0].nValue = 50 * COIN;
    coinbaseTx.vout[0].scriptPubKey = CScript() << ParseHex("04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f")
                                                << OP_CHECKSIG;
    genesis.vtx.push_back(coinbaseTx);
}

/**
 * Read in Bitcoin balances and accounts (as hash-160 strings) from a snapshot
 * file.  A transaction output is created for each (account, balance) pair: the
 * output's value (nValue) is equal to the balance, and its P2PKH validation
 * script (scriptPubKey) is set up using the account string.
 */
void Snapshot::LoadGenesisBlock(CBlock& genesis)
{
    std::ifstream snapfile;
    boost::filesystem::path curpath(boost::filesystem::canonical(boost::filesystem::current_path()));
    std::string SNAPSHOT_FILE = curpath.string() + "/balances/balances.txt";
    snapfile.open(SNAPSHOT_FILE.c_str());
    if (snapfile.good()) {
        while (!snapfile.eof()) {
            char buffer[1024];
            const char* btcBalance = 0;
            const char* btcHash160 = 0;
            snapfile.getline(buffer, 1024);
            btcBalance = strtok(buffer, " ");
            if (btcBalance) {
                btcHash160 = strtok(0, " ");
                if (btcHash160) {
                    CTransaction tx;
                    tx = GenesisTx(genesis, btcHash160, btcBalance);
                    if (tx.vin[0].scriptSig.size() > 1) genesis.vtx.push_back(tx);
                }
            }
        }
    }
}

/**
 * Construct "snapshot" transactions and load into the genesis block.
 */
CTransaction Snapshot::GenesisTx(CBlock& genesis,
                                 const char* btcHash160,
                                 const char* btcBalance)
{
    CTransaction tx;
    tx.vin.resize(1);
    tx.vin[0].scriptSig = CScript() << ParseHex(btcHash160);
    tx.vout.resize(1);
    tx.vout[0].nValue = atoi64(btcBalance) * COIN;
    tx.vout[0].scriptPubKey = CScript() << OP_DUP
                                        << OP_HASH160
                                        << ParseHex(btcHash160)
                                        << OP_EQUALVERIFY
                                        << OP_CHECKSIG;
    return tx;
}

/**
 * Mine the genesis block.
 */
void Snapshot::HashGenesisBlock(CBlock& block, bool verbose)
{
    block.nNonce = 0;
    uint256 hashTarget = CBigNum().SetCompact(block.nBits).getuint256();
    if (verbose) {
        uint256 testHash = block.GetHash();
        uint256 smallHash = testHash;
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
    } else {
        while (block.GetHash() > hashTarget) {
            ++block.nNonce;
            if (block.nNonce == 0) {
                ++block.nTime;
            }
        }
    }
    puts("Genesis block found.");
    printf("- nTime: %u\n", block.nTime);
    printf("- nNonce: %u\n", block.nNonce);
    printf("- Hash: %s\n", block.GetHash().ToString().c_str());
    printf("- hashMerkleRoot: %s\n", block.hashMerkleRoot.ToString().c_str());
    printf("- nBits: %08x\n", block.nBits);
}
