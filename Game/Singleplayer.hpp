#pragma once 

#include "SFML/Graphics.hpp"

#include "../Renderer.hpp"
#include "../Player/Head.hpp"

class Singleplayer
{
	public:
		Singleplayer() = default;
		~Singleplayer();

		void init(Renderer* renderer);
		void update(float delta);
		Head* getHead();

	private:
		
		Renderer*	m_renderer;
		Head 		m_head;
		
};