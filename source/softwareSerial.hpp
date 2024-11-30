/*
 * softwareSerial.hpp
 * 
 * loose softwareSerial simulation for simple Arduino
 * code testing but in non-arduino environment.
 * 
 * 28-11-2024 by madpl
 */
#pragma once

#include <queue>
#include <utility>
#include <chrono>


class SoftwareSerial
{
public:
	SoftwareSerial(const std::string& filename, int delay):
		m_delayMs(delay)
	{
		std::ifstream myfile(filename);
		std::string line;
		
		if(myfile.is_open())
		{
			while(std::getline(myfile, line))
			{
				for(char c : line)
					m_dataQueue.push(c);
				
				m_dataQueue.push('\n');
			}
			
			myfile.close();
		}
		else
			std::cerr << "can not open file!\n";
	}
	
	~SoftwareSerial()
	{
		m_delayMs = 0;
		m_dataQueue = std::move(std::queue<char>{});
	}

	int available() const
	{
		return m_dataQueue.size();
	}

	char read()
	{
		if(not m_dataQueue.empty())
		{
			delay(m_delayMs);
			
			char c = m_dataQueue.front();
			m_dataQueue.pop();
			
			return c;
		}
		
		return '\0';
	}

private:
	void delay(int msec) // active waiting
	{
		auto start = std::chrono::high_resolution_clock::now();
		while(true)
		{
			auto now = std::chrono::high_resolution_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
			
			if(elapsed >= msec)
				break;
		}
	}
	
	std::queue<char> m_dataQueue{};
	int m_delayMs;
};
