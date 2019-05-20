#pragma once

#include <SFML/Graphics.hpp>

class Button
{

	public:
		Button() = default;
		Button(sf::Font* font, std::string text, int textSize, sf::Color textColor, sf::Color backgroundColor, sf::Color outlineColor, float outlineSize, sf::Vector2f pos);
		~Button();

		void update(float delta);
		sf::RectangleShape* getBody();
		sf::Text* getText();

	private:
		sf::RectangleShape		m_body;
		sf::Text				m_text;


};