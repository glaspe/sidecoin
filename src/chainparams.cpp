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
    uint256 hashGenesisBlock = uint256("0x00000000fed46bbc2172a89455873cf6794528545797ff7a013e551f6fc73ef7");
    uint256 hashMerkleRoot = uint256("0x32468230e9b3593905e33425122214b0836d90ce312ca535f98bc3b55a89c39b");

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

    // Build coinbase transaction
    // genesis.vtx.push_back(snapshot::CoinbaseTx(genesis.nBits));
    const char* pszTimestamp = "Boeing wins role in next U.S. space chapter";
    
    CTransaction txNew;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CBigNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = 50 * COIN;
    txNew.vout[0].scriptPubKey = CScript() << ParseHex("04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f") << OP_CHECKSIG;
    genesis.vtx.push_back(txNew);
    genesis.hashPrevBlock = 0;
    genesis.hashMerkleRoot = genesis.BuildMerkleTree();
    genesis.nVersion = 1;

    genesis.nTime = 1410847826;
    genesis.nNonce = 3652069002;
    genesis.nBits = 0x1d00ffff; // difficulty = 1 (max target value)

    // Load snapshot file data into transaction outputs
    // snapshot::LoadGenesisBlock(genesis);

    printf("- nTime: %u\n", genesis.nTime);
    printf("- nNonce: %u\n", genesis.nNonce);
    printf("- Hash: %s\n", genesis.GetHash().ToString().c_str());
    printf("- hashMerkleRoot: %s\n", genesis.hashMerkleRoot.ToString().c_str());
    printf("- nBits: %08x\n", genesis.nBits);

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
        snapshot::HashGenesisBlock(genesis, true);
    }

    assert(genesis.vtx.size() == 1);
    assert(genesis.GetHash() == hashGenesisBlock);
    assert(genesis.hashMerkleRoot == hashMerkleRoot);

    // if (mapBlockIndex.empty()) {

    /*
    Genesis Block:
    GetHash()      = 0x000000000019d6689c085ae165831e934ff763ae46a2a6c172b3f1b60a8ce26f
    hashMerkleRoot = 0x4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b
    txNew.vin[0].scriptSig     = 486604799 4 0x736B6E616220726F662074756F6C69616220646E6F63657320666F206B6E697262206E6F20726F6C6C65636E61684320393030322F6E614A2F33302073656D695420656854
    txNew.vout[0].nValue       = 5000000000
    txNew.vout[0].scriptPubKey = 0x5F1DF16B2B704C8A578D0BBAF74D385CDE12C11EE50455F3C438EF4C3FBCF649B6DE611FEAE06279A60939E028A8D65C10B73071A6F16719274855FEB0FD8A6704 OP_CHECKSIG
    block.nVersion = 1
    block.nTime    = 1231006505
    block.nBits    = 0x1d00ffff
    block.nNonce   = 2083236893
    CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
      CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
        CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
      vMerkleTree: 4a5e1e
    */

    if (GENESIS_SWITCH) {
        try {
            // unsigned int nBlockSize = ::GetSerializeSize(genesis, SER_DISK, CLIENT_VERSION);
            // CDiskBlockPos blockPos;
            // CValidationState state;
            // if (!FindBlockPos(state, blockPos, nBlockSize+8, 0, genesis.nTime))
            //     return error("LoadBlockIndex() : FindBlockPos failed");
            // if (!genesis.WriteToDisk(blockPos))
            //     return error("LoadBlockIndex() : writing genesis block to disk failed");
            // if (!genesis.AddToBlockIndex(state, blockPos))
            //     return error("LoadBlockIndex() : genesis block not accepted");
        } catch(std::runtime_error &e) {
            // return error("LoadBlockIndex() : failed to initialize block database: %s", e.what());
        }
        printf("[%s] genesis block ok\n", network);
    }
}

/**
 * Claim unspent outputs from the genesis block.
 * ./sidecoind getblockhash 0
 * ./sidecoind getblock <genesis block hash>
 */
CTransaction CMainParams::ClaimTx(const char* btcSig,
                                  const char* btcHash160,
                                  std::string genesisBlockHash)
{
    CTransaction tx;
    CBlock block;

    std::string strHash = genesisBlockHash;
    uint256 hash(strHash);

    // if (mapBlockIndex.count(hash) == 0) {
    //     return tx;
    // }
    // CBlockIndex* pblockindex = mapBlockIndex[hash];
    
    // ReadBlockFromDisk(block, pblockindex);

    // // Find UTXO matching user's Bitcoin hash-160 pubkey
    // for (unsigned i = 0, len = block.vtx.size(); i < len; ++i) {
    //     if (block.vtx[i].vout[0] /* CScript comparison */) {
    //         tx = block.vtx[i];
    //     }
    // }
    return tx;
}

//
// Testnet (v3)
//
CTestNetParams::CTestNetParams()
{
    // Stored genesis block hash and merkle root
    // uint256 hashGenesisBlock = uint256("0x0000001b7af66da68df2afaca8b561784a16152e5d4bbb972d4d33cda07c57fc");
    // uint256 hashMerkleRoot = uint256("0x808e11f1c1b824ff499979298d7999a76ab2e8fa72240f6bb8a354328877039c");
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
    genesis.nTime = 1410847826;
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
    // uint256 hashGenesisBlock = uint256("0x0000001b7af66da68df2afaca8b561784a16152e5d4bbb972d4d33cda07c57fc");
    // uint256 hashMerkleRoot = uint256("0x808e11f1c1b824ff499979298d7999a76ab2e8fa72240f6bb8a354328877039c");
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

    genesis.nTime = 1410847826;
    genesis.nNonce = 3652069002;

    CheckGenesisBlock("regtest", hashGenesisBlock, hashMerkleRoot);
    
    vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.

    // ClaimTx("IBy7UaBOkuSYyrT2IM2F+4Fy2tUA+Te8Pk+0i+aSeV1IsgEVlTPLa9wU3coFOOwRVslLGdyT6vk2RfZN327rQIw=",
    //         "5c29c74d111b80c2feabd688ee3867d1464d8699",
    //         "00000000623ea9295ad827d257f70683f6c1e284390dba5be23b0cbd81c5911b");
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
