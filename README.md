# Algoduino

<p align="center">
    <img src="https://github.com/algoduino/algoduino/blob/master/banner.png" />
</p>

> An easy to use Library to interact with the Algorand Blockchain.

> Lead Maintainer: [Ted Nivan](https://github.com/TedNIVAN)

## Documentation

You can find installation instructions and detailed instructions on how to use this package at the [dedicated documentation site](https://www.algoduino.com/docs).

## Example

> Gets the current node status.

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

## Security

If you discover a security vulnerability within this package, please send an e-mail to hello@algoduino.com. All security vulnerabilities will be promptly addressed.

## License

[MIT](LICENSE) © [Algoduino](https://www.algoduino.com/)
