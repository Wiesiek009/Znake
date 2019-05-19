#pragma once

#include "SFML/Graphics.hpp"

#include "../../Engine/Renderer.hpp"
#include "Lobby.hpp"

class Multiplayer
{
	public:
		Multiplayer(Renderer* renderer);
		~Multiplayer();

		void update(float delta);

	private:

		Renderer*	m_renderer;

		Lobby		m_lobby;

};