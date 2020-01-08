#ifndef _AD5254_ASUKIAAA_H_
#define _AD5254_ASUKIAAA_H_
#include <Arduino.h>
#include <Wire.h>

#define AD5254_ASUKIAAA_ADDR_A0_GND_A1_GND B0101100
#define AD5254_ASUKIAAA_ADDR_A0_GND_A1_VDD B0101101
#define AD5254_ASUKIAAA_ADDR_A0_VDD_A1_GND B0101110
#define AD5254_ASUKIAAA_ADDR_A0_VDD_A1_VDD B0101111

class AD5254_asukiaaa {
 public:
  AD5254_asukiaaa(int address);
  void setWire(TwoWire* wire);
  int begin();
  int writeRDAC(uint8_t ch, uint8_t v);
  int readRDAC(uint8_t ch, uint8_t* v);
  int saveEEPROM(uint8_t ch, uint8_t v);
  int loadEEPROM(uint8_t ch, uint8_t* v);

 private:
  int address;
  TwoWire* wire;
  int writeI2c(uint8_t regAddr, uint8_t v);
  int readI2c(uint8_t regAddr, uint8_t* v);
};

#endif
