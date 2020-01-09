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
    class Session_var
    {
    public:
        Session_var():
            id(id_counter++){}

        int content;
        int id;
        static int id_counter;
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
            recieve_arraysintIndex(0),
            _issession(false){};


        LightData(unsigned char recievePin,unsigned char transmitPin, long Speed):
            LDStream(recievePin,transmitPin,Speed),
            recieve_charIndex(0),
            recieve_arraysintIndex(0),
            _issession(false){};

        LightData(unsigned char recievePin,unsigned char transmitPin):
            LDStream(recievePin,transmitPin),
            recieve_charIndex(0),
            recieve_arraysintIndex(0),
            _issession(false){};

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


        void session_start(Session_var[]); /*this needs to get some kind of struct or something, so that it knows all the nescesary variables that get send every so often*/
        void session_update(Session_var[]); /*when this is called all session variables are forced to get updated, 
                                else the variables get updatet when the programm recognizes a value change in these variables*/
        void session_stop();


    /*recieving functions*/

        void wait_for_input();
        void wait_for_session_start();
        bool issession(){   return _issession;  }

        LD::data getData();/****this also needs something where it can dump the data to*******
                        (1): this function dups out all the data send in the last stream
                        (2): this function also dumps out all the session information, specifications & data if a session is started*/


    protected:
        volatile LD::data L2_buffer;
        volatile LD::data L2_data; //L2 because now the incoming data is gets further processed
        volatile unsigned int recieve_charIndex; //the number of the recieved char (when the length of the message is known this gets set and then countet down)
        volatile unsigned char recieve_arraysintIndex;
        bool _issession;
        Session_var* session_vars;
        virtual void processData(volatile char Data);
        LD::data constructData(){LD::data tmp; return tmp;};
    };



}
