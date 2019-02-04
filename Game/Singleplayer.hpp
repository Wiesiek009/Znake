#pragma once 

#include "SFML/Graphics.hpp"

#include "../Engine/Renderer.hpp"
#include "../Player/Head.hpp"
#include "../Engine/Config.hpp"
#include "../Player/Score.hpp"

class Singleplayer
{
	public:
		Singleplayer(Renderer* renderer, Config* config);
		~Singleplayer();

		void update(float delta);

	private:
		
		Renderer*	m_renderer;
		Head 		m_head;
		Score* 		m_score;
		
};