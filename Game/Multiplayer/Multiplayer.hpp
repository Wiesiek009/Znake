#pragma once

#include "SFML/Graphics.hpp"

#include "../../Renderer.hpp"

class Multiplayer
{
	public:
		Multiplayer(Renderer* renderer);
		~Multiplayer();

		void update(float delta);

	private:

		Renderer*	m_renderer;

};