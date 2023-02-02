Servo roueD;
Servo roueG;
#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "SoftwareSerial.h"

char ssid[] = "Iphone de Greg";     //  Nom du reseau WIFI
char pass[] = "grxggg...";  // Mot de passe
int status = WL_IDLE_STATUS;

unsigned int localPort = 8888;
char packetBuffer[255]; //buffer to hold incoming packet
WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  pinMode(LED,OUTPUT); // déclaration en sortie des broches où sont cablées les leds
  // Tentative de connexion au reseau WIFI
  while ( status != WL_CONNECTED) {
    Serial.print("Connexion au reseau : ");
    Serial.println(ssid);
    Serial.println();
    status = WiFi.begin(ssid,pass);
    delay(5000); // Delais de 5s pour attendre la connection
    if (status != WL_CONNECTED) Serial.println("Erreur de connexion");
  }
  Serial.println("Connecte au WiFi");
  IPAddress ip = WiFi.localIP(); // Afficher adresse IP
  Serial.print("Adresse IP : "); // Afficher adresse IP
  Serial.println(ip); // Afficher adresse IP
  Serial.println("\nPret a recevoir des donnees...");
  udp.begin(localPort);
}





void loop () {
  udp.read(packetBuffer,255);
  if (packetBuffer[1]==0x32){
    // // il fait le 1er mouvement: c'est à dire il tourne de 20°
    roueD.attach(8);
    roueD.writeMicroseconds(1515);
    roueG.attach(9);
    Serial.begin(9600);
    roueG.writeMicroseconds(1505);
  }
  else if (packetBuffer[1] == 0x32){
    // il fait le 2ème mouvement: c'est à dire il avance 
    roueD.attach(8);
    roueD.writeMicroseconds(1515);
    roueG.attach(9);
    Serial.begin(9600);
    roueG.writeMicroseconds(1505);
  }
}
