int laser = 11;
int photoresistor = A5;
int sensorValue = 0;
int acknowledge = 7;
String readings = "";

void setup() {
  pinMode(laser, OUTPUT);
  pinMode(acknowledge, OUTPUT);
  Serial.begin(9600);
  digitalWrite(laser, HIGH);
  delay(5000);
}

void loop() {
  sensorValue = analogRead(photoresistor);
  digitalWrite(acknowledge, LOW);
  if (sensorValue < 75){
    readings += "1";
  }
  else{
    readings += "0";
  }
  digitalWrite(acknowledge, HIGH);
  delay(100);
  Serial.println(readings);
}

