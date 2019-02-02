#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>

#include "Tail.hpp"

class Head
{
	public:
		Head() = default;
		Head(sf::Vector2f pos);
		~Head();

		void move(float delta);
		void update(float delta);
		void control(float delta);
		sf::CircleShape* getBody();
		sf::RectangleShape* getLine();
		sf::RectangleShape* getDirLine();
		Tail* getTail();

	private:
	
		float 				m_radius;
		float 				m_angle;
		sf::CircleShape 	m_body;
		sf::RectangleShape 	m_line;
		sf::RectangleShape 	m_dirLine;

		Tail				m_tail;
		float				m_time = 0;
		bool				m_shit = 0;
};