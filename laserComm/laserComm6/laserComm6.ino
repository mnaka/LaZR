int laser = 11;
int photoresistor = A5;
int sensorValue = 0;
String binary = "11101010000101010001101000011001010010000001110001011101010110100101100011011010110010000001100010011100100110111101110111011011100010000001100110011011110111100000100000011010100111010101101101011100000110010101100100001000000110111101110110011001010111001000100000011101000110100001100101001000000110110001100001011110100111100100100000011001000110111101100111001011100001010111";
String readings = "";

void setup() {
  pinMode(laser, OUTPUT);
  Serial.begin(9600);
  digitalWrite(laser, HIGH);
  delay(5000);
}

void loop() {
  delay(10);
  Serial.println(binary.substring(0,8));

  
  
  if (PYTHON SCRIPT(binary.substring(0,8) = -1){
    start = 9;
    stopper = 18;
    while(1<5){
      if (PYTHON SCRIPT(binary.substring(start,stopper) = -2)){
        SEND TO OLIVIA'S SCRIPT binary.substring(9,stopper);
      }
      else{
        start += 8;
        stopper += 8;
      }
    }
  }

  delay(10);
  sensorValue = analogRead(photoresistor);
  if (sensorValue < 20){
    readings += "1";
  }
  else{
    readings += "0";
  }
}

