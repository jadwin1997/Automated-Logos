/* Automated Logos ESC test code
 * Date:
 * Contributor(s):
 *  Version:1.0
 */
#include <Servo.h>

Servo LeftMotor;  // create servo object to control ESC
Servo RightMotor;  // create servo object to control ESC
int state = 0;
int PWM = 1500;

void setup() {
  LeftMotor.attach(9);  // attach ESC to pin 9
  RightMotor.attach(10);// attach ESC to pin 10
  Serial.begin(9600);
}

void loop() {

  //state machine controlling menu
  switch (state) {
    case 0:    // Menu
      Serial.println("Welcome to AL's ESC tester");
      Serial.println("1: test left motor  2: test right motor  3: test both motors");

      //Read user choice and check if valid
      while(1==1){
        if(Serial.available()>0){
        state = Serial.parseInt();
        if(state<0||state>3){
          state = 0;
        }
        break;
        }
      }
      break;
    case 1:    // Left Motor Test
      Serial.println("Please type in a PWM value to be ran on the Left Motor for 3 seconds");

      //Get user choice and check if valid
      while(1==1){
        if(Serial.available()>0){
        PWM = Serial.parseInt();
        if(PWM <0 || PWM > 5000){
          PWM = 0;
        }
        break;
        }
       }

      //Run ESC for 3 seconds
      int timeOld = millis();
      while((millis()-timeOld)<3000){
      LeftMotor.writeMicroseconds(PWM);
      }
      break;

    //TODO: add right motor and duel motor menu options.
    case 2:    // Left
      Serial.println("medium");
      state = 0;
      break;
    case 3:    // Right
      Serial.println("bright");
      state = 0;
      break;
  }
}
