game: GameCharacter.o game.o
	c++ GameCharacter.o game.o -o game

GameCharacter.o: GameCharacter.cpp
	c++ -c GameCharacter.cpp

game.o: game.cpp
	c++ -c game.cpp

clean:
	rm *.o game
