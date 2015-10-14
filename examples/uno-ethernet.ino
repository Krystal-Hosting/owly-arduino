#include <SPI.h>
#include <Ethernet.h>
#include <Owly.h>

// Update these with values suitable for your network.
byte mac[]    = {  0x90, 0xA2, 0xDA, 0x0D, 0xC0, 0x7F };
IPAddress ip(192, 168, 1, 123);

EthernetClient ethClient;

Owly owly("input_username", "input_password", ethClient);

void setup()
{
  // Uno Ethernet Shield Start
  Ethernet.begin(mac, ip);

  // Let the hardware relax
  delay(2000);
  
  if(owly.Connect())
  {
    // Publish a message!
    owly.Publish("your_topic", "your_value");

    // Four blinks for success!
    blink();
    blink();
    blink();
    blink();
  }
  else
  {
    // Two blinks for error!
    blink();
    blink();
  }
}

void loop()
{
  // Loop and keep the connection open.
  owly.Loop(); 
}

void blink()
{
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(100);
}
