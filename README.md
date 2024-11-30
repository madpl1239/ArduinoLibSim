# Simulated libraries for Arduino: tinyGPSPLus, softwareSerial 

The code simulates two libraries for Arduino: tinyGPS++ and softwareSerial.<br />
These libraries work on different systems (they are platform independent) and can be compiled using gcc or another compiler.<br />
They do not require additional libraries for operation - for now:))<br /><br />
I wrote these libraries to simulate the operation of Arduino with a GPS module, but without using the Arduino IDE.<br />
It is only a loose simulation of these libraries and contains only a few methods necessary to simulate reading latitude and longitude from GPS:))
<br /><br />
**Compilation**
<br />
- mkdir build
- cd build
- cmake ../ -G "Unix Makefiles" - for Linux
- cmake ../ -G "MinGW Makefiles" - for Windows and mingw32/64 compilers
<br />

**Running**
- type in terminal: tstGPS
<br />
