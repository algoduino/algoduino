#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", <network>);

void setup()
{
  myAlgoduino.begin();
  Serial.begin(115200);
}

void loop()
{
  TransactionInformation transactionInformation = myAlgoduino.getTransactionInformation("<txid>");

  String type = transactionInformation.type;
  String tx = transactionInformation.tx;
  String from = transactionInformation.from;
  int fee = transactionInformation.fee;
  long first_round = transactionInformation.first_round;
  long last_round = transactionInformation.last_round;
  String noteb64 = transactionInformation.noteb64;
  long round = transactionInformation.round;
  long id = transactionInformation.curxfer.id;
  int amt = transactionInformation.curxfer.amt;
  String snd = transactionInformation.curxfer.snd;
  String rcv = transactionInformation.curxfer.rcv;
  String closeto = transactionInformation.curxfer.closeto;
  int fromrewards = transactionInformation.fromrewards;
  String genesisID = transactionInformation.genesisID;
  String genesishashb64 = transactionInformation.genesishashb64;

  Serial.println(type);
  Serial.println(tx);
  Serial.println(from);
  Serial.println(fee);
  Serial.println(first_round);
  Serial.println(last_round);
  Serial.println(noteb64);
  Serial.println(round);
  Serial.println(id);
  Serial.println(amt);
  Serial.println(snd);
  Serial.println(rcv);
  Serial.println(closeto);
  Serial.println(fromrewards);
  Serial.println(genesisID);
  Serial.println(genesishashb64);
  Serial.println("");

  delay(500);
}
