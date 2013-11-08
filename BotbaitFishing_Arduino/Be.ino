
// -- BE -- //

void beExcited() {
  
  squareOff();
  for(uint8_t i=0; i<3; i++) {
  
    squareColour(0, 0, true);
    squareColour(0, 1, true);
    
    squareColour(1, 0, true);
    squareColour(1, 1, false);
    
    squareColour(2, 0, true);
    squareColour(2, 1, true);
    
    squareColour(3, 0, true);
    squareColour(3, 1, false);
    
    delay(200);
    
    squareColour(0, 0, true);
    squareColour(0, 1, false);
    
    squareColour(1, 0, true);
    squareColour(1, 1, true);
    
    squareColour(2, 0, true);
    squareColour(2, 1, false);
    
    squareColour(3, 0, true);
    squareColour(3, 1, true);
    
    delay(200);
  
  }
  
  squareColour(0, 0, true);
  squareColour(0, 1, true);
  
  squareColour(1, 0, true);
  squareColour(1, 1, true);
  
  squareColour(2, 0, true);
  squareColour(2, 1, true);
  
  squareColour(3, 0, true);
  squareColour(3, 1, true);
  
  
  chaseTentacle(3, 50);
  
}

void beSurprised() {
  
  for(uint8_t i=0; i<2; i++) {
    tentacleOff();
    delay(100);
    tentacleOn();
    delay(100);
  }
  
  squareOff();
  for(uint8_t i=0; i<3; i++) {
    
    squareColour(0, 0, true);
    squareColour(0, 1, false);
    squareColour(0, 2, true);
    
    squareColour(1, 0, true);
    squareColour(1, 1, true);
    squareColour(1, 2, true);
    
    squareColour(2, 0, true);
    squareColour(2, 1, false);
    squareColour(2, 2, true);
    
    squareColour(3, 0, true);
    squareColour(3, 1, true);
    squareColour(3, 2, true);
    
    delay(200);
    
    squareColour(0, 0, true);
    squareColour(0, 1, true);
    squareColour(0, 2, true);
    
    squareColour(1, 0, true);
    squareColour(1, 1, false);
    squareColour(1, 2, true);
    
    squareColour(2, 0, true);
    squareColour(2, 1, true);
    squareColour(2, 2, true);
    
    squareColour(3, 0, true);
    squareColour(3, 1, false);
    squareColour(3, 2, true);
    
    delay(200);
    
  }
  
  squareColour(0, 0, true);
  squareColour(0, 1, true);
  squareColour(0, 2, true);
  
  squareColour(1, 0, true);
  squareColour(1, 1, true);
  squareColour(1, 2, true);
  
  squareColour(2, 0, true);
  squareColour(2, 1, true);
  squareColour(2, 2, true);
  
  squareColour(3, 0, true);
  squareColour(3, 1, true);
  squareColour(3, 2, true);
  
}

void beRelieved() {
  
  fadeTentacle(100, 1);
  
  squareOff();
  for(uint8_t i=0; i<3; i++) {
    
    squareColour(0, 1, true);
    squareColour(1, 1, false);
    squareColour(2, 1, true);
    squareColour(3, 1, false);
    
    delay(200);
    
    squareColour(0, 1, false);
    squareColour(1, 1, true);
    squareColour(2, 1, false);
    squareColour(3, 1, true);
    
    delay(200);
    
  }
  
  squareColour(0, 1, true);
  squareColour(1, 1, true);
  squareColour(2, 1, true);
  squareColour(3, 1, true);
  
  fadeTentacle(255, 1);
  
}

