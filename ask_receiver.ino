#include <RH_ASK.h>

RH_ASK driver;

void setup()
{
    Serial.begin(9600); 
    if (!driver.init())
         Serial.println("no radio");
}

#define BUFSIZE 10

void loop()
{
    uint8_t buf[BUFSIZE];
    uint8_t buflen;

    buflen = BUFSIZE;
    if (driver.recv(buf, &buflen)) 
    {
      Serial.print("Received "); Serial.print(buflen,DEC); Serial.write(" bytes:  ");
      buf[buflen]=0;
      Serial.println((char*)buf);         
    }
}
