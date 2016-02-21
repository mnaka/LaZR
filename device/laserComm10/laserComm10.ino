int laser = 11;
int photoresistor = A5;
int sensorValue = 0;
String readings = "";
int acknowledgeSent = 6;
int acknowledgeReceived = 7;

void setup() {
  pinMode(laser, OUTPUT);
  pinMode(acknowledgeReceived, INPUT);
  pinMode(acknowledgeSent, OUTPUT);
  Serial.begin(9600);
  digitalWrite(laser, HIGH);
  digitalWrite(acknowledgeSent, LOW);
}

void loop() {
 delay(100);
 if (Serial.available() > 0 && digitalRead(acknowledgeReceived) == LOW && digitalRead(acknowledgeSent) == LOW){
    if(Serial.read() == '0'){
      digitalWrite(laser, LOW);
      Serial.print("0");
    }
    else{
      digitalWrite(laser, HIGH);
      Serial.print("1");
    }
    digitalWrite(acknowledgeSent, HIGH);
    }
    if(digitalRead(acknowledgeReceived) == HIGH && digitalRead(acknowledgeSent) == HIGH){
      digitalWrite(acknowledgeSent, LOW);
    }
  }
