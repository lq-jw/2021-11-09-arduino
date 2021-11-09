#include "pitches.h"

int freq = 2000;
int channel = 0;
int resolution = 8;

int tonePin = 12;

int melody[] = {
  NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C6, NOTE_A5, NOTE_C6, NOTE_A5,
  NOTE_G5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_C5,
  NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_G5, NOTE_E5,
  NOTE_D5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_G5,
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C6, NOTE_A5,
  NOTE_C6, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_C5,
  NOTE_D5, NOTE_C5,
};
int noteDurations[] = {
  3, 8, 4, 4, 4, 8, 8,
  2, 3, 8, 4, 4, 2, 2,
  4, 4, 4, 4, 4, 8, 8,
  2, 4, 4, 4, 4, 4, 8,
  8, 2, 3, 8, 4, 4, 4,
  8, 8, 2, 3, 8, 4, 4,
  2, 2,
};

void setup() {
  Serial.begin(115200);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(tonePin, channel);
}

void loop() {
    for (int thisNote = 0; thisNote < 44; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      ledcWriteTone(channel, melody[thisNote]);
      delay(noteDuration);
      ledcWriteTone(channel, 0);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
}