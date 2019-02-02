#include "Singleplayer.hpp"

Singleplayer::~Singleplayer()
{
	m_renderer->clear();
}

void Singleplayer::init(Renderer* renderer)
{
	m_renderer = renderer;
	m_head = Head(sf::Vector2f(100, 100));
}

void Singleplayer::update(float delta)
{
	m_head.update(delta);
}

Head* Singleplayer::getHead()
{
	return &m_head;
}