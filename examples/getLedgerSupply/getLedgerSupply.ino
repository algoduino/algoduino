#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", "<network>");

void setup()
{
  myAlgoduino.begin();
  Serial.begin(115200);
}

void loop()
{
  LedgerSupply ledgerSupply = myAlgoduino.getLedgerSupply();

  long round = ledgerSupply.round;
  long long totalMoney = ledgerSupply.totalMoney;
  long long onlineMoney = ledgerSupply.onlineMoney;

  Serial.println(round);
  //Serial.println(totalMoney);
  //Serial.println(onlineMoney);
  Serial.println("");

  delay(500);
}
