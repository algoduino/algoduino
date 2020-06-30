#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", <network>, "<fingerprint>");

void setup()
{
  myAlgoduino.begin();
  Serial.begin(115200);
}

void loop()
{
  AccountInformation accountInformation = myAlgoduino.getAccountInformation("<address>");

  long round = accountInformation.round;
  String address = accountInformation.address;
  long long amount = accountInformation.amount;
  long long pendingrewards = accountInformation.pendingrewards;
  long long amountwithoutpendingrewards = accountInformation.amountwithoutpendingrewards;
  long long rewards = accountInformation.rewards;
  String status = accountInformation.status;
  String partpkb64 = accountInformation.participation.partpkb64;
  String vrfpkb64 = accountInformation.participation.vrfpkb64;
  long votefst = accountInformation.participation.votefst;
  long votelst = accountInformation.participation.votelst;
  int votekd = accountInformation.participation.votekd;

  Serial.println("round: " + String(round));
  Serial.println("address: " + address);
  //Serial.println("amount: " + String(amount));
  //Serial.println("pendingrewards: " + String(pendingrewards));
  //Serial.println("amountwithoutpendingrewards: " + String(amountwithoutpendingrewards));
  //Serial.println("rewards: " + String(rewards));
  Serial.println("status: " + status);
  Serial.println("partpkb64: " + partpkb64);
  Serial.println("vrfpkb64: " + vrfpkb64);
  Serial.println("votefst: " + String(votefst));
  Serial.println("votelst: " + String(votelst));
  Serial.println("votekd: " + String(votekd));
  Serial.println("");

  delay(500);
}
