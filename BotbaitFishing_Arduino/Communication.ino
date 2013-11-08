
boolean reading = false;
boolean completed = false;
int msgIndex = 0;
const int msgLen = 12;
char msg[msgLen];

char cmd[2];
char val[4];
int valLen = 0;
double valResult = 0;

int cmdCount = 12;
int cmdRow = 99;

// -- receive
char rxCmds[][2] = { {'M', 'X'},
                     {'M', 'Y'},
                     {'F', 'F'} };

// -- send
char txCmds[][2] = { {'D', 'S'},
                     {'I', 'N'} };


// -- misc
long lastFishCatch = 0;

void listenForMessage() {
 
  // -- LISTEN -- //
  char m;
  if(Serial.available() > 0) {
    while(Serial.available() > 0) {
    
      m = Serial.read();
      
      if(m == '!') {
        reading = true;
      }
      
      if(reading) {
        if(msgIndex < msgLen) msg[msgIndex++] = m; 
      }
      
      if(m == '~') {
        reading = false;
        completed = true;
      }
      
    }
  }
  
  if(completed) {
   if(DEBUG) Serial << "good job" << endl; 
   
   for(int i=0; i<msgIndex; i++) {
     if(DEBUG) Serial << msg[i];
   }
   if(DEBUG) Serial << "\n";
   
   if(msg[0] == '!') {
     cmd[0] = msg[1];
     cmd[1] = msg[2];
   }
   
   if(msg[3] == ':') {
     for(int i=4; i<(msgIndex-1); i++) {
       val[i-4] = msg[i];
     }
     valLen = msgIndex-5;
   }
   
   boolean good = false;
   if(msg[(msgIndex-1)] == '~') {
     good = true;
   }
   
   if(good) {
     if(DEBUG) Serial << "good!" << endl;
     
     boolean match = false;
       for(int j=0; j<cmdCount; j++) {
         if(cmd[0] == rxCmds[j][0]) {
           if(cmd[1] == rxCmds[j][1]) {
             if(DEBUG) Serial << "match!" << j << endl;
             match = true;
             cmdRow = j;
           }
         }
       }
       
       if(match) {
           
           for(int i=0; i<valLen; i++) {
             if(DEBUG) Serial << val[i] << " ";
           }
           if(DEBUG) Serial << endl;
           
           for(int i=0; i<valLen; i++) {
               valResult += (val[(valLen-1)-i] - '0')*pow(10, i);
               if(DEBUG) Serial << i << ": " << val[(valLen-1)-i] << " " << (val[(valLen-1)-i] - '0') << " " << pow(10, i) << "=" << (val[(valLen-1)-i] - '0')*pow(10, i) << endl;
           }

           if(DEBUG) Serial << "Result: " << (int)valResult << endl;
           
           // do something with result
           parseMessage(cmdRow, (int)valResult);
           
           // at the end, clean!
           valResult = 0;
           valLen = 0;

       }
     
   }
   
   msgIndex = 0;
   completed = false;
   
  }
  
}

void parseMessage(int cmdRow, int valResult) {
  
 switch(cmdRow) {
   case 2: { // number of fish in middle
     
     for(int i=0; i<LEDQTY; i++) {
       if(i < valResult) {
       digitalWrite(leds[LEDQTY-(i+1)], HIGH);
       ledVals[i] = 255;
       } else {
         digitalWrite(leds[LEDQTY-(i+1)], LOW);
       ledVals[i] = 0;
       }
     }
     
     if(valResult >= 4 && millis()-lastFishCatch >= 1500) {
       beExcited2();
       sendMessage(1, 0);
       mvClose();
       lastFishCatch = millis();
     } else if(valResult >= 2) {
       bePleased2();
     } 
   
   }
   break;
 }
  
}

void sendMessage(int cmdRow, int val) {
  Serial << "!" << txCmds[cmdRow][0] << txCmds[cmdRow][1] <<":" << val << "~" << endl;
}


