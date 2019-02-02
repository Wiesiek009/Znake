#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../Renderer.hpp"
#include "Button.hpp"

class Menu 
{

	public:
		Menu(Renderer* renderer);
		~Menu();

		void update(float delta);
		void click();


	private:
		Renderer*				m_renderer;

		sf::Font				m_font;

		Button*					m_button[5];

};