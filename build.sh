#!/bin/sh
cd $(dirname $0)

mkdir -p build
g++ -c src/v2/main.cpp -o build/main.o
g++ build/main.o -o build/main -lsfml-graphics -lsfml-window -lsfml-system

