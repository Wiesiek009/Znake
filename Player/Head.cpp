#include "Head.hpp"

Head::Head(Config* config, float angle, int id)
{
	m_config = config;
	m_radius = m_config->m_playerSize;
	m_angle = angle;
	m_id = id;

	m_body.setRadius(m_radius);
	m_body.setOrigin(m_radius, m_radius);

	if(id == 0)
	{
		m_name = "Player1";
		sf::Vector2f loc = sf::Vector2f(m_config->m_width / 8.f, m_config->m_height / 6.f);
		m_body.setPosition(loc);
		m_dirLine.setPosition(loc);
		m_tailColor = sf::Color::Green;
	}
	else if(id == 1)
	{
		m_name = "Player2";
		sf::Vector2f loc = sf::Vector2f(m_config->m_width - (m_config->m_width / 8.f), m_config->m_height - (m_config->m_height / 6.f));
		m_body.setPosition(loc);
		m_dirLine.setPosition(loc);
		m_tailColor = sf::Color::Red;
	}
	else if(id == 2)
	{
		m_name = "Player3";
		sf::Vector2f loc = sf::Vector2f(m_config->m_width - (m_config->m_width / 8.f), m_config->m_height / 6.f);
		m_body.setPosition(loc);
		m_dirLine.setPosition(loc);
		m_tailColor = sf::Color::Blue;
	}
	else if(id == 3)
	{
		m_name = "Player4";
		sf::Vector2f loc = sf::Vector2f(m_config->m_width / 8.f, m_config->m_height - (m_config->m_height / 6.f));
		m_body.setPosition(loc);
		m_dirLine.setPosition(loc);
		m_tailColor = sf::Color::Yellow;
	}
	m_body.setFillColor(m_tailColor);
	m_dirLine.setFillColor(sf::Color::White);
	m_dirLine.setSize(sf::Vector2f(m_radius, 2.f));
	m_dirLine.setOrigin(0, m_dirLine.getSize().y / 2.f);
	m_dirLine.setRotation(m_angle);

	m_tail = Tail(m_tailColor);
	m_tail.update(m_body.getPosition(), m_angle, m_radius);
	m_turbo = Turbo(m_id, m_config, m_booster, m_tailColor);
}

Head::~Head()
{
	
}

void Head::move(float delta)
{
	sf::Vector2f dir;

	dir.x = (cos(m_angle * M_PI / 180.f) * delta * m_config->m_speed);
	dir.y = (sin(m_angle * M_PI / 180.f) * delta * m_config->m_speed);

	m_body.move(dir);
}

void Head::update(float delta)
{
	control(delta);
	m_turbo.update(delta);

	if(*m_booster == 0)
		move(delta);
	else
		move(delta * 2.f);

	*m_booster = false;

	m_body.setRotation(m_angle);
	m_dirLine.setRotation(m_angle);

	m_time += delta;
	if (m_time > 0.025f)
	{
		m_tail.update(m_body.getPosition(), m_angle, m_radius);
		m_time = 0;
	}

	m_dirLine.setPosition(m_body.getPosition());
}

void Head::control(float delta)
{
	if(m_name == "Player1")
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			m_angle -= delta * m_config->m_speed * 1.15;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			m_angle += delta * m_config->m_speed * 1.15;
	}

	else if(m_name == "Player2")
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			m_angle -= delta * m_config->m_speed * 1.15;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			m_angle += delta * m_config->m_speed * 1.15;
	}

	else if(m_name == "Player3")
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			m_angle -= delta * m_config->m_speed * 1.15;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			m_angle += delta * m_config->m_speed * 1.15;
	}

	if(m_angle > 360.f)
		m_angle = 0;

	if(m_angle < 0)
		m_angle = 360.f;
}

void Head::feed()
{
	m_tail.extend();
}

sf::CircleShape* Head::getBody()
{
	return &m_body;
}

sf::RectangleShape* Head::getDirLine()
{
	return &m_dirLine;
}

sf::Vector2f Head::getPosition()
{
	return m_body.getPosition();
}

Tail* Head::getTail()
{
	return &m_tail;
}

Turbo* Head::getTurbo()
{
	return &m_turbo;
}

short Head::getId()
{
	return m_id;
}

std::string Head::getName()
{
	return m_name;
}

sf::Color Head::getColor()
{
	return m_tailColor;
}