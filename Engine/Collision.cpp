#include "Collision.hpp"

Collision::Collision(Config* config, Renderer* renderer, Score* score)
{
	m_config = config;
	m_renderer = renderer;
	m_score = score;

	m_heads = m_renderer->getHeads();

	for (int i = 0; i < m_heads->size(); i++)
		m_tails.push_back(m_heads->at(i).getTail());
}

Collision::~Collision()
{
}

float Collision::distance(sf::Vector2f pos1, sf::Vector2f pos2)
{
	sf::Vector2f d = pos2 - pos1;
	return sqrt(d.x*d.x + d.y*d.y);
}

void Collision::update()
{
	m_erase.clear();

	for (int i = 0; i < m_heads->size(); i++)
	{
		if (distance(m_score->getPosition(), m_heads->at(i).getPosition()) <= m_config->m_playerSize * 2.f)
		{
			m_heads->at(i).feed();
			m_score->randScore();
		}

		for (int j = i + 1; j < m_heads->size(); j++)
		{
			if (distance(m_heads->at(i).getPosition(), m_heads->at(j).getPosition()) <= m_config->m_playerSize * 2.f)
			{
				m_erase.push_back(j);
				m_erase.push_back(i);
			}
		}

		if (m_heads->at(i).getPosition().x > m_config->m_width - m_config->m_playerSize)
					m_erase.push_back(i);
		if (m_heads->at(i).getPosition().x < 0 + m_config->m_playerSize)
					m_erase.push_back(i);
		if (m_heads->at(i).getPosition().y > m_config->m_height - m_config->m_playerSize)
					m_erase.push_back(i);
		if (m_heads->at(i).getPosition().y < 0 + m_config->m_playerSize)
					m_erase.push_back(i);

		for (int j = 0; j < m_tails.size(); j++)
		{
			for (int k = m_tails[j]->getPoints()->size() - 8; k > -1; k--)
			{
				if (distance(m_heads->at(i).getPosition(), m_tails[j]->getPoints()->at(k).position) < m_config->m_playerSize)
		 		{
		 			if (distance(m_score->getPosition(), m_heads->at(i).getTail()->getPoints()->at(j).position) <= m_config->m_playerSize)
						m_score->randScore();

		 			std::cout << "Kolizja gracza nr: "<< m_heads->at(i).getId() <<"  na: " << k << " pozycji ogonu numer: " << j << std::endl;
		 			std::cout << m_tails[j]->getPoints()->at(k).position.x << " --- " << m_tails[j]->getPoints()->at(k).position.y << std::endl;
					m_erase.push_back(i);
				}
			}
		}
	}

	for(int i = 0; i < m_erase.size(); i++)
		m_heads->erase(m_heads->begin() + m_erase[i]);
}