# ESP32 ASR33 controller

Direct control of an ASR33 and connection to MQTT

This uses ESP32-RevK and so has the commands and settings as per that library
https://github.com/revk/ESP32-RevK

Additional settings:-
- uart:	UART number
- tx:	Tx pin
- rx:	Rx pin
- on:	On pin (a low on this wakes up)(
- sonoff:	The topic to use for power on/off the teletype
- idle:	The number of seconds before powering off after printing done
- keyidle: The number of seconds before powering off in manual mode (i.e. on function not just printing)
- echo:	If echo on or off

Commands :-
- on: Turn on now (automatically done if message to send)
- off: Turn off now (automatically done after idle delay)
- tx:	Raw 8 bit data to send to teletype
- text:	Text, adding carriage returns and setting even parity, and skipping utf-8 (print up arrow)

Status :-
- power: If power on or off
- busy: If tx queue is getting full - don't send it busy

Events :-
- rx:	Raw 8 bit data from teletype (one character at a time)
- line:	Text typed, parity stripped, a whole line of typed text

Copyright © 2020 Adrian Kennard, Andrews & Arnold Ltd. See LICENCE file for details. GPL 3.0
