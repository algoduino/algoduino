#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", <network>);

void setup()
{
  myAlgoduino.begin();
  Serial.begin(115200);
}

void loop()
{
  Version version = myAlgoduino.getVersions();

  String versions = version.versions;
  String genesis_id = version.genesis_id;
  String genesis_hash_b64 = version.genesis_hash_b64;
  int major = version.build.major;
  int minor = version.build.minor;
  int build_number = version.build.build_number;
  String commit_hash = version.build.commit_hash;
  String branch = version.build.branch;
  String channel = version.build.channel;

  Serial.println("versions: " + versions);
  Serial.println("genesis_id: " + genesis_id);
  Serial.println("genesis_hash_b64: " + genesis_hash_b64);
  Serial.println("major: " + String(major));
  Serial.println("minor: " + String(minor));
  Serial.println("build_number: " + String(build_number));
  Serial.println("commit_hash: " + commit_hash);
  Serial.println("branch: " + branch);
  Serial.println("channel: " + channel);
  Serial.println("");

  delay(500);
}
