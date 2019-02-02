#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Renderer.hpp"
#include "Game/Singleplayer.hpp"
#include "Player/Head.hpp"
#include "Status.hpp"

class Engine
{
	public:

		Engine();
		~Engine();

		void start();
		void render();
		void events();

	private:


		sf::RenderWindow	m_window;
		sf::ContextSettings	m_settings;

		Renderer 			m_renderer;
		sf::Clock 			m_clock;
		sf::Event 			m_event;
		Status  			m_status = Status::MENU;

		Singleplayer 		m_singleplayer;

		float 				m_delta;
};