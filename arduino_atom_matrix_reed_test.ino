/*

PINOUT ATOM MATRIX (M5STACK)

                    WIFI
                  ________________
             3V3 |                |
  reed2 +3V3 G22 |                |G21 reed1 +3.3V
             G19 |     BOTTOM     |G25
             G23 |                |5V
  reed2 GND  G33 |________________|GND reed1 GND
                   GND 5V G26 G32

*/
#include <Adafruit_NeoPixel.h>

// constants won't change. They're used here to set pin numbers:
const int ReedPin = 21;       // the number of the pushbutton pin
const int ReedPin2 = 22;      // the number of the pushbutton pin
const int ReedPin2_gnd = 33;  // the number of the pushbutton pin

// Paramètres de la bande LED
#define LED_PIN 27   // 23: default Pin de données pour les LEDs BAND 2
#define MAX_LEDS 25  // Nombre maximum de LEDs prises en charge

Adafruit_NeoPixel strip1(MAX_LEDS, LED_PIN, NEO_RGB + NEO_KHZ800);

#define WAIT_BLINK 100

unsigned long previousMillis;
int i = 0;
int matrice_led[8] = { 6, 7, 8, 13, 18, 17, 16, 11 };
int indice = 0;


// variables will change:
int ReedState = 0;   // variable for reading the pushbutton status
int ReedState2 = 0;  // variable for reading the pushbutton status

void setup() {
  Serial.begin(115200);  // Initialiser la communication série
  strip1.begin();        // Initialiser la bande LED
  strip1.show();         // Éteindre toutes les LEDs au démarrage

  strip1.setPixelColor(0, strip1.Color(255, 0, 0));
  strip1.show();
  delay(250);
  strip1.setPixelColor(0, strip1.Color(0, 0, 0));
  strip1.show();
  delay(250);
  strip1.setPixelColor(0, strip1.Color(255, 0, 0));
  strip1.show();
  delay(250);
  strip1.setPixelColor(0, strip1.Color(0, 0, 0));
  strip1.show();
  delay(250);
  // initialize the pushbutton pin as an input:
  pinMode(ReedPin, INPUT_PULLUP);

  pinMode(ReedPin2, INPUT_PULLUP);
  pinMode(ReedPin2_gnd, OUTPUT);
  digitalWrite(ReedPin2_gnd, LOW);
}

void loop() {

  if (millis() >= previousMillis) {
    previousMillis = millis() + WAIT_BLINK;
    strip1.setPixelColor(6, strip1.Color(0, 0, 0));
    strip1.setPixelColor(7, strip1.Color(0, 0, 0));
    strip1.setPixelColor(8, strip1.Color(0, 0, 0));
    strip1.setPixelColor(13, strip1.Color(0, 0, 0));
    strip1.setPixelColor(18, strip1.Color(0, 0, 0));
    strip1.setPixelColor(17, strip1.Color(0, 0, 0));
    strip1.setPixelColor(16, strip1.Color(0, 0, 0));
    strip1.setPixelColor(11, strip1.Color(0, 0, 0));
    i++;
    strip1.setPixelColor(matrice_led[i % 8], strip1.Color(0, 0, 0));
    strip1.setPixelColor(matrice_led[(i + 1) % 8], strip1.Color(0, 0, 0));
    strip1.setPixelColor(matrice_led[(i + 2) % 8], strip1.Color(0, 0, 10));
    strip1.setPixelColor(matrice_led[(i + 3) % 8], strip1.Color(0, 0, 20));
    strip1.setPixelColor(matrice_led[(i + 4) % 8], strip1.Color(0, 0, 30));
    strip1.setPixelColor(matrice_led[(i + 5) % 8], strip1.Color(0, 0, 40));
    strip1.setPixelColor(matrice_led[(i + 6) % 8], strip1.Color(0, 0, 50));
    strip1.setPixelColor(matrice_led[(i + 7) % 8], strip1.Color(0, 0, 70));
  }

  // read the state of the pushbutton value:
  digitalWrite(ReedPin2_gnd, LOW);
  ReedState = digitalRead(ReedPin);
  ReedState2 = digitalRead(ReedPin2);
  digitalWrite(ReedPin2_gnd, HIGH);

  Serial.print(ReedState);
  Serial.print(",");
  Serial.println(ReedState2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (ReedState == HIGH) {
    // turn LED on:
    strip1.setPixelColor(0, strip1.Color(0, 0, 0));
    strip1.setPixelColor(5, strip1.Color(0, 0, 0));
    strip1.setPixelColor(10, strip1.Color(0, 0, 0));
    strip1.setPixelColor(15, strip1.Color(0, 0, 0));
    strip1.setPixelColor(20, strip1.Color(0, 0, 0));

  } else {
    // turn LED off:
    strip1.setPixelColor(0, strip1.Color(255, 0, 0));
    strip1.setPixelColor(5, strip1.Color(255, 0, 0));
    strip1.setPixelColor(10, strip1.Color(255, 0, 0));
    strip1.setPixelColor(15, strip1.Color(255, 0, 0));
    strip1.setPixelColor(20, strip1.Color(255, 0, 0));
  }

  if (ReedState2 == HIGH) {
    // turn LED on:
    strip1.setPixelColor(4, strip1.Color(0, 0, 0));
    strip1.setPixelColor(9, strip1.Color(0, 0, 0));
    strip1.setPixelColor(14, strip1.Color(0, 0, 0));
    strip1.setPixelColor(19, strip1.Color(0, 0, 0));
    strip1.setPixelColor(24, strip1.Color(0, 0, 0));

  } else {
    // turn LED off:
    strip1.setPixelColor(4, strip1.Color(0, 255, 0));
    strip1.setPixelColor(9, strip1.Color(0, 255, 0));
    strip1.setPixelColor(14, strip1.Color(0, 255, 0));
    strip1.setPixelColor(19, strip1.Color(0, 255, 0));
    strip1.setPixelColor(24, strip1.Color(0, 255, 0));
  }
  strip1.show();
  delay(10);
}
