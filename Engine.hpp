#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>

#include "Renderer.hpp"
#include "Game/Menu/Menu.hpp"
#include "Game/Singleplayer.hpp"
#include "Game/Multiplayer/Multiplayer.hpp"
#include "Game/Credits.hpp"
#include "Player/Head.hpp"

enum Status
{
	MENU = 0,
	SINGLEPLAYER,
	MULTIPLAYER_LOBBY,
	MULTIPLAYER_GAME,
	OPTIONS,
	CREDITS,
	EXIT
};

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

		Menu* 							m_menu;
		Singleplayer* 					m_singleplayer;
		Multiplayer* 					m_multiplayer;
		Credits* 						m_credits;

		float 							m_delta;
};