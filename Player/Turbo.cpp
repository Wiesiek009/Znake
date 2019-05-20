#include "Turbo.hpp"

Turbo::Turbo(short id, Config* config, bool* booster, sf::Color color)
{
	m_config = config;
	m_id = id;
	m_booster = booster;

	m_body.setSize(sf::Vector2f(config->m_width / 8.f, config->m_height / 40.f));
	m_outline.setSize(sf::Vector2f(config->m_width / 8.f, config->m_height / 40.f));

	m_body.setOrigin(m_body.getSize().x / 2.f , m_body.getSize().y / 2.f);
	m_outline.setOrigin(m_outline.getSize().x / 2.f , m_outline.getSize().y / 2.f);

	color.a = 150;
	m_body.setFillColor(color);
	color.a = 30;
	m_outline.setFillColor(color);

	if(id == 0)
	{
		m_body.setPosition(0 + m_body.getSize().x, 0 + m_body.getSize().y);
		m_outline.setPosition(0 + m_body.getSize().x, 0 + m_body.getSize().y);
	}

	else if(id == 1)
	{
		m_body.setPosition(config->m_width - m_body.getSize().x, config->m_height - m_body.getSize().y);
		m_outline.setPosition(config->m_width - m_body.getSize().x, config->m_height - m_body.getSize().y);
	}
		
	else if(id == 2)
	{
		m_body.setPosition(config->m_width - m_body.getSize().x, 0 + m_body.getSize().y);
		m_outline.setPosition(config->m_width - m_body.getSize().x, 0 + m_body.getSize().y);
	}
	else if(id == 3)
	{
		m_body.setPosition(0 + m_body.getSize().x, config->m_height - m_body.getSize().y);
		m_outline.setPosition(0 + m_body.getSize().x, config->m_height - m_body.getSize().y);
	}
}

void Turbo::control(sf::Keyboard::Key shit, float delta)
{
	if(sf::Keyboard::isKeyPressed(shit))
	{
		if(m_used == 0)
		{
			m_value -= delta * 100.f;
			*m_booster = true;

			if(m_value < 0)
				m_used = true;	
		}
	}
	else
	{	
		if(m_used == 0)
		{
			m_value += delta * 100.f;
			if(m_value > 100)
				m_value = 100;
		}

	}
}

void Turbo::update(float delta)
{
	if(m_id == 0)
		control(sf::Keyboard::Up, delta);
	else if(m_id == 1)
		control(sf::Keyboard::W, delta);
	else if(m_id == 2)
		control(sf::Keyboard::I, delta);
	else if(m_id == 3)
		control(sf::Keyboard::O, delta);

	m_body.setSize(sf::Vector2f((m_config->m_width / 8.f) * (m_value / 100.f), m_config->m_height / 40.f));
}

sf::RectangleShape* Turbo::getBody()
{
	return &m_body;
}

sf::RectangleShape* Turbo::getOutline()
{
	return &m_outline;
}