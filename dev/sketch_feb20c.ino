#include <stdlib.h>

int sensor_pin = A5;
int sensor_value = 0;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int i = 0;
  
void setup() {
  // initialize serial:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(140);
}

void loop() {
  // print the string when a newline arrives:
  sensor_value = analogRead(sensor_pin);
  //Serial.println(sensor_value, DEC);
  if (stringComplete) {
    for (i = 0; i<inputString.length(); i++)
    {
      char myChar = inputString.charAt(i);
      for(int j = 7; j >= 0; j--)
      {
        byte bytes = bitRead(myChar,j);
        //Serial.print(bytes, BIN);
        if (bytes == 1){
            digitalWrite(13, HIGH);
        }
        else {
            digitalWrite(13, LOW);
        }
      }      
    }
    //Serial.print('\n');
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
