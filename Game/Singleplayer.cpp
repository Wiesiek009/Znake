#include "Singleplayer.hpp"

Singleplayer::Singleplayer(Renderer* renderer)
{
	m_renderer = renderer;
	m_head = Head(sf::Vector2f(100, 100));

	m_renderer->push(m_head.getBody());
	m_renderer->push(m_head.getLine());
	m_renderer->push(m_head.getDirLine());
	m_renderer->push(m_head.getTail()->getPoints());
}

Singleplayer::~Singleplayer()
{
	m_renderer->clear();
}

void Singleplayer::update(float delta)
{
	m_head.update(delta);
}