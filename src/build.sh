#!/bin/sh
cd /home/jj/Projects/snake/src
g++ -c snake.cpp -o .snake.o
g++ .snake.o graphic.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
