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
  sensorValue = analogRead(photoresistor);
  if (sensorValue < 75){
    readings += "1";
  }
  else{
    readings += "0";
  }
  delay(5);
  Serial.println(readings);
}

