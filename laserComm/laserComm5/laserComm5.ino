int laser = 11;
int photoresistor = A5;
int sensorValue = 0;
String incoming = "1110101000";
String endofMessage = "0001010111";
String binary = "11101010000101010001101000011001010010000001110001011101010110100101100011011010110010000001100010011100100110111101110111011011100010000001100110011011110111100000100000011010100111010101101101011100000110010101100100001000000110111101110110011001010111001000100000011101000110100001100101001000000110110001100001011110100111100100100000011001000110111101100111001011100001010111";
String readings = "";

void setup() {
  pinMode(laser, OUTPUT);
  Serial.begin(9600);
  digitalWrite(laser, HIGH);
  delay(5000);
}

void loop() {
  delay(10);
  if(binary.substring(0,10) == incoming){
    binary=binary.substring(10,binary.length());
    int ending = findEnd(binary.substring(0, binary.length()));
    Serial.println(ending);
    Serial.println(binary.substring(0, ending * 8));
    binary = "11101010000101010001101000011001010010000001110001011101010110100101100011011010110010000001100010011100100110111101110111011011100010000001100110011011110111100000100000011010100111010101101101011100000110010101100100001000000110111101110110011001010111001000100000011101000110100001100101001000000110110001100001011110100111100100100000011001000110111101100111001011100001010111";
  }
  else{
    binary = binary.substring(1, binary.length());
  }

  delay(10);
  sensorValue = analogRead(photoresistor);
  if (sensorValue < 20){
    readings += "1";
  }
  else{
    readings += "0";
  }
}

int findEnd(String str){
  int ending = 0;
  while (1 < 5){
    if (str.substring(0,10) == endofMessage){
      return ending;
    }
    else{
      ending++;
      str = str.substring(8,str.length());
    }
  }
  return -1;
}
