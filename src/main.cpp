#include <Arduino.h>
#include <LightData.h>

LD::LightData ld(10/*Recieve Pin*/,11/*transmit Pin*/, 1250/*transmit speed*/);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  int arr [] = { 1,2,3,4,2,34,2334,2,3,5 };
  ld.send(arr, ARRAY_SIZE(arr));
  ld.send('H');
  // put your main code here, to run repeatedly:

  //use bitset and bitread to set and read bits
}