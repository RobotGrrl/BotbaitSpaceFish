void squareColour(uint8_t led, uint8_t col, boolean beOn) {
 
  if(beOn) {
    digitalWrite(rgbleds[led][col], HIGH);
    squareLeds[led][col] = true;
  } else {
    digitalWrite(rgbleds[led][col], LOW);
    squareLeds[led][col] = false;
  }
  
}

void squareOff() {
  
  for(uint8_t j=0; j<4; j++) {
    for(uint8_t i=0; i<3; i++) {
      digitalWrite(rgbleds[j][i], LOW);
      squareLeds[j][i] = false;
    }
  }
  
}

void squareOn() {
  
  for(uint8_t j=0; j<4; j++) {
    for(uint8_t i=0; i<3; i++) {
      digitalWrite(rgbleds[j][i], HIGH);
      squareLeds[j][i] = true;
    }
  }
  
}


void updateSquareRainbow() {
  
  lastSquareRainbow++;
  if(lastSquareRainbow > 6) lastSquareRainbow = 0;
  
  switch(lastSquareRainbow) {
    case 0: // R  
    
    for(uint8_t i=0; i<4; i++) {
      digitalWrite(rgbleds[i][0], HIGH);
      digitalWrite(rgbleds[i][1], LOW);
      digitalWrite(rgbleds[i][2], LOW);
      squareLeds[i][0] = true;
      squareLeds[i][1] = false;
      squareLeds[i][2] = false;
    }
    
    break;
    case 1: // RG  
    
    for(uint8_t i=0; i<4; i++) {
      digitalWrite(rgbleds[i][0], HIGH);
      digitalWrite(rgbleds[i][1], HIGH);
      digitalWrite(rgbleds[i][2], LOW);
      squareLeds[i][0] = true;
      squareLeds[i][1] = true;
      squareLeds[i][2] = false;
    }
    
    break;
    case 2: // G  
    
    for(uint8_t i=0; i<4; i++) {
      digitalWrite(rgbleds[i][0], LOW);
      digitalWrite(rgbleds[i][1], HIGH);
      digitalWrite(rgbleds[i][2], LOW);
      squareLeds[i][0] = false;
      squareLeds[i][1] = true;
      squareLeds[i][2] = false;
    }
    
    break;
    case 3: // GB  
    
    for(uint8_t i=0; i<4; i++) {
      digitalWrite(rgbleds[i][0], LOW);
      digitalWrite(rgbleds[i][1], HIGH);
      digitalWrite(rgbleds[i][2], HIGH);
      squareLeds[i][0] = false;
      squareLeds[i][1] = true;
      squareLeds[i][2] = true;
    }
    
    break;
    case 4: // B  
    
    for(uint8_t i=0; i<4; i++) {
      digitalWrite(rgbleds[i][0], LOW);
      digitalWrite(rgbleds[i][1], LOW);
      digitalWrite(rgbleds[i][2], HIGH);
      squareLeds[i][0] = false;
      squareLeds[i][1] = false;
      squareLeds[i][2] = true;
    }
    
    break;
    case 5: // BR  
    
    for(uint8_t i=0; i<4; i++) {
      digitalWrite(rgbleds[i][0], HIGH);
      digitalWrite(rgbleds[i][1], LOW);
      digitalWrite(rgbleds[i][2], HIGH);
      squareLeds[i][0] = true;
      squareLeds[i][1] = false;
      squareLeds[i][2] = true;
    }
    
    break;
  }
  
  millisSquareRainbow = millis();
  
}

/*
void updatePropogate() {

  for(uint8_t i=0; i<4; i++) {
    for(uint8_t j=0; j<3; j++) {
      
      if(squareLeds[i][j] == true) {
        digitalWrite();
      }  
      
    }
  }
  
}
*/
