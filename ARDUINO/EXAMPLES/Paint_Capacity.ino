#include "HX711.h"

#define DOUT  3
#define CLK  2

HX711 scale;

float calibration_factor = -9090; //calibration = -9090 seems to work
long weight_change = 0;
long weight = 0;
long weight_f = 0;
long max_weight = 38; 

void setup() {
  Serial.begin(9600);
  
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
     Serial.print(weight*100/max_weight);// find out if average changes
     Serial.println(" %");
     Serial.println("Weight Changed");
  }
  weight_f = weight;
  

  
  
  // put your main code here, to run repeatedly:

}
