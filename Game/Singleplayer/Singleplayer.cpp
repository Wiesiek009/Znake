#include "Singleplayer.hpp"

Singleplayer::Singleplayer(Renderer* renderer, Config* config)
{
	m_renderer = renderer;
	m_config = config;

	m_text.setCharacterSize(30);
	m_text.setFont(m_config->m_font);

	m_renderer->push(&m_head);
	m_renderer->push(&m_text);
	m_score = new Score(m_renderer, m_config);

	m_scoreboard = new Scoreboard(m_renderer, m_config);
}

Singleplayer::~Singleplayer()
{
	m_renderer->clear();
}

void Singleplayer::update(float delta, bool* pause)
{
	switch(m_phase)
	{
		case PREPARE:

			m_head.push_back(Head(m_config, 45, 0));
			m_head.push_back(Head(m_config, 225, 1));
			if(m_config->m_players > 2)	
				m_head.push_back(Head(m_config, 135, 2));
			if(m_config->m_players > 3)				
				m_head.push_back(Head(m_config, 315, 3));

			for (int i = 0; i < m_head.size(); i++)
				m_scoreboard->setName(i, m_head[i].getName(), m_head[i].getColor());


			m_collision = new Collision(m_config, m_renderer, m_score);
			m_score->randScore();

			m_phase = Phase::GAME;
			*pause = true;
			break;

		case GAME:

			if(*pause == false)
			{
				for(int i = 0; i < m_head.size(); i++)
	 				m_head[i].update(delta);

				m_collision->update();
			}
				
			if(m_head.size() == 1)
			{
				m_scoreboard->addScore(m_head[0].getId());
				m_scoreboard->drawTable(m_head[0].getId());

			 	m_phase = Phase::SCOREBOARD;
			}
			else if(m_head.size() == 0)
			{
				m_scoreboard->drawTable(-1);

			 	m_phase = Phase::SCOREBOARD;	
			}

			break;

		case SCOREBOARD:

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				m_phase = Phase::CLEAR;
				m_text.setString("");
				m_scoreboard->remvTable();
			}
			
			break;

		case CLEAR:

			m_head.clear();
			m_phase = Phase::PREPARE;
			
			break;

		default:
			break;
	}
}