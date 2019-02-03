#pragma once

#include <SFML/Graphics.hpp>

#include "../Renderer.hpp"

class Score
{
 	public:
		Score(Renderer* renderer);
		~Score();

		void randScore();

	private:

		sf::CircleShape		m_body;
};