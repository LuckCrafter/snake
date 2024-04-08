#pragma once

#include <iostream>
#include <thread>
#include <chrono>

void loopedFunc(int secondsRunning) {
    auto startTime = std::chrono::steady_clock::now();
    auto stopTime = startTime + std::chrono::seconds(secondsRunning);
    while (std::chrono::steady_clock::now() < stopTime) {
        //code here
        std::cout << "Thread läuft seit "
                  << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - startTime).count()
                  << " Mikrosekunden."  << std::endl;
        //std::this_thread::sleep_for(std::chrono::microseconds(2300));
        //code have to end here

        auto diff = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - startTime).count()%1000000;
        std::this_thread::sleep_for(std::chrono::microseconds(1000000 - diff));
    }
}

/*
void timedLoop(int durationInSeconds) {
    auto startTime = std::chrono::steady_clock::now();
    auto endTime = startTime + std::chrono::seconds(durationInSeconds);
    auto start = std::chrono::high_resolution_clock::now();

    while (std::chrono::steady_clock::now() < endTime) {
        // Hier kannst du deine zeitbasierten Aufgaben ausführen
        // Zum Beispiel:
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Thread läuft seit "
                  << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - startTime).count()
                  << " Sekunden." << duration.count() << std::endl;

        // Warte eine gewisse Zeit, bevor du die Schleife erneut durchläufst
        auto wait = std::chrono::steady_clock::now();
        auto deltaWait = std::chrono::duration_cast<std::chrono::microseconds>(wait - startTime);
        std::this_thread::sleep_for(std::chrono::microseconds(duration.count())+std::chrono::seconds(1)-deltaWait);
    }
}
*/