
#include "HCSR04.h"
#include "Servo.h"  // on inclut la bibliothèque pour piloter un servomoteur
#include "SoftwareSerial.h"
//#include "GSM.h"

// Définition des numéros de port
/*const int trigPin = 8; // Trigger (émission)
const int echoPin = 9; // Echo (réception)
int led_rouge=12;
int led_jaune=7;
// Variables utiles
long duree; // Durée de l'echo
float distance;*/
Servo monServo;  // on crée l'objet monServo

/*// Configuration des broches de communication série
const int GSM_TX_PIN = 3;  // Broche de transmission du module GSM
const int GSM_RX_PIN = 4;  // Broche de réception du module GSM

//SoftwareSerial gsmSerial(GSM_TX_PIN, GSM_RX_PIN);  // Création d'un objet SoftwareSerial pour communiquer avec le module GSM
*/


void setup() {

/*
    pinMode(trigPin, OUTPUT); // Configuration du port du Trigger comme une SORTIE
    pinMode(echoPin, INPUT); // Configuration du port de l'Echo comme une ENTREE
    Serial.begin(9600) ; // Démarrage de la communication série à 9600 bits/s
    pinMode(led_rouge, OUTPUT);
    pinMode(led_jaune, OUTPUT);*/
    monServo.attach(8); // on définit le Pin utilisé par le servomoteur
        monServo.write(250);      // on dit à l'objet de mettre le servo à 0°



    // Initialisation du port série pour le débogage
  Serial.begin(9600);

  
}
    

void loop() {

  /*
    // Émission d'un signal de durée 10 microsecondes
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Écoute de l'écho
    duree = pulseIn(echoPin, HIGH);
    // Calcul de la distance
    distance = duree*0.034/2;
    // Affichage de la distance dans le Moniteur Série
    //Serial.print("Distance en cm :") ;
    if(distance <50)
    {
      //Serial.println("moins de 5") ; 
      digitalWrite(led_jaune, HIGH);
      digitalWrite(led_rouge, LOW);*/

        monServo.write(0);      // on dit à l'objet de mettre le servo à 0°
      
            
      delay(5000); // Délai d'attente pour éviter d'afficher trop de résultats à la seconde
    /*
    }
    else
    {
      
      //Serial.println("5 ou plus") ;      
      digitalWrite(led_rouge, HIGH);
      
      digitalWrite(led_jaune, LOW);
      //delay(500); // Délai d'attente pour éviter d'afficher trop de résultats à la seconde
        // on dit à l'objet de mettre le servo à 180°
      */
      monServo.write(250);    // on dit à l'objet de mettre le servo à 180°
      //monServo.write(250);    // on dit à l'objet de mettre le servo à 180°

        delay(5000); // Délai d'attente pour éviter d'afficher trop de résultats à la seconde
    /*}
       delay(500); // Délai d'attente pour éviter d'afficher trop de résultats à la seconde
  

  // Envoi du message texte
  int ret = gsmAccess.sendSMS(destNumber, "Ceci est un message texte envoyé depuis un module GSM Arduino.");

  // Vérification du résultat de l'envoi
  if (ret == GSM_OK) {
    Serial.println("Message texte envoyé avec succès !");
  } else {
    Serial.println("Erreur lors de l'envoi du message texte.");
  }

  // Attente avant le prochain envoi de message
  delay(3600000);


// Envoi d'un message texte
  //sendSMS("+243976296356", "bonjour, je suis un robot !");
  
  //delay(500000);  // Attente de 5 secondes entre chaque envoi de message
*/
}

