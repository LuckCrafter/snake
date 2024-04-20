#!/bin/sh

cd $(dirname $0)
#cd /home/jj/Projects/snake/src
g++ -c snake.cpp -o .snake.o -std=c++17 -ggdb -O0
g++ .snake.o graphic.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system -std=c++17 -ggdb
