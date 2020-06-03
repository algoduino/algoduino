/** 
 * AlgoduinoTypes.h - Algorand IoT library for Arduino 
 * Copyright (c) 2020 Algoduino.  All right reserved.
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef AlgoduinoTypes_h
#define AlgoduinoTypes_h

#include "Arduino.h"

/** 
 * Algorand network enum.
 */
enum Network
{
  BETANET = 0,
  TESTNET,
  MAINNET
};

/**
 *  AccountInformation struct. 
 */
struct AccountInformation
{
  long round;
  String address;
  long long amount;
  long long pendingrewards;
  long long amountwithoutpendingrewards;
  long long rewards;
  String status;
  struct Participation
  {
    String partpkb64;
    String vrfpkb64;
    long votefst;
    long votelst;
    int votekd;
  };
  Participation participation;
};

/**
 *  AssetInformation struct. 
 */
struct AssetInformation
{
  String creator;
  long long total;
  int decimals;
  bool defaultfrozen;
  String unitname;
  String assetname;
  String url;
  String managerkey;
  String reserveaddr;
  String freezeaddr;
  String clawbackaddr;
};

/**
 *  LedgerSupply struct. 
 */
struct LedgerSupply
{
  long round;
  long long totalMoney;
  long long onlineMoney;
};

/**
 *  Status struct. 
 */
struct Status
{
  long lastRound;
  String lastConsensusVersion;
  String nextConsensusVersion;
  long nextConsensusVersionRound;
  bool nextConsensusVersionSupported;
  long long timeSinceLastRound;
  int catchupTime;
  bool hasSyncedSinceStartup;
  bool stoppedAtUnsupportedRound;
};

/**
 *  TransactionInformation struct. 
 */
struct TransactionInformation
{
  String type;
  String tx;
  String from;
  int fee;
  long first_round;
  long last_round;
  String noteb64;
  long round;
  struct Curxfer
  {
    long id;
    int amt;
    String snd;
    String rcv;
    String closeto;
  };
  Curxfer curxfer;
  int fromrewards;
  String genesisID;
  String genesishashb64;
};

/**
 *  TransactionParams struct. 
 */
struct TransactionParams
{
  int fee;
  String genesisID;
  String genesishashb64;
  long lastRound;
  String consensusVersion;
  int minFee;
};

/**
 *  Version struct. 
 */
struct Version
{
  String versions;
  String genesis_id;
  String genesis_hash_b64;
  struct Build
  {
    int major;
    int minor;
    int build_number;
    String commit_hash;
    String branch;
    String channel;
  };
  Build build;
};

#endif