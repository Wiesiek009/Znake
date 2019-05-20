#include "Credits.hpp"

Credits::Credits(Renderer* renderer, Config* config)
{
	m_renderer = renderer;
	m_config = config;

	m_font.loadFromFile("Bebas.ttf");

	m_textLeft = sf::Text("", m_font);
	m_textLeft.setPosition(m_config->m_width * 1 / 8, m_config->m_height + 20);

	m_textRight = sf::Text("", m_font);
	m_textRight.setPosition(m_config->m_width * 2 / 4, m_config->m_height + 20);

	m_textLeft.setString(m_textLeft.getString() + "\n" + "Mariusz");
	m_textRight.setString(m_textRight.getString() + "\n" + "To  zalezy");

	m_textLeft.setString(m_textLeft.getString() + "\n" + "Sebastian");
	m_textRight.setString(m_textRight.getString() + "\n" + "Jebali   mu   mame");

	m_textLeft.setString(m_textLeft.getString() + "\n" + "Lucek");
	m_textRight.setString(m_textRight.getString() + "\n" + "Tester / Elita / Mistrz");

	m_textLeft.setString(m_textLeft.getString() + "\n" + "Marcin");
	m_textRight.setString(m_textRight.getString() + "\n" + "Useless / Dzban");

	m_textLeft.setString(m_textLeft.getString() + "\n" + "Krzysiu");
	m_textRight.setString(m_textRight.getString() + "\n" + "Lokalny   Kebab / Turas");


	m_textLeft.setString(m_textLeft.getString() + "\n" + "Norbert");
	m_textRight.setString(m_textRight.getString() + "\n" + "Dobry   kierowca   aka   rysuje   na   piachu");

	m_renderer->push(&m_textLeft);
	m_renderer->push(&m_textRight);
}

Credits::~Credits()
{
	m_renderer->clear();
}

void Credits::update(float delta, Status* next)
{

	m_textLeft.move(0, -50.f * delta);
	m_textRight.move(0, -50.f * delta);

	if ( (m_textRight.getGlobalBounds().height + m_textRight.getGlobalBounds().top) < 0)
	{
		*next = Status::MENU;
	}

}