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

		void addScore(int id);
		int getScore(int id);
		void resetScores();

	private:

		Renderer*			m_renderer;
		Config*				m_config;

		int					m_punctation[4];

		sf::Text			m_text;
};