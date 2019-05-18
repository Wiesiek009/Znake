#include "Scoreboard.hpp"

Scoreboard::Scoreboard(Renderer* renderer, Config* config)
{
	m_renderer = renderer;
	m_config = config;

	for (int i = 0; i < 4; i++)
		m_punctation[i] = 0;

	m_text.setCharacterSize(30);
	m_text.setFont(m_config->m_font);
	m_renderer->push(&m_text);
}

Scoreboard::~Scoreboard()
{
	m_renderer->clear();
}

void Scoreboard::drawTable(int winID)
{
	std::string m("Wygral gracz => ");
	m += std::to_string(winID + 1);
	m += "\n";

	for (int i = 0; i < m_config->m_players; i++) 
	{
		m += "Gracz " + std::to_string(i + 1) + " => " + std::to_string(getScore(i));
		m += "\n";
	}

	m_text.setString(m);

	sf::FloatRect rect = m_text.getLocalBounds();
	m_text.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
	m_text.setPosition(sf::Vector2f(m_config->m_width / 2.0f, m_config->m_height / 2.0f));

}

void Scoreboard::remvTable() 
{
	m_text.setString("");
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