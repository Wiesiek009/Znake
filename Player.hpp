#pragma once 

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Player : public sf::TcpSocket
{
	public:
	
		Player() = default;
		void init(short id, std::string name);
		~Player();


		sf::Vector2f		pos;
		float				radius;

	private:

		short						m_id;
		std::string					m_name;
		
		sf::Color					m_color;
		std::vector<sf::Vector2f>	m_tail;
};