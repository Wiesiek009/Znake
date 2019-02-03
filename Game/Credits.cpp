#include "Credits.hpp"

Credits::Credits(Renderer* renderer)
{
	m_renderer = renderer;

	m_font.loadFromFile("Bebas.ttf");

	m_textLeft = sf::Text("Lucek\nMarcin", m_font);
	m_textLeft.setPosition(200.f, 200.f);

	m_textRight = sf::Text("programista\nuseless", m_font);
	m_textRight.setPosition(400.f, 200.f);

	m_renderer->push(&m_textLeft);
	m_renderer->push(&m_textRight);
}

Credits::~Credits()
{
	m_renderer->clear();
}

void Credits::update(float delta)
{

	m_textLeft.move(0, -30.f * delta);
	m_textRight.move(0, -30.f * delta);

}