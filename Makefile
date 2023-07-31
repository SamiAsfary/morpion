CC=g++
FLAGS=-Wall -Werror -g

all	:	morpion

morpion	:	main.o player.o game.o
		$(CC) main.o player.o game.o -o morpion

player.o	:	player.cpp player.hpp 
			$(CC) -c player.cpp $(FLAGS) -o player.o

game.o	:	game.cpp game.hpp player.hpp
		$(CC) -c game.cpp $(FLAGS) -o game.o

main.o	:	main.cpp game.hpp player.hpp
		$(CC) -c main.cpp $(FLAGS) -o main.o

clean	:
		rm -rf *.o

