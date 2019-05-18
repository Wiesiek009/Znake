#include "Engine.hpp"

Engine::Engine()
{
	m_config.load();
	m_settings.antialiasingLevel = m_config.m_aliasing;
	m_settings.majorVersion = 3;
	m_settings.minorVersion = 0;
	m_window.create(sf::VideoMode(m_config.m_width, m_config.m_height), "Znake ver. 0.0.0.1-ALPHA", sf::Style::Close, m_settings);
	m_renderer = Renderer(&m_window);
	
	m_menu = new Menu(&m_renderer, &m_config);
}

Engine::~Engine()
{

}

void Engine::start()
{
	while(m_window.isOpen())
	{
		checkStatus();
		events();

		switch(m_status)
		{
			case(Status::MENU):
				m_menu->update(m_delta);
				break;

			case(Status::SINGLEPLAYER):
				m_singleplayer->update(m_delta, &m_pause);
				break;

			case(Status::MULTIPLAYER_LOBBY):
				break;

			case(Status::MULTIPLAYER_GAME):
				break;

			case(Status::OPTIONS):
				m_options->update(m_delta);
				break;

			case(Status::CREDITS):
				m_credits->update(m_delta, &m_nextStatus);
				break;
				
			case(Status::EXIT):
				m_window.close();
				break;
		}

		render();

		m_delta = m_clock.restart().asSeconds();

		if(m_pause)
			m_delta = 0;
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

		if (m_event.type == sf::Event::KeyPressed &&  m_event.key.code == sf::Keyboard::Escape)
		{
			if (m_status == Status::SINGLEPLAYER)
				m_nextStatus = Status::MENU;
			
			else if (m_status == Status::OPTIONS)
				m_nextStatus = Status::MENU;

			else if (m_status == Status::CREDITS)
				m_nextStatus = Status::MENU;

			else
				m_window.close();
		}


		if (m_event.type == sf::Event::MouseButtonPressed && m_event.mouseButton.button == sf::Mouse::Left && m_status == Status::MENU)
		{
			m_menu->click(sf::Vector2f(m_event.mouseButton.x, m_event.mouseButton.y), &m_nextStatus);
		}

		if (m_event.type == sf::Event::MouseMoved && m_status == Status::MENU)
		{
			m_menu->move(sf::Vector2f(m_event.mouseMove.x, m_event.mouseMove.y));
		}

		if (m_event.type == sf::Event::MouseButtonPressed && m_event.mouseButton.button == sf::Mouse::Middle)
		{
			std::cout << "Mysz: " << m_event.mouseButton.x << " --- " << m_event.mouseButton.y << std::endl;
		}

		if(m_event.type == sf::Event::KeyPressed &&  m_event.key.code == sf::Keyboard::Space)
		{
			if(m_pause)
				m_pause = false;
			else
				m_pause = true;
		}
	}
}

void Engine::checkStatus()
{
	if (m_status != m_nextStatus)
	{
		if (m_nextStatus == Status::SINGLEPLAYER and m_status == Status::MENU)
		{
			delete m_menu;
			m_singleplayer = new Singleplayer(&m_renderer, &m_config);
		}
		else if (m_nextStatus == Status::MULTIPLAYER_LOBBY and m_status == Status::MENU)
		{
			delete m_menu;
			m_multiplayer = new Multiplayer(&m_renderer);
		}
		else if (m_nextStatus == Status::MULTIPLAYER_GAME and m_status == Status::MENU)
		{
			delete m_menu;
		}
		else if (m_nextStatus == Status::CREDITS and m_status == Status::MENU)
		{
			delete m_menu;
			m_credits = new Credits(&m_renderer, &m_config);
		}
		else if (m_nextStatus == Status::OPTIONS and m_status == Status::MENU)
		{
			delete m_menu;
			m_options = new Options(&m_renderer, &m_config);
		}
		else if (m_nextStatus == Status::EXIT and m_status == Status::MENU)
		{
			delete m_menu;
		}
		else if (m_nextStatus == Status::MENU and m_status != Status::MENU)
		{
			if(m_status == Status::SINGLEPLAYER)
				delete m_singleplayer;
			if (m_status == Status::MULTIPLAYER_GAME)
				delete m_multiplayer;
			if (m_status == Status::OPTIONS)
				delete m_options;
			if (m_status == Status::CREDITS)
				delete m_credits;

			m_menu = new Menu(&m_renderer, &m_config);
		}
		m_status = m_nextStatus;
	}
}
