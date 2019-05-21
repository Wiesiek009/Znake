#pragma once

#include "SFML/Graphics.hpp"

#include "../../Engine/Renderer.hpp"
#include "../../Engine/Config.hpp"

class Scoreboard
{
	public:
		Scoreboard() = default;
		Scoreboard(Renderer* renderer, Config* config);
		~Scoreboard() = default;

		void drawTable(int winID);
		void remvTable();

		void updateInfo(int id, std::string name, sf::Color color);
		void addScore(int id);
		int getScore(int id);
		void resetScores();

	private:

		Renderer*			m_renderer;
		Config*				m_config;

		int					m_punctation[4];
		std::string			m_names[4];
		sf::Color			m_colors[4];

		sf::Text			m_textTitle;
		sf::Text			m_textLeft[4];
		sf::Text			m_textRight[4];
};