#include <pitches.h>

/*
   Arduino Theremin with A minor pentatonic scale
*/

const int trigger = 5;
const int echo = 4;

const int piezo = 10;

int distance = 0;
int distanceHigh = 0;

int lengthOfScale_i = 0;
int lengthOfScale_l = 0;
int lengthOfScale_j = 0;
int lengthOfScale_a = 0;
int lengthOfScale_f = 0;
int note = 0;
int cero = 0 ;
int last_note=0;

#include "pitches.h"


//Notas
int Irene [] = {
 NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_A5,NOTE_A4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_G5,NOTE_A4,NOTE_A4,NOTE_C5,NOTE_G5,NOTE_C5,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_C5,NOTE_C5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_C6,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_A5,NOTE_E5,NOTE_D5,NOTE_D6,NOTE_D6,NOTE_C5,NOTE_A5,NOTE_C6,NOTE_A5,NOTE_C6,NOTE_C6,NOTE_C6,NOTE_C6,0
};
int Lazaro [] = {
  };

int Joan []={
};

int Adriana []={
 };

int full []={
};

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  distanceHigh = 5250;

  for (byte i = 0; i < (sizeof(Irene) / sizeof(Irene[0])); i++) {
    lengthOfScale_i += 1;
  }
  for (byte i = 0; i < (sizeof(Lazaro) / sizeof(Lazaro[0])); i++) {
    lengthOfScale_l += 1;
  }
  for (byte i = 0; i < (sizeof(Joan) / sizeof(Joan[0])); i++) {
    lengthOfScale_j += 1;
  }
  for (byte i = 0; i < (sizeof(Adriana) / sizeof(Adriana[0])); i++) {
    lengthOfScale_a += 1;
  }
  for (byte i = 0; i < (sizeof(full) / sizeof(full[0])); i++) {
    lengthOfScale_f += 1;
  }  
}

void loop() {
  digitalWrite(trigger, HIGH);
  digitalWrite(trigger, LOW);

  distance = pulseIn(echo, HIGH);

  if (distance <= distanceHigh) {

    /* Irene's case, first button*/
    if (distance > 250 && distance <=1250 ){
     for (int j = 0; j < (lengthOfScale_i); j++) {
        if (Irene[j]!=0){
          tone(piezo, Irene[j], 800);
          if (Irene[j+1]==0){
            delay(800);
          }
          else {
            delay(200);
          }
        }
        else {
          delay(200);
        }   
     }
   }
    /* Lázaro's case, second button*/
    else if (distance > 1250 && distance <=2250 ){
     for (int j = 0; j < (lengthOfScale_l); j++) {
        if (Lazaro[j]!=0){
          tone(piezo, Lazaro[j], 800);
          if (Lazaro[j+1]==0){
            delay(800);
          }
          else {
            delay(200);
          }
        }
        else {
          delay(200);
        }   
     }  
   }

    /* Joan's case, third button*/
    else if (distance > 2250 && distance <=3250 ){
     for (int j = 0; j < (lengthOfScale_j); j++) {
        if (Joan[j]!=0){
          tone(piezo, Joan[j], 800);
          if (Joan[j+1]==0){
            delay(800);
          }
          else {
            delay(200);
          }
        }
        else {
          delay(200);
        }   
     }
   }
    /* Adriana's case, fourth button*/
    else if (distance > 3250 && distance <=4250 ){
     for (int j = 0; j < (lengthOfScale_a); j++) {
        if (Adriana[j]!=0){
          tone(piezo, Adriana[j], 800);
          if (Adriana[j+1]==0){
            delay(800);
          }
          else {
            delay(200);
          }
        }
        else {
          delay(200);
        }   
     }
   }

    /* full's case, final button*/
    else if (distance >4250 && distance <=5250 ){
     for (int j = 0; j < (lengthOfScale_f); j++) {
        if (full[j]!=0){
          tone(piezo, full[j], 800);
          if (full[j+1]==0){
            delay(800);
          }
          else {
            delay(200);
          }
        }
        else {
          delay(200);
        }   
     }
   }


  }
  delay(200);
}
