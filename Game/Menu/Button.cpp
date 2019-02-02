#include "Button.hpp"

Button::Button(sf::Font* font, std::string text, int textSize, sf::Color textColor, sf::Color backgroundColor, sf::Color outlineColor, float outlineSize, sf::Vector2f pos)
{
	float width = 800, height = 600;

	m_body.setSize(sf::Vector2f(width / 5.f, height / 10.f));
	m_body.setOrigin(m_body.getSize().x / 2.f, m_body.getSize().y / 2.f);
	m_body.setOutlineThickness(outlineSize);
	m_body.setOutlineColor(outlineColor);
	m_body.setFillColor(backgroundColor);
	m_body.setPosition(pos);

	m_text = sf::Text(text, *font);
	m_text.setCharacterSize(textSize);
	m_text.setFillColor(textColor);
	m_text.setPosition(pos);

	sf::FloatRect box = m_text.getLocalBounds();
	m_text.setOrigin(box.left + box.width / 2.f, box.top + box.height / 2.f);
}

Button::~Button()
{

}

void Button::update(float delta)
{

}

sf::RectangleShape* Button::getBody()
{
	return &m_body;
}

sf::Text* Button::getText()
{
	return &m_text;
}
