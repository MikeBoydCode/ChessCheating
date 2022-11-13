#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

String in_chars;
String in_chars_previous;

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
char move_string[4];


void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  char move_string[] = "h1h2";
}

void loop() {
  

  //radio.write(&move_string, sizeof(move_string));
  readSerial();
  
  //delay(100);
  


  //delay(5000);
//  exit(0);
  
}

void readSerial() {
  //Serial.println("Read Serial Function");
  in_chars_previous = in_chars;
  //while (!Serial.available());
  if (Serial.available() > 3){
    in_chars = Serial.readString();
  }
  
  //Serial.print(in_chars);
  //in_chars.trim();  // remove any \r \n whitespace at the end of the String

  if (in_chars[4] == 'x' && in_chars_previous != in_chars){
    in_chars.toCharArray(move_string, 5);
    Serial.println(move_string);

   //Serial.print("move_string: ");
    
  }
  radio.write(&move_string, sizeof(move_string));
  //Serial.println(move_string);

}









