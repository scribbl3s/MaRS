1) Wind Vane

This circuit can detect wind speed and direction. For measuring the direction, I wanted a sensor that can rotate and change some parameter to reflect the angle of rotation, so I used the circular potentiometer. A tall wind vane will be mounted on this, and when that rotates the potentiometer knob will rotate as well. I am using its output voltage to find the angle covered using simple ratios, as the voltage varies linearly based on the arc length that the potentiometer knob has rotated by. 
To measure the load exerted by wind, I used the proportionality (voltage given by sensor/1023)=(force detected by the sensor/max force that can be detected by the sensor).  The angle of the wind and wind load in that direction are displayed on the LCD for the user to see.

Limitations/Improvements:
- The circular potentiometer on Tinkercad can only rotate 270 degrees and not 360, so I'm measuring angles only from 45 to 135. In real life, I would use a potentiometer that can rotate as close to 360 degrees as possible.
- If we know the area of the sensor, we can divide force by area to get the wind pressure, and calculated its velocity based on this pressure and the average density of air.
- The force sensor has a fixed sensitivity. To change that, I would use a potentiometer that would let the user decide the sensitivity based on the location or application.
  
---------------------------------------------------------------------------------------------------------------
2) Plotting the effect of temperature on soil moisture level

This circuit measures the temperature and soil moisture level, graphs the instantaneous change in soil moisture level over time using an oscilloscope (its slope gives evaporation rate). The LCD displays the temperature and instantaneous evaporation rate at that time. To find the rate of evaporation every second, I stored the soil moisture values for every 2 consecutive runs of void loop() which has a delay of 1 second, and found their difference during each run to get the rate over that 1 second.
Evaporation rate = Change in moisture level over time/time;
I fastforwaded this process by 10x to see the results quicker and steeply enough to distinguish during our simulation (instead of incrementing time by 1s each time, I incremented by 10).
I wanted to display the moisture levels on a CRO because the user can see how it changes for given temperatures.
----------------------------------------------------------------------------------------------------------------
3) Smoke detection system

If the slide switch is on, the system is functional.
The has sensor continuously monitors smoke levels.
If the smoke level is below a first threshold value, nothing happens.
If the smoke level is above the first threshold but below a higher second threshold, the exhaust fan runs.
If the smoke level is above the second threshold, a fire alarm is sounded through the buzzer.
