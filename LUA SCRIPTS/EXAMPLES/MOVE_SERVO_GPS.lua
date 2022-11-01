-- This script moves a servo if the rover arrives at it's next GPS point.
--
-- The following parameters should be set:
--     SERVO1_FUNCTION = 94 (Script 1) 

local ACCEPTANCE_DISTANCE = 1.0

local K_SCRIPTING1 = 94 -- for servo control

function update()
  local target  = vehicle:get_target_location()
  local current = ahrs:get_location()

  if (current and target) then
    local dist = target:get_distance(current)
    if dist < ACCEPTANCE_DISTANCE then
        SRV_Channels:set_output_norm(K_SCRIPTING1,1)
    end
  end      
  return update, 10 -- run at 100hz
end

gcs:send_text(6, "Paint spray script is running")
return update()
