#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <iostream>

#include "Player.hpp"
#include "Config.hpp"

class Collision
{
	public:
		Collision() = default;
		Collision(Config* config);
		~Collision();

		void push(std::vector<Player>* heads);
		float distance(sf::Vector2f pos1, sf::Vector2f pos2);
		void update();
	private:
	
		std::vector<Player>*	m_players;
		
		Config*					m_config;
};

