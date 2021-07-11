
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

	if (!(*m_player1).getIsHuman()) {
		(*static_cast<AI*>(m_player1)).setGame(this);
	}
	if (!(*m_player2).getIsHuman()) {
		(*static_cast<AI*>(m_player2)).setGame(this);
	}

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
}


void Game::launchGame()
{
	// On definie le joueur qui ne commence pas : noire
	m_numTurn = 0;
	m_player_turn = m_player1;
	if ((*m_player2).getColor() == Color::Black) {
		m_player_turn = m_player2;
	}
	displayBoard();

	// boucle de jeu
	while(!hasPlayerWon((*m_player_turn).getColor())) {
		
		// On change le joueur qui a le trait
		changePlayerTurn();

		// On change le numero du tour
		incrementNumTurn();
		
		// On affiche les informations du tour
		(*m_gameUI).displayTurnInfo(m_numTurn, (*m_player_turn).getColor());

		// on recupere le move et on verifie qu'il soit correct
		Move move;
		do {
			move = (*m_player_turn).makeMove();
		} while (!(*m_board).isMoveValid(move));

		// On joue le coup
		(*m_board).addMoveToBoard(move);
		
		// On affiche le coup
		(*m_gameUI).displayMove(move);

		// On afiche le plateau
		displayBoard();

	}
}


// const ?
bool Game::hasPlayerWon(Color color)
{
	std::stack<Tile *> stack;
	Tile * currentTile;
	// On ajoute les premiere cases dans la pile
	for (int i=0; i<m_boardSize; ++i) {
		if (color == Color::White) {
			currentTile = (*m_board).getTile(0, i);
		} else {
			currentTile = (*m_board).getTile(i, 0);
		}
		if ((*currentTile).getColor() == color) {
			stack.push(currentTile);
			(*currentTile).setIsChecked(true);
		}
	}
	// On parcour les cases de la couleur du joueur
	while (!stack.empty()) {
		currentTile = stack.top();
		stack.pop();
		IterNeighbour it(m_board, (*currentTile).getI(), (*currentTile).getJ());

		for (it.begin(); *it!=it.end(); ++it) {
			// On test si la case appartient au joueur
			
			if ((**it).getColor() == color) {
				// On test si le joueur a atteint l'autre cote du board
				if ( (color == Color::White && (**it).getI() == m_boardSize-1) || 
					 (color == Color::Black && (**it).getJ() == m_boardSize-1) ) {
					return true;
				}
				if (!(**it).getIsChecked()) {
					stack.push(*it);
					(**it).setIsChecked(true);
				}
			}
			
		}
	}

	(*m_board).resetCheckup();

	return false;
}


bool Game::isGameFinished()
{
	// code
	return false;
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


Player* Game::ConvertCodeToPlayer(int code, Color color) {
	if (code == 1) {
		return new Human(color, m_gameUI);
	} else if (code == 21) {
		return new RandomAI(color, this);
	} else if (code == 22) {
		return new MonteCarlo(color, this);
	}
	return nullptr;
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
