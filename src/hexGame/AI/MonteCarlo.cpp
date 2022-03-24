
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
	int nbGameOfExploration = 100;
	int board_size = (*current_board).getSize();
	Color colorWinner;
	int nbWin;
	int maxNbWin = -1;
	Move move_play;
	Move move_save;
	move_play.color = m_color;
	move_save.color = m_color;
	AdjacentList adjList_save(board_size*board_size);
	AdjacentList adjList_play(board_size*board_size);
	Tile* current_tile;


	// On remet le plateau d'exploration a zeros
	ResetExploreBoard(current_board);

	// On sauvegarde les tiles qui n'ont pas ete jouees
	adjList_save.fillWithBoard(m_explore_board);

	for (int i=0; i<adjList_save.size(); ++i) {
		// On recupere la tile qui va etre jouer
		current_tile = adjList_save[i];

		// On enleve la tile de celle qui peuvent etre jouees
		move_play.i = (*current_tile).getI();
		move_play.j = (*current_tile).getJ();
		nbWin = 0;

		// On explore les parties
		for (int k=0; k<nbGameOfExploration; ++k) {
			// On joue le coup
			(*m_explore_board).addMoveToBoard(move_play);

			// On simule une partie
			adjList_play = adjList_save;
			adjList_play.remove(i);
			colorWinner = playUntilEnd(adjList_play);

			if (colorWinner == m_color)
				++nbWin;

			// On remet le plateau d'exploration a zeros
			ResetExploreBoard(current_board);
		}
		// std::cout << "i=" << move_play.i << " j=" << move_play.j << " => " << nbWin << std::endl;

		// On sauvgarde le coup si c'est le meilleur trouve actuellement
		if (nbWin > maxNbWin) {
			maxNbWin = nbWin;
			move_save.i = move_play.i;
			move_save.j = move_play.j;
		}
	}

	return move_save;
}

Color MonteCarlo::playUntilEnd(AdjacentList& adjList) {
	Color color = m_color;
	int size = (*m_explore_board).getSize();

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
