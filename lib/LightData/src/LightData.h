#pragma once

namespace LD{

    /* for now, i'm not gonna make two seperate classes for sending and recieving, since in the future I want this to be able to do both in one class on one Arduino*/
    class LightData
    {
    public:
        enum class Flags
        {
            /*with the flag Lazy, it checks the incomming value every interval(set by checkSpeed) even if there is an input from the sending device*/
            Lazy=0,
            /*with the flag SuperSpeed, it checks the incomming value every interval(set by checkSpeed) but if there is an input from the sending device,
            the incomming value can get checked much more often (set by transmitSpeed)*/
            SuperSpeed=1

            /*other flags, such as an encryption standart or something with parody bits can still be added*/
        };


    /*setup functions*/

        LightData():
            recievePin(0),
            transmitPin(0),
            checkSpeed(0),
            transmitSpeed(0),
            Method(Flags::Lazy),
            _issession(false){};

        LightData(unsigned char recievePin,unsigned char transmitPin, long checkSpeed):
            recievePin(recievePin),
            transmitPin(transmitPin),
            checkSpeed(checkSpeed),
            transmitSpeed(0),
            Method(Flags::Lazy),
            _issession(false){};

        LightData(unsigned char recievePin,unsigned char transmitPin, long checkSpeed, long transmitSpeed):
            recievePin(recievePin),
            transmitPin(transmitPin),
            checkSpeed(checkSpeed),
            transmitSpeed(transmitSpeed),
            Method(Flags::SuperSpeed),
            _issession(false){};

        ~LightData();

        void setrecievePin(unsigned char recievePin);
        void settransmitPin(unsigned char transmitPin);
        void setPins(unsigned char transmitPin,unsigned char recievePin);

        void setSpeed(long checkSpeed);
        void setSpeed(long checkSpeed, long transmitSpeed);

        void setMethod(Flags Method);

    /*sending Functions*/

        template<typename T> //Typename is that this function accepts any variable type (thus creating a new function for every new type)
        void send(T value);

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
        unsigned char recievePin;
        unsigned char transmitPin;
        long checkSpeed;
        long transmitSpeed;
        Flags Method;
        bool _issession;
    };
}