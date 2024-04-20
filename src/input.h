#include <thread>
#include <chrono>
//#include <SFML/System.hpp>
#include "graphic.h"

void selectinput() {
	auto startTime = std::chrono::steady_clock::now();
	int frameCount {0};
	while(true) {
		frameCount++;
		//move the snake
		move(moving);
		auto expectedTime = startTime + frameCount * std::chrono::microseconds(1000000);
		std::this_thread::sleep_until(expectedTime);
	}
}