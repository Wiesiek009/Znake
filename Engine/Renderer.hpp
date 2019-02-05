#pragma once 

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Player/Head.hpp"
#include "../Player/Tail.hpp"

class Renderer
{
	public:
		Renderer() = default;
		Renderer(sf::RenderWindow* window);
		~Renderer();

		void push(sf::CircleShape* body);
		void push(sf::RectangleShape* body);
		void push(sf::Text* body);
		void push(std::vector<sf::Vertex>* body);
		void push(Tail* end);
		std::vector<std::vector<sf::Vertex>*>* get_allTails();
		void draw();
		void clear();

	private:

		std::vector<sf::Text*> 					m_texts;
		std::vector<sf::CircleShape*> 			m_cBodies;
		std::vector<sf::RectangleShape*> 		m_rBodies;
		std::vector<std::vector<sf::Vertex>*>	m_tails;
		std::vector<Tail*>						m_ends;
		sf::RenderWindow*						m_window = nullptr;

};