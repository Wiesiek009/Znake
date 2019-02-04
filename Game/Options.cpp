#include "Options.hpp"

Options::Options(Renderer* renderer, Config* config)
{
	m_renderer = renderer;
	m_config = config;

	m_font.loadFromFile("Bebas.ttf");

	m_title = sf::Text("Options", m_font);
	m_title.setPosition(m_config->m_width / 2, m_config->m_height / 5);


	m_renderer->push(&m_title);
}

Options::~Options()
{
	m_renderer->clear();
}

void Options::update(float delta)
{
}
