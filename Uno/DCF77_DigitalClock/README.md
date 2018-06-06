# DCF77 DigitalClock

Simple hardware with LCD-Display (16x2) and DCF77-receiver to show a digital clock for time and date. Time and date will refresh after 60 seconds.
The sequence is as followed:
  - Init display and DCF77
  - Wait for correct DCF77-signal and set Arduino time
  - Refresh display with current data
  - Refresh after 60 seconds
  - Start refreshing time after 1 hour (3600 seconds)

### In this repository

  - Fritzing sketch
  - Code

### Needed hard- and software

| Hard- or Software | Link |
| ------ | ------ |
| Arduino Uno | [Link Arduino Uno] [hwUNO] |
| DCF77 | [Link DCF77][hwDCF77] |
|LCD-Display i2C|[Link LCD-Display][hwLCD]|
|Arduino IDE|[Link Arduino IDE][swArduino]|

License
----

MIT


**Free Software, Feel free to modify**

   [hwUno]: <https://store.arduino.cc/usa/arduino-uno-rev3>
   [hwDCF77]: <https://smile.amazon.de/Empfangsmodul-Funkzeit-Funkuhr-Arduino-Frankfurt/dp/B014I7VUS6/ref=sr_1_1?ie=UTF8&qid=1528304110&sr=8-1&keywords=DCF77>
   [hwLCD]: <https://smile.amazon.de/1602-serielles-LCD-Modul-Display-Bluescreen-Bibliotheksdateien/dp/B00D8S3YZO/ref=smi_www_rco2_go_smi_g4315534973?_encoding=UTF8&%2AVersion%2A=1&%2Aentries%2A=0&ie=UTF8>
   [swArduino]: <https://www.arduino.cc/en/Main/Software>