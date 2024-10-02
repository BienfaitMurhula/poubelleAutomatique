#include <SoftwareSerial.h>
#define GSM_TX_PIN 1
#define GSM_RX_PIN 0
#define GSM_BAUD_RATE 9600

 SoftwareSerial gsmSerial(GSM_TX_PIN,GSM_RX_PIN); 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
gsmSerial.begin(GSM_BAUD_RATE);
delay(100);
Serial.println("AT+CMGF=1");
delay(100);
gsmSerial.println("AT+CMGS=\"+243978167647\"");
delay(100);
gsmSerial.println("Salut");
delay(100);
gsmSerial.write(0x1A);
delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:

}
