#include <Arduino.h>
#include <LightData.h>

LD::LightData ld(1250/*transmit speed*/);
LD::LDStream* LD::LDStream::instance = &ld; //this sets the instance pointer to the correct instance of the class (needed for the ISR function)


void setup() {
    ld.setrecieve(2);
    ld.beginn()
}

void loop() {
  char in;
  int* in_arr;
  unsigned short int lenth;
  if(ld.getData(in_arr,lenth)){
      /*do stuff*/
  }
  bool isinput = ld.getData(in);

  unsigned int raw_length;
  char* rawdata = ld.getData_charArray(raw_length);

}