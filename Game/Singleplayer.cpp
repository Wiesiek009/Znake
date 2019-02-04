#include "Singleplayer.hpp"

Singleplayer::Singleplayer(Renderer* renderer, Config* config)
{
	m_renderer = renderer;
	m_head = Head(sf::Vector2f(100, 100), config);
	m_score = new Score(m_renderer, config);

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

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		m_score->randScore();
}