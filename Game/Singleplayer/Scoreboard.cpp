#include "Scoreboard.hpp"

Scoreboard::Scoreboard(Renderer* renderer, Config* config)
{
	m_renderer = renderer;
	m_config = config;

	for (int i = 0; i < 4; i++)
		m_punctation[i] = 0;

	m_text1.setCharacterSize(50);
	m_text1.setStyle(sf::Text::Bold);
	m_text1.setLetterSpacing(2);
	m_text1.setFont(m_config->m_font);
	m_renderer->push(&m_text1);

	m_text2.setCharacterSize(30);
	m_text2.setFont(m_config->m_font);
	m_renderer->push(&m_text2);

	m_text3.setCharacterSize(30);
	m_text3.setFont(m_config->m_font);
	m_renderer->push(&m_text3);
}

Scoreboard::~Scoreboard()
{

}

void Scoreboard::drawTable(int winID)
{
	m_text1.setString("Wygral " + m_names[winID] + "!");
	sf::FloatRect rect1 = m_text1.getLocalBounds();
	m_text1.setOrigin(rect1.left + rect1.width / 2.0f, rect1.top + rect1.height / 2.0f);
	m_text1.setPosition(sf::Vector2f(m_config->m_width / 2.0f, m_config->m_height / 5.0f));






	std::string m2("");
	for (int i = 0; i < m_config->m_players; i++) 
	{
		m2 +=  m_names[i] + "\n";
	}
	m_text2.setString(m2);
	sf::FloatRect rect2 = m_text2.getLocalBounds();
	m_text2.setOrigin(rect2.left + rect2.width, 0);
	m_text2.setPosition(sf::Vector2f((m_config->m_width / 2.0f) - (m_config->m_width / 20.0f), m_config->m_height / 5.0f * 1.3f));


	std::string m3("");
	for (int i = 0; i < m_config->m_players; i++)
	{
		m3 += std::to_string(getScore(i)) + "\n";
	}
	m_text3.setString(m3);
	m_text3.setPosition(sf::Vector2f((m_config->m_width / 2.0f) + (m_config->m_width / 20.0f), m_config->m_height / 5.0f * 1.3f));
}

void Scoreboard::remvTable() 
{
	m_text1.setString("");
	m_text2.setString("");
	m_text3.setString("");
}

void Scoreboard::setName(int id, std::string name)
{
	if (id > 3 || id < 0)
		return;
	m_names[id] = name;
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