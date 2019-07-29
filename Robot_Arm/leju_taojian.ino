void setup(){
  Serial.begin(9600);
  Serial.println("-CHANNEL=2");
}

void loop(){
  if (analogRead(A7) < 750) {
    Serial.println("-LJROBOT=1");
    delay(2000);
  }
}
