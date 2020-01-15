#include "LightData.h"
#include <Arduino.h>

#define ARRAYLEN_LEN 2

namespace LD
{
/*sending Functions*/
    /************************
     * al of these functions first send the type of the variable as the first byte
     *  and then Data as the next bytes
     ************************/
    void LightData::send(char value)
    {
        LDStream::send((char)types::_char); //casting operation
        LDStream::send(value);
    }

    void LightData::send(unsigned char value)
    {
        LDStream::send((char)types::_uchar); //casting operation
        LDStream::send((char)value); //casting operation
    }

    void LightData::send(short int value)
    {
        LDStream::send((char)types::_sint); //casting operation
        for (unsigned int i = 0; i < sizeof(value); i++)
        {
            LDStream::send((char)(value & 0xff)); //casting operation
            value >>= 8;
        }
    }

    void LightData::send(unsigned short int value)
    {
        LDStream::send((char)types::_usint); //casting operation
        for (unsigned int i = 0; i < sizeof(value); i++)
        {
            LDStream::send((char)(value & 0xff)); //casting operation
            value >>= 8;
        }
    }

    void LightData::send(int value)
    {
        LDStream::send((char)types::_int); //casting operation
        for (unsigned int i = 0; i < sizeof(value); i++)
        {
            LDStream::send((char)(value & 0xff)); //casting operation
            value >>= 8;
        }
    }

    void LightData::send(unsigned int value)
    {
        LDStream::send((char)types::_uint); //casting operation
        for (unsigned int i = 0; i < sizeof(value); i++)
        {
            LDStream::send((char)(value & 0xff)); //casting operation
            value >>= 8;
        }
    }

    void LightData::send(long long int value)
    {
        LDStream::send((char)types::_llint); //casting operation
        for (unsigned int i = 0; i < sizeof(value); i++)
        {
            LDStream::send((char)(value & 0xff)); //casting operation
            value >>= 8;
        }
    }
    
    void LightData::send(unsigned long long int value)
    {
        LDStream::send((char)types::_llint); //casting operation
        for (unsigned int i = 0; i < sizeof(value); i++)
        {
            LDStream::send((char)(value & 0xff)); //casting operation
            value >>= 8;
        }
    }
    

    //array sending functions
    /************************
     * al of these functions first send the type of the variable as the first byte
     * then two bytes as Array length
     * and then Data as the next bytes
     ************************/

    void LightData::send(char value[],unsigned short int length)
    {
        LDStream::send((char)types::arr_char); //casting operation

        //send the length of the array
        LDStream::send((char)(length >> 8)); //casting operation
        LDStream::send((char)(length & 0xff)); //casting operation

        //send the contents of the array
        for (unsigned int i = 0; i < length; i++)
        {
            LDStream::send(value[i]);
        }
        
    }

    void LightData::send(unsigned char value[],unsigned short int length)
    {
        LDStream::send((char)types::arr_uchar); //casting operation

        //send the length of the array
        LDStream::send((char)(length >> 8)); //casting operation
        LDStream::send((char)(length & 0xff)); //casting operation

        //send the contents of the array
        for (unsigned int i = 0; i < length; i++)
        {
            LDStream::send((char)value[i]);
        }
    }

    void LightData::send(short int value[],unsigned short int length)
    {
        LDStream::send((char)types::arr_sint); //casting operation

        //send the length of the array
        LDStream::send((char)(length >> 8)); //casting operation
        LDStream::send((char)(length & 0xff)); //casting operation

        //send the contents of the array
        for (unsigned int i = 0; i < length; i++)
        {
            for (unsigned int j = 0; j < sizeof(value[0]); j++)
            {
                LDStream::send((char)(value[i] & 0xff)); //casting operation
                value[i] >>= 8;
            }
        }
    }

    void LightData::send(unsigned short int value[],unsigned short int length)
    {
        LDStream::send((char)types::arr_usint); //casting operation

        //send the length of the array
        LDStream::send((char)(length >> 8)); //casting operation
        LDStream::send((char)(length & 0xff)); //casting operation

        //send the contents of the array
        for (unsigned int i = 0; i < length; i++)
        {
            for (unsigned int j = 0; j < sizeof(value[0]); j++)
            {
                LDStream::send((char)(value[i] & 0xff)); //casting operation
                value[i] >>= 8;
            }
        }
    }

    void LightData::send(int value[],unsigned short int length)
    {
        LDStream::send((char)types::arr_int); //casting operation

        //send the length of the array
        LDStream::send((char)(length >> 8)); //casting operation
        LDStream::send((char)(length & 0xff)); //casting operation

        //send the contents of the array
        for (unsigned int i = 0; i < length; i++)
        {
            for (unsigned int j = 0; j < sizeof(value[0]); j++)
            {
                LDStream::send((char)(value[i] & 0xff)); //casting operation
                value[i] >>= 8;
            }
        }
    }

    void LightData::send(unsigned int value[],unsigned short int length)
    {
        LDStream::send((char)types::arr_uint); //casting operation

        //send the length of the array
        LDStream::send((char)(length >> 8)); //casting operation
        LDStream::send((char)(length & 0xff)); //casting operation

        //send the contents of the array
        for (unsigned int i = 0; i < length; i++)
        {
            for (unsigned int j = 0; j < sizeof(value[0]); j++)
            {
                LDStream::send((char)(value[i] & 0xff)); //casting operation
                value[i] >>= 8;
            }
        }
    }
    
    void LightData::send(long long int value[],unsigned short int length)
    {
        LDStream::send((char)types::arr_llint); //casting operation

        //send the length of the array
        LDStream::send((char)(length >> 8)); //casting operation
        LDStream::send((char)(length & 0xff)); //casting operation

        //send the contents of the array
        for (unsigned int i = 0; i < length; i++)
        {
            for (unsigned int j = 0; j < sizeof(value[0]); j++)
            {
                LDStream::send((char)(value[i] & 0xff)); //casting operation
                value[i] >>= 8;
            }
        }
    }

    void LightData::send(unsigned long long int value[],unsigned short int length)
    {
        LDStream::send((char)types::arr_ullint); //casting operation

        //send the length of the array
        LDStream::send((char)(length >> 8)); //casting operation
        LDStream::send((char)(length & 0xff)); //casting operation

        //send the contents of the array
        for (unsigned int i = 0; i < length; i++)
        {
            for (unsigned int j = 0; j < sizeof(value[0]); j++)
            {
                LDStream::send((char)(value[i] & 0xff)); //casting operation
                value[i] >>= 8;
            }
        }
    }

    //function definitions still missing
    /*** these function deffinitions are not ready since 
     * turning them into bytes is complicated 
     * and we havend found a way to do so ...Yet***/
    void LightData::send(float value){}
    void LightData::send(double value){}
    void LightData::send(long double value){}
    
    void LightData::send(float value[],unsigned short int length){}
    void LightData::send(double value[],unsigned short int length){}
    void LightData::send(long double value[],unsigned short int length){}
} // namespace LD