// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014 Dyffy, Inc.
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "snapshot.h"
#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"
#include <boost/assign/list_of.hpp>

using namespace boost::assign;

//
// Main network
//

unsigned pnSeed[] = { 0x45a4c4ef };

CMainParams::CMainParams()
{
    // Stored genesis block hash and merkle root
    uint256 hashGenesisBlock;
    uint256 hashMerkleRoot;
    hashGenesisBlock = uint256("0x00000000fed46bbc2172a89455873cf6794528545797ff7a013e551f6fc73ef7");
    hashMerkleRoot = uint256("0x32468230e9b3593905e33425122214b0836d90ce312ca535f98bc3b55a89c39b");

    // The message start string is designed to be unlikely to occur in normal data.
    // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
    // a large 4-byte int at any alignment.
    pchMessageStart[0] = 0xf9;
    pchMessageStart[1] = 0xbe;
    pchMessageStart[2] = 0xb4;
    pchMessageStart[3] = 0xd9;
    vAlertPubKey = ParseHex("04fc9702847840aaf195de8442ebecedf5b095cdbb9bc716bda9110971b28a49e0ead8564ff0db22209e0374782c093bb899692d524e9d6a6956e7c5ecbcd68284");
    nDefaultPort = 6543;
    nRPCPort = 6544;
    bnProofOfWorkLimit = CBigNum(~uint256(0) >> 32);
    nSubsidyHalvingInterval = 210000;

    genesis.nBits = 0x1d00ffff; // difficulty = 1 (max target value)

    // Build coinbase transaction
    snapshot.CoinbaseTx(genesis);

    genesis.hashPrevBlock = 0;
    genesis.hashMerkleRoot = genesis.BuildMerkleTree();
    genesis.nVersion = 1;
    genesis.nTime = 1410847826;
    genesis.nNonce = 3652069002;

    // Load snapshot file data into transaction outputs
    if (SNAPSHOT_LOAD) {
        snapshot.LoadGenesisBlock(genesis);
    }

    CheckGenesisBlock("main", hashGenesisBlock, hashMerkleRoot);

    vSeeds.push_back(CDNSSeedData("crypto.cab", "69.164.196.239"));

    base58Prefixes[PUBKEY_ADDRESS] = list_of(63); // S prefix
    base58Prefixes[SCRIPT_ADDRESS] = list_of(5);
    base58Prefixes[SECRET_KEY]     = list_of(128);
    base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
    base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);

    // Convert the pnSeeds array into usable address objects.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    for (unsigned i = 0, len = ARRAYLEN(pnSeed); i < len; ++i) {
        const int64_t nOneWeek = 7*24*60*60;
        struct in_addr ip;
        memcpy(&ip, &pnSeed[i], sizeof(ip));
        CAddress addr(CService(ip, GetDefaultPort()));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vFixedSeeds.push_back(addr);
    }
}

void CMainParams::CheckGenesisBlock(const char* network,
                                    uint256 hashGenesisBlock,
                                    uint256 hashMerkleRoot)
{
    // If needed, find and hash the genesis block
    if (GENESIS_SWITCH && (genesis.GetHash() != hashGenesisBlock)) {
        printf("[%s] Mining genesis block\n", network);
        snapshot.HashGenesisBlock(genesis, true);
    }

    if (!SNAPSHOT_LOAD) {
        assert(genesis.vtx.size() == 1);
    }
    assert(genesis.GetHash() == hashGenesisBlock);
    assert(genesis.hashMerkleRoot == hashMerkleRoot);

    if (GENESIS_SWITCH) {
        printf("[%s] genesis block ok\n", network);
        if (!strcmp(network, "regtest")) {
            printf("  nTime: %u\n", genesis.nTime);
            printf("  nNonce: %u\n", genesis.nNonce);
            printf("  Hash: %s\n", genesis.GetHash().ToString().c_str());
            printf("  hashMerkleRoot: %s\n", genesis.hashMerkleRoot.ToString().c_str());
            printf("  nBits: %08x\n", genesis.nBits);
            printf("  vtx.size: %ld\n", genesis.vtx.size());
            for (unsigned i = 0, len = genesis.vtx.size(); i < len; ++i) {
                printf("  tx-%u:\n", i);
                printf("    vin.scriptSig: %s\n", genesis.vtx[i].vin[0].scriptSig.ToString().c_str());
                printf("    vout.nValue: %ld\n", genesis.vtx[i].vout[0].nValue);
                printf("    vout.scriptPubKey: %s\n", genesis.vtx[i].vout[0].scriptPubKey.ToString().c_str());
                if (i > 3) break;
            }
            printf("  Block contains %ld transactions total.\n", genesis.vtx.size());
        }
    }
}

