#include <Arduino.h>
#include <HID-Project.h>
#include <Encoder.h>

const int NB_SWITCH = 5;
const int PINSSW[NB_SWITCH] = {4, 5, 6, 7, 8};

const ConsumerKeycode ACTIONS[NB_SWITCH] = {
  MEDIA_PREVIOUS, MEDIA_REWIND, MEDIA_PLAY_PAUSE, MEDIA_FAST_FORWARD, MEDIA_NEXT
};

/*const int NB_POTS = 3;
const int PINSPOT[NB_POTS] = {A0,A1,A2};*/

const int ENC1_CLK = 0;
const int ENC1_DT  = 1;
/*const int ENC2_CLK = 2;
const int ENC2_DT  = 3;*/

Encoder enc1(ENC1_CLK, ENC1_DT);  // APRÈS les constantes
long lastEncPos = 0;

void setup() {
  //setup switchs
  Consumer.begin();
  for (int i = 0; i < NB_SWITCH; i++) {
    pinMode(PINSSW[i], INPUT_PULLUP);
  }

  //setup pot
  /*Serial.begin(9600);*/
}

void loop() {
  //switchs
  for (int i = 0; i < NB_SWITCH; i++) {
    if (digitalRead(PINSSW[i]) == LOW) {
      Consumer.write(ACTIONS[i]);
      delay(200);
    }
  }

  //pot
  /*for (int i = 0; i < NB_POTS; i++) {
    int val = analogRead(PINSPOT[i]);
    // Convertit 0-1023 en 0-100
    int pct = map(val, 0, 1023, 0, 100);
    Serial.print(pct);
    if (i < NB_POTS - 1) Serial.print("|");
  }
  Serial.println();
  delay(50); // 20 fois par seconde*/

    // Encodeur
  long pos = enc1.read();
  if (pos > lastEncPos + 2) {
    Consumer.write(MEDIA_VOLUME_UP);
    lastEncPos = pos;
  }
  if (pos < lastEncPos - 2) {
    Consumer.write(MEDIA_VOLUME_DOWN);
    lastEncPos = pos;
  }
}