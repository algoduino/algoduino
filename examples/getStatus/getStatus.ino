#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", TESTNET);

void setup()
{
  myAlgoduino.begin();
  Serial.begin(115200);
}

void loop()
{
  String status = myAlgoduino.getStatus();
  Serial.println(status);  
  delay(2000);
}
