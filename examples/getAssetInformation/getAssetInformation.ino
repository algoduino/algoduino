#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino(<ssid>, <password>, <apiKey>, <network>, <fingerprint>);

void setup()
{
  myAlgoduino.begin();
  Serial.begin(115200);
}

void loop()
{
  AssetInformation assetInformation = myAlgoduino.getAssetInformation(<index>);

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

  Serial.println("creator: " + creator);
  //Serial.println("total: " + String(total));
  Serial.println("decimals: " + String(decimals));
  Serial.println("defaultfrozen: " + String(defaultfrozen));
  Serial.println("unitname: " + unitname);
  Serial.println("assetname: " + assetname);
  Serial.println("url: " + url);
  Serial.println("managerkey: " + managerkey);
  Serial.println("reserveaddr: " + reserveaddr);
  Serial.println("freezeaddr: " + freezeaddr);
  Serial.println("");

  delay(500);
}
