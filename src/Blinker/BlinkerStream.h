#ifndef BLINKER_STREAM_H
#define BLINKER_STREAM_H

#if ARDUINO >= 100
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif

// #if defined(BLINKER_AT_MQTT)
//     #include "Blinker/BlinkerMQTTATBase.h"
// #endif

class BlinkerStream
{
    public :
        virtual int available() = 0;
        virtual char * lastRead() = 0;
        virtual void flush() = 0;
        // virtual int print(const String & s, bool needCheck = true) = 0;
        virtual int print(char * data, bool needCheck = true) = 0;
        virtual int connect() = 0;
        virtual int connected() = 0;
        virtual void disconnect() = 0;

        #if defined(BLINKER_MQTT) || defined(BLINKER_PRO) || \
            defined(BLINKER_AT_MQTT) || defined(BLINKER_MQTT_AT) || \
            defined(BLINKER_GATEWAY)           
            virtual int aliPrint(const String & data) = 0;
            virtual int duerPrint(const String & data) = 0; 
            // virtual void ping() = 0;
        #endif

        #if defined(BLINKER_MQTT) || defined(BLINKER_PRO) || \
            defined(BLINKER_AT_MQTT) || defined(BLINKER_GATEWAY)
            virtual char * deviceName() = 0;
            virtual char * authKey() = 0;
            virtual int init() = 0;           
            virtual int mConnected() = 0;
            virtual int bPrint(char * name, const String & data) = 0;
            virtual int autoPrint(uint32_t id) = 0;
            virtual void freshAlive() = 0;
            virtual void sharers(const String & data);
            virtual int aligenieAvail() = 0;
            virtual int duerAvail() = 0;
            virtual int needFreshShare() = 0;
        #endif

        // #if defined(BLINKER_MQTT) || defined(BLINKER_PRO)
        //     virtual int aligenieAvail() = 0;
        //     virtual int duerAvail() = 0;
        #if defined(BLINKER_AT_MQTT)
            virtual void begin(const char* auth) = 0;
            // virtual void begin() = 0;
            virtual int serialAvailable() = 0;
            virtual int serialPrint(const String & s1, const String & s2, bool needCheck = true) = 0;
            virtual int serialPrint(const String & s, bool needCheck = true) = 0;
            virtual int mqttPrint(const String & data);
            virtual char * serialLastRead() = 0;
            virtual void aligenieType(int _type) = 0;
            virtual void duerType(int _type) = 0;
            virtual char * deviceId() = 0;
            virtual char * uuid() = 0;
            virtual void softAPinit() = 0;
            virtual void smartconfig() = 0;
            virtual int autoInit() = 0;
            virtual void connectWiFi(String _ssid, String _pswd) = 0;
            virtual void connectWiFi(const char* _ssid, const char* _pswd) = 0;
        #endif

        #if defined(BLINKER_PRO)
            virtual int deviceRegister() = 0;
            virtual int authCheck() = 0;
            virtual void begin(const char* _deviceType) = 0;
        #endif
};

#endif
