
#include "IterNeighbour.hpp"

Neighbour &operator++(Neighbour &n) {
    n = static_cast<Neighbour>(static_cast<int>(n) + 1);
    return n;
}

IterNeighbour::IterNeighbour(Board *board, int i, int j)
    : m_i(i), m_j(j), m_numCurrentNeighbour(Neighbour::NOT_INIT),
      m_board(board) {
}

Tile *IterNeighbour::begin() {
    operator++();
    return operator*();
}

Tile *IterNeighbour::end() {
    return nullptr;
}

Tile *IterNeighbour::operator*() {
    switch (m_numCurrentNeighbour) {
    case (Neighbour::TOP_LEFT):
        return (*m_board).getTile(m_i - 1, m_j);
        break;
    case (Neighbour::TOP_RIGHT):
        return (*m_board).getTile(m_i - 1, m_j + 1);
        break;
    case (Neighbour::RIGHT):
        return (*m_board).getTile(m_i, m_j + 1);
        break;
    case (Neighbour::BOTTOM_RIGHT):
        return (*m_board).getTile(m_i + 1, m_j);
        break;
    case (Neighbour::BOTTOM_LEFT):
        return (*m_board).getTile(m_i + 1, m_j - 1);
        break;
    case (Neighbour::LEFT):
        return (*m_board).getTile(m_i, m_j - 1);
    default:
        return nullptr;
    }
}

Tile *IterNeighbour::operator++() {
    do {
        ++m_numCurrentNeighbour;
    } while (operator*() == nullptr && m_numCurrentNeighbour != END);
    return operator*();
}
