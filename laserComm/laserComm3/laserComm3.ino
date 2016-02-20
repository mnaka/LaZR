int laser = 11;
int photoresistor = A5;
int sensorValue = 0;

String myText = "abcdefghijklmnopqrstuvwxyz The quick brown fox jumped over the lazy dog.";
String binary = "";
String readings = "";
String letters = "";

//void decrypt(String readings){
// for (int i = 0; i < readings.length(); i++){
//  char myChar = readings.charAt(i);
//   
// }
//}

void setup() {
  // put your setup code here, to run once:
  pinMode(laser, OUTPUT);
//  pinMode(photoresistor, OUTPUT);
  Serial.begin(9600);
  //Convert the text into binary
  for(int i=0; i<myText.length(); i++){
   char myChar = myText.charAt(i);
    for(int i=7; i>=0; i--){
      byte bytes = bitRead(myChar,i);
//      Serial.print(bytes, BIN);
      binary += bytes;
    }
  }
//  Serial.println(binary);
  digitalWrite(laser, HIGH);
  delay(5000);
//  Serial.println("EHER");
}

void loop() {
  // put your main code here, to run repeatedly:
    if(binary != ""){
    if(binary.charAt(0) == '0'){
      digitalWrite(laser, LOW);
    }
    else{
      digitalWrite(laser, HIGH);
    }
    binary = binary.substring(1,binary.length());
  }
  else{
    Serial.println(readings);
    delay(1000000000);
  }
  delay(1);
  sensorValue = analogRead(photoresistor);
  if (sensorValue < 20){
    readings += "1";
  }
  else{
    readings += "0";
  }
//  Serial.println(sensorValue);
//  Serial.println(sensorValue, DEC);


  delay(1);


}
