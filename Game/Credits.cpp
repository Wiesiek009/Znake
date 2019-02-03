#include "Credits.hpp"

Credits::Credits(Renderer* renderer)
{
	m_renderer = renderer;

	m_font.loadFromFile("Bebas.ttf");

	m_text = sf::Text("Lucek programista", m_font);
	m_text.setPosition(200.f, 200.f);

	m_renderer->push(&m_text);
}

Credits::~Credits()
{
	m_renderer->clear();
}

void Credits::update(float delta)
{

	m_text.move(0, -3.f * delta);

}