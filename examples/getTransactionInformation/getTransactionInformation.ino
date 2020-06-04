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

  Serial.println("type: " + type);
  Serial.println("txt: " + tx);
  Serial.println("from: " + from);
  Serial.println("fee: " + String(fee));
  Serial.println("first_round: " + String(first_round));
  Serial.println("last_round: " + String(last_round));
  Serial.println("noteb64: " + noteb64);
  Serial.println("round: " + String(round));
  Serial.println("id: " + String(id));
  Serial.println("amt: " + String(amt));
  Serial.println("snd: " + snd);
  Serial.println("rcv: " + rcv);
  Serial.println("closeto: " + closeto);
  Serial.println("fromrewards: " + String(fromrewards));
  Serial.println("genesisID: " + genesisID);
  Serial.println("genesishashb64: " + genesishashb64);
  Serial.println("");

  delay(500);
}
