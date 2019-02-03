#include "Menu.hpp"

Menu::Menu(Renderer* renderer) 
{
	m_renderer = renderer;

	m_font.loadFromFile("ariblk.ttf");

	float width = 800, height = 600;

	m_button[0] = new Button(&m_font, "Singleplayer", 15, sf::Color::Black, sf::Color::White, sf::Color::Black, 3, sf::Vector2f(width / 2.f, height / 2.f - 80));
	m_button[1] = new Button(&m_font, "Multiplayer", 15, sf::Color::Black, sf::Color::White, sf::Color::Black, 3, sf::Vector2f(width / 2.f, height / 2.f));
	m_button[2] = new Button(&m_font, "Options", 15, sf::Color::Black, sf::Color::White, sf::Color::Black, 3, sf::Vector2f(width / 2.f, height / 2.f + 80));
	m_button[3] = new Button(&m_font, "Credits", 15, sf::Color::Black, sf::Color::White, sf::Color::Black, 3, sf::Vector2f(width / 2.f, height / 2.f + 160));
	m_button[4] = new Button(&m_font, "Exit", 15, sf::Color::Black, sf::Color::White, sf::Color::Black, 3, sf::Vector2f(width / 2.f, height / 2.f + 240));

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

void Menu::click(sf::Vector2f pos)
{
	for (int i = 0; i < 5; i++)
	{
		if(m_button[i]->getBody()->getGlobalBounds().contains(pos))
		{
			
		}
	}
}
