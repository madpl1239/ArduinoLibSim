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

double kalmanLat = 0.0;
double kalmanLon = 0.0;
double Plat = 0.0;
double Plon = 0.0;


int main(void)
{
	while(gpsSerial.available() > 0)
	{
		char c = gpsSerial.read();
		gps.encode(c);
		
		if(gps.location.isUpdated())
		{
			double lat = gps.location.lat();
			double lon = gps.location.lng();
			
			// apply Kalman filter
			kalmanLat = kalmanFilter(lat, kalmanLat, Plat);
			kalmanLon = kalmanFilter(lon, kalmanLon, Plon);
			
			std::cout << std::fixed << std::setprecision(7);
			
			std::cout << "Lat: " << kalmanLat 
					  << ", Lng: " << kalmanLon 
					  << std::endl;
					  
			gps.location.resetUpdate();
		}
	}

	return 0;
}
