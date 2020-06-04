#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", <network>);

void setup()
{
  myAlgoduino.begin();
  Serial.begin(115200);
}

void loop()
{
  Status status = myAlgoduino.getStatus();

  long lastRound = status.lastRound;
  String lastConsensusVersion = status.lastConsensusVersion;
  String nextConsensusVersion = status.nextConsensusVersion;
  long nextConsensusVersionRound = status.nextConsensusVersionRound;
  bool nextConsensusVersionSupported = status.nextConsensusVersionSupported;
  long long timeSinceLastRound = status.timeSinceLastRound;
  int catchupTime = status.catchupTime;
  bool hasSyncedSinceStartup = status.hasSyncedSinceStartup;
  bool stoppedAtUnsupportedRound = status.stoppedAtUnsupportedRound;

  Serial.println("lastRound: " + String(lastRound));
  Serial.println("lastConsensusVersion: " + lastConsensusVersion);
  Serial.println("nextConsensusVersion: " + nextConsensusVersion);
  Serial.println("nextConsensusVersionRound: " + String(nextConsensusVersionRound));
  Serial.println("nextConsensusVersionSupported: " + String(nextConsensusVersionSupported));
  //Serial.println("timeSinceLastRound: " + String(timeSinceLastRound));
  Serial.println("catchupTime: " + String(catchupTime));
  Serial.println("hasSyncedSinceStartup: " + String(hasSyncedSinceStartup));
  Serial.println("stoppedAtUnsupportedRound: " + String(stoppedAtUnsupportedRound));
  Serial.println("");

  delay(500);
}
