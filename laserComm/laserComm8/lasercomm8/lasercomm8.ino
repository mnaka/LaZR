int laser = 13;
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
}

