#pragma once 

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

class Config
{
	public:
	
		Config();
		~Config();

		void load();
		void write();
		void takeValue(float* value, const char* name);
		void takeValue(std::string* value, const char* name);

		float			m_width;
		float			m_height;
		float			m_aliasing;
		float			m_playerSize;
		float			m_players;
		float 			m_speed;

		sf::Font		m_font1;

	private:

		std::ifstream	m_file;
};