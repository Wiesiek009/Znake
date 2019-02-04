#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>

#include "Renderer.hpp"
#include "../Game/Menu/Menu.hpp"
#include "../Game/Singleplayer.hpp"
#include "../Game/Multiplayer/Multiplayer.hpp"
#include "../Game/Credits.hpp"
#include "../Player/Head.hpp"
#include "Status.hpp"
#include "Config.hpp"

class Engine
{
	public:

		Engine();
		~Engine();

		void start();
		void render();
		void events();
		void checkStatus();

	private:


		sf::RenderWindow	m_window;
		sf::ContextSettings	m_settings;

		Renderer 			m_renderer;
		sf::Clock 			m_clock;
		sf::Event 			m_event;
		Status  			m_status = Status::MENU;
		Status				m_nextStatus;

		Config							m_config;

		Menu* 							m_menu = nullptr;
		Singleplayer* 					m_singleplayer = nullptr;
		Multiplayer* 					m_multiplayer = nullptr;
		Credits* 						m_credits = nullptr;

		float 							m_delta;
};