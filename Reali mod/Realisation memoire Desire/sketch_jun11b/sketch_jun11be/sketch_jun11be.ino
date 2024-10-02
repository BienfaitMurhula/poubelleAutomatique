// Broches de contrôle des pompes à eau
const int PIN_POMPE_1 = 13;
const int PIN_POMPE_2 = 12;

// Durée de fonctionnement des pompes en millisecondes
const unsigned long DUREE_POMPE = 50000;

void setup() {
  // Initialise les broches des pompes en sortie
  pinMode(PIN_POMPE_1, OUTPUT);
  pinMode(PIN_POMPE_2, OUTPUT);
}

void loop() {
  // Active la pompe 1 pendant la durée spécifiée
  digitalWrite(PIN_POMPE_1, HIGH);
  delay(DUREE_POMPE);
  
  // Désactive la pompe 1
  digitalWrite(PIN_POMPE_1, LOW);
  
  // Attend un certain temps avant d'activer à nouveau la pompe 1 (ici 1 minute)
  delay(60000);
  
  // Active la pompe 2 pendant la durée spécifiée
  digitalWrite(PIN_POMPE_2, HIGH);
  delay(DUREE_POMPE);
  
  // Désactive la pompe 2
  digitalWrite(PIN_POMPE_2, LOW);
  
  // Attend un certain temps avant d'activer à nouveau la pompe 2 (ici 1 minute)
  delay(60000);
}

