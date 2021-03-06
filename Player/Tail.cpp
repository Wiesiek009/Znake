#include "Tail.hpp"

Tail::Tail(sf::Color color)
{
	m_color = color;

	// m_colors.push_back(sf::Color(255, 0, 0));
	// m_colors.push_back(sf::Color(255, 127, 0));
	// m_colors.push_back(sf::Color(255, 255, 0));
	// m_colors.push_back(sf::Color(0, 255, 0));
	// m_colors.push_back(sf::Color(0, 0, 255));
	// m_colors.push_back(sf::Color(75, 0, 130));
	// m_colors.push_back(sf::Color(238, 130, 238));
}

Tail::~Tail()
{
	m_points.clear();
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

	if (m_points.size() > 1)
	{
		m_end.setRadius(radius);
		m_end.setOrigin(radius, radius);
		m_end.setFillColor(m_points[0].color);
		m_end.setPosition((m_points[0].position.x + m_points[1].position.x) / 2.f, (m_points[0].position.y + m_points[1].position.y) / 2.f);
	}
}

void Tail::addPoint(sf::Vector2f pos)
{
	// m_points.push_back(sf::Vertex(pos, m_colors[m_curColor]));
	m_points.push_back(sf::Vertex(pos, m_color));

	if (m_points.size() == m_lenght)
	{
		m_points.erase(m_points.begin());
	}

	// if(m_step % (m_colors.size() + 1) == m_colors.size())
	// 	m_curColor++;

	// m_step++;

	// if (m_curColor > m_colors.size() - 1)
	// {
	// 	m_curColor = 0;
	// 	m_step = 0;
	// }
}

void Tail::extend()
{
	m_lenght += 16;
}

std::vector<sf::Vertex>* Tail::getPoints()
{
	return &m_points;
}

sf::CircleShape * Tail::getEnd()
{
	return &m_end;
}
