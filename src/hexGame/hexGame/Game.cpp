
#include <iostream>
#include <string>
#include <stack>
#include <iostream>
#include "Game.hpp"
#include "IterNeighbour.hpp"
#include "Board.hpp"
#include "gameUtils.hpp"
#include "Player.hpp"
#include "Human.hpp"
#include <AI/RandomAI.hpp>
#include <AI/MonteCarlo.hpp>

Game::Game(GameUI* gameUI, Player * player1, Player * player2, int boardSize):
	m_boardSize(boardSize),
	m_board(nullptr),
	m_gameUI(gameUI),
	m_player1(player1),
	m_player2(player2),
	m_numTurn(0),
	m_player_turn(nullptr)
{
	m_board = new Board(boardSize);

}

Game::~Game()
{
	delete m_board;
	delete m_player1;
	delete m_player2;

}


void Game::initGame()
{
	(*m_board).initBoard();
	(*m_player1).initPlayer(m_board);
	(*m_player2).initPlayer(m_board);
	
	m_numTurn = 0;

	// On definie le joueur qui ne commence pas : noire
	m_player_turn = m_player1;
	if ((*m_player2).getColor() == Color::Black) {
		m_player_turn = m_player2;
	}
}


void Game::launchGame()
{

	displayBoard();

	// boucle de jeu
	while(!(*m_board).hasPlayerWon((*m_player_turn).getColor())) {
		
		// On change le joueur qui a le trait
		changePlayerTurn();

		// On change le numero du tour
		incrementNumTurn();
		
		// On affiche les informations du tour
		(*m_gameUI).displayTurnInfo(m_numTurn, (*m_player_turn).getColor());

		// on recupere le move et on verifie qu'il soit correct
		Move move;
		do {
			move = (*m_player_turn).makeMove(m_board);
		} while (!(*m_board).isMoveValid(move));

		// On joue le coup
		(*m_board).addMoveToBoard(move);
		
		// On affiche le coup
		(*m_gameUI).displayMove(move);

		// On afiche le plateau
		displayBoard();

	}
}


bool Game::isGameFinished()
{
	return (*m_board).hasPlayerWon(Color::White) || (*m_board).hasPlayerWon(Color::Black);
}


void Game::displayBoard() const
{
	(*m_gameUI).displayBoard(m_board);
}


void Game::incrementNumTurn() {
	if ((*m_player_turn).getColor() == Color::White) {
		++m_numTurn;
	}
}


void Game::changePlayerTurn() {
	if ((*m_player1).getColor() == (*m_player_turn).getColor()) {
		m_player_turn = m_player2;
	} else {
		m_player_turn = m_player1;
	}
}


Board* Game::getBoard() const{
	return m_board;
}


int Game::getNumTurn() const{
	return m_numTurn;
}


Player* Game::getPlayerTurn() const{
	return m_player_turn;
}
