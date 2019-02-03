#pragma once

#include "SFML/Graphics.hpp"

#include "../Renderer.hpp"

class Credits
{
	public:
		Credits(Renderer* renderer);
		~Credits();

		void update(float delta);

	private:

		Renderer*				m_renderer;

		sf::Font				m_font;
		sf::Text				m_text;
};