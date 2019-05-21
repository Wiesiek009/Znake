#include "Config.hpp"

Config::Config()
{
}

Config::~Config()
{
}

void Config::load()
{
	m_file.open("Config.cfg");

	if (m_file.good() != true)
		std::cout << "cfg corrupted" << std::endl;
	else
	{
		takeValue(&m_width, "Width:");
		takeValue(&m_height, "Height:");
		takeValue(&m_aliasing, "Aliasing:");
		takeValue(&m_players, "Players:");
		takeValue(&m_speed, "Speed:");
		takeValue(&m_playerSize, "PlayerSize:");

		std::string fontName;
		takeValue(&fontName, "Font1:");
		m_font1.loadFromFile(fontName);
	}
}

void Config::write()
{
}

void Config::takeValue(float* value, const char* name)
{
	std::string check;
	m_file >> check;
	if (check == name)
		m_file >> *value;

	std::cout << check << " " << *value << std::endl;
}

void Config::takeValue(std::string* value, const char* name)
{
	std::string check;
	m_file >> check;
	if (check == name)
		m_file >> *value;

	std::cout << check << " " << *value << std::endl;
}