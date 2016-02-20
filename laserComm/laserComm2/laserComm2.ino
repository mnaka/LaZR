int laser = 11;
int photoresistor = A5;
int sensorValue = 0;

String myText = "Hello World!!!!";
String binary = "";

void setup() {
  // put your setup code here, to run once:
  pinMode(laser, OUTPUT);
//  pinMode(photoresistor, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  for(int i=0; i<myText.length(); i++){
   char myChar = myText.charAt(i);
    for(int i=7; i>=0; i--){
      byte bytes = bitRead(myChar,i);
//      Serial.print(bytes, BIN);
      binary += bytes;
    }
  }
  Serial.println(binary);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(photoresistor);
//  Serial.println(sensorValue, DEC);

  delay(1);

  if (digitalRead(laser) == 0){
    digitalWrite(laser, HIGH);
  }
  else{
    digitalWrite(laser, LOW);
  }
  delay(1);
}
