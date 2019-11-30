#include <AD5254_asukiaaa.h>

AD5254_asukiaaa potentio(AD5254_ASUKIAAA_ADDR_A0_VDD_A1_VDD);

void setup() {
  Serial.begin(115200);
  potentio.begin();
}

void loop() {
  uint8_t resister;
  if (potentio.readRDAC(0, &resister) == 0) {
    Serial.println("RDAC of channel 0 is " + String(resister));
  } else {
    Serial.println("Cannot read RDAC of channel 0.");
  }
  // Make sure the WP is connected to VDD
  if (potentio.writeRDAC(0, 200) == 0) {
    Serial.println("Update RDAC of channel 0");
  } else {
    Serial.println("Cannot update RDAC of channel 0.");
  }
  delay(1000);
}
