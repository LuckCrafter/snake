//#include <iostream>
//#include <thread>
//#include <chrono>
#include "graphic.h"
#include "thread.h"

void engine() {
    Game game;
    while(game.running()) {
        game.update();
        game.render();
    }
}

int main() {
    enum Move {up, down, left, right};
    // Starte einen neuen Thread für die zeitbasierte Schleife
    std::thread loopThread(loopedFunc, 10);
    //std::thread loopThread(timedLoop, duration);
    std::thread gameEngine(engine);
    gameEngine.join();
    return 0;
}
