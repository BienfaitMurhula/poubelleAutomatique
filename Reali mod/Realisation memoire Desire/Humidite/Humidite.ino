// Constante pour définir la broche à laquelle le capteur d'humidité est connecté
const int waterSensorPin = A1;
// Broches de contrôle des pompes à eau
const int relayPin = 12; // Broche de commande du relais

// Durée de fonctionnement des pompes en millisecondes
const unsigned long DUREE_POMPE = 50000;

void setup() {
  // Initialisation de la communication série
  Serial.begin(9600);
   // Initialise les broches des pompes en sortie
  //pinMode(PIN_POMPE_1, OUTPUT);

  pinMode(relayPin, OUTPUT); // Définir la broche du relais en sortie
  
}

void loop() {
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
            delay(500); // Attendre 5 secondes
            deactivatePump();

            
      }else if(humidityPercentage<12){
          // Désactive la pompe 1
          deactivatePump();
          
                 
          // Attend un certain temps avant d'activer à nouveau la pompe 1 (ici 1 minute)
          //delay(60000);
        }
   //Attente de 1 seconde avant la prochaine lecture
  delay(1000);
}
// Fonction pour activer la pompe à eau
void activatePump() {
  digitalWrite(relayPin, HIGH); // Activer le relais
}

// Fonction pour désactiver la pompe à eau
void deactivatePump() {
  digitalWrite(relayPin, LOW); // Désactiver le relais
  delay(5000); // Attendre 5 secondes
}

