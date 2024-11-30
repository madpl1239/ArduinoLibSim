/*
 * tinyGPSPlus.hpp
 * 
 * loose simulation of tinyGPS simple Arduino code
 * testing but in non-arduino environment.
 * 
 * 28-11-2024 by madpl
 */
#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


class TinyGPSPlus
{
public:
	class Location
	{
	public:
		Location():
			m_updated(false),
			m_latitude(0.0),
			m_longitude(0.0)
		{}
		
		~Location()
		{
			m_updated = false;
			m_latitude = 0.0;
			m_longitude = 0.0;
		}
		
		bool isUpdated() const
		{
			return m_updated;
		}
		
		double lat() const
		{
			return m_latitude;
		}
		
		double lng() const
		{
			return m_longitude;
		}
		
		void setLocation(double lat, double lng)
		{
			m_latitude = lat;
			m_longitude = lng;
			m_updated = true;
		}
		
		void resetUpdate()
		{
			m_updated = false;
		}
		
	private:
		bool m_updated;
		double m_latitude;
		double m_longitude;
	};

	Location location;

	// encode method simulating character stream processing
	bool encode(char c)
	{
		if(c == '\n')
		{
			// processing full line
			std::istringstream lineStream(s_buffer);
			double lat, lng;
			
			if(lineStream >> lat >> lng)
				location.setLocation(lat, lng);
			
			s_buffer.clear();
			
			return true;
		}
		else
			s_buffer += c;
		
		return false;
	}
	
private:
	inline static std::string s_buffer{};
};
