#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <time.h>
#include <cstdlib>

#include "../Renderer.hpp"
#include "../Config.hpp"

class Score
{
 	public:
 		Score() = default;
		Score(Renderer* renderer, Config* config);
		~Score();

		void randScore();

	private:

		sf::CircleShape		m_body;
		Config* 			m_config;
};