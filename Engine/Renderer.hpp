#pragma once 

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Player/Head.hpp"
#include "../Player/Tail.hpp"
#include "../Player/Turbo.hpp"

class Renderer
{
	public:
		Renderer() = default;
		Renderer(sf::RenderWindow* window);
		~Renderer();

		void push(sf::RectangleShape* body);
		void push(sf::CircleShape* body);
		void push(sf::Text* body);
		void push(std::vector<Head>* heads);
		void draw();
		void clear();


		std::vector<Head>* getHeads();
		void clearTexts();

		
	private:

		std::vector<Head>* 						m_heads = nullptr;
		std::vector<sf::Text*> 					m_texts;
		std::vector<sf::CircleShape*> 			m_cBodies;
		std::vector<sf::RectangleShape*> 		m_rBodies;
		sf::RenderWindow*						m_window = nullptr;

};