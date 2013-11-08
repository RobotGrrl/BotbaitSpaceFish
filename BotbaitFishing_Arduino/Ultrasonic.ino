
uint8_t readDistance() {

  long duration = 0;
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
  Serial << microsecondsToCentimeters(duration) << "cm" << endl;
  
  return microsecondsToCentimeters(duration);
  
}

uint8_t microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return uint8_t(microseconds / 29 / 2);
}

void distanceBehaviour() {

  uint8_t dist = readDistance();
  
  if(dist <= 25) {
    chaseTentacle(2, dist*5);
  }
  
}

void checkButton() {

  boolean butt = digitalRead(buttonPin);
  
  Serial << "button: " << butt << endl;
  
  if(!butt) lastButtonPress = millis();
  
}

