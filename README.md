# robot-esp32
Mon robot autonome sur ESP32
## Test du capteur HC-SR04

Ce programme mesure la distance à un obstacle avec un capteur à ultrasons HC-SR04 branché sur l'ESP32 (Trig sur GPIO26, Echo sur GPIO25). Il envoie une impulsion de 10 µs, mesure le temps de retour de l'écho avec `pulseIn()`, puis calcule la distance en cm (durée × vitesse du son ÷ 2). Le résultat s'affiche toutes les 0,5 s dans le moniteur série à 115200 bauds, avec un message si aucun écho n'est reçu. Il sert de brique de base pour la détection d'obstacles du mini-véhicule autonome.
