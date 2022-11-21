-- This script moves a servo if the rover arrives at it's next GPS point.
--
-- The following parameters should be set:
--     SERVO1_FUNCTION = 94 (Script 1) 

--find serial port
local port = serial:find_serial(0)
port:begin(115200)
port:set_flow_control(0)

local ACCEPTANCE_DISTANCE = 1.0

local K_SCRIPTING1 = 94 -- for servo control
local holder = 1
function update()
  
    gcs:send_text(0,holder)
    port:write(holder)
    if(holder == 1)then
        holder = 0
    else
        holder = 1
    end

  return update, 1000 -- run at 1 hz
end

gcs:send_text(6, "Paint spray script is running")
return update()
