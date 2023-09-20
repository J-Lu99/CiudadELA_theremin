#include <pitches.h>

/*
   Arduino Theremin with A minor pentatonic scale
*/

const int trigger = 5;
const int echo = 4;

const int piezo = 10;

int distance = 0;
int distanceHigh = 0;

int lengthOfScale = 0;

int note = 0;
int cero = 0 ;
int last_note=1;

#include "pitches.h"
//A Minor pentatonic scale
int scale[] = {
  NOTE_D3, NOTE_E3, NOTE_G3,NOTE_A3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4,
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_G6,
  NOTE_A6, NOTE_C7, NOTE_D7
};

//C Major scale
/*int scale[] = {
  NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5,
  NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};*/


void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  distanceHigh = 5000;

  /*while (millis() < 5000) {
    digitalWrite(trigger, HIGH);
    digitalWrite(trigger, LOW);
    distance = pulseIn(echo, HIGH);

    if (distance > distanceHigh) {
      distanceHigh = distance;
    }
  }*/

  for (byte i = 0; i < (sizeof(scale) / sizeof(scale[0])); i++) {
    lengthOfScale += 1;
  }
}

void loop() {
  digitalWrite(trigger, HIGH);
  digitalWrite(trigger, LOW);

  distance = pulseIn(echo, HIGH);

  if (distance <= distanceHigh) {
    cero=0;
    note = map(distance, 250, distanceHigh, scale[0], scale[lengthOfScale - 1]);
    for (byte j = 0; j < (lengthOfScale); j++) {
     if (note == scale[j]) {
        tone(piezo, note, 800);
        Serial.print(note);
        last_note=note;
 
        break;
     }
      else if (note > scale[j] && note < scale[j + 1]) {
        note = scale[j];
        tone(piezo, note, 800);
        Serial.println(note);
        last_note=note;
        break;
     }

    }
  }
  else if (distance > distanceHigh) {
   cero+=1;
   if (last_note !=0) {
    delay(400);
   }
   
   if (cero < 6){
    tone(piezo, 0, 100);
    Serial.println(0);
    last_note=0;
   }
  }
  delay(200);
}
