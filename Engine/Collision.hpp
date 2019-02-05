#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <iostream>

#include "../Player/Head.hpp"
#include "../Player/Tail.hpp"
#include "../Player/Score.hpp"
#include "Config.hpp"

class Collision
{
	public:
		Collision() = default;
		Collision(Config* config, Renderer* renderer, Score* score);
		~Collision();

		void push(std::vector<Head>* heads);
		float distance(sf::Vector2f pos1, sf::Vector2f pos2);
		void update();
	private:
	
		std::vector<Head>*		m_heads;
		Score*					m_score = nullptr;
		Config*					m_config;
		Renderer*				m_renderer;

};

