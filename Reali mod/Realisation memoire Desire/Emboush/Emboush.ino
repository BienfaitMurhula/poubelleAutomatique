
#include "HCSR04.h"
#include <Servo.h>
#include "NewPing.h"
#include <SoftwareSerial.h>

 SoftwareSerial myserial(11,10);
#define TRIG_PIN1 3
#define ECHO_PIN1 4  
#define MAX_DISTANCE 45
#define MAX_DISTANCE_R 15
#define TRIG_PIN2 5
#define ECHO_PIN2 6
#define led_rouge 7 
#define led_vert 8
//fonctions
void  capterDistance();
void sendMessageverificationpoubelle();
void sendMessage();
void sendMessage2(); 
void ouverture();
void fermeture();
void activatePump();
void deactivatePump();
void sendMessageMedicament();

long duree,duree2; // Durée de l'echo
float distance1=0,distance2=0,verifierPoubelle;
// on crée l'objet monServo

Servo monServo;  
//unsigned long embouteillageStartTime = 0;



//VAIABLE POUR TEMP ENVOI MESSAGE ET APPEL
unsigned long previousTime = 0; // Variable pour stocker le temps précédent
 unsigned long interval = 3000; // 1 minutes en millisecondes
unsigned long currentTime;


//VAIABLE POUR AROSER
unsigned long previousTime2 = 0; // Variable pour stocker le temps précédent
 unsigned long interval2 = 60000; // 1 minutes en millisecondes
unsigned long currentTime2;

//VAIABLE POUR ENVOI DES DONNEES EN LIGNE
unsigned long previousTime3 = 0; // Variable pour stocker le temps précédent
 unsigned long interval3 = 60000; // 1 minutes en millisecondes
unsigned long currentTime3;

// Constante pour définir la broche à laquelle le capteur d'humidité est connecté
const int waterSensorPin = A1;
// Broches de contrôle des pompes à eau
const int relayPin = 2; // Broche de commande du relais
// Durée de fonctionnement des pompes en millisecondes
const unsigned long DUREE_POMPE = 50000;
//double verifierPoubelle;


