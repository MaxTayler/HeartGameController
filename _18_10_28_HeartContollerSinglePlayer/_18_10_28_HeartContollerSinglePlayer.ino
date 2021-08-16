//Single Player Heart Rate Contoller Last Edited 2018_10_28
// Coded By Max Tayler
#include <Keyboard.h>// call keyboard libary 

int pulseHigh1 = 0; // analog value coming off pulse sensor
void setup() {
  // put your setup code here, to run once:

  pinMode (13,INPUT); // setup Led Pin 13 (onboard Led)
  digitalWrite (13,LOW);// Turn Led Off 

  Keyboard.begin();

}

void loop() {
// put your main code here, to run repeatedly:

 int lockSwitch = analogRead(A0);// setup keyboard switch lock and update  
 int pulseHigh = analogRead(A1);// setup pulse sensor and update
  
 if(lockSwitch >= 800) //tests switch to on/off on keyboard output
 {
    if (pulseHigh >= 900 ) //looks at sensor value to see if pulse is high 
      {
        Keyboard.press(KEY_LEFT_ARROW);// sends left arrow key press to computer
        delay(10);// allows for keyboard signal to be read
      }
      else
      {
        Keyboard.release(KEY_LEFT_ARROW);// sends left arrow key release to computer
        delay(10);
      }

  }
  else{Keyboard.release(KEY_LEFT_ARROW);delay(10);} // if turned makes sure key is released 
   
}



