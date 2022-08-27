
#include "MonteCarloCrossGame.hpp"
#include "gameUtils.hpp"
#include <cstdlib>
#include <ctime>

MonteCarloCrossGame::MonteCarloCrossGame(Color color, Board *board)
    : MonteCarlo::MonteCarlo(color, board) {
}

MonteCarloCrossGame::MonteCarloCrossGame(Color color) : MonteCarloCrossGame(color, nullptr) {
}

MonteCarloCrossGame::~MonteCarloCrossGame() {
    
}

Move MonteCarloCrossGame::makeMove(Board *current_board) {
    std::srand((int)std::time(nullptr));

    // On choisie le nombre de partie a jouer
    int nbGameOfExploration = 100;
    int board_size = (*current_board).size();
    Color colorWinner;
    int maxNbWin = -1;
    Move move_play;
    move_play.color = m_color;
    AdjacentList<Tile> adjList_save(board_size * board_size);
    AdjacentList<Tile> adjList_play(board_size * board_size);
    Tile *current_tile;

    // On remet le plateau de denombrement a zeros
    resetCountBoard();

    // On remet le plateau d'exploration a zeros
    ResetExploreBoard(current_board);

    // On sauvegarde les tiles qui n'ont pas ete jouees
    adjList_save.fillWithContainer(*m_explore_board, [](Tile *t) -> bool {
        return t->getColor() == Color::Undefined;
    });

    for (int i = 0; i < adjList_save.size(); ++i) {
        // On recupere la tile qui va etre jouer
        current_tile = adjList_save[i];

        // On enleve la tile de celle qui peuvent etre jouees
        move_play.i = (*current_tile).getI();
        move_play.j = (*current_tile).getJ();

        // On explore les parties
        for (int k = 0; k < nbGameOfExploration; ++k) {
            // On joue le coup
            (*m_explore_board).addMoveToBoard(move_play);

            // On simule une partie
            adjList_play = adjList_save;
            adjList_play.remove(i);
            colorWinner = playUntilEnd(adjList_play);

            // On met a jour le plateau de denombrement
            if(colorWinner == m_color)
                updateBoardCounter();

            // On remet le plateau d'exploration a zeros
            ResetExploreBoard(current_board);
        }

    }

    return chooseMove(current_board);
}


void MonteCarloCrossGame::initPlayer(Board *board) {
    m_explore_board = new Board(board);
    initGameCounter();
}

void MonteCarloCrossGame::initGameCounter() {
    int size = m_explore_board->size();
    m_boardCounter.reserve(size*size);
    for(int i=0; i<size*size; ++i)
        m_boardCounter.push_back(0);
}

void MonteCarloCrossGame::resetCountBoard() {
    std::vector<int>::iterator it;
    for(it=m_boardCounter.begin(); it!=m_boardCounter.end(); ++it)
        *(it) = 0;
}

void MonteCarloCrossGame::updateBoardCounter() {
    int size = m_explore_board->size();
    for(int i=0; i<size; ++i) {
        for(int j=0; j<size; ++j) {
            if(m_explore_board->getTile(i, j)->getColor() == m_color) {
                ++m_boardCounter.at(i*size+j);
            }
        }
    }
}

Move MonteCarloCrossGame::chooseMove(Board *current_board) {
    int max = -1;
    int nb;
    int size = m_explore_board->size();
    Move move;

    for(int i=0; i<size; ++i) {
        for(int j=0; j<size; ++j) {
            if(current_board->getTile(i, j)->getColor() == Color::Undefined) {
                nb = m_boardCounter.at(i*size+j);
                if(nb > max) {
                    max = nb;
                    move.i = i;
                    move.j = j;
                }
            }
        }
    }
    move.color = m_color;
    return move;
}
