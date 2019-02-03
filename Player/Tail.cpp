#include "Tail.hpp"

Tail::Tail()
{
	m_colors[0] = sf::Color(255, 0, 0);
	m_colors[1] = sf::Color(255, 127, 0);
	m_colors[2] = sf::Color(255, 255, 0);
	m_colors[3] = sf::Color(0, 255, 0);
	m_colors[4] = sf::Color(0, 0, 255);
	m_colors[5] = sf::Color(75, 0, 130);
	m_colors[6] = sf::Color(238, 130, 238);
}

Tail::~Tail()
{
	
}

void Tail::update(sf::Vector2f pos, float angle, float radius)
{
	sf::Vector2f tmp = sf::Vector2f(0, 0);

	tmp.x = (cos((angle + 270.f) * M_PI / 180.f) * radius);
	tmp.y = (sin((angle + 270.f) * M_PI / 180.f) * radius);
	tmp.x += pos.x;
	tmp.y += pos.y;

	addPoint(tmp);

	tmp.x = (cos((angle + 90) * M_PI / 180.f) * radius);
	tmp.y = (sin((angle + 90) * M_PI / 180.f) * radius);
	tmp.x += pos.x;
	tmp.y += pos.y;

	addPoint(tmp);
}

void Tail::addPoint(sf::Vector2f pos)
{
	m_points.push_back(sf::Vertex(pos, m_colors[m_curColor]));

	if (m_points.size() == m_lenght)
	{
		m_points.erase(m_points.begin());
	}

	if(m_step % 8 == 7)
		m_curColor++;

	m_step++;

	if (m_curColor > 6)
	{
		m_curColor = 0;
		m_step = 0;
	}
}

std::vector<sf::Vertex>* Tail::getPoints()
{
	return &m_points;
}
