#pragma once 

#include "SFML/Graphics.hpp"

#include "../Engine/Renderer.hpp"
#include "../Player/Head.hpp"
#include "../Engine/Config.hpp"
#include "../Player/Score.hpp"
#include "../Engine/Collision.hpp"

class Singleplayer
{
	public:
		Singleplayer(Renderer* renderer, Config* config);
		~Singleplayer();

		void update(float delta);

	private:
		
		Renderer*				m_renderer;
		std::vector<Head> 		m_head;
		Score* 					m_score;
		Collision*				m_collision;
};