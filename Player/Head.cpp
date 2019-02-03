#include "Head.hpp"

Head::Head(sf::Vector2f pos)
{
	m_radius = 7.f;
	m_angle = 0;

	m_body.setRadius(m_radius);
	m_body.setOrigin(m_radius, m_radius);
	m_body.setFillColor(sf::Color::Red);

	m_body.setPosition(pos);
	m_line.setPosition(pos);
	m_dirLine.setPosition(pos);

	m_line.setSize(sf::Vector2f(2.f, m_radius * 2.f));
	m_line.setOrigin(m_line.getSize().x / 2.f, m_line.getSize().y / 2.f);

	m_dirLine.setSize(sf::Vector2f(m_radius, 2.f));
	m_dirLine.setOrigin(0, m_dirLine.getSize().y / 2.f);

	m_tail.update(m_body.getPosition(), m_angle, m_radius);
}

Head::~Head()
{
	
}

void Head::move(float delta)
{
	sf::Vector2f dir;

	dir.x = (cos(m_angle * M_PI / 180.f) * delta * 150.f);
	dir.y = (sin(m_angle * M_PI / 180.f) * delta * 150.f);

	m_body.move(dir);
}

void Head::update(float delta)
{
	m_body.setRotation(m_angle);
	m_line.setRotation(m_angle);
	m_dirLine.setRotation(m_angle);

	control(delta);
	move(delta);

	m_time += delta;
	if (m_time > 0.04f)
	{
		m_tail.update(m_body.getPosition(), m_angle, m_radius);
		m_time = 0;
	}

	m_line.setPosition(m_body.getPosition());
	m_dirLine.setPosition(m_body.getPosition());
}

void Head::control(float delta)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_angle -= delta * 175.f;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_angle += delta * 175.f;

	if(m_angle > 360.f)
		m_angle = 0;

	if(m_angle < 0)
		m_angle = 360.f;
}

sf::CircleShape* Head::getBody()
{
	return &m_body;
}

sf::RectangleShape* Head::getLine()
{
	return &m_line;
}

sf::RectangleShape* Head::getDirLine()
{
	return &m_dirLine;
}

Tail* Head::getTail()
{
	return &m_tail;
}
