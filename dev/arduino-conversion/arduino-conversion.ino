#include <stdlib.h>

int sensor_pin = A5;               // Analog out pin for photoresistor
int sensor_value = 0;              // Value at sensor
String inputString = "";           // a string to hold incoming data
boolean stringComplete = false;    // whether the string is complete
boolean transmissionOn = false;    // whether or no the transmission has begun

byte check_sequence[24] = {0, 0, 0, 0, 0, 0, 0, 0,
                           0, 1, 1, 1, 1, 1, 1, 1, 
                           0, 0, 0, 0, 0, 0, 0, 0}         // sequence that signals start of transmission NULL-DEL-NULL

byte candidate_sequence[24] = {0, 0, 0, 0, 0, 0, 0, 0, 
                               0, 0, 0, 0, 0, 0, 0, 0, 
                               0, 0, 0, 0, 0, 0, 0, 0}
  
void setup() {
  // initialize serial:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  inputString.reserve(140);
}

void loop() {
  // print the string when a newline arrives:
  sensor_value = analogRead(sensor_pin);
  
  if (stringComplete)                                    // If there is a word in the device buffer, send it with the laser
  {
    for (int i = 0; i<inputString.length(); i++)         // For each letter, convert ascii to binary
    {
      char myChar = inputString.charAt(i);               
      for(int j = 7; j >= 0; j--)
      {
        byte bytes = bitRead(myChar,j);
        if (bytes == 1){
            digitalWrite(13, HIGH);                      // 1 -> laser on
        }
        else {
            digitalWrite(13, LOW);                       // 0 -> laser off
        }
        delay(1);
      }      
    }
    inputString = "";                                    // Set inputString to empty
    stringComplete = false;                              // Lower string flag
  }
}

void serialEvent() {                                    // Run this loop only if there is something to read out of the device buffer
  while (Serial.available()) {
    char inChar = (char)Serial.read();                  // Get next byte
    inputString += inChar;                              // Add to inputString
    if (inChar == '\n') {                               // If EOL, raise flag
      stringComplete = true;
    }
  }
}
