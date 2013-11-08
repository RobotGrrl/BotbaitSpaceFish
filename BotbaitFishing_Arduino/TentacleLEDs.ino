void blinkTentacle(uint8_t rep, uint8_t del) {
 
  for(uint8_t j=0; j<rep; j++) {
  
     for(uint8_t i=0; i<LEDQTY; i++) {
        digitalWrite(leds[i], LOW);
        ledVals[i] = 0;
     }
     
     delay(del);
     
     for(uint8_t i=0; i<LEDQTY; i++) {
        digitalWrite(leds[i], HIGH);
        ledVals[i] = 255;
     }
 
     delay(del);
 
  }
  
}

void chaseTentacle(uint8_t rep, uint8_t del) {

  uint8_t lit = -1;
  boolean dir = false;
  uint8_t r = 0;
  
  while(r < rep) {

     if(!dir) {
     lit++;
       if(lit == 5) {
         dir = !dir;
         r++; 
       }
     } else {
     lit--;
       if(lit == 0) {
         dir = !dir;
         r++;
       }
     }
  
    for(uint8_t i=0; i<LEDQTY; i++) {
      if(lit == i) {
        digitalWrite(leds[i], HIGH);
        ledVals[i] = 255;
      } else {
        digitalWrite(leds[i], LOW);
        ledVals[i] = 0;
      }
    }
 
   delay(del);
  }
  
}

void fadeTentacle(uint8_t toVal, uint8_t stepTime) {
  
  Serial << "fade to: " << toVal << endl;
  
  uint8_t skipEvery[LEDQTY];
  
  for(uint8_t i=0; i<LEDQTY; i++) {
    skipEvery[i] = 255/abs(ledVals[i]-toVal);
  }
  
  for(uint8_t i=0; i<255; i++) {
  
    for(uint8_t j=0; j<LEDQTY; j++) {
    
      if(ledVals[j] < toVal) {
        
        if(i <= toVal) {
          if(i % skipEvery[j] == 0) analogWrite(leds[j], i);
        }
        
      } else if(ledVals[j] > toVal) {
         
        if(i <= (255-toVal)) {
          if(i % skipEvery[j] == 0) analogWrite(leds[j], 255-i);
        }
        
      }
      
    }
    
    delay(stepTime);
    
  }
  
  for(uint8_t i=0; i<LEDQTY; i++) {
    analogWrite(leds[i], toVal);
    ledVals[i] = toVal;
  }
  Serial << "done fade" << endl;
  
}

void tentacleOn() {
  
  for(uint8_t i=0; i<LEDQTY; i++) {
    digitalWrite(leds[i], HIGH);
    ledVals[i] = 255;
  }
  
}

void tentacleOff() {
  
  for(uint8_t i=0; i<LEDQTY; i++) {
    digitalWrite(leds[i], LOW);
    ledVals[i] = 0;
  }
  
}

