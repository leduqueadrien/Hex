
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
	int boardSize = (*board).getSize();
	std::string space = "";

	for (int i=0; i<boardSize; ++i) {
		space.append(" ");
		std::cout << space;
		for (int j=0; j<boardSize; ++j) {
			std::cout << "[" << displayTile((*board).getTile(i, j)) << "]";
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void ConsoleUI::displayTurnInfo(int numTurn, Color color) {
	std::cout << "Turn number " << numTurn << ", ";
	if (color == Color::White) {
		std::cout << "White";
	} else {
		std::cout << "Black";
	}
	std::cout << " turn" << std::endl;
}


void ConsoleUI::displayMove(Move move) {
	std::cout << "player's move : ";
	std::cout <<  "(" << move.i+1 << "," << move.j+1 << ")" << std::endl;
}


void ConsoleUI::getPlayerMove(Move& move)
{
	
	std::cout << "line number : ";
	std::cin >> move.i;

	std::cout << "colonne number : ";
	std::cin >> move.j;
}