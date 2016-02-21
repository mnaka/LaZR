int laser = 11;
int photoresistor = A5;
int sensorValue = 0;
String readings = "";

void setup() {
  pinMode(laser, OUTPUT);
  Serial.begin(9600);
  digitalWrite(laser, HIGH);
  delay(5000);
}

void loop() {
  int counter = 0;
  while (Serial.available() > 0){
    counter++;
    if(Serial.read() == '0'){
      digitalWrite(laser, LOW);
    }
    else{
      digitalWrite(laser, HIGH);
    }
    delay(5);
    sensorValue = analogRead(photoresistor);
//    Serial.println(sensorValue);
    if (sensorValue < 75){
      readings += "1";
    }
    else{
      readings += "0";
    }
  }
  delay(5);
  Serial.println(readings);
  int i = 1;
  while(i<2){
    Serial.println(counter);
    Serial.print("11101010010101000110100001100101001000000111000101110101011010010110001101101011001000000110001001110010011011110111011101101110001000000110011001101111011110000010000001101010011101010110110101110000011001010110010000100000011011110111011001100101011100100010000001110100011010000110010100100000011011000110000101111010011110010010000001100100011011110110011100010101");
    delay(10000000000);
    i++;
  }
}

