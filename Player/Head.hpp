#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>

#include "Tail.hpp"
#include "../Engine/Config.hpp"
#include "Turbo.hpp"

#define M_PI 3.14159265358979323846

class Head
{
	public:
		Head() = default;
		Head(Config* config, float angle, int id);
		~Head();

		void move(float delta);
		void update(float delta);
		void control(float delta);
		void feed();
		sf::CircleShape* getBody();
		sf::RectangleShape* getDirLine();
		sf::Vector2f getPosition();
		Tail* getTail();
		Turbo* getTurbo();
		short getId();


	private:
	
		Config* 			m_config;
		Turbo				m_turbo;

		bool* 				m_booster = new bool(false);
		float 				m_radius;
		float 				m_angle;
		sf::CircleShape 	m_body;
		sf::RectangleShape 	m_dirLine;
		short				m_id;

		Tail				m_tail;
		sf::Color			m_tailColor;
		float				m_time = 0;
		bool				m_shit = 0;
		std::string 		m_name;
};