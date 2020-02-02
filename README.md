# AD5254_asukiaaa

A library to manage 256 position 4 ch digital potentiometer AD5254.

# Usage

```c
#include <AD5254_asukiaaa.h>

AD5254_asukiaaa potentio(AD5254_ASUKIAAA_ADDR_A0_VDD_A1_VDD);

uint8_t targetChannel = 0;
String targetChannelStr = String(targetChannel);

void setup() {
  Serial.begin(115200);

  // Wire2.begin();
  // potentio.setWire(&Wire2);

  potentio.begin();
}

void loop() {
  uint8_t value;
  if (potentio.readRDAC(targetChannel, &value) == 0) {
    Serial.println("RDAC of channel " + targetChannelStr + " is " + String(value));
  } else {
    Serial.println("Cannot read RDAC of channel " + targetChannelStr + ".");
  }

  uint8_t targetValue = (millis() / 1000) % 256;
  if (potentio.writeRDAC(targetChannel, targetValue) == 0) {
    Serial.println("Update RDAC of channel " + targetChannelStr + " to " + String(targetValue));
  } else {
    Serial.println("Cannot update RDAC of channel " + targetChannelStr + ".");
  }

  delay(1000);
}
```

See [example projects](./examples) and [header file](./src/AD5254_asukiaaa.h) to know more information.

# License

MIT

# References

- [AD5254 product info](https://www.analog.com/en/products/ad5254.html)
- [AD5253/AD5254 Datasheet (PDF)](https://www.analog.com/media/en/technical-documentation/data-sheets/AD5253_5254.pdf)
- [asukiaaa/AD5254Breakout](https://github.com/asukiaaa/AD5254Breakout)
- [ポテンショメーター（信号で制御可能な可変抵抗）AD5254をArduinoで制御してみた](http://asukiaaa.blogspot.com/2020/01/ad5254arduino.html)
