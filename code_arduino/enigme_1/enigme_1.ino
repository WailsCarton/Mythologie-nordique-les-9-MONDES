#include "SoftwareSerial.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "SoftwareSerial.h"
 
#if defined(ARDUINO_ARCH_AVR)
#define SERIAL Serial
SoftwareSerial mySerial(2,3);
#define TRANS_SERIAL  mySerial
#elif defined(ARDUINO_ARCH_SAMD)
#define SERIAL SerialUSB
#define TRANS_SERIAL  Serial
#else
 
#endif
rgb_lcd lcd;
 
const int colorR = 255;
const int colorG = 0;
const int colorB = 0; 
//RX=2,TX=3(D2) Software Serial Port

char ssid[] = "ssid";     //  Nom du reseau WIFI
char pass[] = "pass";  // Mot de passe

int status = WL_IDLE_STATUS;

unsigned int localPort = 8888;
IPAddress remoteIP(192,168,42,176); // Adresse IP du receveur
WiFiUDP udp;

 String donnees;
 int a;
 
void setup() {
    TRANS_SERIAL.begin(9600);
    lcd.begin(16, 2); 
    Serial.begin(115200);
    
    lcd.setRGB(colorR, colorG, colorB);
    SERIAL.begin(9600);  // start serial for output
    SERIAL.println("Version:v1.0");
    lcd.print("4 + * = 6");
}
 
void loop() {
    printData();
}
 
/*
* data mapping:E1---1；E2---2；E3---3；E4---4；E5---5；E6---6；
*              E7---7；E8---8；E9---9；EA---*；EB---0；EC---#；
*/
void printData() {
    while(TRANS_SERIAL.available()) {
        uint8_t data = TRANS_SERIAL.read();
        lcd.setCursor(0, 1);
        switch(data) {
                case 0xE1 :
                    lcd.println("1");
                    break;
                case 0xE2 :
                    lcd.println("2");
                    a = 2;
                    break;
                case 0xE3 :
                    lcd.println("3");
                    break;
                case 0xE4 :
                    lcd.println("4");
                    break;
                case 0xE5 :
                    lcd.println("5");
                    break;
                case 0xE6 :
                    lcd.println("6");
                    break;
                case 0xE7 :
                    lcd.println("7");
                    break;
                case 0xE8 :
                    lcd.println("8");
                    break;
                case 0xE9 :
                    lcd.println("9");
                    break;
                case 0xEA :
                    lcd.println("*");
                    break;
                case 0xEB :
                    lcd.println("0");
                    break;
                case 0xEC :
                    lcd.println("#");
                    break;
                default:
                    break;
            }
    }
    if (a == 2){
    udp.beginPacket(remoteIP, 8888);
    udp.write("#1");
    udp.endPacket(); 
    }
}
