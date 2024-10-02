#include <SoftwareSerial.h>

// Configuration des broches pour la communication série avec le module SIM900a
SoftwareSerial sim900(8,7);  // RX, TX

void setup()
{
  // Ouvre la communication série avec une vitesse de bauds de 9600
  Serial.begin(9600);
  sim900.begin(9600);

  // Attendre que le module SIM900a s'initialise
  delay(2000);
   
  // Envoyer une commande AT pour vérifier la communication avec le module SIM900a
  sim900.println("AT");
}

void loop()
{
  if (sim900.available())
  {
    // Afficher les réponses du module SIM900a sur le moniteur série
    Serial.write(sim900.read());
  }

  if (Serial.available())
  {
    // Envoyer les commandes saisies sur le moniteur série vers le module SIM900a
    sim900.write(Serial.read());
  }
}

 
