// BestMove.cpp
#include "BestMove.h"



BestMove::BestMove() {
  Serial.println("Object created");
  char last_move = "0000";
  char next_move = "0000";
  unsigned long time = millis();

}

void BestMove::check_move() {
  //Serial.println("check_move function");
  //char next_move[] = "e3d3";
  
  // Serial.print("Last Move  ");
  // Serial.println(last_move);
  // Serial.print("Next Move  ");
  // Serial.println(next_move);
  
  if (String(last_move) != String(next_move) || (millis() - time > 30000)){

      if (String(next_move).length() >1 ){
        vibrate_alert();
        int dec_array[4];
        dec_array[0] = int(next_move[0]) - 96;
        dec_array[1] =  int(next_move[1]) - 48;
        dec_array[2] = int(next_move[2] - 96);
        dec_array[3] = int(next_move[3] - 48);
      
        // for (int element : dec_array){
        //   vibrate(element);
        // }

        for (int i = 0; i <= 1; i++){
          vibrate(dec_array[i]);
        }
        for (int i = 2; i <= 3; i++){
          vibrate(dec_array[i]);
        }
        strcpy(last_move, next_move);
        delay(5000);
        
      }
  }

}



int BestMove::getState() {
}

void BestMove::vibrate(int x){
  int mult = 1; //multiplier for speeding up debugging. Speeds up pulses
  int pulse_on = 15/mult;
  int pulse_off = 300/mult;
  int rest_pulse = 2000/mult;
  
  for (int i = 0; i < x; i++) {
    digitalWrite(2, HIGH);
    delay(pulse_on);
    digitalWrite(2, LOW);
    delay(pulse_off);
  }
  delay(rest_pulse);
  time = millis();
}

// Alert the user of incoming new move by buzzing for 1 second
void BestMove::vibrate_alert(){
  int pulse_on = 15;
  int pulse_off = 100;
  int rest_pulse = 2000;
  if (String(last_move) != String(next_move)){
    digitalWrite(2, HIGH);
    delay(pulse_on);
    digitalWrite(2, LOW);
    delay(pulse_off);
    digitalWrite(2, HIGH);
    delay(pulse_on);
    digitalWrite(2, LOW);
    delay(pulse_off);
    digitalWrite(2, HIGH);
    delay(pulse_on);
    digitalWrite(2, LOW);
    delay(rest_pulse);
    }
}