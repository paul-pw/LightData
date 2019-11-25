#include <Arduino.h>
#include <LightData.h>

LD::LightData ld(10/*Recieve Pin*/,11/*transmit Pin*/, 9600/*check rate*/, 1250/*transmit speed*/);

void setup() {
  // put your setup code here, to run once:
  ld.setMethod(LD::LightData::Flags::SuperSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
}