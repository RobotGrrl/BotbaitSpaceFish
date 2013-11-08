Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOQTY 4
#define LEDQTY 6

uint16_t homePos[] = {420, 420, 420, 380};
uint16_t posdiff = 145;

uint8_t servonum = 0;
uint16_t currentPos[] = {0, 0, 0, 0};
uint16_t startPos[] = {0, 0, 0, 0};
uint16_t finalPos[] = {0, 0, 0, 0};
boolean movingServo[] = {false, false, false, false};
uint8_t jumpVal[] = {0, 0, 0, 0};


uint8_t leds[] = {13, 12, 11, 10, 9, 8};
uint8_t ledVals[] = {255, 255, 255, 255, 255, 255};

uint8_t rgbleds[4][3] = { { 22, 23, 24 },
                          { 25, 26, 27 },    
                          { 28, 29, 30 },
                          { 31, 32, 33 } };
boolean squareLeds[4][3];
uint8_t lastSquareRainbow = 0;
long millisSquareRainbow = 0;
uint8_t freqSquareRainbow = 500;


// -- sensors
const uint8_t pingPin = 52;
const uint8_t buttonPin = 19;
long lastButtonPress = 0;

// -- emo
uint8_t emoState = 0;
uint8_t chosenServo = 0;
uint8_t introFrame = 0;
uint8_t technique = 0;
uint8_t numButtonPresses = 0;
uint8_t buttonState = false;
long starButtonChange = 0;


// -- just distance
uint8_t distState = 0;
uint8_t distState_prev = 0;


void initTentacle() {

  pinMode(pingPin, INPUT);
  pinMode(buttonPin, INPUT);

  for(uint8_t i=0; i<LEDQTY; i++) {
    pinMode(leds[i], OUTPUT);
    ledVals[i] = 0;
  }

  for(uint8_t i=0; i<4; i++) {
    for(uint8_t j=0; j<3; j++) {
      pinMode(rgbleds[i][j], OUTPUT);
      squareLeds[i][j] = false;
    }
  }

  pwm.begin();
  
  pwm.setPWMFreq(60);
  
  attachInterrupt(4, starButton, CHANGE);
  
  // -- boot up sequence
  for(uint8_t i=0; i<4; i++) {
    squareColour(i, 0, true);
    squareColour(i, 1, false);
    squareColour(i, 2, true);
  }
  
  fadeTentacle(255, 1);
  
  for(uint8_t i=0; i<SERVOQTY; i++) {
    pwm.setPWM(i, 0, homePos[i]);
    currentPos[i] = homePos[i];
  }
  delay(100);
  
}


void starButton() {
  
  /*
  if(emoState == 1) {
    buttonState = true;
    starButtonChange = millis();
    
    // celebrate a little
    squareOn();
    tentacleOn();
    
  }
  */
  
  if(millis()-starButtonChange >= 100) {
    buttonState = true;
    sendMessage(0, 1);
    starButtonChange = millis();
  }
  
}

void checkStates() {
 
 if(buttonState) {
    uint8_t chosenServo = (uint8_t)random(0, 4);
      
    pwm.setPWM(chosenServo, 0, homePos[chosenServo]+posdiff);
    delay(300);
    pwm.setPWM(chosenServo, 0, homePos[chosenServo]-posdiff);
    delay(300);
      
    pwm.setPWM(chosenServo, 0, homePos[chosenServo]);
    buttonState = !buttonState;
  }
  
}

