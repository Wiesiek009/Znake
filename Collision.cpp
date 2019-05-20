#include "Collision.hpp"

Collision::Collision(Config* config)
{
	m_config = config;
}

Collision::~Collision()
{
}

void Collision::push(std::vector<Player>* players)
{
	m_players = players;
}

float Collision::distance(sf::Vector2f pos1, sf::Vector2f pos2)
{
	sf::Vector2f d = pos2 - pos1;
	return sqrt(d.x*d.x + d.y*d.y);
}

void Collision::update()
{

}