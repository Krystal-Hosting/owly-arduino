#include "Arduino.h"
#include "Owly.h"
#include "libs/PubSubClient/PubSubClient.h"
#include "libs/PubSubClient/PubSubClient.cpp"
#include "Client.h"

PubSubClient _pubsubclient();

Owly::Owly(const char *inputuser_username, const char *inputuser_password, Client& client)
{
    this->_inputuser_username = inputuser_username;
    this->_inputuser_password = inputuser_password;
    this->_clientid = inputuser_username; // TODO Should be changed to a random string.
    
    _pubsubclient.setClient(client);
    _pubsubclient.setServer("mqtt.owly.uk", 1883);
}

void Owly::Publish(char* topic, int int_payload)
{
    char payload[10];
    sprintf(payload, "%d", int_payload);
    _pubsubclient.publish(topic, payload);
}

void Owly::Publish(char* topic, char* payload)
{
     _pubsubclient.publish(topic, payload);
}

boolean Owly::Connect()
{
    return _pubsubclient.connect(this->_clientid, this->_inputuser_username, this->_inputuser_password);
}

void Owly::Loop()
{
    if (!_pubsubclient.connected())
    {
        _pubsubclient.connect(this->_clientid, this->_inputuser_username, this->_inputuser_password);
    }
    
    _pubsubclient.loop();
}