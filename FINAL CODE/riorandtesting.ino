/*   PWM_Oscillating
 *   Increases the PWM duty cycle from 0 to 100% and then back down
 *   Changes the direction of the wheel when at 0 duty cycle
 *     
 *   created 2021
 *   Mad-EE  (Mad Electrical Engineer)
 *   www.mad-ee.com
 *   
 *   This example code is in the public domain.
 *   
 *   Platform:  Arduino UNO
 */

// Pin declarations for UNO board
const int PIN_DIR = 2;    // Motor direction signal
const int PIN_PWM = 9;    // 490Hz pins 3, 9, 10, 11
const int DELAY = 20;     // Amount of time to delay between increments

// Variables
int _pwmCtrl = 0;         // PWM control signal 0-255
int _pwmInc = 1;          // Increment the PWM by this amount 
bool _dir = 0;            // Direction of the motor

void setup() 
{
    // Set DIR pin to output
    pinMode(PIN_DIR, OUTPUT);
    
    // Set PWM pin to output
    pinMode(PIN_PWM, OUTPUT);
}

void loop() 
{
    // Increment or Decrement the pwm control
    _pwmCtrl += _pwmInc;

    // Change increment to negative if we are too high
    if (_pwmCtrl >= 255)
        _pwmInc = -1;

    // Change increment to positive if we are at zero
    // Change direction of motor if we are at zero
    if (_pwmCtrl <= 0)
    {
        _pwmInc = 1;
        _dir = !_dir;
    }

    // Set the PWM output
    analogWrite(PIN_PWM, _pwmCtrl);

    // Set the direction
    digitalWrite(PIN_DIR, _dir);

    // Add a delay so we don't change too fast
    delay(DELAY);
}
