#include <iostream>
#include <string>
#include "graphic.h"
//#include "graphic.cpp"


// https://www.sfml-dev.org/index.php
/*
void window() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }

}
*/

int main() {
	// Init Game
	Game game;

	// Game loop
	while(game.running()) {
		game.update();
		game.render();
	}

	return 0;
}
