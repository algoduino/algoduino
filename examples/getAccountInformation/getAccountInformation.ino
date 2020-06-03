#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", "<network>");

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

  Serial.println(round);
  Serial.println(address);
  //Serial.println(amount);
  //Serial.println(pendingrewards);
  //Serial.println(amountwithoutpendingrewards);
  //Serial.println(rewards);
  Serial.println(status);
  Serial.println(partpkb64);
  Serial.println(vrfpkb64);
  Serial.println(votefst);
  Serial.println(votelst);
  Serial.println(votekd);
  Serial.println("");

  delay(500);
}
