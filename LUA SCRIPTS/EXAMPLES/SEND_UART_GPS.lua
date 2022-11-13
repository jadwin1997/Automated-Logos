-- This script sends a 1 or 0 over UART if the rover arrives at it's next GPS point.
-- The scripting protocol needs to be enabled on the serial parameter


--find serial port
local port = serial:find_serial(0)

--set baud rate
port:begin(9600)
port:set_flow_control(0)

--set acceptable distance (idk what units this is in, i assume meters)
local ACCEPTANCE_DISTANCE = 1.0


function update()
  -- get our target location set by the auto pilot
  local target  = vehicle:get_target_location()

  -- get location of bot
  local current = ahrs:get_location()

  --check if current and target exist
  if (current and target) then
    --get distance from target
    local dist = target:get_distance(current)
    
    -- check if within acceptance distance
    if dist < ACCEPTANCE_DISTANCE then
        --write 1 to arduino
        port:write(1)
    else
        --write 0 to arduino
        port:write(0)
    end
else
    port:write(0)
  end      
  return update, 10 -- run at 100hz
end

gcs:send_text(6, "Paint spray script is running")
return update()
