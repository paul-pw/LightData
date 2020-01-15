#pragma once

#include "Stream/LDStream.h"
#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))

namespace LD{

    //defines all the types that can be used to send data (basicaly just assigns every type a number 0x00 - 0xe6)
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

    //this class holds all the data recieved
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

    

    /* only one class for beth sending and recieving cause in the future one arduino should be able to do both (send and recieve) */
    /*LightData class for high level (Bytewise) protocoll implementation*/
    class LightData : public LDStream
    {
    public:

    /*setup functions*/
        //constructor functions (reference the LDStream constructor)
        LightData(long Speed):
            LDStream(Speed),
            L2_buffer(nullptr),
            L2_buffer_length(0),
            L2_buffer_index(0),
            L2_data(nullptr),
            L2_data_length(0),
            L2_buffer_type(types::empty),
            L2_buffer_arraylength(0),
            L2_buffer_arraylength_byteindex(0){};


        LightData(unsigned char recievePin,unsigned char transmitPin, long Speed):
            LDStream(recievePin,transmitPin,Speed),
            L2_buffer(nullptr),
            L2_buffer_length(0),
            L2_buffer_index(0),
            L2_data(nullptr),
            L2_data_length(0),
            L2_buffer_type(types::empty),
            L2_buffer_arraylength(0),
            L2_buffer_arraylength_byteindex(0){};

        LightData(unsigned char recievePin,unsigned char transmitPin):
            LDStream(recievePin,transmitPin),
            L2_buffer(nullptr),
            L2_buffer_length(0),
            L2_buffer_index(0),
            L2_data(nullptr),
            L2_data_length(0),
            L2_buffer_type(types::empty),
            L2_buffer_arraylength(0),
            L2_buffer_arraylength_byteindex(0){};

    /*sending Functions*/

        //these functions are written so that they can accept every data type (thus creating a new function for type)
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
        char* getData_charArray(){return (char*)L2_data;}/*this function dups out all the data send in the last stream*/
        
        bool getData(char &Buffer);
        bool getData(unsigned char &Buffer);
        bool getData(short int &Buffer);
        bool getData(unsigned short int &Buffer);
        bool getData(int &Buffer);
        bool getData(unsigned int &Buffer);
        bool getData(long long int &Buffer);
        bool getData(unsigned long long int &Buffer);
        bool getData(float &Buffer);
        bool getData(double &Buffer);
        bool getData(long double &Buffer);

        bool getData(char* &Buffer,unsigned short int &length);
        bool getData(unsigned char* &Buffer,unsigned short int &length);
        bool getData(short int* &Buffer,unsigned short int &length);
        bool getData(unsigned short int* &Buffer,unsigned short int &length);
        bool getData(int* &Buffer,unsigned short int &length);
        bool getData(unsigned int* &Buffer,unsigned short int &length);
        bool getData(long long int* &Buffer,unsigned short int &length);
        bool getData(unsigned long long int* &Buffer,unsigned short int &length);
        bool getData(float* &Buffer,unsigned short int &length);
        bool getData(double* &Buffer,unsigned short int &length);
        bool getData(long double* &Buffer,unsigned short int &length);


    protected:
        volatile char* L2_buffer;//L2 because now the incoming data is gets further processed
        volatile unsigned int L2_buffer_length;
        volatile unsigned int L2_buffer_index;
        volatile char* L2_data;
        volatile unsigned int L2_data_length;

        volatile types L2_buffer_type;
        volatile unsigned short int L2_buffer_arraylength;
        volatile unsigned char L2_buffer_arraylength_byteindex;
        virtual void processData(volatile char Data);
    };



}
