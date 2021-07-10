
#include "MonteCarlo.hpp"
#include "AI.hpp"
#include "hexgame/gameUtils.hpp"
#include <stack>
#include <vector>
#include <ctime>
#include <iostream>
#include <string>


MonteCarlo::MonteCarlo(Color color, Game* game) :
	AI::AI(color, game),
	m_size((*(*m_game).getBoard()).getSize())
{
	for (int i=0; i<m_size; ++i) {
		std::vector<int> tmpBoard;
		std::vector<int> tmpExploreBoard;
		std::vector<int> tmpChecked;
		std::vector<int> tmpProba;
		for (int j=0; j<m_size; ++j) {
			tmpBoard.push_back(0);
			tmpExploreBoard.push_back(0);
			tmpChecked.push_back(0);
			tmpProba.push_back(0);
		}
		// Ajout des nouveaux vecteurs dans les vecteurs
		m_board.push_back(tmpBoard);
		m_exploreBoard.push_back(tmpBoard);
		m_isChecked.push_back(tmpChecked);
		m_proba.push_back(tmpProba);
    }

	// On initialise la graine
	std::srand((int)std::time(nullptr));
}

MonteCarlo::~MonteCarlo() {}

void printVector(std::vector<std::vector<int>>& vecteur)
{
	int boardSize = vecteur.size();
	std::string space = "";

	for (int i=0; i<boardSize; ++i) {
		space.append(" ");
		std::cout << space;
		for (int j=0; j<boardSize; ++j) {
			std::cout << " " << vecteur.at(i).at(j) << " ";
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;
}


Move MonteCarlo::makeMove() {

	// On choisie le nombre de partie a jouer
	int npGameOfExploration = 200;
	int colorWinner;
	int nbWin;
	int maxNbWin = -1;
	Move move;
	move.color = m_color;

	// On met a jour le board
	MajBoard();

	for (int i=0; i<m_size; ++i) {
		for (int j=0; j<m_size; ++j) {
			if (m_board.at(i).at(j) == 0) {
				nbWin = 0;
				for (int k=0; k<npGameOfExploration; ++k) {
					
					// On remet le plateau d'exploration a zeros
					restartSimulationGame();
					
					m_exploreBoard.at(i).at(j) = 1;

					// On joue jusqu'a la fin d'une partie
					colorWinner = playUntilEnd();
					
					nbWin += colorWinner == 1;			
				}
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

int MonteCarlo::playUntilEnd() {
	int color = 1;
	do {
		if (color == 1) {
			color = -1;
		} else {
			color = 1;
		}
		simulateMove(color);
	} while(!isPlayerWin(color));
	return color;
}

Move MonteCarlo::chooseMove() const {
	Move move;
	move.color = m_color;
	int max_proba = 0;
	int proba;
	
	for (int i=0; i<m_size; ++i) {
		for (int j=0; j<m_size; ++j) {
			if (m_board.at(i).at(j) == 0 ) {
				proba = m_proba.at(i).at(j);
				if (proba > max_proba) {
					max_proba = proba;
					move.i = i;
					move.j = j;
				}
			}
		}
	}

	return move;
}

void MonteCarlo::restartSimulationGame() {
	m_exploreBoard = m_board;
}

void MonteCarlo::simulateMove(int color) {
	int n = (*(*m_game).getBoard()).getSize();
	int i;
	int j;
	
	// On choisit les coordonnees du coup
	do {
		i = std::rand() % n;
		j = std::rand() % n;
	}while(!isMoveValid(i, j));

	// On joue le coup
	m_exploreBoard.at(i).at(j) = color;
}

void MonteCarlo::updateProba(int winnerColor) {
	if (winnerColor == -1)
		return;
	
	for (int i=0; i<m_size; ++i) {
		for (int j=0; j<m_size; ++j) {
			if (m_exploreBoard.at(i).at(j) == 1) {
				++m_proba.at(i).at(j);
			}
		}
	}

}

void MonteCarlo::restVectorOfVectorOfInt(std::vector<std::vector<int>>& vector) {
	for(int i=0; i<m_size; ++i) {
		for(int j=0; j<m_size; ++j) {
			vector.at(i).at(j) = 0;
		}
	}
}

bool MonteCarlo::isMoveValid(int i, int j) const {
	return m_exploreBoard.at(i).at(j) == 0;
}


bool MonteCarlo::isPlayerWin(int color) {
	std::stack<Point> stack;
	Point curPoint;
	Point p;
	// Couleur du joueur dont l'on test sa victoire
	Color playerColor = Color::White;
	if( (m_color == Color::Black && color == 1) ||
		(m_color == Color::White && color == -1) )
	{
		playerColor = Color::Black;
	}

	// On ajoute les premiere cases dans la pile
	for (int i=0; i<m_size; ++i) {
		if (playerColor == Color::White)
		{
			curPoint = constructPoint(0, i);
		} else {
			curPoint = constructPoint(i, 0);
		}
		if (m_exploreBoard.at(curPoint.i).at(curPoint.j) == color) {
			stack.push(curPoint);
			m_isChecked.at(curPoint.i).at(curPoint.j) = 1;
		}
	}

	// On parcour les cases de la couleur du joueur
	while (!stack.empty()) {
		curPoint = stack.top();
		stack.pop();
		// IterNeighbour it(m_board, (*currentTile).getI(), (*currentTile).getJ());

		for (int numNeighbour=1; numNeighbour<=6; ++numNeighbour) {
			// On test si la case appartient au joueur
			p = getNextNeighbour(curPoint.i, curPoint.j, numNeighbour);
			if (p.i >= 0 && p.i < m_size && p.j >= 0 && p.j < m_size) {
				if (m_exploreBoard.at(p.i).at(p.j) == color) {
					// On test si le joueur a atteint l'autre cote du board
					if ( (playerColor == Color::White  && p.i == m_size-1) || 
						 (playerColor == Color::Black &&  p.j == m_size-1) ) {
						return true;
					}
					if (!m_isChecked.at(p.i).at(p.j) == 1) {
						stack.push(p);
						m_isChecked.at(p.i).at(p.j) = 1;
					}
				}
			}

			
		}
	}

	restVectorOfVectorOfInt(m_isChecked);

	return false;
}

Point MonteCarlo::getNextNeighbour(int tile_i, int tile_j, int num_neighbour) {
		Point p;
		p.i = -1;
		p.j = -1;
		switch (num_neighbour) {
		case (1) :
			p.i = tile_i-1;
			p.j = tile_j;
		break;
		case (2) :
			p.i = tile_i-1;
			p.j = tile_j+1;
		break;
		case (3) :
			p.i = tile_i;
			p.j = tile_j+1;
		break;
		case (4) :
			p.i = tile_i+1;
			p.j = tile_j;
		break;
		case (5) :
			p.i = tile_i+1;
			p.j = tile_j-1;
		break;
		case (6) :
			p.i = tile_i;
			p.j = tile_j-1;
	}
	return p;
}

Point MonteCarlo::constructPoint(int i, int j) {
	Point p;
	p.i =i;
	p.j = j;
	return p;
}

void MonteCarlo::MajBoard() {
	Color color;
	int valeurBoard;
	for (int i=0; i<m_size; ++i) {
		for (int j=0; j<m_size; ++j) {
			color = (*(*(*m_game).getBoard()).getTile(i,j)).getColor();
			if (color == Color::Undefined) {
				valeurBoard = 0;
			} else if(color == m_color) {
				valeurBoard = 1;
			} else {
				valeurBoard = -1;
			}
			m_board.at(i).at(j) = valeurBoard;
		}
	}
}

