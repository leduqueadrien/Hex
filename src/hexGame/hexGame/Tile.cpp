
#include "Tile.hpp"

Tile::Tile() : Tile(-1, -1, Undefined, false) {
}

Tile::Tile(int i, int j) : Tile(i, j, Undefined, false) {
}

Tile::Tile(int i, int j, Color color, bool isChecked)
    : m_i(i), m_j(j), m_color(color), m_isChecked(isChecked) {
}

Tile::Tile(const Tile &tile)
    : Tile((tile).m_i, (tile).m_j, (tile).m_color, (tile).m_isChecked) {
}

int Tile::getI() const {
    return m_i;
}

int Tile::getJ() const {
    return m_j;
}

void Tile::setIndexes(int i, int j) {
    m_i = i;
    m_j = j;
}

Color Tile::getColor() const {
    return m_color;
}

void Tile::setColor(Color color) {
    m_color = color;
}

bool Tile::getIsChecked() const {
    return m_isChecked;
}

void Tile::setIsChecked(bool isChecked) {
    m_isChecked = isChecked;
}

void Tile::initTile() {
    m_color = Color::Undefined;
    m_isChecked = false;
}

Tile &Tile::operator=(const Tile &tile) {
    if (this != &tile) {
        m_i = tile.m_i;
        m_j = tile.m_j;
        m_color = tile.m_color;
        m_isChecked = tile.m_isChecked;
    }
    return *this;
}

bool operator==(const Tile &tile1, const Tile &tile2) {
    return tile1.getI() == tile2.getI() && tile1.getJ() == tile2.getJ() &&
           tile1.getColor() == tile2.getColor();
}

bool operator!=(const Tile &tile1, const Tile &tile2) {
    return !(tile1.getI() == tile2.getJ());
}
