#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", <network>);

void setup()
{
  myAlgoduino.begin();
  Serial.begin(115200);
}

void loop()
{
  AssetInformation assetInformation = myAlgoduino.getAssetInformation("<index>");

  String creator = assetInformation.creator;
  long long total = assetInformation.total;
  int decimals = assetInformation.decimals;
  bool defaultfrozen = assetInformation.defaultfrozen;
  String unitname = assetInformation.unitname;
  String assetname = assetInformation.assetname;
  String url = assetInformation.url;
  String managerkey = assetInformation.managerkey;
  String reserveaddr = assetInformation.reserveaddr;
  String freezeaddr = assetInformation.freezeaddr;
  String clawbackaddr = assetInformation.clawbackaddr;

  Serial.println(creator);
  //Serial.println(total);
  Serial.println(decimals);
  Serial.println(defaultfrozen);
  Serial.println(unitname);
  Serial.println(assetname);
  Serial.println(url);
  Serial.println(managerkey);
  Serial.println(reserveaddr);
  Serial.println(freezeaddr);
  Serial.println("");

  delay(500);
}
