#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <memory>

enum Move {up,down,left,right};
inline Move moving {right};

class Game
{
private:
	std::unique_ptr <sf::RenderWindow> window;
	sf::Event ev;
	sf::VideoMode videoMode;

//	void initVar();
//	void initWin(int w, int h);
public:
	// Constructures and Destrocters? KP was das iss
	Game();
//	virtual ~Game();

	const bool running() const;

	void waitEvent();
	void update();
	void render();
};

void move(Move moving);
#endif
