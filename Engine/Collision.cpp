#include "Collision.hpp"

Collision::Collision(Config* config, Renderer* renderer, Score* score)
{
	m_config = config;
	m_renderer = renderer;
	m_score = score;
}

Collision::~Collision()
{
}

void Collision::push(std::vector<Head>* heads)
{
	m_heads = heads;
}

float Collision::distance(sf::Vector2f pos1, sf::Vector2f pos2)
{
	sf::Vector2f d = pos2 - pos1;
	return sqrt(d.x*d.x + d.y*d.y);
}

void Collision::update()
{
	for (int i = 0; i < m_heads->size(); i++)
	{
		if (distance(m_score->getPosition(), m_heads->at(i).getPosition()) <= m_config->m_playerSize * 2.f)
		{
			m_heads->at(i).feed();
			m_score->randScore();
		}

		for (int j = i + 1; j < m_heads->size(); j++)
			if (distance(m_heads->at(i).getPosition(), m_heads->at(j).getPosition()) <= m_config->m_playerSize * 2.f)
			{
				m_heads->erase(m_heads->begin() + i);
				m_heads->erase(m_heads->begin() + j);
			}

		for (int j = 0; j < m_renderer->get_allTails()->size(); j++)
		{
			if (m_renderer->get_allTails()->at(j)->size() > 6)
				for (int k = 2; k < m_renderer->get_allTails()->at(j)->size() - 6; k++)
				{
					if (distance(m_heads->at(i).getPosition(), m_renderer->get_allTails()->at(j)->at(k).position) <= m_config->m_playerSize)
						m_heads->erase(m_heads->begin() + i);

					if (distance(m_score->getPosition(), m_renderer->get_allTails()->at(j)->at(k).position) <= m_config->m_playerSize)
						m_score->randScore();
				}
		}
	}
}