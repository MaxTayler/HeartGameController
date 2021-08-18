//Single Player Heart Rate Contoller Last Edited 2018_10_28
// Coded By Max Tayler
#include <Keyboard.h>// call keyboard libary 

//int pulseHigh1 = 0; // analog value coming off pulse sensor
//int pulseHigh2 = 0; // analog value coming off pulse sensor


void setup() {
  // put your setup code here, to run once:
  // Setup LED PINS 
  pinMode (4,INPUT); // setup  can be changed Led Pin 13 (onboard Led)
  pinMode (3,INPUT); // Player 1
  pinMode (2,INPUT); //Player 2 
  
  digitalWrite (4,LOW);// Turn Leds Off 
  digitalWrite (3,LOW);
  digitalWrite (2,LOW);
  
  Keyboard.begin();// start key library 

}

void loop() {
// put your main code here, to run repeatedly:

 int lockSwitch = analogRead(A0);// setup keyboard switch lock and update  
 int pulseHigh1 = analogRead(A1);// setup pulse sensor and update
 int pulseHigh2 = analogRead(A2);// setup pulse sensor and update
  
 if(lockSwitch >= 800) //tests switch to on/off on keyboard output
 {
  
    if (pulseHigh1 >= 900 ) //looks at sensor value to see if pulse is high 
      {
        Keyboard.press(KEY_LEFT_ARROW);// sends left arrow key press to computer
        digitalWrite (3,HIGH);
        delay(10);// allows for keyboard signal to be read
      }
      else
      {
        Keyboard.release(KEY_LEFT_ARROW);// sends left arrow key release to computer
        digitalWrite (3,LOW);
        delay(10);
      }
  
  if (pulseHigh2 >= 900 ) //looks at sensor value to see if pulse is high 
      {
        Keyboard.press(KEY_RIGHT_ARROW);// sends right arrow key press to computer
        digitalWrite (2,HIGH);
        delay(10);// allows for keyboard signal to be read
      }
      else
      {
        Keyboard.release(KEY_RIGHT_ARROW);// sends right arrow key release to computer
        digitalWrite (2,LOW);
        delay(10);
      }
  
    digitalWrite (4,HIGH);// Turn Leds ON
  }
  else{
    Keyboard.release(KEY_LEFT_ARROW); // makes sure keyboard presses are not locked on 
    Keyboard.release(KEY_RIGHT_ARROW); 
    delay(10);
    digitalWrite (4,LOW);
    } // if turned makes sure key is released 
   




}
