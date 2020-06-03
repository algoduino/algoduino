#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", "<network>");

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

  Serial.println(lastRound);
  Serial.println(lastConsensusVersion);
  Serial.println(nextConsensusVersion);
  Serial.println(nextConsensusVersionRound);
  Serial.println(nextConsensusVersionSupported);
  //Serial.println(timeSinceLastRound);
  Serial.println(catchupTime);
  Serial.println(hasSyncedSinceStartup);
  Serial.println(stoppedAtUnsupportedRound);
  Serial.println("");

  delay(500);
}
