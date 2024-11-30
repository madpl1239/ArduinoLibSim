/*
 * main.cpp
 * 
 * Simulation of tinyGPSPLus and softwareSerial behavior.
 * 
 * 28-11-2024 by madpl
 */
#include <iostream>
#include <iomanip>
#include "tinyGPSPlus.hpp"
#include "softwareSerial.hpp"

SoftwareSerial gpsSerial("./gps_data.txt", 50);
TinyGPSPlus gps;


int main(void)
{
	while(gpsSerial.available() > 0)
	{
		char c = gpsSerial.read();
		gps.encode(c);
		
		if(gps.location.isUpdated())
		{
			std::cout << std::fixed << std::setprecision(7);
			
			std::cout << "Lat: " << gps.location.lat() 
					  << ", Lng: " << gps.location.lng() 
					  << std::endl;
					  
			gps.location.resetUpdate();
		}
	}

	return 0;
}
