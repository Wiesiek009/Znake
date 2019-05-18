#pragma once 

#include "SFML/Graphics.hpp"

#include "../Engine/Renderer.hpp"
#include "../Player/Head.hpp"
#include "../Engine/Config.hpp"
#include "../Player/Score.hpp"
#include "../Engine/Collision.hpp"

enum Phase
{
	PREPARE,
	GAME,
	SCOREBOARD,
	CLEAR
};

class Singleplayer
{
	public:
		Singleplayer(Renderer* renderer, Config* config);
		~Singleplayer();

		void update(float delta, bool* pause);

	private:
		
		Renderer*				m_renderer;
		Config*					m_config;
		std::vector<Head> 		m_head;
		Score* 					m_score;
		Collision*				m_collision;
		sf::Text				m_text;
		short					m_points[4];

		Phase					m_phase = Phase::PREPARE;
};