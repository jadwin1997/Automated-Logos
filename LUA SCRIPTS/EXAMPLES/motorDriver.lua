local flipflop = true
local motor = 73
local leftMotor = SRV_Channels:find_channel(motor)
--local rightMotor = SRV_Channels:find_channel(4)

function update()
   
    output_pwm = SRV_Channels:get_output_scaled(leftMotor)
    gcs:send_text(0,output_pwm)
    return update, 2000
end

gcs:send_text(6, "servo_set_get.lua is running")
return update, 1000