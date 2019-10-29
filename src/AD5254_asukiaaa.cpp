#include <AD5254_asukiaaa.h>

AD5254_asukiaaa::AD5254_asukiaaa(int address) {
  this->address = address;
  this->wire = NULL;
}

void AD5254_asukiaaa::setWire(TwoWire* wire) {
  this->wire = wire;
}

int AD5254_asukiaaa::begin() {
  if (wire == NULL) {
    wire = &Wire;
    wire->begin();
  }
  wire->beginTransmission(address);
  return wire->endTransmission();
}

int AD5254_asukiaaa::writeRDAC(uint8_t ch, uint8_t v) {
  if (ch >= 4) return -1;
  uint8_t regAddr = ch;
  return writeI2c(regAddr, v);
}

int AD5254_asukiaaa::readRDAC(uint8_t ch, uint8_t* v) {
  if (ch >= 4) return -1;
  uint8_t regAddr = ch;
  return readI2c(regAddr, v);
}

int AD5254_asukiaaa::writeI2c(uint8_t regAddr, uint8_t v) {
  wire->beginTransmission(address);
  wire->write(regAddr);
  wire->write(v);
  return wire->endTransmission();
}

int AD5254_asukiaaa::readI2c(uint8_t regAddr, uint8_t* v) {
  wire->beginTransmission(address);
  wire->write(regAddr);
  int result = wire->endTransmission();
  if (result != 0) return result;

  wire->requestFrom(address, 1);
  while (wire->available()) {
    *v = wire->read();
  }
  return 0;
}
