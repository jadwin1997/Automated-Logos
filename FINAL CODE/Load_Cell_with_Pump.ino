#include "HX711.h"

#define DOUT  3
#define CLK  2

HX711 scale;

float calibration_factor = -9090; //calibration = -9090 seems to work
long weight_change = 0;
long weight = 0;
long weight_f = 0;
long max_weight = 38; 
// constants won't change
const int ENA_PIN = 7; // the Arduino pin connected to the EN1 pin L298N
const int IN1_PIN = 6; // the Arduino pin connected to the IN1 pin L298N
const int IN2_PIN = 5; // the Arduino pin connected to the IN2 pin L298N


void setup() {
  Serial.begin(9600);
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
  long weight = scale.get_units(20);
  long weight_f = weight;
  
}

void loop() {
  
  scale.set_scale(calibration_factor);
  long weight = scale.get_units(20); //get average of 20 

  if(weight < weight_f  ||weight > weight_f)
  {
     Serial.print("p");
     Serial.println(weight*100/max_weight);// find out if average changes
     
  }
  weight_f = weight;
  
  if(Serial.available()>0){
    if(int(Serial.read()) == 1){
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, LOW);
    digitalWrite(ENA_PIN, HIGH);
    }
    else{
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, HIGH);
    digitalWrite(ENA_PIN, HIGH);  
    }
  }
  
  
  // put your main code here, to run repeatedly:

}
