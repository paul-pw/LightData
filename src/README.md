# Main Location of code

put your main code here to runn in this directory there must be one file with the 
arduino ```setup``` and ```function``` loop (not two not zero, exactly one!!! else nothing will work and you wont know why)

for the LightData library to work you further need some setup work todo.
in the Main file just put: 
```c++
#include <LightData.h>

LD::LightData ld(10/*Recieve Pin*/,11/*transmit Pin*/, 1250/*transmit speed*/);
LD::LDStream* LD::LDStream::instance = &ld; //this sets the instance pointer to the correct instance of the class (needed for the ISR function)
int LD::Session_var::id_counter=0;


void setup() 
{
  // put your setup code here, to run once:
  ld.beginn();
}

void loop() 
{

}
```
_if this doesnt work just look at the main file, you should be able to find out what must be used in the current version of the Library code_
