#pragma once

#include "SFML/Graphics.hpp"
#include "iostream"

#include "../Engine/Renderer.hpp"
#include "../Engine/Config.hpp"
#include "../Engine/Status.hpp"

class Credits
{
	public:
		Credits(Renderer* renderer, Config* config);
		~Credits();

		void update(float delta, Status* next);

	private:

		Renderer*				m_renderer;
		Config* 				m_config;

		sf::Font				m_font;
		sf::Text				m_textLeft;
		sf::Text				m_textRight;
};