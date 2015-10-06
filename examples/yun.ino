#include <Bridge.h>
#include <HttpClient.h>
#include <YunClient.h>
#include <YunServer.h>
#include <Owly.h>

YunClient yun;

Owly owly("input_username", "input_password", yun);

void setup()
{
  // Bridge for Yun
  Bridge.begin();

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

