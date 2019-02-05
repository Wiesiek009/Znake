#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow* window)
{
	m_window = window;
}

Renderer::~Renderer()
{

}

void Renderer::push(sf::CircleShape* body)
{
	m_cBodies.push_back(body);
}

void Renderer::push(sf::RectangleShape* body)
{
	m_rBodies.push_back(body);
}

void Renderer::push(sf::Text * body)
{
	m_texts.push_back(body);
}

void Renderer::push(std::vector<sf::Vertex>* body)
{
	m_tails.push_back(body);
}


void Renderer::draw()
{
	for(int i = 0; i < m_tails.size(); i++)
		if (m_tails[i]->size() != 0)
			m_window->draw(&m_tails[i]->front(), m_tails[i]->size(), sf::LinesStrip);

	for(int i = 0; i < m_cBodies.size(); i++)
		m_window->draw(*m_cBodies[i]);

	for(int i = 0; i < m_rBodies.size(); i++)
		m_window->draw(*m_rBodies[i]);

	for (int i = 0; i < m_texts.size(); i++)
		m_window->draw(*m_texts[i]);
}

void Renderer::clear()
{
	m_cBodies.clear();
	m_rBodies.clear();
	m_tails.clear();
	m_texts.clear();
}