#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", <network>, "<fingerprint>");

void setup()
{
  myAlgoduino.begin();
  Serial.begin(115200);
}

void loop()
{
  TransactionParams transactionParams = myAlgoduino.getTransactionParams();

  int fee = transactionParams.fee;
  String genesisID = transactionParams.genesisID;
  String genesishashb64 = transactionParams.genesishashb64;
  long lastRound = transactionParams.lastRound;
  String consensusVersion = transactionParams.consensusVersion;
  int minFee = transactionParams.minFee;

  Serial.println("fee: " + String(fee));
  Serial.println("genesisID: " + genesisID);
  Serial.println("genesishashb64: " + genesishashb64);
  Serial.println("lastRound: " + String(lastRound));
  Serial.println("consensusVersion: " + consensusVersion);
  Serial.println("minFee: " + String(minFee));
  Serial.println("");

  delay(500);
}
