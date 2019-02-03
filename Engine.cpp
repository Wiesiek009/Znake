#include "Engine.hpp"

Engine::Engine()
{
	m_config.load();
	m_settings.antialiasingLevel = m_config.m_aliasing;
	m_window.create(sf::VideoMode(m_config.m_width, m_config.m_height), "Znake ver. 0.0.0.1-ALPHA", sf::Style::Close, m_settings);
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
				m_credits->update(m_delta);
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
				m_status = Status::MENU;
				delete m_singleplayer;
				m_menu = new Menu(&m_renderer);
			}
			else if (m_status == Status::CREDITS)
			{
				m_status = Status::MENU;
				delete m_credits;
				m_menu = new Menu(&m_renderer);
			}
			else 
				m_window.close();

		if(m_event.type == sf::Event::KeyPressed && m_event.key.code == sf::Keyboard::P && m_status != Status::SINGLEPLAYER)
		{
			m_status = Status::SINGLEPLAYER;
			delete m_menu;
			m_singleplayer = new Singleplayer(&m_renderer);
		}

		if (m_event.type == sf::Event::KeyPressed && m_event.key.code == sf::Keyboard::C && m_status == Status::MENU)
		{
			m_status = Status::CREDITS;
			delete m_menu;
			m_credits = new Credits(&m_renderer);
		}


		if (m_event.type == sf::Event::MouseButtonPressed && m_event.mouseButton.button == sf::Mouse::Left && m_status == Status::MENU)
		{
			m_menu->click(sf::Vector2f(m_event.mouseButton.x, m_event.mouseButton.y));
		}

		if (m_event.type == sf::Event::MouseMoved && m_status == Status::MENU)
		{
			m_menu->move(sf::Vector2f(m_event.mouseMove.x, m_event.mouseMove.y));
		}
	}
}