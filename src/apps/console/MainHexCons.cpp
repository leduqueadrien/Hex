
#include <iostream>
#include <string>
#include <game/Game.hpp>

void printBoard() {
	int boardSize = 11;
	std::string space = "";

	std::cout << std::endl;
	for (int i=0; i<=boardSize; i++) {

		space.append(" ");
		std::cout << space;
		for (int j=0; j<=boardSize; j++) {
			std::cout << "[]";
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main(int, char const **)
{
	std::cout << "Starting Game" << std::endl;
	printBoard();
	// Game game = new Game();
	return 0;
}
