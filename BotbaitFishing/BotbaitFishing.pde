/*
 * Botbait Fishing!
 * ::.:.:..::.::.::.
 *
 * Visualization of pixelated fish swimming around in
 * cosmic-coloured fluid. Botbait the tentacle mechanism
 * robot can disturb the fish in different ways, triggered
 * by your interaction with it.
 *
 * For more info:
 * http://robobrrd.com/tentacle
 * 
 * By RobotGrrl for RoboBrrd.com
 * Nov. 7, 2013
 *
 * CC BY-SA
 */

import controlP5.*;
import processing.serial.*;
import msafluid.*;
import javax.media.opengl.GL2;
import processing.opengl.*;
import javax.media.opengl.*;

static final boolean DEBUG = false;

final float FLUID_WIDTH = 120;
static final int numFish = 5;

MSAFluidSolver2D fluidSolver;
ParticleSystem particleSystem;

float invWidth, invHeight;
float aspectRatio, aspectRatio2;
PImage imgFluid;

PImage fishImg[] = new PImage[numFish];

boolean drawFluid = true;
// ---


void setup() {
  //size(960, 640, P3D);
  size(displayWidth * 49/50, displayHeight * 49/50, P3D);
  noStroke();

  invWidth = 1.0f/width;
  invHeight = 1.0f/height;
  aspectRatio = width * invHeight;
  aspectRatio2 = aspectRatio * aspectRatio;

  // create fluid and set options
  fluidSolver = new MSAFluidSolver2D((int)(FLUID_WIDTH), (int)(FLUID_WIDTH * height/width));
  //fluidSolver.enableRGB(true).setFadeSpeed(0.00003).setDeltaT(0.7).setVisc(0.0001);
  fluidSolver.enableRGB(true).setFadeSpeed(0.003).setDeltaT(0.7).setVisc(0.0001);

  // create image to hold fluid picture
  imgFluid = createImage(fluidSolver.getWidth(), fluidSolver.getHeight(), RGB);

  // create particle system
  particleSystem = new ParticleSystem();

  // fish images
  for(int i=0; i<numFish; i++) {
    fishImg[i] = loadImage("fish.png");
  }

  initControlP5();

}


void draw() {

  doInitOcean();
  
  doBlurps();
  doCornerBlurps();
  doSideBlurps();
  
  fluidSolver.update();

  if(drawFluid) {
      for(int i=0; i<fluidSolver.getNumCells(); i++) {
          int d = 2;
          imgFluid.pixels[i] = color(fluidSolver.r[i] * d, fluidSolver.g[i] * d, fluidSolver.b[i] * d);
      }  
      imgFluid.updatePixels();//  fastblur(imgFluid, 2);
      imageMode(CORNER);
      image(imgFluid, 0, 0, width, height);
  } 

  particleSystem.updateAndDraw();
  
  rotateFishes();
  
  if(guiVisible) {
    cp5.draw();
    cp5_v2.draw();
  }
  
  checkForFishies();
  
  readData();
  
}


void mousePressed() {

}


void mouseMoved() {
  float mouseNormX = mouseX * invWidth;
  float mouseNormY = mouseY * invHeight;
  float mouseVelX = (mouseX - pmouseX) * invWidth;
  float mouseVelY = (mouseY - pmouseY) * invHeight;

  addForce(mouseNormX, mouseNormY, mouseVelX, mouseVelY, generateColour(mouseNormX, mouseNormY));
}


void keyPressed() {
    switch(key) {
    case 'r': 
        renderUsingVA ^= true; 
        println("renderUsingVA: " + renderUsingVA);
        break;
    case 'h':
      guiVisible = !guiVisible;
      break;
    }
    println(frameRate);
}


// add force and dye to fluid, and create particles
void addForce(float x, float y, float dx, float dy, color c) {
  float speed = dx * dx  + dy * dy * aspectRatio2;    // balance the x and y components of speed with the screen aspect ratio

  if(speed > 0) {
    if(x<0) x = 0; 
    else if(x>1) x = 1;
    if(y<0) y = 0; 
    else if(y>1) y = 1;

    float colorMult = 5;
    float velocityMult = 30.0f;

    int index = fluidSolver.getIndexForNormalizedPosition(x, y);

    color drawColor;

    drawColor = c;
    
    colorMode(RGB, 1);

    fluidSolver.rOld[index]  += red(drawColor) * colorMult;
    fluidSolver.gOld[index]  += green(drawColor) * colorMult;
    fluidSolver.bOld[index]  += blue(drawColor) * colorMult;

    particleSystem.addParticles(x * width, y * height, 10);
    fluidSolver.uOld[index] += dx * velocityMult;
    fluidSolver.vOld[index] += dy * velocityMult;
  }
}


color generateColour(float x, float y) {
  colorMode(HSB, 360, 1, 1);
  float hue = ((x + y) * 180 + frameCount) % 360;
  color drawColor = color(hue, 1, 1);
  return drawColor;
}


