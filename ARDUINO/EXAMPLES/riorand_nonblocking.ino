// Pin declarations for UNO board
const int PIN_DIR1 = 2;    // Motor direction signal
const int PIN_PWM1 = 9;    // 490Hz pins 3, 9, 10, 11
const int DELAY = 20;     // Amount of time to delay between increments


const int PIN_DIR2 = 4;    // Motor direction signal
const int PIN_PWM2 = 10;    // 490Hz pins 3, 9, 10, 11
//const int DELAY = 20;     // Amount of time to delay between increments
// Variables
int _pwmCtrl = 0;         // PWM control signal 0-255
int _pwmInc = 1;          // Increment the PWM by this amount 
bool _dir1 = 0;            // Direction of the motor

// Variables
int _pwmCtrl2 = 0;         // PWM control signal 0-255
int _pwmInc2 = 1;          // Increment the PWM by this amount 
bool _dir2 = 0;            // Direction of the motor
volatile unsigned long pulseWidth1;
volatile unsigned long pulseWidth2;
const int pwmPin1 = 2;
const int pwmPin2 = 4;


void setup() 
{
    // Set DIR pin to output
    pinMode(PIN_DIR1, OUTPUT);
    
    // Set PWM pin to output
    pinMode(PIN_PWM1, OUTPUT);

      attachInterrupt(digitalPinToInterrupt(pwmPin1), handleInterrupt1, CHANGE);
      attachInterrupt(digitalPinToInterrupt(pwmPin2), handleInterrupt2, CHANGE);
}

void loop() 
{
    if(pulseWidth1 > 1500){
      digitalWrite(PIN_DIR1,HIGH);
      analogWrite(PIN_PWM1, map(pulseWidth1,1500,2000,0,255));
    }
    else{
      digitalWrite(PIN_DIR1,LOW);
      analogWrite(PIN_PWM1, map(pulseWidth1,1000,1500,0,255));
    }

    //delay(DELAY);
}



void handleInterrupt1() {
  static unsigned long start_time;
  static bool state = LOW;
  
  if (digitalRead(pwmPin1) == state) {
    // This is a glitch in the signal, ignore it
    return;
  }
  
  if (state == LOW) {
    // Falling edge, start the pulse
    start_time = micros();
  } else {
    // Rising edge, end the pulse and record the width
    pulseWidth1 = micros() - start_time;
  }
  
  state = !state;
}


void handleInterrupt2() {
  static unsigned long start_time;
  static bool state = LOW;
  
  if (digitalRead(pwmPin2) == state) {
    // This is a glitch in the signal, ignore it
    return;
  }
  
  if (state == LOW) {
    // Falling edge, start the pulse
    start_time = micros();
  } else {
    // Rising edge, end the pulse and record the width
    pulseWidth2 = micros() - start_time;
  }
  
  state = !state;
}
