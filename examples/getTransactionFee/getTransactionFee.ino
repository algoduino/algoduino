#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", <network>);

void setup()
{
  myAlgoduino.begin();
  Serial.begin(115200);
}

void loop()
{
  int fee = myAlgoduino.getTransactionsFee();

  Serial.println("fee: " + String(fee));
  Serial.println("");

  delay(500);
}
