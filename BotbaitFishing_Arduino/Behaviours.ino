
// -- DIST ACTIONS -- //

void distAction(uint8_t _distState) {
  
  Serial << "dist state: " << _distState << endl;
  
  switch(_distState) {
    case 0:
      mvReallyClose();
    break;
    case 1:
      mvClose();
    break;
    case 2: 
      mvMedium();
    break;
    case 3: 
      mvAlmostFar();
    break;
    case 4:
      mvFar();
    break;
    case 5:
      mvReallyFar(); 
    break;
  }
  
}

void distActionTest() {
  
  Serial << "really close" << endl;
  distAction(0);
  delay(2000);
  
  Serial << "close" << endl;
  distAction(1);
  delay(2000);
  
  Serial << "medium" << endl; // favourite, goes in a circle
  distAction(2);
  delay(2000);
  
  Serial << "almost far" << endl;
  distAction(3);
  delay(2000);
  
  Serial << "far" << endl;
  distAction(4);
  delay(2000);
  
  Serial << "really far" << endl; // another favourite, swings back & forth but it can really move!!
  distAction(5);
  delay(2000);
  
}



// -- DIST BEHAVIOUR -- //

void distBehaviour() {
 
 
  for(uint8_t i=0; i<4; i++) {
    squareOn();
    delay(200);
    squareOff();
    delay(200);
  }
  squareOn();
  delay(400);
  
  uint8_t dist = readDistance();
  
  if(dist <= 15) {
    Serial << "really close" << endl;
    distState = 0;
  } else if(dist > 15 && dist <= 20) {
    Serial << "close" << endl;
    distState = 1;
  } else if(dist > 20 && dist <= 25) {
    Serial << "medium" << endl;
    distState = 2;
  } else if(dist > 25 && dist <= 30) {
    Serial << "almost far" << endl;
    distState = 3;
  } else if(dist > 30 && dist <= 40) {
    Serial << "far" << endl;
    distState = 4;
  } else {
    Serial << "really far" << endl;
    distState = 5;
  }
  
  squareOff();
  
  
  switch(distState) {
    case 0:
      if(distState_prev != 0 && distState_prev != 1) {
        Serial << "We are really close now!" << endl;
        beExcited();
      } else {
        Serial << "Oh! What is going on here?!" << endl;
        beSurprised();
      }
      distAction(distState);
    break;
    case 1:
      if(distState_prev != 1 && distState_prev != 2) {
        if(distState_prev < distState) {
          Serial << "Glad you backed up a little bit there..." << endl;
          beRelieved();
        } else {
          Serial << "I can sense you much more closely now!" << endl;
          bePleased();
        }
      } else {
        Serial << "Oh! What is going on here?!" << endl;
        beSurprised();
      }
      distAction(distState);
    break;
    case 2:
      if(distState_prev != 2 && distState_prev != 3) {
        if(distState_prev < distState) {
          Serial << "You backed up a little? Was it too close?" << endl;
          beConfused();
        } else {
          Serial << "We're a good distance between each other. Medium." << endl;
          beContent();
        }
      } else {
        Serial << "Oh! What is going on here?!" << endl;
        beSurprised();
      }
      distAction(distState);
    break;
    case 3:
      if(distState_prev != 3 && distState_prev != 4) {
        if(distState_prev < distState) {
          Serial << "You are getting almost far away right now..." << endl;
          beDiscontent();
        } else {
          Serial << "Excellent! Come closer! Come closer! Heeheehee" << endl;
          bePleased();
        }
      } else {
        Serial << "Oh! What is going on here?!" << endl;
        beSurprised();
      }
      distAction(distState);
    break;
    case 4:
      if(distState_prev != 4 && distState_prev != 5) {
        if(distState_prev < distState) {
          Serial << "Oh, I guess we are farther away now... okay." << endl;
          beDiscontent();
        } else {
          Serial << "Why hello there human or something!" << endl;
          beContent();
        }
      } else {
        Serial << "Oh! What is going on here?!" << endl;
        beSurprised();
      }
      distAction(distState);
    break;
    case 5:
      if(distState_prev != 5) {
        Serial << "It's so hard to say goodbye... not. GOODBYE!" << endl;
        beAngry();
      } else {
        Serial << "I wonder if I will ever meet a human in my lifetime..." << endl;
        beWondering();
      }
      distAction(distState);
    break;
  }
  
}






















// ---------------------------------------------- //

void theContemplationBehaviour() {

  if(emoState == 0) { // waiting to have a person in front
    
    if(millis()%50 == 0) {
      if(readDistance() <= 10) emoState = 1;
    }
    
    if(millis()%300 == 0) nextTechnique();
    
  } else if(emoState == 1) { // waiting to be pressed 3 times
    if(buttonState) {
      
      buttonState = false;
      long timeDelta = millis()-starButtonChange;
      if(timeDelta < 1000) numButtonPresses++; 
      
      Serial << "num presses: " << numButtonPresses << " time delta: " << timeDelta << endl;
      
      pwm.setPWM(0, 0, homePos[chosenServo]-posdiff);
      pwm.setPWM(2, 0, homePos[chosenServo]+posdiff);
      delay(300);
      squareOff();
      tentacleOff();
      pwm.setPWM(0, 0, homePos[chosenServo]);
      pwm.setPWM(2, 0, homePos[chosenServo]);
      delay(100);
      
      if(numButtonPresses >= 3) {
        chaseTentacle(5, 50);
        tentacleOn();
        emoState = 2;
      }
    
    } else {
      // here we need to 'bait' the human into pressing the button 3 times.
      if(millis()%100 == 0) nextTechnique();
    }
    
  } else if(emoState == 2) {
   
    randomMovementGen();
    servoUpdate();
    
    if(millis()-millisSquareRainbow > freqSquareRainbow) updateSquareRainbow();
    
  }
  
}


