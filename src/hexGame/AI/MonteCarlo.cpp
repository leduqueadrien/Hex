
#include "MonteCarlo.hpp"
#include "AI.hpp"
#include "hexgame/gameUtils.hpp"
#include "AdjacentList.hpp"
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
						++nbWin;
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
	int size = (*m_explore_board).getSize();
	AdjacentList adjList = AdjacentList(size*size);
	for (int i=0; i<size; ++i)
		for(int j=0; j<size; ++j) {
			Tile* t = (*m_explore_board).getTile(i, j);
			if ((*t).getColor() == Color::Undefined)
				adjList.push_back(t);
		}

	while ((*m_explore_board).getNbFreeTiles() != size*size)
	{
		if (color == Color::Black) {
			color = Color::White;
		} else {
			color = Color::Black;
		}
		simulateMove(color, adjList);
	}
	if ((*m_explore_board).hasPlayerWon(color)) {
		return color;
	} else {
		if (color == Color::Black)
			return Color::White;
		else
			return Color::Black;
	}
}


void MonteCarlo::simulateMove(Color color, AdjacentList& adjList) {
	int size;
	Move move;
	int index;
	move.color = color;
	
	// On choisit les coordonnees du coup
	size = adjList.size();
	index = std::rand() % size;
	move.i = (*adjList[index]).getI();
	move.j = (*adjList[index]).getJ();
	adjList.remove(index);

	// On joue le coup
	(*m_explore_board).addMoveToBoard(move);
}


void MonteCarlo::ResetExploreBoard(Board* current_board) {
	Color c;
	int size_board = (*m_explore_board).getSize();
	for (int i=0; i<size_board; ++i) {
		for (int j=0; j<size_board; ++j) {
			c = (*(*current_board).getTile(i, j)).getColor();
			(*(*m_explore_board).getTile(i, j)).setColor(c);
			(*(*m_explore_board).getTile(i, j)).setIsChecked(false);
		}
	}
	(*m_explore_board).setNbFreeTiles((*current_board).getNbFreeTiles());
}

void MonteCarlo::initPlayer(Board* board) {
	m_explore_board = new Board(board);
}
