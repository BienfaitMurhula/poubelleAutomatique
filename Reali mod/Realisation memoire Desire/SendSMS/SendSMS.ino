#include <SoftwareSerial.h>
int ledsms=4;
int ledappel=5;



 SoftwareSerial myserial(11,10);
void setup() 
{
  // Initialisation de la communication série avec le module GSM
    myserial.begin(9600);
    delay(5000);
    //sendMessage();
    //callSomeone();
  pinMode(ledsms,OUTPUT);
  pinMode(ledappel,OUTPUT);
}

void loop() {
  sendMessage();
  delay(10000);
  //sendMessage2();
   callSomeone();
   delay(10000);
    
}
void callSomeone()
{
  digitalWrite(ledappel,HIGH);
  
   myserial.println("ATD++243972575093;");
  delay(2000);
  myserial.println();
  delay(30000); 
   myserial.println("ATH");
   delay(5000);
   digitalWrite(ledappel,LOW);
  }
void sendMessage(){
  digitalWrite(ledsms,HIGH);
  myserial.print("AT+CMGF=1\r");
  delay(2000);
  myserial.println("AT+CMGS=\"+243972575093\"");
  delay(2000);  
  myserial.println("La poubelle numero 1(C. kadutu,Q. nkafu av. hopital Gen)est remplie, priere de passer la vider,Merci");
  delay(2000);  
  myserial.println((char)26);
  delay(2000);  
  myserial.println();
    delay(5000);
    myserial.print("");
    digitalWrite(ledsms,LOW);
  }
void sendMessage2(){
  digitalWrite(ledsms,HIGH);
  myserial.print("AT+CMGF=1\r");
  delay(2000);
  myserial.println("AT+CMGS=\"+243971212482\"");
  delay(2000);  
  myserial.println("La poubelle numero 1(C. kadutu,Q. nkafu av. hopital Gen)est remplie, priere de passer la vider,Merci");
  delay(2000);  
  myserial.println((char)26);
  delay(2000);  
  myserial.println();
    delay(5000);
    myserial.print("");
    digitalWrite(ledsms,LOW);
  }

