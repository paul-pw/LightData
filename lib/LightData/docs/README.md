# the actual LightData Library
this is the folder that has to be zipped and loaded into the arduino IDE for use in the IDE, 
recomended use is still with Platform IO and the folder structure as presented in the root directory of this repo. 

This Folder holds all the classes, functions and variables that can be used in the main arduino (.ino) file if the library gets included.
the Main file has to link to `LightData.h` (with `#include <LightData.h>`) 
and from then on every function should work if you follow all the instructions given in the other documentation

in PlatformIO for VS code to find all the new header files you need to 'PlaformIO: Rebuild intellisense index' with 'f1'
