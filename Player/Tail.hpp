#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

// red (255, 0, 0), orange (255, 127, 0), yellow (255, 255, 0), green (0, 255, 0), blue (0, 0, 255), indigo(‎75, 0, 130), violet(238, 130, 238)

// constexpr auto M_PI = 3.14159265359f;

class Tail
{
 	public:
 		Tail() = default;
		Tail(sf::Color color);
		~Tail();

		void update(sf::Vector2f pos, float angle, float radius);
		void addPoint(sf::Vector2f pos);
		void extend();
		std::vector<sf::Vertex>* getPoints();
		sf::CircleShape* getEnd();

	private:

		std::vector<sf::Vertex>		m_points;
		sf::CircleShape				m_end;

		short						m_id;
		sf::Color 					m_color;

		int							m_lenght = 50;
		int							m_curColor = 0;
		int							m_step = 0;
		std::vector<sf::Color>		m_colors;
};