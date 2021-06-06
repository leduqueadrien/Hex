
#include <iostream>
#include <string>
#include <stack>
#include "Game.hpp"
#include "IterNeighbour.hpp"
#include "Board.hpp"
#include "gameUtils.hpp"
#include "Player.hpp"
#include "iostream"

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
	delete m_board;
}


void Game::initGame()
{
	(*m_board).initBoard();
}


void Game::launchGame()
{
	// On definie le joueur qui ne commence pas : noire
	Player * playerHadMove = m_player1;
	if ((*m_player2).getColor() == Color::Black) {
		playerHadMove = m_player2;
	}
	displayBoard();

	// boucle de jeu
	while(!isGameFinished((*playerHadMove).getColor())) {
		
		// On change le joueur qui a le trait
		if ((*m_player1).getColor() == (*playerHadMove).getColor()) {
			playerHadMove = m_player2;
		} else {
			playerHadMove = m_player1;
		}

		// on recupere le move et on verifie qu'il soit correct
		std::cout << "debut move" << std::endl;
		Move move;
		do {
			move = (*playerHadMove).makeMove();
		} while (!(*m_board).isMoveValid(move));
		std::cout << "fin move" << std::endl;

		// On joue le coup
		(*m_board).addMoveToBoard(move);

		// On afiche le plateau
		displayBoard();

	}
}

// Pas sur que ce soit const
bool Game::isGameFinished(Color color) const
{
	std::cout << "debut fin " << std::endl;
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
		}
	}
	std::cout << "intermediaire " << std::endl;
	// On parcour les cases de la couleur du joueur
	while (!stack.empty()) {
		currentTile = stack.top();
		stack.pop();
		IterNeighbour it(m_board, (*currentTile).getI(), (*currentTile).getJ());
		for (it.begin(); *it!=it.end(); ++it) {
			// On test si la case appartient au joueur
			if ((**it).getColor() == color) {
				// On test si le joueur a atteint l'autre cote du board
				if ( (color == Color::White && (**it).getJ() == m_boardSize-1) || 
					(color == Color::Black && (**it).getI() == m_boardSize-1) ) {
					std::cout << "fin fin " << std::endl;
					return true;
				}
				if (!(**it).getIsChecked()) {
					stack.push(*it);
					(**it).setIsChecked(true);
				}
			}
			
		}
	}

	std::cout << "fin fin " << std::endl;

	return false;
}


void Game::displayBoard() const
{
	m_gameUI->displayBoard(m_board);
}
