# LightData 
**Abstract:**
_new Data Protocol for use in arduino, especialy targeted for the use with fiber optics cables_ 

## the API
for the Library to compile you must include these lines of code in your source file
```c++
#include <LightData.h>
LD::LightData ld(); //any other cunstructor of LightData can also be used
LD::LDStream* LD::LDStream::instance = &ld;
int LD::Session_var::id_counter=0; 
```
and for the Library to _work_ you must include 
```c++
  ld.beginn(); //or anny other LightData::beginn function
```
in the `setup` part of the main arduino Programm 
( ``.beginn()` initializes the ISR function)

the following functions can then be used:
* `.send(/*input here*/)` put anny data in there and it will be send over the fiberoptics cable (_take a look at the code to see what you can **actualy** send_)
* `.getData()` dumps out the last recieved Data as an `LD::data` object
* `.wait_for_input()` will just wait until the next input occures
```diff
- more functions are found in the code but they will not yet work Properly since they are not finnished yet
! also some more functions are not named here since they are only nescesary for setup and can be easily understood by looking at the code
```

## implement in the Arduino IDE
for the LightData Library to be used in the **Arduino IDE** you need to zip
 the folder of the library and then in the Arduino 
IDE included like so:
`Sketch/include Libraries/add .ZIP Library` ind it, add it 
and then with `Sketch/include Libraries/LightData` include it in your code.

_an already zipped and compiling version of the library can be found 
as an release on github_

for more information on libraries in Arduino and especialy **PlatformIO** please take a look at [this File](lib/README.md)

## Platform IO
in Development of this Library we used Platform IO and not the Standart Arduino IDE. this is because the Arduino IDE lacks some important features we needed in development. all of these Features are found in Platform IO and VScode. these Features include:
* Syntax highlighting
* Code Autocompletion
* a propper file explorer
* a workspace System
* integration with Git & Github
