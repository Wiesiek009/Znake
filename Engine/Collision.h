#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "../Player/Head.hpp"
#include "../Player/Tail.hpp"
#include "../Player/Score.hpp"

class Collision
{
	public:
		Collision();
		~Collision();

		void push(Head* head);
		float distance(sf::Vector2f pos1, sf::Vector2f pos2);
		void update();
	private:
	
		std::vector<Head*>		m_heads;
		std::vector<Tail*>		m_tails;
		Score*					m_score = nullptr;

};

