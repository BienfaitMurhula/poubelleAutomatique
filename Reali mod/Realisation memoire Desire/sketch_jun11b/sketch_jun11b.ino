#include <GSM.h>

// Paramètres de connexion au réseau GSM
//char apn[] = "apn_du_reseau";
//char gprsUser[] = "nom_d_utilisateur_gprs";
//char gprsPass[] = "mot_de_passe_gprs";

// Numéro de téléphone de destination
char destNumber[] = "+243978167647";

// Objet GSM
GSM gsmAccess;

void setup() {
  // Initialisation du port série pour le débogage
  Serial.begin(9600);

  // Initialisation de la connexion GSM
  while (gsmAccess.begin() != GSM_READY) {
    Serial.println("Connexion au réseau GSM en cours...");
    delay(1000);
  }
  Serial.println("Connexion au réseau GSM réussie.");
}

void loop() {
  // Envoi du message texte
//  int ret = gsmAccess.sendSMS(destNumber, "Ceci est un message texte envoyé depuis un module GSM Arduino.");

  // Vérification du résultat de l'envoi
//  if (ret == GSM_OK) {
//    Serial.println("Message texte envoyé avec succès !");
//  } else {
//    Serial.println("Erreur lors de l'envoi du message texte.");
//  }

  // Attente avant le prochain envoi de message
  delay(10000);
}

