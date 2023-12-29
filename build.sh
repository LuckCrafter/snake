#!/bin/sh
cd /home/jj/Projects/snake
g++ -c main.cpp -o .main.o
g++ .main.o graphic.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
