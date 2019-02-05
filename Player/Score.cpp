#include "Score.hpp"

Score::Score(Renderer* renderer, Config* config)
{
	srand(time(NULL));

	m_config = config;
	std::cout << m_config->m_playerSize << std::endl;
	m_body.setRadius(m_config->m_playerSize);
	m_body.setOrigin(m_config->m_playerSize, m_config->m_playerSize);
	m_body.setFillColor(sf::Color::Green);

	randScore();
	renderer->push(&m_body);
}

Score::~Score()
{

}

void Score::randScore()
{
	sf::Vector2f pos;

	pos.x = (rand() % (int)(m_config->m_width - (m_config->m_playerSize * 2))) +  m_config->m_playerSize;
	pos.y = (rand() % (int)(m_config->m_height - (m_config->m_playerSize * 2))) +  m_config->m_playerSize;

	m_body.setPosition(pos);
}

sf::Vector2f Score::getPosition()
{
	return m_body.getPosition();
}
