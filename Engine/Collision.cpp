#include "Collision.h"



Collision::Collision()
{
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
		for (int j = 6; j < m_heads[i]->getTail()->getPoints()->size(); j++)
		{

		}
	}
}