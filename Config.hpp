#pragma once 

#include <SFML/Network.hpp>
#include <iostream>
#include <fstream>
#include <string>

class Config
{
	public:
	
		Config();
		~Config();

		void load();
		void write();
		void takeValue(float* value, const char* name);
		void takeValue(sf::IpAddress* value, const char* name);

		sf::IpAddress	m_ip;
		float			m_port;
		float			m_width;
		float			m_height;
		float			m_playerSize;
		float			m_players;
		float 			m_speed;

	private:

		std::ifstream	m_file;
};