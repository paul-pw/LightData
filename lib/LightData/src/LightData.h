#pragma once

#include "Stream/LDStream.h"
#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))

namespace LD{


    enum types{
        empty,
        sess_start,
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
        arr_char,
        arr_uchar,
        arr_sint,
        arr_usint,
        arr_int,
        arr_uint,
        arr_llint,
        arr_ullint,
        arr_float,
        arr_double,
        arr_ldouble,
    };

    class data
    {
    public:
        data():
            Data(nullptr),
            type(types::empty),
            length(0){}
        void* Data;
        types type;
        unsigned short length;
    };

    

    /* for now, i'm not gonna make two seperate classes for sending and recieving, since in the future I want this to be able to do both in one class on one Arduino*/
    /*LightData class for software protocoll implementation*/
    class LightData : public LDStream
    {
    public:

    /*setup functions*/

        LightData(long Speed):
            LDStream(Speed),
            recieve_charIndex(0),
            recieve_arraysintIndex(0){};


        LightData(unsigned char recievePin,unsigned char transmitPin, long Speed):
            LDStream(recievePin,transmitPin,Speed),
            recieve_charIndex(0),
            recieve_arraysintIndex(0){};

        LightData(unsigned char recievePin,unsigned char transmitPin):
            LDStream(recievePin,transmitPin),
            recieve_charIndex(0),
            recieve_arraysintIndex(0)){};

    /*sending Functions*/

        //this function is written so that it can accept every data type needed that this function accepts any variable type (thus creating a new function for every new type)
        void send(char value);
        void send(unsigned char value);
        void send(short int value);
        void send(unsigned short int value);
        void send(int value);
        void send(unsigned int value);
        void send(long long int value);
        void send(unsigned long long int value);
        void send(float value);
        void send(double value);
        void send(long double value);
        //or arrays like this
        void send(char value[],unsigned short int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(unsigned char value[],unsigned short int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(short int value[],unsigned short int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(unsigned short int value[],unsigned short int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(int value[],unsigned short int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(unsigned int value[],unsigned short int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(long long int value[],unsigned short int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(unsigned long long int value[],unsigned short int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(float value[],unsigned short int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(double value[],unsigned short int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(long double value[],unsigned short int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);



    /*recieving functions*/

        LD::data getData();/* this function dups out all the data send in the last stream*/


    protected:
        volatile LD::data L2_buffer;
        volatile LD::data L2_data; //L2 because now the incoming data is gets further processed
        volatile unsigned int recieve_charIndex; //the number of the recieved char (when the length of the message is known this gets set and then countet down)
        volatile unsigned char recieve_arraysintIndex;
        virtual void processData(volatile char Data);
        LD::data constructData(){LD::data tmp; return tmp;};
    };



}
