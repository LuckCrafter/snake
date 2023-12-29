#include "graphic.h"
	sf::RectangleShape player(sf::Vector2f(30.f, 30.f));

void Game::initVar() {
	this->window = nullptr;
}

void Game::initWin(int width , int height) {
	this->videoMode.height = height;
	this->videoMode.width = width;
	this->window = new sf::RenderWindow(this->videoMode, "My Game");
}

Game::Game() {
	player.setFillColor(sf::Color::Green);
	player.setPosition(5.f, 5.f);
	int h = 600;
	int w = 800;
	this->initVar();
	this->initWin(w, h);
}

Game::~Game() {
	delete this->window;
}


const bool Game::running() const {
	return this->window->isOpen();
}

void move(char movement) {
	switch(movement) {
	case 'U':
	player.setPosition(sf::Vector2(player.getPosition().x, player.getPosition().y-40.f));
	if (player.getPosition().y < 0) player.setPosition(player.getPosition().x, player.getPosition().y+600.f);
	break;
	case 'D':
	player.setPosition(sf::Vector2(player.getPosition().x, player.getPosition().y+40.f));
	if (player.getPosition().y >= 600) player.setPosition(player.getPosition().x, player.getPosition().y-600.f);
	break;
	case 'L':
	player.setPosition(sf::Vector2(player.getPosition().x-40.f, player.getPosition().y));
	if (player.getPosition().x < 0) player.setPosition(player.getPosition().x+800.f, player.getPosition().y);
	break;
	case 'R':
	player.setPosition(sf::Vector2(player.getPosition().x+40.f, player.getPosition().y));
	if (player.getPosition().x >= 800) player.setPosition(player.getPosition().x-800.f, player.getPosition().y);
	break;
	}
}



void Game::pollEvent() {
	while(this->window->pollEvent(this->ev)) {
		switch(this->ev.type) {
		case sf::Event::Closed:
		    this->window->close();
		    break;
		default:
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) this->window->close();
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) move('U');
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) move('D');
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) move('L');
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) move('R');
		    break;
		}
	}
}

void Game::update() {
	this->pollEvent();
}

void Game::render() {

	this->window->clear(sf::Color(30,30,30,255));

	sf::RectangleShape shape(sf::Vector2f(40.f, 40.f));

	bool color = true;
	for (float i=0.f;i<600;i+=40.f) {
		for (float j=0.f;j<800;j+=40.f){
			if (color) shape.setFillColor(sf::Color(30,30,30,255));
			else shape.setFillColor(sf::Color(50,50,50,255));
			shape.setPosition(j,i);
			this->window->draw(shape);
			color = !color;
		}
		color = !color;
	}
	this->window->draw(player);
	this->window->display();
}

