#include "graphic.h"

sf::RectangleShape player(sf::Vector2f(30.f, 30.f));

Game::Game() {
	player.setFillColor(sf::Color::Green);
	player.setPosition(5.f, 5.f);
	int h = 600;
	int w = 800;
	videoMode.height = h;
	videoMode.width = w;
	//window = new sf::RenderWindow(videoMode, "MyGame");
	window = std::make_unique<sf::RenderWindow> (videoMode, "My Game");
}
/*
Game::~Game() {
	delete window;
}
*/

const bool Game::running() const {
	return window->isOpen();
}

void move(Move moving) {
	switch(moving) {
	case 0:
	player.setPosition(sf::Vector2(player.getPosition().x, player.getPosition().y-40.f));
	if (player.getPosition().y < 0) player.setPosition(player.getPosition().x, player.getPosition().y+600.f);
	break;
	case 1:
	player.setPosition(sf::Vector2(player.getPosition().x, player.getPosition().y+40.f));
	if (player.getPosition().y >= 600) player.setPosition(player.getPosition().x, player.getPosition().y-600.f);
	break;
	case 2:
	player.setPosition(sf::Vector2(player.getPosition().x-40.f, player.getPosition().y));
	if (player.getPosition().x < 0) player.setPosition(player.getPosition().x+800.f, player.getPosition().y);
	break;
	case 3:
	player.setPosition(sf::Vector2(player.getPosition().x+40.f, player.getPosition().y));
	if (player.getPosition().x >= 800) player.setPosition(player.getPosition().x-800.f, player.getPosition().y);
	break;
	}
}



void Game::waitEvent() {
	while(window->waitEvent(ev)) {
		switch(ev.type) {
		case sf::Event::Closed:
		    window->close();
		    break;
		default:
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) moving = up;
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) moving = down;
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) moving = left;
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) moving = right;
		    break;
		}
	}
}



void Game::update() {
	waitEvent();
}

void Game::render() {

	window->clear(sf::Color(30,30,30,255));

	sf::RectangleShape shape(sf::Vector2f(40.f, 40.f));

	bool color = true;
	for (float i=0.f;i<600;i+=40.f) {
		for (float j=0.f;j<800;j+=40.f){
			if (color) shape.setFillColor(sf::Color(30,30,30,255));
			else shape.setFillColor(sf::Color(50,50,50,255));
			shape.setPosition(j,i);
			window->draw(shape);
			color = !color;
		}
		color = !color;
	}
	window->draw(player);
	window->display();
}

