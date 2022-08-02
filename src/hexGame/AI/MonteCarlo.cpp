
#include "MonteCarlo.hpp"
#include "gameUtils.hpp"
#include <cstdlib>
#include <ctime>

MonteCarlo::MonteCarlo(Color color, Board *board)
    : AI::AI(color), m_explore_board(board) {
}

MonteCarlo::MonteCarlo(Color color) : MonteCarlo(color, nullptr) {
}

MonteCarlo::~MonteCarlo() {
    delete m_explore_board;
}

Move MonteCarlo::makeMove(Board *current_board) {
    std::srand((int)std::time(nullptr));

    // On choisie le nombre de partie a jouer
    int nbGameOfExploration = 100;
    int board_size = (*current_board).size();
    Color colorWinner;
    int nbWin;
    int maxNbWin = -1;
    Move move_play;
    Move move_save;
    move_play.color = m_color;
    move_save.color = m_color;
    AdjacentList<Tile> adjList_save(board_size * board_size);
    AdjacentList<Tile> adjList_play(board_size * board_size);
    Tile *current_tile;

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
        nbWin = 0;

        // On explore les parties
        for (int k = 0; k < nbGameOfExploration; ++k) {
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

        // On sauvgarde le coup si c'est le meilleur trouve actuellement
        if (nbWin > maxNbWin) {
            maxNbWin = nbWin;
            move_save.i = move_play.i;
            move_save.j = move_play.j;
        }
    }

    return move_save;
}

Color MonteCarlo::playUntilEnd(AdjacentList<Tile> &adjList) {
    Color color = m_color;
    int size = (*m_explore_board).size();

    while ((*m_explore_board).getNbOccupiedTiles() != size * size) {
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

void MonteCarlo::simulateMove(Color color, AdjacentList<Tile> &adjList) {
    size_t size;
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

void MonteCarlo::ResetExploreBoard(Board *current_board) {
    Color c;
    int size_board = (*m_explore_board).size();
    for (int i = 0; i < size_board; ++i) {
        for (int j = 0; j < size_board; ++j) {
            c = (*(*current_board).getTile(i, j)).getColor();
            (*(*m_explore_board).getTile(i, j)).setColor(c);
            (*(*m_explore_board).getTile(i, j)).setIsChecked(false);
        }
    }
    (*m_explore_board)
        .setNbOccupiedTiles((*current_board).getNbOccupiedTiles());
}

void MonteCarlo::initPlayer(Board *board) {
    m_explore_board = new Board(board);
}
