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
		takeValue(&m_ip, "Ip:");
		takeValue(&m_port, "Port:");
		takeValue(&m_width, "Width:");
		takeValue(&m_height, "Height:");
		takeValue(&m_players, "Players:");
		takeValue(&m_speed, "Speed:");
		takeValue(&m_playerSize, "PlayerSize:");
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

void Config::takeValue(sf::IpAddress* value, const char* name)
{
	std::string check;
	m_file >> check;
	if (check == name)
	{
		int octet[4];

		for (int i = 0; i < 4; i++)
		{
			m_file >> octet[i];
		}

		*value = sf::IpAddress(octet[0], octet[1], octet[2], octet[3]);
		std::cout << check << " " << *value << std::endl;
	}
}