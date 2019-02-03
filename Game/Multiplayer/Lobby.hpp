#pragma once

#include "SFML/Graphics.hpp"

#include "../../Renderer.hpp"

class Lobby
{
	public:
		Lobby() = default;
		Lobby(Renderer* renderer);
		~Lobby();

		void update(float delta);

	private:

		Renderer*				m_renderer;
};