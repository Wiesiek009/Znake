#pragma once 

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

		float			m_width;
		float			m_height;
		float			m_aliasing;
		float			m_playerSize;

	private:

		std::ifstream	m_file;
};