#pragma once

#include "SFML/Graphics.hpp"

#include "../Engine/Renderer.hpp"

class Options
{

	public:
		Options(Renderer* rendered, Config* config);
		~Options();

		void update(float delta);

	private:

		Renderer*				m_renderer;
		Config* 				m_config;

		sf::Font				m_font;
		sf::Text				m_title;

};