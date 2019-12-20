#pragma once
namespace LD{

    /* Stream class for the Hardware Protocoll implementation*/
    class LDStream
    {
    public:

    /*setup functions*/

        LDStream(long Speed):
            recievePin(0),
            recieve(false),
            transmitPin(0),
            transmit(false),
            Speed(Speed),
            buffer(0){};
        
        LDStream(unsigned char recievePin,unsigned char transmitPin, long Speed):
            recievePin(recievePin),
            recieve(true),
            transmitPin(transmitPin),
            transmit(true),
            Speed(Speed),
            buffer(0){};

        LDStream(unsigned char recievePin,unsigned char transmitPin):
            recievePin(recievePin),
            recieve(true),
            transmitPin(transmitPin),
            transmit(true),
            Speed(0),
            buffer(0){};

        void beginn();
        void beginn(long Speed);
        void setrecieve(unsigned char recievePin);
        void settransmit(unsigned char transmitPin);
        void setPins(unsigned char transmitPin,unsigned char recievePin);

    /*sending Functions*/
    void send(char Data);



    /*recieving functions*/
    char read();


    protected:
        static LDStream *instance;
        unsigned char recievePin;
        bool recieve;
        unsigned char transmitPin;
        bool transmit;
        long Speed;
        /*variables needed for reciving*/
        volatile char buffer;
        volatile char data;
        volatile unsigned long oldTime;

        static void ISRfunc(){
            instance->dataStream();
        }

        void dataStream();

        virtual void processData(char data){};
    /*virtual because we need the inheriting classes to have a definition for this function
    Diese function wird in der derived class ('LightData') deffiniert und wird immer gecalled wenn ein neues byte an input daten vorhanden ist*/
    };


}
