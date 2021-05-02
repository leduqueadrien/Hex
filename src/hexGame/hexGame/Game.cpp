
#include <iostream>
#include <string>
#include "Game.hpp"

Game::Game(GameUI* gameUI, Player* player1, Player* player2, int boardSize):
	m_gameUI(gameUI),
	m_player1(player1),
	m_player2(player2),
	m_boardSize(boardSize)
{
	m_board = new Board(boardSize);
}

Game::~Game()
{
}


void Game::initGame()
{
}


void Game::launchGame()
{
	while(!isGameFinished()) {
		displayBoard();

	}
}


bool Game::isGameFinished() const
{
	return false;
}


void Game::displayBoard() const
{
	m_gameUI->displayBoard(m_board);
}
