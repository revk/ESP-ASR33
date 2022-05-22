# ESP32 ASR33 controller

Hardware and software for ESP32 based controller for ASR33 teletype.

- 20mA current sources for Tx and Rx 110 Baud.
- WiFi connection (IPv4 and IPv6)
- Simple TCP socket to interface to teletype
- MQTT connection
- Includes stand alone Colossal Cave adventure game

See ASR33.pages for more details

![ASR33](https://user-images.githubusercontent.com/996983/151703933-0d369dc1-1d2b-4c1f-b951-0e8e34954b85.png)

# Building

Git clone this `--recursive` to get all the submodules, and it should build with just `make`. That actually runs the normal `idf.py` to build. `make menuconfig` can be used to fine tune the settings, but the defaults should be mostly sane. `make flash` should work to program.