void nextTechnique() {
 
  if(emoState == 0) {
    
    technique++;
    if(technique > 2) technique = 0;
    
    switch(technique) {
      case 0:
        fadeTentacle(5, 1);
      break;
      case 1:
        chaseTentacle(5, 100);
      break;
      case 2:
        fadeTentacle(255, 1);
      break;
    }
    
    if(millis()-millisSquareRainbow > freqSquareRainbow) updateSquareRainbow();
    
  } else if(emoState == 1) {
 
   technique++;
    if(technique > 2) technique = 0;
    
    switch(technique) {
      case 0: {
        
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]-posdiff);
        delay(400);
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]+posdiff);
        delay(400);
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]);
        delay(400);
        
        chosenServo++;
        if(chosenServo > 3) chosenServo = 0;
      }
      break;
      
      case 1: {
      for(uint8_t i=0; i<3; i++) {
        tentacleOn();
        delay(250);
        tentacleOff();
        delay(250);
      }
      }
      break;
      
      case 2: {
      uint8_t randomColour = (uint8_t)random(0, 4);
      
      squareOff();
      
      for(uint8_t j=0; j<3; j++) {
      
        for(uint8_t i=0; i<4; i++) {
          squareColour(i, randomColour, true);
        }
        delay(250);
        
        squareOff();
        delay(250);
      }
      }
      break;
    
    }
    
    
  }
  
}



void mvReallyClose() {
 
 for(uint8_t i=0; i<2; i++) {
      
        for(uint8_t j=0; j<5; j++) {
          pwm.setPWM(i, 0, homePos[i]-30);
          pwm.setPWM(i+1, 0, homePos[i+1]-30);
          delay(50);
          pwm.setPWM(i, 0, homePos[i]+30);
          pwm.setPWM(i+1, 0, homePos[i+1]+30);
          delay(50);
        }
      
      }
      
      uint8_t chosenServo = (uint8_t)random(0, 4);
      
      for(uint8_t i=0; i<2; i++) {
        for(uint8_t j=0; j<4; j++) {
          pwm.setPWM(j, 0, homePos[j]+posdiff);
          delay(150);
          pwm.setPWM(j, 0, homePos[j]-posdiff);
          delay(150);
        }
      }
      
      for(uint8_t j=0; j<4; j++) {
        pwm.setPWM(j, 0, homePos[j]);
        delay(100);
      }
  
}

void mvClose() {
 
 uint8_t chosenServo = (uint8_t)random(0, 4);
      
      for(uint8_t i=0; i<2; i++) {
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]+posdiff);
        delay(150);
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]-posdiff);
        delay(150);
      }
      
      pwm.setPWM(chosenServo, 0, homePos[chosenServo]);
      
      chosenServo = (uint8_t)random(0, 4);
      
      for(uint8_t i=0; i<4; i++) {
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]+posdiff);
        delay(150);
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]-posdiff);
        delay(150);
      }
      
      pwm.setPWM(chosenServo, 0, homePos[chosenServo]);
  
}

void mvMedium() {
 
 
      for(uint8_t j=0; j<3; j++) {
      
        for(uint8_t i=0; i<4; i++) {
          pwm.setPWM(i, 0, homePos[i]+posdiff);
          delay(100);
        }
        delay(150);
      
        for(uint8_t i=0; i<4; i++) {
          pwm.setPWM(i, 0, homePos[i]-posdiff);
          delay(100);
        }
        delay(150);
      
      }
      
      for(uint8_t i=0; i<4; i++) {
        pwm.setPWM(i, 0, homePos[i]);
        delay(100);
      }
  
}

void mvAlmostFar() {
  
 uint8_t chosenServo = (uint8_t)random(0, 4);
      
      for(uint8_t i=0; i<2; i++) {
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]+posdiff);
        delay(250);
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]-posdiff);
        delay(250);
      }
      
      for(uint8_t i=0; i<3; i++) {
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]+posdiff);
        delay(100);
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]-posdiff);
        delay(100);
      }
      
      pwm.setPWM(chosenServo, 0, homePos[chosenServo]); 
      
}

void mvFar() {
 
 
      uint8_t chosenServo = (uint8_t)random(0, 4);
      uint8_t secondServo = (uint8_t)random(0, 4);
      
      while(chosenServo == secondServo) {
        secondServo = (uint8_t)random(0, 4);
      }
      
      for(uint8_t i=0; i<4; i++) {
        
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]+posdiff);
        
        for(uint8_t j=0; j<3; j++) {
          pwm.setPWM(secondServo, 0, homePos[secondServo]+30);
          delay(100);
          pwm.setPWM(secondServo, 0, homePos[secondServo]-30);
          delay(100);
        }
        
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]-posdiff);
        
        for(uint8_t j=0; j<3; j++) {
          pwm.setPWM(secondServo, 0, homePos[secondServo]+30);
          delay(100);
          pwm.setPWM(secondServo, 0, homePos[secondServo]-30);
          delay(100);
        }
        
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]+posdiff);
        
      }
      
      pwm.setPWM(chosenServo, 0, homePos[chosenServo]);
      pwm.setPWM(secondServo, 0, homePos[secondServo]);
  
}

void mvReallyFar() {
 
 uint8_t chosenServo = (uint8_t)random(0, 4);
      
      for(uint8_t i=0; i<4; i++) {
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]+posdiff);
        delay(300);
        pwm.setPWM(chosenServo, 0, homePos[chosenServo]-posdiff);
        delay(300);
      }
      
      pwm.setPWM(chosenServo, 0, homePos[chosenServo]);
  
}
