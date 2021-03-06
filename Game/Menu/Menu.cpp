#include "Menu.hpp"

Menu::Menu(Renderer* renderer, Config* config) 
{
	m_renderer = renderer;
	m_config = config;

	m_font.loadFromFile("Bebas.ttf");
	
	m_button[0] = new Button(&m_font, "Singleplayer", 15, sf::Color::Black, sf::Color::White, sf::Color::Black, 3, sf::Vector2f(m_config->m_width / 2.f, m_config->m_height / 2.f - 80));
	m_button[1] = new Button(&m_font, "Multiplayer", 15, sf::Color::Black, sf::Color::White, sf::Color::Black, 3, sf::Vector2f(m_config->m_width / 2.f, m_config->m_height / 2.f));
	m_button[2] = new Button(&m_font, "Options", 15, sf::Color::Black, sf::Color::White, sf::Color::Black, 3, sf::Vector2f(m_config->m_width / 2.f, m_config->m_height / 2.f + 80));
	m_button[3] = new Button(&m_font, "Credits", 15, sf::Color::Black, sf::Color::White, sf::Color::Black, 3, sf::Vector2f(m_config->m_width / 2.f, m_config->m_height / 2.f + 160));
	m_button[4] = new Button(&m_font, "Exit", 15, sf::Color::Black, sf::Color::White, sf::Color::Black, 3, sf::Vector2f(m_config->m_width / 2.f, m_config->m_height / 2.f + 240));

	for (int i = 0; i < 5; i++)
	{
		m_renderer->push(m_button[i]->getBody());
		m_renderer->push(m_button[i]->getText());
	}
}

Menu::~Menu() 
{
	m_renderer->clear();
}

void Menu::update(float delta)
{
}

void Menu::keyPress(sf::Keyboard::Key code, Status* next)
{
	if (code == sf::Keyboard::S)
		* next = Status::SINGLEPLAYER;
	if (code == sf::Keyboard::O)
		* next = Status::OPTIONS;
	if (code == sf::Keyboard::C)
		* next = Status::CREDITS;
	if (code == sf::Keyboard::E)
		* next = Status::EXIT;
}

void Menu::move(sf::Vector2f pos)
{
	for (int i = 0; i < 5; i++)
	{
		if (m_button[i]->getBody()->getGlobalBounds().contains(pos))
		{
			m_button[i]->getBody()->setFillColor(sf::Color::Cyan);
		}
		else
		{
			m_button[i]->getBody()->setFillColor(sf::Color::White);
		}
	}
}

void Menu::click(sf::Vector2f pos, Status* next)
{
	for (int i = 0; i < 5; i++)
	{
		if (m_button[i]->getBody()->getGlobalBounds().contains(pos))
		{
			if (i == 0)
				*next = Status::SINGLEPLAYER;
			else if (i == 2)
				*next = Status::OPTIONS;
			else if (i == 3)
				*next = Status::CREDITS;
			else if (i == 4)
				*next = Status::EXIT;
		}
	}
}