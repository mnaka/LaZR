int laser = 11;
int photoresistor = A5;
int sensorValue = 0;
String incoming = "2";
String endofMessage = "3";
String binary = "";
String myText = "abcdefghijklmnopqrstuvwxyz";

String readings = "";

void setup() {
  pinMode(laser, OUTPUT);
  Serial.begin(9600);
  readings += incoming;
  for(int i=0; i<myText.length(); i++){
   char myChar = myText.charAt(i);
    for(int i=7; i>=0; i--){
      byte bytes = bitRead(myChar,i);
      binary += bytes;
    }
  }
  digitalWrite(laser, HIGH);
  delay(5000);
}

void loop() {
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
        readings += endofMessage;
        if (printer(readings)){
          readings = "";
          digitalWrite(laser, LOW);
          delay(1000000);
        }
        else{
          Serial.println("Missed Start of Message, Try Again");
          readings="";
          delay(1000000);
        }
    }
    delay(1);
    sensorValue = analogRead(photoresistor);
    if (sensorValue < 20){
      readings += "1";
    }
    else{
      readings += "0";
    }
    delay(1);
}

boolean printer(String str){
  Serial.println(str);
  int start = 0;
  int ending = 0;
  for (int i=0; i < str.length(); i++){
    if (str.charAt(i) == '2'){
      start = i+1;
      break;
    }
  }
  for(int j = start; j < str.length(); j++){
    if (str.charAt(j) == '3'){
      ending = j;
      break;
    }
  }

  if(start > 0 && ending > 0){
    Serial.print(str.substring(start, ending));
    return true;
  }
  else{
    return false;
  }
}

