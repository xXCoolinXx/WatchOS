# WatchOS
WatchOS for the Arduino <br>

This is a project I made back in 2017. I had the initial goal of creating a fully functioning OS to put on your watch where you could play games and stuff, but I was never able to finish it. I did pick up the project again this year and attempted a much more advanced rewrite (at least compared to my novice programming in the older projects), but I still haven't added all I want to add and probably won't any time soon. If you're interested in using this project, the main branch is the folder WatchOS, and it's using an ESP8266 with a joystick, Adafruit SSD1331 screen, a DS1307 clock, a button and a speaker. Some of the issues are screen clearing and being very slow, but I think it's definitely fixable. Also, I use a weird configuration for the joystick since the ESP8266 only has one analog pin that I could use, so you will need a couple resistors and to calibrate a couple variables I think. Alternatively, you could buy an I2C analog extension and connect the joystick that way. <br>

Some examples of things I wanted to add but haven't are a News (RSS?) reader using the WiFi feature, a snake game, Something based on Among Us (haha), and flappy bird type game <br>

Also make sure to fill in your own WiFi SSID and password if you want syncing the real time.
