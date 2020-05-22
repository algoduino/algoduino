/** 
 * Algoduino.h - Algorand IoT library for Arduino - description
 * Based on ESP8266WiFi.h and ESP8266HTTPClient.h from ESP8266 core for Arduino.
 * Copyright (c) 2020 Arduino Blockchain.  All right reserved.
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef Algoduino_h
#define Algoduino_h

#include "Arduino.h"

/** 
 * Algorand network enum.
 */
enum Network {
  BETANET = 0,
  TESTNET,
  MAINNET
};

/**
 *  Algoduino class. 
 */
class Algoduino
{
public:
  /**
   * @brief Initialize the connection.
   * @param ssid Wifi network SSID.
   * @param password Wifi network password.
   * @param apiKey API key to connect to a node.
   * @param network Algorand network: BETANET, TESTNET or MAINNET.   
   */
  Algoduino(String ssid, String password, String apiKey, Network network);

  /**
   * @brief Start the Wifi connection.
   */       
  void begin(void);

  /**
   * @brief Get the network health.
   * @see _fetch()
   * @return String containing the response.
   */ 
  String getHealth(void);

  /**
   * @brief Get account information.
   * @see _fetch()
   * @param address An account public key.
   * @return String containing accounts status, balance and spendable amounts.
   */  
  String getAccountInformation(String address);

  /**
   * @brief Get a specific confirmed transaction.
   * @see _fetch()
   * @param address An account public key.
   * @param txid A transaction id.
   * @return String containing a list of confirmed transactions.
   */  
  String getConfirmedTransactionInformation(String address, String txid);

  /**
   * @brief Get a specific confirmed transaction.
   * @see _fetch()
   * @param address An account public key.
   * @return String containing a list of confirmed transactions.
   */ 
  String getConfirmedTransactionsList(String address);

  /**
   * @brief Get a specific pending transaction.
   * @see _fetch()
   * @param txid A transaction id.
   * @return String containing the pending transaction information.
   */ 
  String getPendingTransactionInformation(String txid);

  /**
   * @brief Get a list of unconfirmed transactions currently in the transaction pool.
   * @see _fetch()
   * @return String containing a list of unconfirmed transactions.
   */ 
  String getPendingTransactionsList(void);

  /**
   * @brief Get a list of unconfirmed transactions currently in the transaction pool by address.
   * @see _fetch()
   * @param address An account public key.
   * @return String containing a list of unconfirmed transactions by address.
   */ 
  String getPendingTransactionsList(String address);

  /**
   * @brief Get asset information.
   * @see _fetch()
   * @param index Asset index.
   * @return String containing asset's creator, manager, reserve, freeze, and clawback addresses.
   */ 
  String getAssetInformation(String index);

  /**
   * @brief Get List of assets.
   * @see _fetch()
   * @param max Maximum number of assets to fetch.
   * @param index Asset index.
   * @return String containing a list of up to max assets.
   */ 
  String getAssetsList(String max, String index);

  /**
   * @brief Get the block for the given round.
   * @see _fetch()
   * @param round The round from which to fetch block information.
   * @return String containing the block information.
   */
  String getBlock(String round);

  /**
   * @brief Get the current supply reported by the ledger.
   * @see _fetch()
   * @return String containing the current supply information.
   */
  String getLedgerSupply(void);

  /**
   * @brief Gets the current node status.
   * @see _fetch()
   * @return String containing the current node status information.
   */
  String getStatus(void);

  /**
   * @brief Gets the node status after waiting for the given round.
   * @see _fetch()
   * @param round The round from which to fetch block information.
   * @return String containing the node status information.
   */
  String getStatus(String round);

  /**
   * @brief Get an information of a single transaction.
   * @see _fetch()
   * @param txid A transaction id.
   * @return String containing the transaction information of the given txid.
   */
  String getTransactionInformation(String txid);

  /**
   * @brief Get the suggested transaction fee.
   * @see _fetch()
   * @return String containing the suggested transaction fee in units of micro-Algos per byte.
   */
  String getTransactionsFee(void);

  /**
   * @brief Get parameters for constructing a new transaction.
   * @see _fetch()
   * @return String containing the transaction parameters information.
   */
  String getTransactionParams(void);

  /**
   * @brief Get the current version of the network.
   * @see _fetch()
   * @return String containing the current version of the network.
   */
  String getVersions(void);

private:
  /// Wifi network SSID.
  String _ssid;

  /// Wifi network password.
  String _password;

  /// API key to connect to a node.
  String _apiKey;

  /// Requested endpoint URL 
  String _endpoint;

  /**
   * @brief Fetch the requested information from the API.
   * @param route API route.
   * @return String containing the requested information.
   */
  String _fetch(String route);
};

#endif
