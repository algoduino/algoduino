# Algoduino

<p align="center">
    <img src="https://github.com/algoduino/assets/blob/master/Algoduino-banner.png" />
</p>

> An easy to use Library to interact with the Algorand Blockchain.

> Lead Maintainer: [Ted Nivan](https://github.com/TedNIVAN)

> <img src="https://www.ardu-badge.com/badge/Algoduino.svg" />
## Documentation

You can find installation instructions and detailed instructions on how to use this package at the [dedicated documentation site](https://algoduino.github.io/documentation/class_algoduino.html).

## Example

> Get the information of a single transaction.

```cpp
#include <Algoduino.h>

Algoduino myAlgoduino = Algoduino("<ssid>", "<password>", "<apiKey>", <network>);

void setup()
{
  myAlgoduino.begin();
  Serial.begin(115200);
}

void loop()
{
  TransactionInformation transactionInformation = myAlgoduino.getTransactionInformation("<txid>");

  String type = transactionInformation.type;
  String tx = transactionInformation.tx;
  String from = transactionInformation.from;
  int fee = transactionInformation.fee;
  long first_round = transactionInformation.first_round;
  long last_round = transactionInformation.last_round;
  String noteb64 = transactionInformation.noteb64;
  long round = transactionInformation.round;
  long id = transactionInformation.curxfer.id;
  int amt = transactionInformation.curxfer.amt;
  String snd = transactionInformation.curxfer.snd;
  String rcv = transactionInformation.curxfer.rcv;
  String closeto = transactionInformation.curxfer.closeto;
  int fromrewards = transactionInformation.fromrewards;
  String genesisID = transactionInformation.genesisID;
  String genesishashb64 = transactionInformation.genesishashb64;

  Serial.println("type: " + type);
  Serial.println("txt: " + tx);
  Serial.println("from: " + from);
  Serial.println("fee: " + String(fee));
  Serial.println("first_round: " + String(first_round));
  Serial.println("last_round: " + String(last_round));
  Serial.println("noteb64: " + noteb64);
  Serial.println("round: " + String(round));
  Serial.println("id: " + String(id));
  Serial.println("amt: " + String(amt));
  Serial.println("snd: " + snd);
  Serial.println("rcv: " + rcv);
  Serial.println("closeto: " + closeto);
  Serial.println("fromrewards: " + String(fromrewards));
  Serial.println("genesisID: " + genesisID);
  Serial.println("genesishashb64: " + genesishashb64);
  Serial.println("");

  delay(500);
}
```

> Output from Serial Monitor

```
type: pay
txt: BIZJ4NW67NRL7OCLCO4DJKURDEUH6MWMWNUCNMDBFVUOBLVHUQRQ
from: PRICEP3G2F5L6ZG5WTJIAKEQW4OJJ3FM4XVFQDZI7M2VBTFVUHTTR2AU2U
fee: 1000
first_round: 7051531
last_round: 7052031
noteb64: eyJwcmljZV9hbGdvX3VzZCI6MC4yNDM0NTczMjg1NTIyMzYzNywicHJpY2VfYWxnb19idGMiOjAuMDAwMDI1Mzc4MTM1NTAzNzEyNDQ4LCJsYXN0X3RyYWRlX2F0IjoiMjAyMC0wNi0wM1QyMTo0ODo0NC4yM1oiLCJ0aW1lc3RhbXAiOiIyMDIwLTA2LTAzVDIxOjQ4OjU4LjIzMFoifQ==
round: 7051533
id: 0
amt: 0
snd: null
rcv: null
closeto: null
fromrewards: 0
genesisID: null
genesishashb64: null
```
## Security

If you discover a security vulnerability within this package, please send an e-mail to hello@algoduino.com. All security vulnerabilities will be promptly addressed.

## License

[MIT](LICENSE) © [Algoduino](https://algoduino.com/)
