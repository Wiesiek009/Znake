#include "Lobby.hpp"

Lobby::Lobby(Renderer* renderer)
{
	m_renderer = renderer;
}

Lobby::~Lobby()
{
	m_renderer->clear();
}

void Lobby::update(float delta)
{
}