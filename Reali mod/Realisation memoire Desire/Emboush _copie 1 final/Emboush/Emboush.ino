#include <SoftwareSerial.h>
#include "HCSR04.h"
#include <Servo.h>

#include "NewPing.h"
#define TRIG_PIN1 3
#define ECHO_PIN1 4
#define MAX_DISTANCE 45
#define MAX_DISTANCE_R 15
#define TRIG_PIN2 5
#define ECHO_PIN2 6
#define led_rouge 7 
#define led_vert 8
void  capterDistance();
void sendMessage();
void sendMessage2();
void ouverture();
void fermeture();
long duree,duree2; // Durée de l'echo
float distance1=0,distance2=0,verifierPoubelle;
// on crée l'objet monServo
Servo monServo;  
//unsigned long embouteillageStartTime = 0;
//initialiser Module GSM
SoftwareSerial myserial(10,11); //RX,TX


unsigned long previousTime = 0; // Variable pour stocker le temps précédent
 unsigned long interval = 10000; // 1 minutes en millisecondes
unsigned long currentTime;


void setup() {
  Serial.begin(9600);
  //Premier Ultrasonic
  pinMode(TRIG_PIN1, OUTPUT); // Configuration du port du Trigger comme une SORTIE
    pinMode(ECHO_PIN1, INPUT);

   //Deuxieme Ultrasonic
     pinMode(TRIG_PIN2, OUTPUT); // Configuration du port du Trigger comme une SORTIE
    pinMode(ECHO_PIN2, INPUT);
    
    //Config led comme sortie
 pinMode(led_rouge,OUTPUT);
  pinMode(led_vert,OUTPUT);

        monServo.attach(9); // on définit le Pin utilisé par le servomoteur
        monServo.write(250);      // on dit à l'objet de mettre le servo à 250°
//digitalWrite(led_rouge, HIGH);

   delay(1000);
  //comptage du temps d'arrossage
//  embouteillageStartTime = millis();
}

void loop() {
 digitalWrite(led_rouge, HIGH);  
  //currentTime=millis();
  //
       capterDistance();
       
   //sI NE PAS REMPLI
  if(verifierPoubelle<=15){
    
     
       currentTime = millis();// Temps actuel en millisecondes
       
          
       Serial.println("ATTENTION POUBELLE REMPLIE");
         // Vérifier si le temps écoulé dépasse l'intervalle de 5 minutes
        if (currentTime - previousTime >= interval) {
          // Si le délai de 5 minutes est écoulé, envoyer le message
          
           //sendMessage();
          delay(5000);
          //sendMessage2();
           //callSomeone();
           //delay(5000);
          // Réinitialiser le temps précédent au temps actuel pour le prochain délai
     
          previousTime=currentTime;
        }

     
  }else{
      if (distance1<45) {
          ouverture();
          //capterDistance();
          
             
          }
          
       if (distance1 >50){
                // Serial.println("objet non détecté !");
              fermeture();
              //capterDistance();
              
            }
           
   
  }
          
  //delay(1000);
}

void arrosage()
{
//  if(embouteillageStartTime = 60){
//      embouteillageStartTime = 0;
//      
//      } 
}

void ouverture(){
   monServo.write(0);      // on dit à l'objet de mettre le servo à 0°
       
      digitalWrite(led_vert, HIGH);
      //arrosage();
      delay(10000); // Délai d'attente pour éviter d'afficher trop de résultats à la second
  }
  
void fermeture(){
   monServo.write(250);    // on dit à l'objet de mettre le servo à 250°
      digitalWrite(led_vert, LOW);
      arrosage();
      delay(2000); // Délai d'attente pour éviter d'afficher trop de résultats à la seconde
  }
  
 void capterDistance()
 {
//    Detection Distance pour les deux caoteurs
  // Émission d'un signal de durée 10 microsecondes
    digitalWrite(TRIG_PIN1, LOW);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN1, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN1, LOW);
    // Écoute de l'écho
    duree = pulseIn(ECHO_PIN1, HIGH);
    // Calcul de la distance
    distance1 = duree*0.034/2;

     digitalWrite(TRIG_PIN2, LOW);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN2, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN2, LOW);
    // Écoute de l'écho
    duree2 = pulseIn(ECHO_PIN2, HIGH);
    // Calcul de la distance
    distance2 = duree2*0.034/2;
 


        if(distance1<45){
          distance2=1000;
          
          
          
          }else{verifierPoubelle=distance2;}

     //previousTime=millis();
     //interval=millis();

     Serial.print("Distance1 : ");
              Serial.print(distance1);
              Serial.println(" cm");
              Serial.print("Distance2 : ");
              Serial.print(distance2);
              Serial.println(" cm");
  }
  void callSomeone()
{
  
  
   myserial.println("ATD++243972575093;");
  delay(2000);
  myserial.println();
  delay(30000); 
   myserial.println("ATH");
   delay(5000);
  }
void sendMessage(){
  
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
    
  }
 void sendMessage2()
 {
  
  myserial.print("AT+CMGF=1\r");
  delay(2000);
  myserial.println("AT+CMGS=\"+243999964829\"");
  delay(2000);  
  myserial.println("La poubelle numero 1(C. kadutu,Q. nkafu av. hopital Gen)est remplie, priere de passer la vider,Merci");
  delay(2000);  
  myserial.println((char)26);
  delay(2000);  
  myserial.println();
    delay(5000);
    myserial.print("");
    }

 
