#include "Credits.hpp"

Credits::Credits(Renderer* renderer)
{
	m_renderer = renderer;
}

Credits::~Credits()
{
	m_renderer->clear();
}

void Credits::update(float delta)
{
}