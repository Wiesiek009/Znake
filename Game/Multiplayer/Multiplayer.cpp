#include "Multiplayer.hpp"

Multiplayer::Multiplayer(Renderer* renderer)
{
	m_renderer = renderer;
}

Multiplayer::~Multiplayer()
{
	m_renderer->clear();
}

void Multiplayer::update(float delta)
{
}