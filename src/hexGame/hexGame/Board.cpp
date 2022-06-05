
#include "Board.hpp"
#include "IterNeighbour.hpp"
#include <stack>
#include <stdexcept>

Board::Board(int size) : m_size(size), m_nbOccupiedTIles(0) {
    m_board.reserve(size*size);
    for (int i = 0; i < m_size*m_size; ++i) {
        m_board.push_back(new Tile(i/m_size, i%m_size));
    }
}

Board::Board(Board *board)
    : m_size((*board).getSize()), m_nbOccupiedTIles((*board).getNbOccupiedTiles()) {
    m_board.reserve(m_size*m_size);
    for (iterator it=board->begin(); it!=board->end(); ++it)
        m_board.push_back(new Tile(**it));
}

Board::~Board() { deleteBoard(); }

void Board::initBoard() {
    m_nbOccupiedTIles = 0;
    for (iterator it = begin(); it != end(); ++it)
        (*it)->initTile();
}

void Board::addMoveToBoard(Move move) {
    m_board.at(m_size*move.i + move.j)->setColor(move.color);
    ++m_nbOccupiedTIles;
}

bool Board::isMoveValid(Move move) const {
    Tile *ptile = getTile(move.i, move.j);
    return ptile != nullptr && (*ptile).getColor() == Color::Undefined;
}

bool Board::hasPlayerWon(Color color) {
    std::stack<Tile *> stack;
    Tile *currentTile;
    // On ajoute les premiere cases dans la pile
    for (int i = 0; i < m_size; ++i) {
        if (color == Color::White) {
            currentTile = getTile(0, i);
        } else {
            currentTile = getTile(i, 0);
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
        IterNeighbour it(this, (*currentTile).getI(), (*currentTile).getJ());

        for (it.begin(); *it != it.end(); ++it) {
            // On test si la case appartient au joueur

            if ((**it).getColor() == color) {
                // On test si le joueur a atteint l'autre cote du
                // board
                if ((color == Color::White && (**it).getI() == m_size - 1) ||
                    (color == Color::Black && (**it).getJ() == m_size - 1)) {
                    return true;
                }
                if (!(**it).getIsChecked()) {
                    stack.push(*it);
                    (**it).setIsChecked(true);
                }
            }
        }
    }

    resetCheckup();

    return false;
}

void Board::resetCheckup() {
    for (iterator it = begin(); it != end(); ++it)
        (*it)->setIsChecked(false);
}

void Board::deleteBoard() {
    for (iterator it = begin(); it != end(); ++it)
        delete *it;
}

Tile *Board::getTile(int i, int j) const {
    try {
        if (i >= 0 && i < m_size && j >= 0 && j < m_size)
            return m_board.at(m_size*i + j);
        else
            throw std::out_of_range("");
    } catch (std::out_of_range e) {
        return nullptr;
    }
}

int Board::getSize() const { return m_size; }

int Board::getNbOccupiedTiles() const { return m_nbOccupiedTIles; }

void Board::setNbOccupiedTiles(int nbFreeTiles) { m_nbOccupiedTIles = nbFreeTiles; }

Board &Board::operator=(const Board &board) {
    if (this != &board) {
        if (board.m_size != m_size) {
            m_size = board.m_size;
            deleteBoard();
            m_board.reserve(m_size*m_size);
            Tile* t;
            for (const_iterator it=board.begin(); it!=board.end(); it++) {
                t = *it;
                m_board.push_back(new Tile(t->getI(), t->getJ(), t->getColor(),
                                           t->getIsChecked()));
            }
        } else {
            for (const_iterator it=board.begin(); it!=board.end(); it++)
                *(getTile((**it).getI(), (**it).getJ())) = (**it);
        }
    }
    return *this;
}

Board::iterator Board::begin() {
    return m_board.begin();
}

Board::const_iterator Board::begin() const {
    return m_board.begin();
}

Board::iterator Board::end() {
    return m_board.end();
}

Board::const_iterator Board::end() const {
    return m_board.end();
}