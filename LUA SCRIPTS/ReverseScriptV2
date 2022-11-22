-- This script moves a servo if the rover arrives at it's next GPS point.
--
-- The following parameters should be set:
--     SERVO1_FUNCTION = 94 (Script 1) 
local relay = SRV_Channels:get_output_pwm(5)
local K_SCRIPTING1 = 94
local K_SCRIPTING5 = 98
function update()

local leftMotor = SRV_Channels:get_output_norm(2)
local rightMotor = SRV_Channels:get_output_norm(4)
if(leftMotor<0)then
    SRV_Channels:set_output_norm(K_SCRIPTING5,1)
    SRV_Channels:set_output_norm(1,-leftMotor)
else

    SRV_Channels:set_output_norm(K_SCRIPTING5,0)
    SRV_Channels:set_output_norm(K_SCRIPTING1,leftMotor)
end
  return update, 10 -- run at 100hz
end



end
gcs:send_text(6, "Paint spray script is running")
return update()
