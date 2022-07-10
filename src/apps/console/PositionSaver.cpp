
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

void PositionSaver::setLineColumn(COORD coord) {
    m_line = coord.Y+1;
    m_column = coord.X+1;
}


NumTurnSaver::NumTurnSaver(int line, int column) : PositionSaver::PositionSaver(line, column), m_numTurn(0) {}
NumTurnSaver::NumTurnSaver() : NumTurnSaver(1, 1) {}

int NumTurnSaver::getNumTurn() const {
    return m_numTurn;
}
void NumTurnSaver::setNumTurn(int numTurn) {
    m_numTurn = numTurn;
}

void NumTurnSaver::updateTerminal() {
    std::cout << SAVE << MOVE(m_line, m_column) << m_numTurn << LOAD;
}

PlayerSaver::PlayerSaver(int line, int column) : PositionSaver::PositionSaver(line, column), m_color(Color::White) {}
PlayerSaver::PlayerSaver() : PlayerSaver(1, 1) {}

Color PlayerSaver::getColor() const {
    return m_color;
}

void PlayerSaver::setColor(Color color) {
    m_color = color;
}

std::string PlayerSaver::convertColorToString() {
    if (m_color == Color::White) {
        return "White";
    } else if (m_color == Color::Black) {
        return "Black";
    } else {
        return "None ";
    }
}

void PlayerSaver::updateTerminal() {
    std::cout << SAVE << MOVE(m_line, m_column) << convertColorToString() << LOAD;
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

void TileSaver::updateTerminal() {
    std::cout << SAVE << MOVE(m_line, m_column) << convertColorToString() << LOAD;
}

void GetTileSaver::updateTerminal() {
    std::cout << SAVE << MOVE(m_line, m_column) << "Tile coordonate : " << LOAD;
}

std::string GetTileSaver::getString() {
    std::cout << SAVE << MOVE(m_line, m_column) << "Tile coordonate : ";
    std::string output;
    std::cin >> output;
    std::cout << LOAD;
    return output;
}

void GetTileSaver::deleteLine() {
    std::cout << CSI"30P";
}