void setup() {
   // Initialisation de la communication série avec le module GSM
    myserial.begin(9600);
    delay(5000);
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
        monServo.write(240);      // on dit à l'objet de mettre le servo à 250°
//digitalWrite(led_rouge, HIGH);

 pinMode(relayPin, OUTPUT); // Définir la broche du relais en sortie
  
   delay(500);
  //comptage du temps d'arrossage
//  embouteillageStartTime = millis();
}
//
void loop() {
 digitalWrite(led_rouge, HIGH);  
  //currentTime=millis();

   
  
  //
       arrosage();//arroser

       capterDistance();
       
   //sI NE PAS REMPLI
  if(distance2 <=15){
    
     
       currentTime = millis();// Temps actuel en millisecondes    
       Serial.println("ATTENTION POUBELLE REMPLIE");
         // Vérifier si le temps écoulé dépasse l'intervalle de 5 minutes
        if (currentTime - previousTime >= interval) {
          // Si le délai de 5 minutes est écoulé, envoyer le message
              sendMessage();
             delay(10000);
            //sendMessage2();
             callSomeone();
             delay(10000);
                     
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
          
  delay(1000);
}

void arrosage()
{
  currentTime2 = millis();// Temps actuel en millisecondes
       
         // Vérifier si le temps écoulé dépasse l'intervalle de 5 minutes
        if (currentTime2 - previousTime2 >= interval2) {
          // Si le délai de 5 minutes est écoulé, envoyer le message
               // Lecture de la valeur analogique du capteur d'humidité
                              int sensorValue = analogRead(waterSensorPin);                            
                             // Conversion de la valeur analogique en pourcentage d'humidité
                             int humidityPercentage = map(sensorValue, 0, 1023, 0, 100);
                           
                              // Affichage de la valeur d'humidité sur le moniteur série
                           Serial.print("Humidity: ");
                              Serial.print(humidityPercentage);
                              Serial.println("%");
                            
                               //test de valeur du capteur d'humidite si <=10
                                   if(humidityPercentage>12)
                                  {
                                    
                                       // Activer la pompe à eau pendant 5 secondes
                                        activatePump();
                                               Serial.println("POUBELLE ARROSEE");
                                        delay(1000); // Attendre 5 secondes
                                        deactivatePump();
                                         sendMessageverificationpoubelle();
                                        previousTime2=currentTime2;
                                        
                            
                                        
                                  }else if(humidityPercentage<12){
                                      // Désactive la pompe 1
                                      deactivatePump();
                                      
                                             
                                      // Attend un certain temps avant d'activer à nouveau la pompe 1 (ici 1 minute)
                                      //delay(60000);
                                      previousTime2=currentTime2;
                                      sendMessageMedicament();
                                      delay(10000); // Attendre 5 secondes
                                    }
                               //Attente de 1 seconde avant la prochaine lecture
                              delay(1000);
                            }
                           

          
           //sendMessage();
          delay(500);
          
          // Réinitialiser le temps précédent au temps actuel pour le prochain délai
     
          //previousTime2=currentTime2;
        }


 // Fonction pour activer la pompe à eau
  void activatePump() {
    digitalWrite(relayPin, HIGH); // Activer le relais
  }
  
  // Fonction pour désactiver la pompe à eau
  void deactivatePump() {
    digitalWrite(relayPin, LOW); // Désactiver le relais
    //delay(5000); // Attendre 5 secondes
  }

void ouverture(){
   monServo.write(0);      // on dit à l'objet de mettre le servo à 0°
       
      digitalWrite(led_vert, HIGH);
      //arrosage();
      delay(3000); // Délai d'attente pour éviter d'afficher trop de résultats à la second
  }
  
void fermeture(){
   monServo.write(240);    // on dit à l'objet de mettre le servo à 250°
      digitalWrite(led_vert, LOW);
      //arrosage();
      delay(1000); // Délai d'attente pour éviter d'afficher trop de résultats à la seconde
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

     
 


        if(distance1<45){
          distance2=1000;
          
          
          }else if(distance1>50){

            digitalWrite(TRIG_PIN2, LOW);
            delayMicroseconds(10);
            digitalWrite(TRIG_PIN2, HIGH);
            delayMicroseconds(10);
            digitalWrite(TRIG_PIN2, LOW);
            // Écoute de l'écho
            duree2 = pulseIn(ECHO_PIN2, HIGH);
            // Calcul de la distance
            distance2 = duree2*0.034/2;
            
            //verifierPoubelle=distance2;
            
            }

     //previousTime=millis();
     //interval=millis();

              Serial.print("Distance1 : ");
              Serial.print(distance1);
              Serial.println(" cm");
              Serial.print("Distance2 : ");
              Serial.print(distance2);
              Serial.println(" cm");
  }
  

void sendMessageMedicament(){
//  digitalWrite(ledsms,HIGH);
  myserial.print("AT+CMGF=1\r");
  delay(2000);
  myserial.println("AT+CMGS=\"+243971212482\"");
  delay(2000);  
  myserial.println("La poubelle numero 1(C. kadutu,Q. nkafu av. hopital Gen) n'a plus de medicament, priere de passer augmenter,Merci");
  delay(2000);  
  myserial.println((char)26);
  delay(2000);  
  myserial.println();
    delay(5000);
    myserial.print("");
//    digitalWrite(ledsms,LOW);
  }





void callSomeone()
{
  
  
   myserial.println("ATD++243971212482;");
  delay(2000);
  myserial.println();
  delay(30000); 
   myserial.println("ATH");
   delay(5000);
   
  }
void sendMessage(){
  
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
    
  }
void sendMessage2(){
 
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
   
  }
void sendMessageverificationpoubelle(){
//  digitalWrite(ledsms,HIGH);
  myserial.print("AT+CMGF=1\r");
  delay(2000);
  myserial.println("AT+CMGS=\"+243971212482\"");
  delay(2000);  
  myserial.println("La poubelle numero 1(C. kadutu,Q. nkafu av. hopital Gen) a ete bien aspergee,Merci");
  delay(2000);  
  myserial.println((char)26);
  delay(2000);  
  myserial.println();
    delay(5000);
    myserial.print("");
//    digitalWrite(ledsms,LOW);
  }

