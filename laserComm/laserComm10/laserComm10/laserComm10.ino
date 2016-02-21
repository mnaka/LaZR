int laser = 11;
int photoresistor = A5;
int sensorValue = 0;
String readings = "";
int acknowledge = 7;

void setup() {
  pinMode(laser, OUTPUT);
  pinMode(acknowledge, INPUT);
  Serial.begin(9600);
  digitalWrite(laser, HIGH);
  delay(5000);
}

void loop() {
  int counter = 0;
  while (Serial.available() > 0 && digitalRead(acknowledge) == LOW){
    counter++;
    if(Serial.read() == '0'){
      digitalWrite(laser, LOW);
    }
    else{
      digitalWrite(laser, HIGH);
    }
    }
  }
