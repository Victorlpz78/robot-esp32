// Test HC-SR04 - Jarvis Victor
// Trig = D26, Echo = D25 (adapté du schéma officiel GPIO5/GPIO18)

const int trigPin = 26;
const int echoPin = 25;

void setup() {
  Serial.begin(115200);       // vitesse moniteur série standard ESP32
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Envoyer une impulsion de 10µs sur Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mesurer la durée de l'écho (en microsecondes)
  long duration = pulseIn(echoPin, HIGH, 30000); // timeout 30ms

  if (duration == 0) {
    Serial.println("Pas d'écho reçu");
  } else {
    // Distance = (durée x vitesse du son) / 2 (aller-retour)
    float distance = duration * 0.0343 / 2; // en cm
    Serial.print("Distance : ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(500); // une mesure toutes les 0,5s
}