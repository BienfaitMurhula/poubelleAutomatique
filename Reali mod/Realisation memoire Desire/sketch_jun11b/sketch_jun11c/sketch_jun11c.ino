// Définition des broches de contrôle
const int relayPin = 12; // Broche de commande du relais

void setup() {
  pinMode(relayPin, OUTPUT); // Définir la broche du relais en sortie
}

void loop() {
  // Activer la pompe à eau pendant 5 secondes
  activatePump();
  delay(10000); // Attendre 5 secondes

  // Désactiver la pompe à eau pendant 5 secondes
  deactivatePump();
  delay(10000); // Attendre 5 secondes
}

// Fonction pour activer la pompe à eau
void activatePump() {
  digitalWrite(relayPin, HIGH); // Activer le relais
}

// Fonction pour désactiver la pompe à eau
void deactivatePump() {
  digitalWrite(relayPin, LOW); // Désactiver le relais
}

