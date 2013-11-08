/*
 * Botbait Fishing!
 * ::.:.:..::.::.::.
 *
 * Demo program of Botbait working with the Botbait Fishing
 * Processing visualization. You can interact with Botbait
 * to have it disturb the fish in different ways.
 *
 * The core communication code is in Communication.ino.
 * You can add commands to be sent or received in there, but
 * remember to also add the commands to Arduino.pde in the
 * Processing sketch.
 *
 * For more info:
 * http://robobrrd.com/tentacle
 *
 * By RobotGrrl for RoboBrrd.com
 * Nov. 7, 2013
 *
 * CC BY-SA
 */

#include <Streaming.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define DEBUG false

void setup() {
  Serial.begin(9600);
  Serial << "WoOooOoOoOoOoOoo Tentacle Mechanism" << endl;
  
  initTentacle();
}


void loop() {
  
  listenForMessage();
  checkStates();
  
}


