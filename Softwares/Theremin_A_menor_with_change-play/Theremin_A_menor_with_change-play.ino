#include <pitches.h>

/*
   Arduino Theremin with A minor pentatonic scale
*/

const int trigger = 5;
const int echo = 4;

const int trigger_c = 8;
const int echo_c = 7;

const int piezo = 10;

int distance = 0;
int distanceHigh = 0;

int distance_c = 0;
int distanceHigh_c = 0;

int lengthOfScale_m = 0;
int lengthOfScale_p = 0;
int lengthOfScale_j = 0;
int lengthOfScale_h = 0;

int note = 0;

#include "pitches.h"


//A Minor pentatonic scale
int scale_p[] = {
  NOTE_C3,NOTE_D3, NOTE_E3, NOTE_G3,NOTE_A3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4,
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_G6,
  NOTE_A6, NOTE_C7, NOTE_D7
};

//C Major scale
int scale_m[] = {
  NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5,
  NOTE_G5, NOTE_A5, NOTE_B5
};

//JoJo's theme
int jojo[] = { 
  NOTE_B4,0,NOTE_B4,0,0,NOTE_A5,NOTE_B5,NOTE_D5,NOTE_B5,NOTE_B4,NOTE_B5,0,0,
  NOTE_A4,NOTE_B4,NOTE_F5,NOTE_E4,NOTE_B4,0,NOTE_B5,0,0,NOTE_A5,NOTE_B5,
  NOTE_D5,NOTE_B5,NOTE_B5,NOTE_B5,0,0,NOTE_A5,NOTE_B5,NOTE_F6,NOTE_E4,NOTE_B5,0,NOTE_B4,0,0,
  NOTE_A5,NOTE_B5,NOTE_D5,NOTE_B5,NOTE_B5,NOTE_B5,0,0,NOTE_A5,NOTE_B5,NOTE_F6,NOTE_E5,NOTE_B4,NOTE_B5,
};

// Happy
int happy [] = {
  NOTE_C5,NOTE_C5,NOTE_E4,NOTE_C5,NOTE_F5,NOTE_E5,0,
  NOTE_C5,NOTE_C5,NOTE_E4,NOTE_C5,NOTE_G5,NOTE_F5,0,
  NOTE_C5,NOTE_C5,NOTE_C5,NOTE_A5,NOTE_F6,NOTE_E5,NOTE_D5,0,
  NOTE_B5,NOTE_B5,NOTE_A5,NOTE_F5,NOTE_G5,NOTE_F5,0,
};

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  distanceHigh = 4000;
  distanceHigh_c = 1500;

  pinMode(trigger_c, OUTPUT);
  pinMode(echo_c, INPUT);
  /*while (millis() < 5000) {
    digitalWrite(trigger, HIGH);
    digitalWrite(trigger, LOW);
    distance = pulseIn(echo, HIGH);

    if (distance > distanceHigh) {
      distanceHigh = distance;
    }
  }*/
  for (byte i = 0; i < (sizeof(scale_m) / sizeof(scale_m[0])); i++) {
    lengthOfScale_m += 1;
    }
  for (byte i = 0; i < (sizeof(scale_p) / sizeof(scale_p[0])); i++) {
    lengthOfScale_p += 1;
    } 
  for (byte i = 0; i < (sizeof(jojo) / sizeof(jojo[0])); i++) {
    lengthOfScale_j += 1;
    } 
  for (byte i = 0; i < (sizeof(happy) / sizeof(happy[0])); i++) {
    lengthOfScale_h += 1;
    }    
}

void loop() {
  digitalWrite(trigger, HIGH);
  digitalWrite(trigger, LOW);

  distance = pulseIn(echo, HIGH);

  digitalWrite(trigger_c, HIGH);
  digitalWrite(trigger_c, LOW);

  distance_c = pulseIn(echo_c, HIGH);

  if ( distance_c > 1000 && distance_c <= distanceHigh_c){
  
    if (distance <= distanceHigh) {
     note = map(distance, 250, distanceHigh, scale_m[0], scale_m[lengthOfScale_m - 1]);
     for (byte j = 0; j < (lengthOfScale_m); j++) {
      if (note == scale_m[j]) {
        tone(piezo, note, 800);
        Serial.println(note);
        break;
     }
      else if (note > scale_m[j] && note < scale_m[j + 1]) {
        note = scale_m[j];
        tone(piezo, note, 800);
        Serial.println(note);
        break;
      } 
    }
   }
   else {
     tone(piezo, 0, 500);
     Serial.println(0);
   }
     
   }
  
  else if (distance_c > 100 && distance_c <= 500){
     for (int j = 0; j < (lengthOfScale_j); j++) {
        tone(piezo, jojo[j], 300);
        delay(310);
        noTone(piezo);   
    }
  }
  else if (distance_c > 500 && distance_c <= 1000){
     for (int h = 0; h < (lengthOfScale_h); h++) {
        tone(piezo, happy[h], 600);
        delay(610);
        noTone(piezo);   
   }
  }
  
  else {
    if (distance <= distanceHigh) {
     note = map(distance, 250, distanceHigh, scale_p[0], scale_p[lengthOfScale_p - 1]);
     for (byte j = 0; j < (lengthOfScale_p); j++) {
      if (note == scale_p[j]) {
        tone(piezo, note, 800);
        Serial.println(note);
        break;
     }
      else if (note > scale_p[j] && note < scale_p[j + 1]) {
        note = scale_p [j];
        tone(piezo, note, 800);
        Serial.println(note);
        break;
      } 
    }
   } 

   else if (distance > distanceHigh) {
     tone(piezo, 0, 500);
     Serial.println(0);
   }

  }
delay(500);
} 
