#pragma once

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>


class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	void initVar();
	void initWin(int w, int h);
public:
	// Constructures and Destrocters? KP was das iss
	Game();
	virtual ~Game();

	const bool running() const;

	void pollEvent();
	void update();
	void render();
};

#endif
