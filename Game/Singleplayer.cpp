#include "Singleplayer.hpp"

Singleplayer::Singleplayer(Renderer* renderer, Config* config)
{
	m_renderer = renderer;
	

	m_head.push_back(Head(sf::Vector2f(100, 100), config));
	m_renderer->push(m_head[0].getBody());
	m_renderer->push(m_head[0].getDirLine());
	m_renderer->push(m_head[0].getTail()->getPoints());
	m_renderer->push(m_head[0].getTail());
	
	m_score = new Score(m_renderer, config);

	m_collision = new Collision(config, renderer, m_score);
	m_collision->push(&m_head);
}

Singleplayer::~Singleplayer()
{
	m_renderer->clear();
}

void Singleplayer::update(float delta)
{
	for(int i = 0; i < m_head.size(); i++)
		m_head[i].update(delta);
	m_collision->update();

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		m_score->randScore();
}