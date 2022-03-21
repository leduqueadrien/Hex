
#include "MonteCarlo.hpp"
#include "AI.hpp"
#include "hexgame/gameUtils.hpp"
#include <stack>
#include <vector>
#include <ctime>
#include <iostream>
#include <string>


MonteCarlo::MonteCarlo(Color color, Board* board) :
	AI::AI(color),
	m_explore_board(board)
{
	// On initialise la graine
	std::srand((int)std::time(nullptr));
}

MonteCarlo::MonteCarlo(Color color) : MonteCarlo(color, nullptr) {}

MonteCarlo::~MonteCarlo() {
	delete m_explore_board;
}


Move MonteCarlo::makeMove(Board* current_board) {

	// On choisie le nombre de partie a jouer
	int npGameOfExploration = 100;
	int board_size = (*current_board).getSize();
	Color colorWinner;
	int nbWin;
	int maxNbWin = -1;
	Move move;
	move.color = m_color;

	// On remet le plateau d'exploration a zeros
	ResetExploreBoard(current_board);

	for (int i=0; i<board_size; ++i) {
		for (int j=0; j<board_size; ++j) {
			if ((*(*m_explore_board).getTile(i, j)).getColor() == Color::Undefined) {
				nbWin = 0;
				// On remet le plateau d'exploration a zeros
				ResetExploreBoard(current_board);
				for (int k=0; k<npGameOfExploration; ++k) {
					
					// On joue le premier coup de l'IA
					(*m_explore_board).addMoveToBoard(Move(m_color, i, j));

					// On joue jusqu'a la fin d'une partie
					colorWinner = playUntilEnd();
					
					if (colorWinner == m_color) {
						nbWin += colorWinner == 1;
					}
					// On remet le plateau d'exploration a zeros
					ResetExploreBoard(current_board);

				}
				// On regarde si c'est le meilleur coup trouver pour le moment
				if (nbWin > maxNbWin) {
					maxNbWin = nbWin;
					move.i = i;
					move.j = j;
				}
			}
		}
	}
	return move;
}
Color MonteCarlo::playUntilEnd() {
	Color color = m_color;
	while(!(*m_explore_board).hasPlayerWon(color)) {
		if (color == Color::Black) {
			color = Color::White;
		} else {
			color = Color::Black;
		}
		simulateMove(color);
	}
	return color;
}


void MonteCarlo::simulateMove(Color color) {
	int board_size = (*m_explore_board).getSize();
	Move move;
	move.color = color;
	
	// On choisit les coordonnees du coup
	do {
		move.i = std::rand() % board_size;
		move.j = std::rand() % board_size;
	}while(!(*m_explore_board).isMoveValid(move));

	// On joue le coup
	(*m_explore_board).addMoveToBoard(move);
}


void MonteCarlo::ResetExploreBoard(Board* current_board) {
	*(m_explore_board) = *(current_board);
}

void MonteCarlo::initPlayer(Board* board) {
	m_explore_board = new Board(board);
}
