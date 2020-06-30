/** 
 * Algoduino.h - Algorand IoT library for Arduino 
 * Copyright (c) 2020 Algoduino.  All right reserved.
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#ifndef Algoduino_h
#define Algoduino_h

#include "Arduino.h"
#include "AlgoduinoTypes.h"

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
   * @return String containing the response.
   */
  String getHealth(void);

  /**
   * @brief Get account information.
   * @param address An account public key.
   * @return AccountInformation structure containing accounts status, balance and spendable amounts.
   */
  AccountInformation getAccountInformation(String address);

  /**
   * @brief Get a specific confirmed transaction.
   * @param address An account public key.
   * @param txid A transaction id.
   * @return String containing a list of confirmed transactions.
   */
  String getConfirmedTransactionInformation(String address, String txid);

  /**
   * @brief Get a specific confirmed transaction.
   * @param address An account public key.
   * @return String containing a list of confirmed transactions.
   */
  String getConfirmedTransactionsList(String address);

  /**
   * @brief Get a specific pending transaction.
   * @param txid A transaction id.
   * @return String containing the pending transaction information.
   */
  String getPendingTransactionInformation(String txid);

  /**
   * @brief Get a list of unconfirmed transactions currently in the transaction pool.
   * @return String containing a list of unconfirmed transactions.
   */
  String getPendingTransactionsList(void);

  /**
   * @brief Get a list of unconfirmed transactions currently in the transaction pool by address.
   * @param address An account public key.
   * @return String containing a list of unconfirmed transactions by address.
   */
  String getPendingTransactionsList(String address);

  /**
   * @brief Get asset information.
   * @param index Asset index.
   * @return AssetInformation structure containing asset's creator, manager, reserve, freeze, and clawback addresses.
   */
  AssetInformation getAssetInformation(String index);

  /**
   * @brief Get List of assets.
   * @param max Maximum number of assets to fetch.
   * @param index Asset index.
   * @return String containing a list of up to max assets.
   */
  String getAssetsList(String max, String index);

  /**
   * @brief Get the block for the given round.
   * @param round The round from which to fetch block information.
   * @return String containing the block information.
   */
  String getBlock(String round);

  /**
   * @brief Get the current supply reported by the ledger.
   * @return LedgerSupply structure containing the current supply information.
   */
  LedgerSupply getLedgerSupply(void);

  /**
   * @brief Gets the current node status.
   * @return Status structure containing the current node status information.
   */
  Status getStatus(void);

  /**
   * @brief Gets the node status after waiting for the given round.
   * @param round The round from which to fetch block information.
   * @return Status structure containing the node status information.
   */
  Status getStatus(String round);

  /**
   * @brief Get the transaction note from a single transaction.
   * @param txid A transaction id.
   * @return TransactionInformation structure containing the transaction information of the given txid.
   */
  TransactionInformation getTransactionInformation(String txid);

  /**
   * @brief Get the suggested transaction fee.
   * @return The suggested transaction fee in units of micro-Algos per byte.
   */
  int getTransactionsFee(void);

  /**
   * @brief Get parameters for constructing a new transaction.
   * @return TransactionParams structure containing the transaction parameters information.
   */
  TransactionParams getTransactionParams(void);

  /**
   * @brief Get the current version of the network.
   * @return Version structure containing the current version of the network.
   */
  Version getVersions(void);

private:
  /// Wifi network SSID.
  String _ssid;

  /// Wifi network password.
  String _password;

  /// API key to connect to a node.
  String _apiKey;

  /// Requested endpoint URL.
  String _endpoint;

  /// Fingerprint of the API provider.
  String _fingerprint;

  /**
   * @brief Fetch the requested information from the API.
   * @param route API route.
   * @return String containing the requested information.
   */
  String _fetch(String route);
};

#endif
