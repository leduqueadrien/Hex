
#include <iostream>
#include "ConsoleUI.hpp"
#include "hexGame/GameUI.hpp"


ConsoleUI::ConsoleUI(/* args */)
{
}


ConsoleUI::~ConsoleUI()
{
}


std::string ConsoleUI::displayTile(Tile * tile)
{
	switch ((*tile).getColor())
	{
	case Color::White :
		return "B";
		break;

	case Color::Black :
		return "N";
		break;

	default:
		return " ";
		break;
	}
}


void ConsoleUI::displayBoard(Board* board)
{
	int boardSize = 11;
	std::string space = "";

	std::cout << std::endl;
	for (int i=0; i<=boardSize; ++i) {

		space.append(" ");
		std::cout << space;
		for (int j=0; j<=boardSize; ++j) {
			std::cout << "[]";
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void ConsoleUI::getPlayerMove(Move& move)
{
	//std::cin ... 
}