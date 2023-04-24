// Pin declarations for UNO board
const int PIN_DIR1 = 4;    // Motor direction signal
const int PIN_PWM1 = 10;    // 490Hz pins 3, 9, 10, 11
const int DELAY = 20;     // Amount of time to delay between increments


const int PIN_DIR2 = 5;    // Motor direction signal
const int PIN_PWM2 = 11;    // 490Hz pins 3, 9, 10, 11
//const int DELAY = 20;     // Amount of time to delay between increments
// Variables
int _pwmCtrl = 0;         // PWM control signal 0-255
int _pwmInc = 1;          // Increment the PWM by this amount 
bool _dir1 = 0;            // Direction of the motor

// Variables
int _pwmCtrl2 = 0;         // PWM control signal 0-255
int _pwmInc2 = 1;          // Increment the PWM by this amount 
bool _dir2 = 0;            // Direction of the motor

//PWM SENT TO ARDUINO
volatile unsigned long pulseWidth1;
volatile unsigned long pulseWidth2;

//PWM INPUT PINS FROM PIXHAWK
const int pwmPin1 = 3;
const int pwmPin2 = 9;


void setup() 
{
    // Set DIR pin to output
    pinMode(PIN_DIR1, OUTPUT);
    
    // Set PWM pin to output
    pinMode(PIN_PWM1, OUTPUT);
    pinMode(pwmPin1,INPUT);

    // Set DIR pin to output
    pinMode(PIN_DIR2, OUTPUT);
    
    // Set PWM pin to output
    pinMode(PIN_PWM2, OUTPUT);
    pinMode(pwmPin2,INPUT);


    
    Serial.begin(9600);
      attachInterrupt(digitalPinToInterrupt(pwmPin1), handleInterrupt1, CHANGE);
      attachInterrupt(digitalPinToInterrupt(pwmPin2), handleInterrupt2, CHANGE);
}

void loop() 
{
    
    //motor 1
    if(pulseWidth1 > 1500){
      digitalWrite(PIN_DIR1,HIGH);
      analogWrite(PIN_PWM1, map(pulseWidth1,1500,2000,0,255));
      Serial.print(PIN_PWM1);
      Serial.println(" Forward");
    }
    else{
      digitalWrite(PIN_DIR1,LOW);
      analogWrite(PIN_PWM1, map(pulseWidth1,1000,1500,255,0));
      Serial.print(pulseWidth1);
      Serial.println(" Backward");
    }

    
    //motor 2
    if(pulseWidth2 > 1500){
      digitalWrite(PIN_DIR2,HIGH);
      analogWrite(PIN_PWM2, map(pulseWidth2,1500,2000,0,255));
      Serial.print(pulseWidth2);
      Serial.println(" Forward");
    }
    else{
      digitalWrite(PIN_DIR2,LOW);
      analogWrite(PIN_PWM2, map(pulseWidth2,1000,1500,0,255));
      Serial.print(pulseWidth2);
      Serial.println(" Backward");
    }

    
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