//
// Testnet (v3)
//
CTestNetParams::CTestNetParams()
{
    // Stored genesis block hash and merkle root
    uint256 hashGenesisBlock = uint256("0x00000000fed46bbc2172a89455873cf6794528545797ff7a013e551f6fc73ef7");
    uint256 hashMerkleRoot = uint256("0x32468230e9b3593905e33425122214b0836d90ce312ca535f98bc3b55a89c39b");

    // The message start string is designed to be unlikely to occur in normal data.
    // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
    // a large 4-byte int at any alignment.
    pchMessageStart[0] = 0x0b;
    pchMessageStart[1] = 0x11;
    pchMessageStart[2] = 0x09;
    pchMessageStart[3] = 0x07;
    vAlertPubKey = ParseHex("04302390343f91cc401d56d68b123028bf52e5fca1939df127f63c6467cdf9c8e2c14b61104cf817d0b780da337893ecc4aaff1309e536162dabbdb45200ca2b0a");
    nDefaultPort = 16543;
    nRPCPort = 16544;
    strDataDir = "testnet3";

    // Modify the testnet genesis block so the timestamp is valid for a later start.
    genesis.nTime = 1412107895;
    genesis.nNonce = 3652069002;

    CheckGenesisBlock("testnet", hashGenesisBlock, hashMerkleRoot);

    vFixedSeeds.clear();
    vSeeds.clear();
    vSeeds.push_back(CDNSSeedData("crypto.cab", "69.164.196.239"));

    base58Prefixes[PUBKEY_ADDRESS] = list_of(111);
    base58Prefixes[SCRIPT_ADDRESS] = list_of(196);
    base58Prefixes[SECRET_KEY]     = list_of(239);
    base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
    base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);
}

//
// Regression Test
//
CRegTestParams::CRegTestParams()
{
    // Stored genesis block hash and merkle root
    uint256 hashGenesisBlock = uint256("0x00000000fed46bbc2172a89455873cf6794528545797ff7a013e551f6fc73ef7");
    uint256 hashMerkleRoot = uint256("0x32468230e9b3593905e33425122214b0836d90ce312ca535f98bc3b55a89c39b");

    pchMessageStart[0] = 0xfa;
    pchMessageStart[1] = 0xbf;
    pchMessageStart[2] = 0xb5;
    pchMessageStart[3] = 0xda;
    nSubsidyHalvingInterval = 150;
    bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
    nDefaultPort = 26543;
    strDataDir = "regtest";

    genesis.nTime = 1412109793;
    genesis.nNonce = 3652069002;

    CheckGenesisBlock("regtest", hashGenesisBlock, hashMerkleRoot);
    
    vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.

    // ClaimTx("IBy7UaBOkuSYyrT2IM2F+4Fy2tUA+Te8Pk+0i+aSeV1IsgEVlTPLa9wU3coFOOwRVslLGdyT6vk2RfZN327rQIw=",
    //     "5c29c74d111b80c2feabd688ee3867d1464d8699");
}

static CMainParams mainParams;
static CTestNetParams testNetParams;
static CRegTestParams regTestParams;
static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network)
{
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine()
{
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }
    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
