#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <list>
#include <cstdlib>

enum Move {up, down, left, right};

class Game {
private:
	std::list<sf::RectangleShape> player {sf::RectangleShape{sf::Vector2f(30.f, 30.f)}};
	sf::RectangleShape fruit {sf::Vector2f(20.f, 20.f)};
	std::unique_ptr <sf::RenderWindow> window;
	Move movement {right};
	void moveFruit();
public:
	Game(); // wird automatisch aufgerufen beim erzeugen (muss gleich heißen wie die structure
//	Game(int w, int h);
	const bool running() const;
	bool move();
	void update();
	void render();
};

Game::Game() {
    player.front().setFillColor(sf::Color::Green);
    player.front().setPosition(5.f, 5.f);
    fruit.setPosition(10.f, 10.f);
    moveFruit();
    fruit.setFillColor(sf::Color::Red);
    sf::VideoMode videoMode;
	videoMode.height = 600;
	videoMode.width = 800;
	window = std::make_unique<sf::RenderWindow> (videoMode, "My Game");
}
/*
Game::Game(int w, int h)  {
	player.setFillColor(sf::Color::Green);
	player.setPosition(5.f, 5.f);
	videoMode.height = h;
	videoMode.width = w;
	window = std::make_unique<sf::RenderWindow> (videoMode, "My Game");
}
*/
const bool Game::running() const {
	return window->isOpen();
}

void Game::moveFruit() {
	float x=std::rand()%800/40*40;
	float y=std::rand()%600/40*40;
	fruit.move(x,y);
	if (fruit.getPosition().x>=800) fruit.move(-800.f,0.f);
	if (fruit.getPosition().y>=600) fruit.move(0.f,-600.f);
}

bool Game::move() {
	auto head = player.front();
	switch(movement) {
	case 0:
	head.move(0.0f, -40.f);
	if (head.getPosition().y < 0) head.move(0.f, 600.f);
	break;
	case 1:
	head.move(0.f, 40.f);
	if (head.getPosition().y >= 600) head.move(0.f, -600.f);
	break;
	case 2:
	head.move(-40.f, 0.f);
	if (head.getPosition().x < 0) head.move(800.f, 0.f);
	break;
	case 3:
	head.move(40.f, 0.f);
	if (head.getPosition().x > 800) head.move(-800.f, 0.f);
	break;
	}
	for (auto& e : player) {
		if ( e.getPosition() == head.getPosition() ) return false;
	}

	player.push_front(head);
	if (fruit.getPosition().x == head.getPosition().x + 5.f && fruit.getPosition().y == head.getPosition().y + 5.f) {
		moveFruit();
	} else {
		player.pop_back();
	}
	return true;
}

void Game::render() {
	//(*window).clear(sf::Color(30,30,30,255));
	window->clear(sf::Color(30,30,30,255));
	sf::RectangleShape shape(sf::Vector2f(40.f,40.f));
	bool color {false};
	for (float i=0.f;i<600;i+=40.f) {
		for (float j=0.f;j<800;j+=40.f) {
			if (color) shape.setFillColor(sf::Color(30,30,30,255));
			else shape.setFillColor(sf::Color(50,50,50,255));
			shape.setPosition(j,i);
			window->draw(shape);
			color = !color;
		}
		color = !color;
	}
	for (auto& e : player) {
		window->draw(e);
	}
	window->draw(fruit);
	window->display();
}

void Game::update() {
	sf::Event ev;
	while(window->pollEvent(ev)) {
		switch(ev.type) {
		case sf::Event::Closed:
			window->close();
			break;
		default:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) movement = up;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) movement = down;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) movement = left;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) movement = right;
			break;
		}
	}
}

int main() {
	//run some code
	auto startTime = std::chrono::steady_clock::now();
	int frameCount {0};
	Game game;
	bool valid {true};
	while(game.running()&&valid) {
		frameCount++;
		game.render();
		game.update();
		if (0 == frameCount%50) valid=game.move();
		auto expectedTime = startTime + frameCount * std::chrono::microseconds(10000);
		std::this_thread::sleep_until(expectedTime);
	}
	return 0;
}
