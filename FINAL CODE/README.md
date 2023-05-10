These are the final files for AL to run. In this directory, we have the arduino code that allows for the use of the load cell as well as the linear actuator. 

The files for the Pixhawk Flight Controller is also attached. If starting over with a new flight controller, you will need to upload the parameter file as well as the LUA script. The parameter file 
sets default parameters for the bot (like motor pins, serial settings, rover mode, etc.) and the LUA script simply controls when the flight controller sprays (either using the DO command or via GPS waypoints). 

If the riorand sensored ESC is still going to be used, we reccomend using an Arduino nano to decode the RC pwm into 50% duty cycle pwm + direction pins. Keep in mind that if the ESC is wired up incorrectly, it will stall and draw a large amount of current (we blew multiple 20 amp fuses beacause of this). 
