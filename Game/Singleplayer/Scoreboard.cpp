#include "Scoreboard.hpp"

Scoreboard::Scoreboard(Renderer* renderer, Config* config)
{
	m_renderer = renderer;
	m_config = config;

	for (int i = 0; i < 4; i++)
		m_punctation[i] = 0;

	m_textTitle.setCharacterSize(50);
	m_textTitle.setStyle(sf::Text::Bold);
	m_textTitle.setFont(m_config->m_font);
	m_renderer->push(&m_textTitle);

	for (int i = 0; i < 4; i++)
	{
		m_textLeft[i].setCharacterSize(30);
		m_textLeft[i].setFont(m_config->m_font);
		m_renderer->push(&m_textLeft[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		m_textRight[i].setCharacterSize(30);
		m_textRight[i].setFont(m_config->m_font);
		m_renderer->push(&m_textRight[i]);
	}
}

void Scoreboard::drawTable(int winID)
{
	if(winID != -1)
		m_textTitle.setString("Wygral " + m_names[winID] + "!");
	else
		m_textTitle.setString("REMIS!");
	
	sf::FloatRect rect1 = m_textTitle.getLocalBounds();
	m_textTitle.setOrigin(rect1.left + rect1.width / 2.0f, rect1.top + rect1.height / 2.0f);
	m_textTitle.setPosition(sf::Vector2f(m_config->m_width / 2.0f, m_config->m_height / 5.0f));

	int y = m_config->m_height / 5.0f * 1.3f;

	for (int i = 0; i < m_config->m_players; i++)
	{
		m_textLeft[i].setString(m_names[i]);
		m_textLeft[i].setFillColor(m_colors[i]);
		sf::FloatRect rect1 = m_textLeft[i].getLocalBounds();
		m_textLeft[i].setOrigin(rect1.left + rect1.width, 0);
		m_textLeft[i].setPosition(sf::Vector2f((m_config->m_width / 2.0f) - (m_config->m_width / 20.0f), y));



		m_textRight[i].setString(std::to_string(getScore(i)));
		m_textRight[i].setFillColor(m_colors[i]);
		m_textRight[i].setPosition(sf::Vector2f((m_config->m_width / 2.0f) + (m_config->m_width / 20.0f), y));

		y += 50;
	}
}

void Scoreboard::remvTable() 
{
	m_textTitle.setString("");
	for (int i = 0; i < 4; i++)
		m_textLeft[i].setString("");

	for (int i = 0; i < 4; i++)
		m_textRight[i].setString("");
}

void Scoreboard::updateInfo(int id, std::string name, sf::Color color)
{
	if (id > 3 || id < 0)
		return;
	m_names[id] = name;
	m_colors[id] = color;
}

void Scoreboard::addScore(int id) 
{
	if (id > 3 || id < 0)
		return;
	m_punctation[id] = m_punctation[id] + 1;
}

int Scoreboard::getScore(int id)
{
	if (id > 3 || id < 0)
		return -1;
	return m_punctation[id];
}

void Scoreboard::resetScores() 
{
	for (int i = 0; i < 4; i++)
		m_punctation[i] = 0;
}