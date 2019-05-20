#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <SFML/network.hpp>

#include "Player.hpp"
#include "Config.hpp"

enum State
{
	waitRoom,
	prepare,
	inGame,
	scoreboard,
	closingConnections
};

class Serwer
{
	public:

		Serwer();
		void mainLoop();

	private:

		Config						m_config;
		sf::TcpListener 			listener;
		sf::Packet 					packet;
		sf::SocketSelector 			selector;
		
		std::vector<Player*>		m_players;

		unsigned short				port;
		sf::IpAddress				Ip;

		int 						width;
		int 						height;
		float						speed;

		State						state = State::waitRoom;
};