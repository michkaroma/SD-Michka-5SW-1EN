#include <Arduino.h>
#include <HID-Project.h>
#include <Encoder.h>

const int NB_SWITCH = 5;
const int PINSSW[NB_SWITCH] = {4, 5, 6, 7, 8};

const ConsumerKeycode ACTIONS[NB_SWITCH] = {
  MEDIA_PREVIOUS, MEDIA_REWIND, MEDIA_PLAY_PAUSE, MEDIA_FAST_FORWARD, MEDIA_NEXT
};

const int ENC1_CLK = 0;
const int ENC1_DT = 1;
const int ENC1_SW = 9;

Encoder enc1(ENC1_CLK, ENC1_DT);
long lastEncPos = 0;

void setup() {
  //setup switchs
  Consumer.begin();
  for (int i = 0; i < NB_SWITCH; i++) {
    pinMode(PINSSW[i], INPUT_PULLUP);
  }

  //setup enc1
  pinMode(ENC1_SW,INPUT_PULLUP);
}

void loop() {
  //switchs
  for (int i = 0; i < NB_SWITCH; i++) {
    if (digitalRead(PINSSW[i]) == LOW) {
      Consumer.write(ACTIONS[i]);
      delay(200);
    }
  }

    //enc1
  long pos = enc1.read();
  if (pos > lastEncPos + 2) {
    Consumer.write(MEDIA_VOLUME_UP);
    lastEncPos = pos;
  }
  if (pos < lastEncPos - 2) {
    Consumer.write(MEDIA_VOLUME_DOWN);
    lastEncPos = pos;
  }
  if(digitalRead(ENC1_SW)==LOW){
    Consumer.write(MEDIA_VOLUME_MUTE);
    delay(200);
  }
}