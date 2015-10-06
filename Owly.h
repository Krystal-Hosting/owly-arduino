#ifndef Owly_h
#define Owly_h

#include "Arduino.h"
#include "libs/PubSubClient/PubSubClient.h"
#include "Client.h"

class Owly
{
    public:
        Owly(const char *inputuser_username, const char *inputuser_password, Client& client);
        boolean Connect();
        void Loop();
        void Publish(char* topic, int int_payload);
        void Publish(char* topic, char* payload);
        void Blink(int time);
    
    private:
        const char *_inputuser_username;
        const char *_inputuser_password;
        const char *_clientid;
        PubSubClient _pubsubclient;
};

#endif