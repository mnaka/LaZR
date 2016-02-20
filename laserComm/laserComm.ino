int laser = 11;
int photoresistor = A5;
int sensorValue = 0;
void setup() {
  pinMode(laser, OUTPUT);
  pinMode(photoresistor, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(photoresistor);
  if (sensorValue < 300){
    Serial.println("HIGH");
  }
  else{
    Serial.println("LOW");
  }
  Serial.println(digitalRead(laser));
  if (digitalRead(laser) == 0){
    digitalWrite(laser, HIGH);
  }
//  else{
//    digitalWrite(laser, LOW);
//  }
  Serial.println(sensorValue, DEC);
  delay(500);
}
