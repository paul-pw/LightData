#include "LightData.h"
#include <Arduino.h>

#define TYPE_LEN 1
#define ISARRAY_LEN 1
#define ARRAYLEN_LEN 2

#define ISARRAY 'A'
#define ISNOTARRAY 'N'

enum types{
    sess_start=0,
    _char,
    _uchar,
    _sint,
    _usint,
    _int,
    _uint,
    _llint,
    _ullint,
    _float,
    _double,
    _ldouble,
};

namespace LD
{
/*sending Functions*/
    void LightData::send(char value)
    {
        char binary[TYPE_LEN+ISARRAY_LEN+sizeof(value)];
        binary[0] = (char)types::_char;
        binary[1] = ISNOTARRAY;
        binary[2] = value;

    }


    //function definitions still missing


    void LightData::send(unsigned char value){}
    void LightData::send(short int value){}
    void LightData::send(unsigned short int value){}
    void LightData::send(int value){}
    void LightData::send(unsigned int value){}
    void LightData::send(long long int value){}
    void LightData::send(unsigned long long int value){}
    void LightData::send(float value){}
    void LightData::send(double value){}
    void LightData::send(long double value){}

    void LightData::send(char value[],unsigned int length){}
    void LightData::send(unsigned char value[],unsigned int length){}
    void LightData::send(short int value[],unsigned int length){}
    void LightData::send(unsigned short int value[],unsigned int length){}
    void LightData::send(int value[],unsigned int length){}
    void LightData::send(unsigned int value[],unsigned int length){}
    void LightData::send(long long int value[],unsigned int length){}
    void LightData::send(unsigned long long int value[],unsigned int length){}
    void LightData::send(float value[],unsigned int length){}
    void LightData::send(double value[],unsigned int length){}
    void LightData::send(long double value[],unsigned int length){}

    void session_start(/*some kind of input needs to go in here*/){}
    void session_update(){}
    void session_stop(){}
} // namespace LD