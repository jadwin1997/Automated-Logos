-- This script moves a servo if the rover arrives at it's next GPS point.
--
-- The following parameters should be set:
--     SERVO1_FUNCTION = 94 (Script 1) 
local relay = SRV_Channels:get_output_pwm(5)
local K_SCRIPTING1 = 94
local K_SCRIPTING5 = 98
function update()
if(relay)then
  gcs:send_text(0,relay)
else
  gcs:send_text(0,"no signal")
end
local CONTROL_OUTPUT_THROTTLE = 3
local CONTROL_OUTPUT_YAW = 4
local steering = vehicle:get_control_output(CONTROL_OUTPUT_YAW)
local throttle = vehicle:get_control_output(CONTROL_OUTPUT_THROTTLE)
--convert from ackerman to skid steering
if (steering and throttle) then
    if (throttle < 0) then
        steering = -steering
    end
    local summed = steering+throttle

    --This may not be correct!!
    local diff = (throttle/2)-steering
  if(diff<-1) then 
    diff = -1
  end
  if(diff>1) then
      diff = 1
  end
  if(summed<-1) then 
      summed = -1
    end
    if(summed>1) then
        summed = 1
    end
    if(diff)then
        gcs:send_text(0,steering)
    end
    if(diff<0)then
    SRV_Channels:set_output_norm(K_SCRIPTING5,1)
    SRV_Channels:set_output_norm(K_SCRIPTING1,-diff)
    else
    SRV_Channels:set_output_norm(K_SCRIPTING5,0)
    SRV_Channels:set_output_norm(K_SCRIPTING1,diff)
    end
  --end of convert steering

  return update, 10 -- run at 100hz
end



end
gcs:send_text(6, "Paint spray script is running")
return update()
