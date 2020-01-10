# Library

This directory is intended for project specific (private) libraries. 

also this is the place where the **Light Data** Library lives. 
for the Libraries to be used in the **Arduino IDE** you need to zip the 
folder of the library
(in the bottom example the folder _Foo_ or _bar_) and then in the Arduino 
IDE included over `Sketch/include Libraries/add .ZIP Library` found, added 
and then with `Sketch/include Libraries/LightData` included
_an already zipped and compiling version of the library can be found 
as an release on github_

**PlatformIO** will compile them to static libraries and link into executable file. <br>
The source code of each library should be placed in a an own separate directory
("lib/your_library_name/[here are source files]").

For example, see a structure of the following two libraries `Foo` and `Bar`:


```
|--lib
|  |
|  |--Bar
|  |  |--docs
|  |  |--examples
|  |  |--src
|  |     |- Bar.c
|  |     |- Bar.h
|  |  |- library.json (optional, custom build options, etc) https://docs.platformio.org/page/librarymanager/config.html !!for use in the Arduino IDE needed
|  |
|  |--Foo
|  |  |- Foo.c
|  |  |- Foo.h
|  |
|  |- README --> THIS FILE
|
|- platformio.ini
|--src
   |- main.c
```

and a contents of `src/main.c`:
```
#include <Foo.h>
#include <Bar.h>

int main (void)
{
  ...
}

```

PlatformIO Library Dependency Finder will find automatically dependent
libraries scanning project source files.

More information about PlatformIO Library Dependency Finder
- https://docs.platformio.org/page/librarymanager/ldf.html
