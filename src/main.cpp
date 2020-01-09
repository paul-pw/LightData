#include <Arduino.h>
#include <LightData.h>

LD::LightData ld(10/*Recieve Pin*/,11/*transmit Pin*/, 1250/*transmit speed*/);
LD::LDStream* LD::LDStream::instance = &ld; //this sets the instance pointer to the correct instance of the class (needed for the ISR function)
int LD::Session_var::id_counter=0;


void setup() {
  // put your setup code here, to run once:
  ld.beginn();
}

void loop() {
  int arr [] = { 1,2,3,4,2,34,2334,2,3,5 };
  ld.send(arr, ARRAY_SIZE(arr));
  ld.send('H');
}