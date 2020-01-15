#include <Arduino.h>
#include <LightData.h>

LD::LightData ld(1250/*transmit speed*/);
LD::LDStream* LD::LDStream::instance = &ld; //this sets the instance pointer to the correct instance of the class (needed for the ISR function)


void setup() {
  // put your setup code here, to run once:
  ld.settransmit(5);
  ld.beginn()
}

void loop() {
  int arr [] = { 1,2,3,4,2,34,2334,2,3,5 };
  ld.send(arr, ARRAY_SIZE(arr));
  delay(600);
  ld.send('H');
}