#include "Engine.hpp"

Engine::Engine()
{
	m_settings.antialiasingLevel = 16;

	m_window.create(sf::VideoMode(800, 600), "Znake ver. 0.0.0.1-ALPHA", sf::Style::Close, m_settings);
	m_renderer = Renderer(&m_window);
	
	m_menu = new Menu(&m_renderer);
}

Engine::~Engine()
{

}

void Engine::start()
{
	while(m_window.isOpen())
	{
		events();

		switch(m_status)
		{
			case(Status::MENU):
				m_menu->update(m_delta);
				break;

			case(Status::SINGLEPLAYER):
				m_singleplayer->update(m_delta);
				break;

			case(Status::MULTIPLAYER_LOBBY):
				break;

			case(Status::MULTIPLAYER_GAME):
				break;

			case(Status::OPTIONS):
				break;

			case(Status::CREDITS):
				break;
				
			case(Status::EXIT):
				m_window.close();
				break;
		}

		render();

		m_delta = m_clock.restart().asSeconds();
	}
}

void Engine::render()
{
	m_window.clear();

	m_renderer.draw();

	m_window.display();
}

void Engine::events()
{
	while(m_window.pollEvent(m_event))
	{
		if(m_event.type == sf::Event::Closed)
			m_window.close();

		if(m_event.type == sf::Event::KeyPressed &&  m_event.key.code == sf::Keyboard::Escape)
			if (m_status == Status::SINGLEPLAYER)
			{
				std::cout << "MENU" << std::endl;
				m_status = Status::MENU;
				delete m_singleplayer;
				m_menu = new Menu(&m_renderer);
			}
			else 
				m_window.close();

		if(m_event.type == sf::Event::KeyPressed && m_event.key.code == sf::Keyboard::P && m_status != Status::SINGLEPLAYER)
		{
			std::cout<< "SINGLEPLAYER"<<std::endl;
			m_status = Status::SINGLEPLAYER;
			delete m_menu;
			m_singleplayer = new Singleplayer(&m_renderer);
		}
	}
}