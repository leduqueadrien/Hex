
#include <iostream>
#include <string>
#include "Game.hpp"

Game::Game(GameUI* gameUI, int boardSize):
	gameUI(gameUI),
	boardSize(boardSize)
{

}

Game::~Game()
{
}


void Game::displayBoard()
{
	gameUI->displayBoard(board);
}
