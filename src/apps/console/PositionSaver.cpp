
#include "PositionSaver.hpp"


PositionSaver::PositionSaver(int line, int column) : m_line(line), m_column(column) {}
PositionSaver::PositionSaver(): PositionSaver(1, 1) {}

int PositionSaver::getLine() const {
    return m_line;
}

void PositionSaver::setLine(int line) {
    m_line = line;
}

int PositionSaver::getColumn() const {
    return m_column;
}

void PositionSaver::setColumn(int column) {
    m_column = column;
}

TileSaver::TileSaver(int line, int column) : PositionSaver::PositionSaver(line, column), m_color(Color::Undefined) {}
TileSaver::TileSaver() : TileSaver(1, 1) {}

Color TileSaver::getColor() const {
    return m_color;
}

void TileSaver::setColor(Color color) {
    m_color = color;
}

std::string TileSaver::convertColorToString() {
    if (m_color == Color::White) {
        return "B";
    } else if (m_color == Color::Black) {
        return "N";
    } else {
        return " ";
    }
}
