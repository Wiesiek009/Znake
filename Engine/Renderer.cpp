#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow* window)
{
	m_window = window;
}

Renderer::~Renderer()
{

}

void Renderer::push(sf::RectangleShape* body)
{
	m_rBodies.push_back(body);
}

void Renderer::push(sf::CircleShape* body)
{
	m_cBodies.push_back(body);
}

void Renderer::push(sf::Text* body)
{
	m_texts.push_back(body);
}

void Renderer::push(std::vector<Head>* heads)
{
	m_heads = heads;
}

void Renderer::draw()
{
	if(m_heads != nullptr)
	{
		for(int i = 0; i < m_heads->size(); i++)
		{
				m_window->draw(*m_heads->at(i).getTail()->getEnd());
				
				for(int j = 0; j < m_heads->at(i).getTail()->getPoints()->size(); j++)
					if(m_heads->at(i).getTail()->getPoints()->size() != 0)
						m_window->draw(&m_heads->at(i).getTail()->getPoints()->front(), m_heads->at(i).getTail()->getPoints()->size(), sf::TriangleStrip);
				
				m_window->draw(*m_heads->at(i).getBody());
				m_window->draw(*m_heads->at(i).getDirLine());
				m_window->draw(*m_heads->at(i).getTurbo()->getBody());
				m_window->draw(*m_heads->at(i).getTurbo()->getOutline());
		}
	}

	for(int i = 0; i < m_cBodies.size(); i++)
		m_window->draw(*m_cBodies[i]);					// some shit

	for(int i = 0; i < m_rBodies.size(); i++)
		m_window->draw(*m_rBodies[i]);					// some shit

	for (int i = 0; i < m_texts.size(); i++)
		m_window->draw(*m_texts[i]);					// some shit
}

void Renderer::clear()
{
	m_cBodies.clear();
	m_rBodies.clear();
	m_texts.clear();
	m_heads = nullptr;	
}

std::vector<Head>* Renderer::getHeads()
{
	return m_heads;	
}

void Renderer::clearTexts()
{
	m_texts.clear();
}