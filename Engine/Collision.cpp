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

void Collision::push(Head* head)
{
	m_heads.push_back(head);
}

float Collision::distance(sf::Vector2f pos1, sf::Vector2f pos2)
{
	sf::Vector2f d = pos1 - pos2;
	return sqrt(d.x*d.x + d.y*d.y);
}

void Collision::update()
{
	for (int i = 0; i < m_heads.size(); i++)
	{
		if (distance(m_score->getPosition(), m_heads[i]->getPosition()))
			m_heads[i]->feed();

		for(int j = i + 1; j < m_heads.size(); j++)
			if(distance(m_heads[i]->getPosition(), m_heads[j]->getPosition()) > m_config->m_playerSize)

		for (int j = 0; j < m_renderer->get_allTails()->size(); j++)
		{
			for (int k = 6; k < m_renderer->get_allTails()[j].size(); k++)
			{
				if (distance(m_heads[i]->getPosition(), m_renderer->get_allTails()->at(j)->at(k).position) > m_config->m_playerSize)
					std::cout << "COLLISION !!! " << std::endl;
			}
		}
	}
}