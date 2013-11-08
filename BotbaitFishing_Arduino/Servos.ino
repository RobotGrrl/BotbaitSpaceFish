
void newMovement(uint8_t servo, uint16_t final, uint8_t jump) {

  Serial << "new movement: " << servo << " " << currentPos[servo] << "->" << final << " jump: " << jump << endl;
  
  startPos[servo] = currentPos[servo];
  finalPos[servo] = final;
  jumpVal[servo] = jump;
  movingServo[servo] = true;
  
}



void randomMovementGen() {
  
 for(uint8_t i=0; i<SERVOQTY; i++) {
 
   if(movingServo[i] == false) {
     
     uint16_t _finalPos = (uint16_t)random(homePos[i]-posdiff, homePos[i]+posdiff);
     uint8_t _jumpVal = 1;
     
     //if(abs(_finalPos-currentPos[i]) > 100) {
     //  _jumpVal = (uint8_t)random(1, 4);
     //}
     
     newMovement(i, _finalPos, _jumpVal);
     
     }
     
 }
 
}

void servoUpdate() {
 
 for(int i=0; i<SERVOQTY; i++) {
    
    if(movingServo[i] == true) {
      
      if(finalPos[i] > startPos[i]) {
        currentPos[i] += jumpVal[i];
        pwm.setPWM(i, 0, currentPos[i]);
      } else if(finalPos[i] < startPos[i]) {
        currentPos[i] -= jumpVal[i];
        pwm.setPWM(i, 0, currentPos[i]);
      }
      
      if(finalPos[i] == currentPos[i]) {
        movingServo[i] = false;
      }
      
    }
    
  }
  
}