void bePleased() {
  
  chaseTentacle(2, 50);
  
  squareOff();
  for(uint8_t i=0; i<3; i++) {
    
    squareColour(0, 0, true);
    squareColour(0, 1, false);
    squareColour(0, 2, true);
    
    squareColour(1, 0, false);
    squareColour(1, 1, true);
    squareColour(1, 2, false);
    
    squareColour(2, 0, true);
    squareColour(2, 1, false);
    squareColour(2, 2, true);
    
    squareColour(3, 0, false);
    squareColour(3, 1, true);
    squareColour(3, 2, false);
    
    delay(200);
    
    squareColour(1, 0, true);
    squareColour(1, 1, false);
    squareColour(1, 2, true);
    
    squareColour(2, 0, false);
    squareColour(2, 1, true);
    squareColour(2, 2, false);
    
    squareColour(3, 0, true);
    squareColour(3, 1, false);
    squareColour(3, 2, true);
    
    squareColour(0, 0, false);
    squareColour(0, 1, true);
    squareColour(0, 2, false);
    
    delay(200);
    
  }
  
  squareColour(0, 0, true);
  squareColour(0, 1, false);
  squareColour(0, 2, true);
  
  squareColour(1, 0, true);
  squareColour(1, 1, false);
  squareColour(1, 2, true);
  
  squareColour(2, 0, true);
  squareColour(2, 1, false);
  squareColour(2, 2, true);
  
  squareColour(3, 0, true);
  squareColour(3, 1, false);
  squareColour(3, 2, true);
  
}

void beConfused() {
  
  fadeTentacle(50, 1);
  fadeTentacle(200, 1);
  
  squareOff();
  
  squareColour(0, 1, true);
  squareColour(0, 2, true);
  
  squareColour(1, 1, true);
  squareColour(1, 2, true);
  
  squareColour(2, 1, true);
  squareColour(2, 2, true);
  
  squareColour(3, 1, true);
  squareColour(3, 2, true);
  
  fadeTentacle(100, 1);
  
}

void beContent() {
  
  chaseTentacle(4, 50);
  
  squareOff();
  for(uint8_t i=0; i<3; i++) {
    
    squareColour(0, 1, true);
    squareColour(1, 1, false);
    squareColour(2, 1, true);
    squareColour(3, 1, false);
    
    delay(200);
    
    squareColour(0, 1, false);
    squareColour(1, 1, true);
    squareColour(2, 1, false);
    squareColour(3, 1, true);
    
    delay(200);
    
  }
  
  squareColour(0, 1, true);
  squareColour(1, 1, true);
  squareColour(2, 1, true);
  squareColour(3, 1, true);
  
}

void beDiscontent() {
  
  tentacleOff();
  
  squareOff();
  for(uint8_t i=0; i<3; i++) {
    
    squareColour(0, 2, true);
    squareColour(1, 2, false);
    squareColour(2, 2, true);
    squareColour(3, 2, false);
    
    delay(200);
    
    squareColour(0, 2, false);
    squareColour(1, 2, true);
    squareColour(2, 2, false);
    squareColour(3, 2, true);
    
    delay(200);
    
  }
  
  squareColour(0, 2, true);
  squareColour(1, 2, true);
  squareColour(2, 2, true);
  squareColour(3, 2, true);
  
  fadeTentacle(100, 1);
  
}

void beAngry() {
  
  for(uint8_t i=0; i<3; i++) {
    tentacleOff();
    delay(100);
    tentacleOn();
    delay(100);
  }
  
  squareOff();
  for(uint8_t i=0; i<3; i++) {
    
    squareColour(0, 0, true);
    squareColour(1, 0, false);
    squareColour(2, 0, true);
    squareColour(3, 0, false);
    
    delay(200);
    
    squareColour(0, 0, false);
    squareColour(1, 0, true);
    squareColour(2, 0, false);
    squareColour(3, 0, true);
    
    delay(200);
    
  }
  
  squareColour(0, 0, true);
  squareColour(1, 0, true);
  squareColour(2, 0, true);
  squareColour(3, 0, true);
  
}

