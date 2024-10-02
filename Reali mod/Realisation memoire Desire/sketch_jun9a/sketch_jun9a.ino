#include <SoftwareSerial.h>

SoftwareSerial gsm(7,8);

void setup() {
  // Configuration de la vitesse de communication avec le module SIM900A
  Serial.begin(9600);
  gsm.begin(9600);
}

void loop() 
{
  
  if(gsm.available()){
      Serial.write(gsm.read());
  }
 if(gsm.available()){
    byte a=Serial.read();
    if(a=='#')
    {
      gsm.write("");
    }
    else
    {
      gsm.write(a);
    }  
}
}
