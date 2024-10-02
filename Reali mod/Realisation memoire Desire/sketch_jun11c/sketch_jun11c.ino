#include <SoftwareSerial.h>

// Définir les broches RX et TX pour la communication avec le module SIM900A
SoftwareSerial sim900A(10, 11);

void setup() {
  // Ouvrir la communication série avec une vitesse de 9600 bps
  Serial.begin(9600);

  // Ouvrir la communication avec le module SIM900A
  sim900A.begin(9600);

  // Attendre que le module SIM900A s'initialise
  delay(2000);

  // Envoyer une commande AT pour vérifier la communication avec le module
  sim900A.println("AT");
  delay(1000);

  // Vérifier si le module SIM900A est prêt
  if (sim900A.find('O')) {
    Serial.println("Module SIM900A prêt.");
  } else {
    Serial.println("Erreur de communication avec le module SIM900A.");
    while (1); // Boucle infinie en cas d'erreur
  }

  // Configurer le module SIM900A pour l'envoi de messages texte en mode texte
  sim900A.println("AT+CMGF=1");
  delay(1000);
}

void loop() {
  // Envoyer un message texte
  sim900A.println("AT+CMGS=\"+243978167647\"");  
  // Remplacez +1234567890 par le numéro de téléphone du destinataire
  delay(1000);
  sim900A.print("Hello, ceci est un message texte envoyé depuis le module SIM900A.");
  delay(100);
  sim900A.println((char)26);  
  // Envoyer le caractère de fin Ctrl+Z
  delay(5000);

  // Attendre 10 secondes avant d'envoyer un autre message
  delay(10000);
}


