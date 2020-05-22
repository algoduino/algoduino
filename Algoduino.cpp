/*
 * Algoduino.cpp - Algorand IoT library for Arduino - description
 * Based on ESP8266WiFi.h and ESP8266HTTPClient.h from ESP8266 core for Arduino.
 * Copyright (c) 2020 Arduino Blockchain.  All right reserved.
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
*/

#include "Algoduino.h"
#include <Arduino.h>
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

String Algoduino::getAccountInformation(String address)
{
  return _fetch("/v1/account/" + address);
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

String Algoduino::getAssetInformation(String index)
{
  return _fetch("/v1/asset/" + index);
}

String Algoduino::getAssetsList(String max, String index)
{
  return _fetch("/v1/assets?max=" + max + "&assetIdx=" + index);
}

String Algoduino::getBlock(String round)
{
  return _fetch("/v1/block/" + round);
}

String Algoduino::getLedgerSupply(void)
{
  return _fetch("/v1/ledger/supply");
}

String Algoduino::getStatus(void)
{
  return _fetch("/v1/status");
}

String Algoduino::getStatus(String round)
{
  return _fetch("/v1/status/wait-for-block-after/" + round);
}

String Algoduino::getTransactionInformation(String txid)
{
  return _fetch("/v1/transaction/" + txid);
}

String Algoduino::getTransactionsFee(void)
{
  return _fetch("/v1/transactions/fee");
}

String Algoduino::getTransactionParams(void)
{
  return _fetch("/v1/transactions/params");
}

String Algoduino::getVersions(void)
{
  return _fetch("/versions");
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
