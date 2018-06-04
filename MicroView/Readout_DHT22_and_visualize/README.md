# Temperatur and Humidity with DHT22 and MicroView
Little programm for an MicroView. Basic is an Arduino UNO
but there is a display on it.
Read out temp and humidity from a DHT22 and show it
on two MicroViewWidgets. Also the information will be
shown at the serial monitor.

### Needed programs
* [ArduinoIDE]	To get the arduinos running
* [Fritzing]	To see schema and other information

### Parts to rebuild this project
* [MicroView]	To see whats happen
* [DHT22]		To get the information
* [MicroViewPart] For full use with Fritzing
* 1kOhm resistor
* Some wire to connect everything

### Needed Libs to let the code running
* [DHT22Lib]
* [MicroViewLib]

### Datasheets
For more informations about the needed parts
* DHT22: http://www.rototron.info/wp-content/uploads/DHT22_Datasheet.pdf

### History
0.1.1 by M3taKn1ght
```sh
Implement rounding-function
````
0.1.0 by M3taKn1ght
```sh
Show both info on screen
Show above a header which widget is what
````
0.0.1 by M3taKn1ght
```sh
First try and upload
````


### Disclaiming
I am not responsible , for any damage to systems by running my small projects.

[ArduinoIDE]: <https://www.arduino.cc/en/Main/Software>
[Fritzing]: <http://fritzing.org/download/>
[MicroView]: <https://www.sparkfun.com/products/12923>
[DHT22]: <https://www.adafruit.com/products/385>
[DHT22Lib]: <https://github.com/adafruit/DHT-sensor-library>
[MicroViewLib]: <https://github.com/geekammo/MicroView-Arduino-Library>
[MicroViewPart]: <https://github.com/geekammo/MicroViewFritzingParts>