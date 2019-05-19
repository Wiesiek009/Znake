#pragma once

#include "SFML/Graphics.hpp"

#include "../../Engine/Renderer.hpp"
#include "../../Engine/Config.hpp"

class Scoreboard
{
	public:
		Scoreboard(Renderer* renderer, Config* config);
		~Scoreboard();

		void drawTable(int winID);
		void remvTable();

		void setName(int id, std::string name);
		void addScore(int id);
		int getScore(int id);
		void resetScores();

	private:

		Renderer*			m_renderer;
		Config*				m_config;

		int					m_punctation[4];
		std::string			m_names[4];

		sf::Text			m_text1;
		sf::Text			m_text2;
		sf::Text			m_text3;
};