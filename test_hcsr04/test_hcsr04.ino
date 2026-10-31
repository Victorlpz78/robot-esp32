// Test HC-SR04 - Jarvis Victor
// Trig = GPIO5, Echo = GPIO18 (adapté du schéma officiel)

const int trigPin = 5;
const int echoPin = 18;

void setup() {
  Serial.begin(115200);        // 1) ouvrir le port série EN PREMIER
  delay(500);                  // petite attente pour que la liaison soit prête
  Serial.println("JV-EFF002"); // 2) puis envoyer le marqueur

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

  delay(500); // une mesure toutes les 0,5 s
}
