#pragma once 

#include "SFML/Graphics.hpp"

#include "../Renderer.hpp"
#include "../Player/Head.hpp"

class Singleplayer
{
	public:
		Singleplayer(Renderer* renderer);
		~Singleplayer();

		void update(float delta);

	private:
		
		Renderer*	m_renderer;
		Head 		m_head;
		
};