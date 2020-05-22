# Algoduino

<p align="center">
    <img src="https://github.com/algoduino/algoduino/blob/master/banner.png" />
</p>

> An easy to use Library to interact with the Algorand Blockchain.

> Lead Maintainer: [Ted Nivan](https://github.com/TedNIVAN)

## Documentation

You can find installation instructions and detailed instructions on how to use this package at the [dedicated documentation site](https://algoduino.github.io/documentation/class_algoduino.html).

## Example

> Gets the current node status

```cpp
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
```

> Output from Serial Monitor

```json
{
   "lastRound":6907687,
   "lastConsensusVersion":"https://github.com/algorandfoundation/specs/tree/8096e2df2da75c3339986317f9abe69d4fa86b4b",
   "nextConsensusVersion":"https://github.com/algorandfoundation/specs/tree/e5f565421d720c6f75cdd186f7098495caf9101f",
   "nextConsensusVersionRound":6915065,
   "nextConsensusVersionSupported":true,
   "timeSinceLastRound":2319203734,
   "catchupTime":0,
   "hasSyncedSinceStartup":false,
   "stoppedAtUnsupportedRound":false
}
```
## Security

If you discover a security vulnerability within this package, please send an e-mail to hello@algoduino.com. All security vulnerabilities will be promptly addressed.

## License

[MIT](LICENSE) © [Algoduino](https://www.algoduino.com/)
