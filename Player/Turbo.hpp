#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Engine/Config.hpp"

class Turbo
{
	public:
		Turbo() = default;
		Turbo(short id, Config* config, bool* booster);
		~Turbo() = default;

		void control(sf::Keyboard::Key shit, float delta);
		void update(float delta);
		sf::RectangleShape* getBody();
		sf::RectangleShape* getOutline();

	private:

		Config*					m_config;
		sf::RectangleShape 		m_body;
		sf::RectangleShape 		m_outline;

		short 					m_id;
		float					m_value = 100;
		float					m_timeElapsed = 0;
		bool 					m_used = false;
		bool* 					m_booster;

};