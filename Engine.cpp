#include "Engine.hpp"

Engine::Engine()
{
	m_settings.antialiasingLevel = 16;

	m_window.create(sf::VideoMode(800, 600), "Znake ver. 0.0.0.1-ALPHA", sf::Style::Close, m_settings);
	m_renderer = Renderer(&m_window);
	m_renderer.pushStatus(&m_status);

	m_renderer.push(m_singleplayer.getHead()->getBody());
	m_renderer.push(m_singleplayer.getHead()->getLine());
	m_renderer.push(m_singleplayer.getHead()->getDirLine());
	m_renderer.push(m_singleplayer.getHead()->getTail()->getPoints());

	m_singleplayer.init(&m_renderer);
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
				break;

			case(Status::SINGLEPLAYER):
				m_singleplayer.update(m_delta);
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

		if (m_event.type == sf::Event::KeyPressed &&  m_event.key.code == sf::Keyboard::Escape) 
		{
			if(m_status == Status::SINGLEPLAYER)
				m_status = Status::MENU;
			else
				m_window.close();
		}
			

		if(m_event.type == sf::Event::KeyPressed && m_event.key.code == sf::Keyboard::P)
		{
			std::cout<< "SINGLEPLAYER"<<std::endl;
			m_status = Status::SINGLEPLAYER;
		}

		if (m_event.type == sf::Event::KeyPressed && m_event.key.code == sf::Keyboard::Enter)
		{
			std::cout << "MENU" << std::endl;
			m_status = Status::MENU;
		}
	}
}