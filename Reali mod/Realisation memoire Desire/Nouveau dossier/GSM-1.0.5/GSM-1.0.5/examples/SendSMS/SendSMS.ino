#include <SoftwareSerial.h>

 SoftwareSerial myserial(7,8);
void setup() {
  // Initialisation de la communication série avec le module GSM
  myserial.begin(9600);
  Serial.begin(9600);
   Serial.println("S-Send sms");
}

void loop() {
    if(Serial.available()>0)
      switch(Serial.read()){
              
    case 's':
    sendMessage();
    break;  
  }
}

void sendMessage(){
  myserial.println("AT+CMGF=1");
  delay(1000);
  myserial.println("AT+CMGs=\"+243972575093\"\r");
  delay(1000);  
  myserial.println("Je suis un robot concu pour vous informer");
  delay(1000);  
  myserial.println((char)(26));
  delay(1000);  

  
  }


