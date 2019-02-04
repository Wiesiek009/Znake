#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../Engine/Renderer.hpp"
#include "Button.hpp"
#include "../../Engine/Status.hpp"

class Menu 
{

	public:
		Menu(Renderer* renderer);
		~Menu();

		void update(float delta);
		void move(sf::Vector2f pos);
		void click(sf::Vector2f pos, Status* next);


	private:
		Renderer*				m_renderer;

		sf::Font				m_font;

		Button*					m_button[5];

};