#pragma once

#include "Stream/LDStream.h"
#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))

namespace LD{

    /* for now, i'm not gonna make two seperate classes for sending and recieving, since in the future I want this to be able to do both in one class on one Arduino*/
    /*LightData class for software protocoll implementation*/
    class LightData : public LDStream
    {
    public:

    /*setup functions*/

        LightData(long Speed):
            LDStream(Speed),
            _issession(false){};


        LightData(unsigned char recievePin,unsigned char transmitPin, long Speed):
            LDStream(recievePin,transmitPin,Speed),
            _issession(false){};

        LightData(unsigned char recievePin,unsigned char transmitPin):
            LDStream(recievePin,transmitPin),
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
        void send(char value[],unsigned int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(unsigned char value[],unsigned int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(short int value[],unsigned int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(unsigned short int value[],unsigned int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(int value[],unsigned int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(unsigned int value[],unsigned int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(long long int value[],unsigned int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(unsigned long long int value[],unsigned int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(float value[],unsigned int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(double value[],unsigned int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);
        void send(long double value[],unsigned int length /*Length can be evaluated with ARRAY_SIZE(arr)*/);


        void session_start(/*some kind of input needs to go in here*/); /*this needs to get some kind of struct or something, so that it knows all the nescesary variables that get send every so often*/
        void session_update(); /*when this is called all session variables are forced to get updated, 
                                else the variables get updatet when the programm recognizes a value change in these variables*/
        void session_stop();


    /*recieving functions*/

        void wait_for_input();
        void wait_for_session_start();
        bool issession(){   return _issession;  }

        void getData();/****this also needs something where it can dump the data to*******
                        (1): this function dups out all the data send in the last stream
                        (2): this function also dumps out all the session information, specifications & data if a session is started*/


    protected:
        bool _issession;
        virtual void processData(char Data);
    };


}
