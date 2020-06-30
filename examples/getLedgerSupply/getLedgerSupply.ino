#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino(<ssid>, <password>, <apiKey>, <network>, <fingerprint>);

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

  Serial.println("round: " + String(round));
  //Serial.println("totalMoney: " + String(totalMoney));
  //Serial.println("onlineMoney: " + String(onlineMoney));
  Serial.println("");

  delay(500);
}
