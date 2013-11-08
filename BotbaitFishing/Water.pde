// -- WATER -- //
boolean initedOcean = false;
int initedCnt = 0;
int lastInitOc = 0;
int lastBlurp = 0;
int lastCornerBlurp = 0;
int cornerBlurp = 0;
int lastSideBlurp = 0;
int sideBlurp = 0;
float fishAngle[] = new float[numFish];
boolean disturbanceDir = false;
int lastFishCountSend = 0;


void initOcean() {
  float vel = 0.3;
  colorMode(HSB, 360, 1, 1);
  //color c = color(random(185, 250), 1.0, 1.0);
  color c = generateColour(0, 1);
  for(float i=0.1; i<1.0; i+=0.1) {
    c = generateColour(i, 0.0);
    addForce(i, 0.0, 0.0, vel, c);
    
    c = generateColour(i, 1.0);
    addForce(i, 1.0, 0.0, -vel, c);
    
    c = generateColour(0.0, i);
    addForce(0.0, i, vel, 0, c);
    
    c = generateColour(1.0, i);
    addForce(1.0, i, -vel, 0, c);
  }
}


void doInitOcean() {
 if(!initedOcean) {
    if(millis()-lastInitOc >= 10) {
      
      initOcean();
      initedCnt++;
      
      if(initedCnt >= 10) {
        initedOcean = true;
      }
      
      lastInitOc = millis();
      
    }
  } 
}


void doBlurps() {
 if(millis()-lastBlurp >= 500) {
    colorMode(HSB, 360, 1, 1);
    //color c = color(300, 1.0, 1.0);
    color c = generateColour(random(0,1.0), random(0,1.0));
    addForce(random(0,1.0), random(0,1.0), random(-0.5,0.5), random(-0.5,0.5), c);
    lastBlurp = millis();
  } 
}


void doCornerBlurps() {
 if(millis()-lastCornerBlurp >= 1000) {
   
   float vel = 0.2;
   
    colorMode(HSB, 360, 1, 1);
    //color c = color(300, 1.0, 1.0);
    color c = generateColour(random(0,1.0), random(0,1.0));
    
    switch(cornerBlurp) {
      case 0:
      addForce(0.0, 0.0, vel, vel, c);
      break;
      case 1:
      addForce(1.0, 0.0, -vel, vel, c);
      break;
      case 2:
      addForce(0.0, 1.0, vel, -vel, c);
      break;
      case 3:
      addForce(1.0, 1.0, -vel, -vel, c);
      cornerBlurp = -1;
      break;
    }
    
    cornerBlurp++;
    
    lastCornerBlurp = millis();
  } 
}


void doSideBlurps() {
 
 if(millis()-lastSideBlurp >= 500) {
   
   float vel = 0.5;
   
   color c = generateColour(random(0,1.0), random(0,1.0));
    
    switch(sideBlurp) {
      case 0:
      addForce(0.5, 0.0, 0.0, vel, c);
      break;
      case 1:
      addForce(1.0, 0.5, -vel, 0.0, c);
      break;
      case 2:
      addForce(0.5, 1.0, 0.0, -vel, c);
      break;
      case 3:
      addForce(0.0, 0.5, vel, 0.0, c);
      sideBlurp = -1;
      break;
    }
   
   sideBlurp++;
   lastSideBlurp = millis();
   
 }
  
}


void disturbance() {
  float vel = 0.3;
  colorMode(HSB, 360, 1, 1);
  //color c = color(random(185, 250), 1.0, 1.0);
  color c = generateColour(0, 1);
  
  float xPos = 0.5;//random(0.5-0.1, 0.5+0.1);
  float yPos = random(0.0, 1.0);
  float xVel = 0.3;
  float yVel = 0.3;
  
  if(disturbanceDir) {
    for(float i=0.1; i<0.7; i+=0.1) {
      addForce( xPos, yPos, xVel+i, yVel+i, generateColour(xPos, yPos) );
    }
  } else {
    for(float i=0.1; i<0.7; i+=0.1) {
      addForce( xPos, yPos, -(xVel+i), -(yVel+i), generateColour(xPos, yPos) );
    }
  }
  
  disturbanceDir = !disturbanceDir;
  
}


void inkance() {
 
  float vel = 0.1;
  color c = generateColour(0, 1);
  
  int d = 0;
  
  for(float j=0.1; j<1.0; j+=0.1) {
    for(float i=0.1; i<0.7; i+=0.1) {
      if(d%2 == 0) {
        addForce( 0.5, j, vel+i, 0.0, generateColour(0.5, j) );  
      } else {
        addForce( 0.5, j, -(vel+i), 0.0, generateColour(0.5, j) );
      }
    }
    d++;
  }
  
}


void checkForFishies() {
 int count = 0;
 for(int i=0; i<numFish; i++) {
   float fishNormX = particleSystem.fishParticles[i].x*invWidth;
   if(fishNormX >= 0.5-0.25 && fishNormX <= 0.5+0.25) {
     count++;
   }
 }
 if(count >= 0 && millis()-lastFishCountSend >= 1000) {
   if(connected) sendSerial(fishNumSerial, count);
   lastFishCountSend = millis();
 }
}


void rotateFishes() {
 imageMode(CENTER);
  for (int i=0; i<5; i++) {
    pushMatrix();
    translate(width/2, height/2);
    translate(-width/2+particleSystem.fishParticles[i].x, -height/2+particleSystem.fishParticles[i].y);
    //rotate(radians(mouseY));
    //rotate(counter*TWO_PI/360);
    if(abs(particleSystem.fishParticles[i].vy) >= 1.0 || abs(particleSystem.fishParticles[i].vx) >= 1.0) {
      fishAngle[i] = atan2(particleSystem.fishParticles[i].vy, particleSystem.fishParticles[i].vx);
    }
    rotate(fishAngle[i]);
    image(fishImg[i],0,0);
    translate(-fishImg[i].width/2, -fishImg[i].height/2);
    popMatrix();
  } 
}

