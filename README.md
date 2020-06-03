# Algoduino

<p align="center">
    <img src="https://github.com/algoduino/algoduino/blob/master/banner.png" />
</p>

> An easy to use Library to interact with the Algorand Blockchain.

> Lead Maintainer: [Ted Nivan](https://github.com/TedNIVAN)

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

  Serial.println(type);
  Serial.println(tx);
  Serial.println(from);
  Serial.println(fee);
  Serial.println(first_round);
  Serial.println(last_round);
  Serial.println(noteb64);
  Serial.println(round);
  Serial.println(id);
  Serial.println(amt);
  Serial.println(snd);
  Serial.println(rcv);
  Serial.println(closeto);
  Serial.println(fromrewards);
  Serial.println(genesisID);
  Serial.println(genesishashb64);
  Serial.println("");

  delay(500);
}
```

> Output from Serial Monitor

```
pay
BIZJ4NW67NRL7OCLCO4DJKURDEUH6MWMWNUCNMDBFVUOBLVHUQRQ
PRICEP3G2F5L6ZG5WTJIAKEQW4OJJ3FM4XVFQDZI7M2VBTFVUHTTR2AU2U
1000
7051531
7052031
eyJwcmljZV9hbGdvX3VzZCI6MC4yNDM0NTczMjg1NTIyMzYzNywicHJpY2VfYWxnb19idGMiOjAuMDAwMDI1Mzc4MTM1NTAzNzEyNDQ4LCJsYXN0X3RyYWRlX2F0IjoiMjAyMC0wNi0wM1QyMTo0ODo0NC4yM1oiLCJ0aW1lc3RhbXAiOiIyMDIwLTA2LTAzVDIxOjQ4OjU4LjIzMFoifQ==
7051533
0
0
null
null
null
0
null
null
```
## Security

If you discover a security vulnerability within this package, please send an e-mail to hello@algoduino.com. All security vulnerabilities will be promptly addressed.

## License

[MIT](LICENSE) © [Algoduino](https://www.algoduino.com/)
