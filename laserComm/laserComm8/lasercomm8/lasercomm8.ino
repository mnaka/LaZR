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
  while (Serial.available() > 0){
    if(Serial.read() == '0'){
      digitalWrite(laser, LOW);
    }
    else{
      digitalWrite(laser, HIGH);
    }
    delay(1);
  }
  Serial.write("I received this message");
}

