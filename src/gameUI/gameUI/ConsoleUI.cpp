
#include <iostream>
#include "ConsoleUI.hpp"


ConsoleUI::ConsoleUI(/* args */)
{
}


ConsoleUI::~ConsoleUI()
{
}


void ConsoleUI::displayBoard()
{
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


void ConsoleUI::getMove()
{
}