int laser = 11;
int photoresistor = A5;
int sensorValue = 0;
int acknowledgeSent = 6;
int acknowledgeReceived = 7;
String readings = "";

void setup() {
  pinMode(laser, OUTPUT);
  pinMode(acknowledgeSent, INPUT);
  pinMode(acknowledgeReceived, OUTPUT);
  Serial.begin(9600);
  digitalWrite(laser, HIGH);
  digitalWrite(acknowledgeReceived, LOW);
}

void loop() {
  delay(100);
  if(digitalRead(acknowledgeSent) == HIGH && digitalRead(acknowledgeReceived) == LOW){

    sensorValue = analogRead(photoresistor);
    if (sensorValue < 60){
      readings += "1";
    }
    else{
      readings += "0";
    }
    digitalWrite(acknowledgeReceived, HIGH);
  }
  Serial.println(readings);

  if(digitalRead(acknowledgeSent) == LOW && digitalRead(acknowledgeReceived == HIGH)){
    digitalWrite(acknowledgeReceived, LOW);
  }
}
