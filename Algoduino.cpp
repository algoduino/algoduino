/*
 * Algoduino.cpp - Algorand IoT library for Arduino 
 * Copyright (c) 2020 Algoduino.  All right reserved.
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
*/

#include "Algoduino.h"
#include <Arduino.h>

#define ARDUINOJSON_USE_LONG_LONG 1
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

constexpr char *fingerprint = "B8 7C 7E 8F 45 E3 0C 87 72 1A 85 47 71 F8 80 4D E2 BC 8B FE";

Algoduino::Algoduino(String ssid, String password, String apiKey, Network network)
{
  _ssid = ssid;
  _password = password;
  _apiKey = apiKey;

  switch (network)
  {
  case BETANET:
    _endpoint = "https://betanet-algorand.api.purestake.io/ps1";
    break;
  case TESTNET:
    _endpoint = "https://testnet-algorand.api.purestake.io/ps1";
    break;
  case MAINNET:
    _endpoint = "https://mainnet-algorand.api.purestake.io/ps1";
    break;
  default:
    _endpoint = "https://testnet-algorand.api.purestake.io/ps1";
  }
}

void Algoduino::begin(void)
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(_ssid, _password);
}

String Algoduino::getHealth(void)
{
  return _fetch("/health");
}

AccountInformation Algoduino::getAccountInformation(String address)
{
  AccountInformation accountInformation;

  const size_t capacity = JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(8) + 330;
  DynamicJsonDocument doc(capacity);

  String json = _fetch("/v1/account/" + address);

  deserializeJson(doc, json);

  accountInformation.round = doc["round"];
  accountInformation.address = doc["address"].as<String>();
  accountInformation.amount = doc["amount"];
  accountInformation.pendingrewards = doc["pendingrewards"];
  accountInformation.amountwithoutpendingrewards = doc["amountwithoutpendingrewards"];
  accountInformation.rewards = doc["rewards"];
  accountInformation.status = doc["status"].as<String>();

  JsonObject participation = doc["participation"];
  accountInformation.participation.partpkb64 = participation["partpkb64"].as<String>();
  accountInformation.participation.vrfpkb64 = participation["vrfpkb64"].as<String>();
  accountInformation.participation.votefst = participation["votefst"];
  accountInformation.participation.votelst = participation["votelst"];
  accountInformation.participation.votekd = participation["votekd"];

  return accountInformation;
}

String Algoduino::getConfirmedTransactionInformation(String address, String txid)
{
  return _fetch("/v1/account/" + address + "/transaction/" + txid);
}

String Algoduino::getConfirmedTransactionsList(String address)
{
  return _fetch("/v1/account/" + address + "/transactions");
}

String Algoduino::getPendingTransactionInformation(String txid)
{
  return _fetch("/v1/transactions/pending/" + txid);
}

String Algoduino::getPendingTransactionsList(void)
{
  return _fetch("/v1/transactions/pending");
}

String Algoduino::getPendingTransactionsList(String address)
{
  return _fetch("/v1/account/" + address + "/transactions/pending");
}

AssetInformation Algoduino::getAssetInformation(String index)
{
  AssetInformation assetInformation;

  const size_t capacity = JSON_OBJECT_SIZE(11) + 480;
  DynamicJsonDocument doc(capacity);

  String json = _fetch("/v1/asset/" + index);

  deserializeJson(doc, json);

  assetInformation.creator = doc["creator"].as<String>();
  assetInformation.total = doc["total"];
  assetInformation.decimals = doc["decimals"];
  assetInformation.defaultfrozen = doc["defaultfrozen"];
  assetInformation.unitname = doc["unitname"].as<String>();
  assetInformation.assetname = doc["assetname"].as<String>();
  assetInformation.url = doc["url"].as<String>();
  assetInformation.managerkey = doc["managerkey"].as<String>();
  assetInformation.reserveaddr = doc["reserveaddr"].as<String>();
  assetInformation.freezeaddr = doc["freezeaddr"].as<String>();
  assetInformation.clawbackaddr = doc["clawbackaddr"].as<String>();

  return assetInformation;
}

String Algoduino::getAssetsList(String max, String index)
{
  return _fetch("/v1/assets?max=" + max + "&assetIdx=" + index);
}

String Algoduino::getBlock(String round)
{
  return _fetch("/v1/block/" + round);
}

LedgerSupply Algoduino::getLedgerSupply(void)
{
  LedgerSupply ledgerSupply;

  const size_t capacity = JSON_OBJECT_SIZE(3) + 40;
  DynamicJsonDocument doc(capacity);

  String json = _fetch("/v1/ledger/supply");

  deserializeJson(doc, json);

  ledgerSupply.round = doc["round"];
  ledgerSupply.totalMoney = doc["totalMoney"];
  ledgerSupply.onlineMoney = doc["onlineMoney"];

  return ledgerSupply;
}

