#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "BestMove.h"

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

BestMove bestmove;

void setup() {
  
  Serial.begin(115200);
  Serial.print("Started!");
  
  pinMode(2, OUTPUT); //vibrator transistor/relay
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  
}

void loop() {
  char move_string[4]; 
  strcpy(move_string, bestmove.last_move);
  if (radio.available()) {
    Serial.println("Radio Available");
    radio.read(&move_string, sizeof(move_string));
    strcpy(bestmove.next_move, move_string);
    // Serial.print("Move String  ");
    Serial.println(move_string);
        
  }
  bestmove.check_move();
}

void vibrate(int x){
  float pulse_on = 200;
  float pulse_off = 200;
  float rest_pulse = 1000;
  
  for (int i = 0; i < x; i++) {
    digitalWrite(2, HIGH);
    delay(pulse_on);
    digitalWrite(2, LOW);
    delay(pulse_off);
  }
  delay(rest_pulse);
}

void next(){
  float pulse_on = 100;
  float pulse_off = 200;
  float rest_pulse = 3000;
  
  for (int i = 0; i <= 10; i++) {
    digitalWrite(2, HIGH);
    delay(pulse_on);
    digitalWrite(2, LOW);
    delay(pulse_off);
  }
}