void beWondering() {
  
  chaseTentacle(3, 100);
  
  for(uint8_t i=0; i<3; i++) {
    
    squareColour(0, 0, true);
    squareColour(0, 2, true);
    
    squareColour(1, 0, false);
    squareColour(1, 2, true);
    
    squareColour(2, 0, true);
    squareColour(2, 2, true);
    
    squareColour(3, 0, false);
    squareColour(3, 2, true);
    
    delay(200);
    
    squareColour(0, 0, true);
    squareColour(0, 2, true);
    
    squareColour(1, 0, false);
    squareColour(1, 2, true);
    
    squareColour(2, 0, true);
    squareColour(2, 2, true);
    
    squareColour(3, 0, false);
    squareColour(3, 2, true);
    
    delay(200);
    
  }
  
  squareColour(0, 0, true);
  squareColour(0, 2, true);
  
  squareColour(1, 0, true);
  squareColour(1, 2, true);
  
  squareColour(2, 0, true);
  squareColour(2, 2, true);
  
  squareColour(3, 0, true);
  squareColour(3, 2, true);
  
}

void beTest() {
  
  Serial << "be excited" << endl;
  beExcited();
  delay(2000);
  
  Serial << "be surprised" << endl;
  beSurprised();
  delay(2000);
  
  Serial << "be relieved" << endl;
  beRelieved();
  delay(2000);
  
  Serial << "be pleased" << endl;
  bePleased();
  delay(2000);
  
  Serial << "be confused" << endl;
  beConfused();
  delay(2000);
  
  Serial << "be content" << endl;
  beContent();
  delay(2000);
  
  Serial << "be discontent" << endl;
  beDiscontent();
  delay(2000);
  
  Serial << "be angry" << endl;
  beAngry();
  delay(2000);
  
  Serial << "be wondering" << endl;
  beWondering();
  delay(2000);

}





void bePleased2() {
  
  squareOff();
  for(uint8_t i=0; i<3; i++) {
    
    squareColour(0, 0, true);
    squareColour(0, 1, false);
    squareColour(0, 2, true);
    
    squareColour(1, 0, false);
    squareColour(1, 1, true);
    squareColour(1, 2, false);
    
    squareColour(2, 0, true);
    squareColour(2, 1, false);
    squareColour(2, 2, true);
    
    squareColour(3, 0, false);
    squareColour(3, 1, true);
    squareColour(3, 2, false);
    
    delay(200);
    
    squareColour(1, 0, true);
    squareColour(1, 1, false);
    squareColour(1, 2, true);
    
    squareColour(2, 0, false);
    squareColour(2, 1, true);
    squareColour(2, 2, false);
    
    squareColour(3, 0, true);
    squareColour(3, 1, false);
    squareColour(3, 2, true);
    
    squareColour(0, 0, false);
    squareColour(0, 1, true);
    squareColour(0, 2, false);
    
    delay(200);
    
  }
  
  squareColour(0, 0, true);
  squareColour(0, 1, false);
  squareColour(0, 2, true);
  
  squareColour(1, 0, true);
  squareColour(1, 1, false);
  squareColour(1, 2, true);
  
  squareColour(2, 0, true);
  squareColour(2, 1, false);
  squareColour(2, 2, true);
  
  squareColour(3, 0, true);
  squareColour(3, 1, false);
  squareColour(3, 2, true);
  
}



void beExcited2() {
  
  squareOff();
  for(uint8_t i=0; i<3; i++) {
  
    squareColour(0, 0, true);
    squareColour(0, 1, true);
    
    squareColour(1, 0, true);
    squareColour(1, 1, false);
    
    squareColour(2, 0, true);
    squareColour(2, 1, true);
    
    squareColour(3, 0, true);
    squareColour(3, 1, false);
    
    delay(200);
    
    squareColour(0, 0, true);
    squareColour(0, 1, false);
    
    squareColour(1, 0, true);
    squareColour(1, 1, true);
    
    squareColour(2, 0, true);
    squareColour(2, 1, false);
    
    squareColour(3, 0, true);
    squareColour(3, 1, true);
    
    delay(200);
  
  }
  
  squareColour(0, 0, true);
  squareColour(0, 1, true);
  
  squareColour(1, 0, true);
  squareColour(1, 1, true);
  
  squareColour(2, 0, true);
  squareColour(2, 1, true);
  
  squareColour(3, 0, true);
  squareColour(3, 1, true);
  
}