Status Algoduino::getStatus(void)
{
  Status status;

  const size_t capacity = JSON_OBJECT_SIZE(9) + 410;
  DynamicJsonDocument doc(capacity);

  String json = _fetch("/v1/status");

  deserializeJson(doc, json);

  status.lastRound = doc["lastRound"];
  status.lastConsensusVersion = doc["lastConsensusVersion"].as<String>();
  status.nextConsensusVersion = doc["nextConsensusVersion"].as<String>();
  status.nextConsensusVersionRound = doc["nextConsensusVersionRound"];
  status.nextConsensusVersionSupported = doc["nextConsensusVersionSupported"];
  status.timeSinceLastRound = doc["timeSinceLastRound"];
  status.catchupTime = doc["catchupTime"];
  status.hasSyncedSinceStartup = doc["hasSyncedSinceStartup"];
  status.stoppedAtUnsupportedRound = doc["stoppedAtUnsupportedRound"];

  return status;
}

Status Algoduino::getStatus(String round)
{
  Status status;

  const size_t capacity = JSON_OBJECT_SIZE(9) + 410;
  DynamicJsonDocument doc(capacity);

  String json = _fetch("/v1/status/wait-for-block-after/" + round);

  deserializeJson(doc, json);

  status.lastRound = doc["lastRound"];
  status.lastConsensusVersion = doc["lastConsensusVersion"].as<String>();
  status.nextConsensusVersion = doc["nextConsensusVersion"].as<String>();
  status.nextConsensusVersionRound = doc["nextConsensusVersionRound"];
  status.nextConsensusVersionSupported = doc["nextConsensusVersionSupported"];
  status.timeSinceLastRound = doc["timeSinceLastRound"];
  status.catchupTime = doc["catchupTime"];
  status.hasSyncedSinceStartup = doc["hasSyncedSinceStartup"];
  status.stoppedAtUnsupportedRound = doc["stoppedAtUnsupportedRound"];

  return status;
}

TransactionInformation Algoduino::getTransactionInformation(String txid)
{
  TransactionInformation transactionInformation;

  const size_t capacity = JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(12) + 420;
  DynamicJsonDocument doc(capacity);

  String json = _fetch("/v1/transaction/" + txid);
  deserializeJson(doc, json);

  JsonObject obj = doc.as<JsonObject>();
  transactionInformation.type = obj["type"].as<String>();
  transactionInformation.tx = obj["tx"].as<String>();
  transactionInformation.from = obj["from"].as<String>();
  transactionInformation.fee = obj["fee"];
  transactionInformation.first_round = obj["first-round"];
  transactionInformation.last_round = obj["last-round"];
  transactionInformation.noteb64 = obj["noteb64"].as<String>();
  transactionInformation.round = obj["round"];

  JsonObject curxfer = doc["curxfer"];
  transactionInformation.curxfer.id = curxfer["id"];
  transactionInformation.curxfer.amt = curxfer["amt"];
  transactionInformation.curxfer.snd = curxfer["snd"].as<String>();
  transactionInformation.curxfer.rcv = curxfer["rcv"].as<String>();
  transactionInformation.curxfer.closeto = curxfer["closeto"].as<String>();

  transactionInformation.fromrewards = doc["fromrewards"];
  transactionInformation.genesisID = doc["genesisID"].as<String>();
  transactionInformation.genesishashb64 = doc["genesishashb64"].as<String>();

  return transactionInformation;
}

int Algoduino::getTransactionsFee(void)
{
  const size_t capacity = JSON_OBJECT_SIZE(1) + 10;
  DynamicJsonDocument doc(capacity);

  String json = _fetch("/v1/transactions/fee");
  deserializeJson(doc, json);

  int fee = doc["fee"];

  return fee;
}

TransactionParams Algoduino::getTransactionParams(void)
{
  TransactionParams transactionParams;

  const size_t capacity = JSON_OBJECT_SIZE(6) + 240;
  DynamicJsonDocument doc(capacity);

  String json = _fetch("/v1/transactions/params");

  deserializeJson(doc, json);

  transactionParams.fee = doc["fee"];
  transactionParams.genesisID = doc["genesisID"].as<String>();
  transactionParams.genesishashb64 = doc["genesishashb64"].as<String>();
  transactionParams.lastRound = doc["lastRound"];
  transactionParams.consensusVersion = doc["consensusVersion"].as<String>();
  transactionParams.minFee = doc["minFee"];

  return transactionParams;
}

Version Algoduino::getVersions(void)
{
  Version version;

  const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(6) + 210;
  DynamicJsonDocument doc(capacity);

  String json = _fetch("/versions");

  deserializeJson(doc, json);

  version.versions = doc["versions"][0].as<String>();
  version.genesis_id = doc["genesis_id"].as<String>();
  version.genesis_hash_b64 = doc["genesis_hash_b64"].as<String>();

  JsonObject build = doc["build"];
  version.build.major = build["major"];
  version.build.minor = build["minor"];
  version.build.build_number = build["build_number"];
  version.build.commit_hash = build["commit_hash"].as<String>();
  version.build.branch = build["branch"].as<String>();
  version.build.channel = build["channel"].as<String>();

  return version;
}

String Algoduino::_fetch(String route)
{
  String payload = "[void]";

  if ((WiFi.status() == WL_CONNECTED))
  {
    HTTPClient https;

    if (https.begin(_endpoint + route, fingerprint))
    {
      https.addHeader("accept", "application/json");
      https.addHeader("x-api-key", _apiKey);

      int httpCode = https.GET();

      if (httpCode > 0)
      {
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY)
        {
          payload = https.getString();
        }
      }

      https.end();
    }
  }

  return payload;
}
