
#include "Printer.hpp"
#include <cmath>
#include <iostream>


Printer::Printer(int board_size) : m_board_size(board_size) {
    setVirtualTerminal();
    setAlternateBuffer();

}

Printer::~Printer() {
    quitAlternateBuffer();
}

bool Printer::setVirtualTerminal() {
    // Set output mode to handle virtual terminal sequences
    m_hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (m_hOut == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(m_hOut, &dwMode))
    {
        return false;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(m_hOut, dwMode))
    {
        return false;
    }
    return true;
}

void Printer::setAlternateBuffer() {
    // Enter the alternate buffer
    std::cout << CSI "?1049h";
    // Set the cursor at 1,1 (top left corner)
    std::cout << CSI "1;1H";
    // Clear screen
    std::cout << CSI "2J";
    // Clear all tab stops
    std::cout << CSI "3g";
}

void Printer::quitAlternateBuffer() {
    // Exit the alternate buffer
    std::cout << CSI "?1049l";
}

void Printer::initDisplay() {
    std::cout << CSI "1;1H";
    initNumTurn();
    initPlayer();
    initBoard();
    initGetTile();
}

void Printer::initNumTurn() {
    std::cout << std::endl << "Turn : ";
    m_numTurnSaver.setLineColumn(getCoord());
    std::cout << m_numTurnSaver.getNumTurn() << std::endl;

}

void Printer::initPlayer() {
    std::cout << std::endl << "Player : ";
    m_playerSaver.setLineColumn(getCoord());
    std::cout << m_playerSaver.convertColorToString() << std::endl;
}

void Printer::initBoard() {
    m_boardSaver.reserve(m_board_size*m_board_size);
    for(int i=0; i<m_board_size*m_board_size; ++i)
        m_boardSaver.push_back(TileSaver());
    
    // On affiche les indicateurs de colonnes
    std:: cout << std::endl << "  ";
    int A_hex = 65;
    for (int i=A_hex; i<A_hex+m_board_size; ++i)
        std::cout << " " << char(i);
    
    std::cout << std::endl;

    // On affiche le plateau
    // On affiche la première ligne
    std::cout << "  ";
    for (int j=0; j<m_board_size; ++j) {   
        std::cout << ESC"(0" << (j==0 ? "l": "w") << ESC"(B";
        std::cout << ESC"(0" << "q" << ESC"(B";
    }
    std::cout << ESC"(0" << "k" << ESC"(B" << std::endl;

    // On affiche toutes les autres lignes
    for (int i=0; i<m_board_size; ++i) {
        bool is_last = i == m_board_size-1;

        // On affiche le numero de la ligne
        if ((i+1) < 10)
            std::cout << " ";
        std::cout << (i+1);
        // On affiche les espaces pour le décalage entre chaque ligne
        for (int k=i; k>0; --k)
            std::cout << " ";
        // On affiche la ligne du milieu de la ligne i
        for (int j=0; j<m_board_size; ++j) {
            std::cout << ESC"(0" << "x" << ESC"(B";
            m_boardSaver.at(i*m_board_size+j).setLineColumn(getCoord());
            std::cout << " ";
        }
        std::cout << ESC"(0" << "x" << ESC"(B" << std::endl;

        // On affiche la ligne entre la case i et i+1
        // On affiche les espaces pour le décalage entre chaque ligne
        std::cout << "  ";
        for (int k=i; k>0; --k)
            std::cout << " ";
        
        for (int j=0; j<m_board_size; ++j) {
            if (j == 0)
                std::cout << ESC"(0" << "m" << ESC"(B";
            else
                std::cout << ESC"(0" << "v" << ESC"(B";
            std::cout << ESC"(0" << (is_last? "q": "w") << ESC"(B";
        }
        if (is_last)
            std::cout << ESC"(0" << "j" << ESC"(B" << std::endl;
        else
            std::cout << ESC"(0" << "v" << "k" << ESC"(B" << std::endl;
    }
}

void Printer::initGetTile() {
    std::cout << std::endl;
    m_getTileSaver.setLineColumn(getCoord());
}


COORD Printer::getCoord() {
    GetConsoleScreenBufferInfo(m_hOut, &m_screenBufferInfo);
    return m_screenBufferInfo.dwCursorPosition;
}

void Printer::displayMove(Move move) {
    TileSaver* tile = &(m_boardSaver.at(move.i*m_board_size+move.j));
    tile->setColor(move.color);
    tile->updateTerminal();
}

void Printer::addMove(Move move) {
    try {
        m_board.at(move.i*m_board_size + move.j) = move.color;
    } catch (const std::out_of_range &) {}
}

std::string Printer::displayTile(Color color) {
    switch (color) {
    case Color::White:
        return "B";
        break;

    case Color::Black:
        return "N";
        break;

    default:
        return " ";
        break;
    }
}

void Printer::displayBoard() {
    // On recupere la taille du plateau
    int boardSize = m_board_size;
    // On calcul sur combien de caractere est la taille
    int roughSize = (int)log10(boardSize);

    // On affiche les numeros des colones
    for (int current10Power = roughSize; current10Power >= 0;
         --current10Power) {
        // On affiche les espaces en plus pour l'affichage des lignes
        std::cout << " ";
        for (int i = roughSize; i >= 0; --i)
            std::cout << " ";
        // On affiche les chiffres de la puissance de 10 courantes.
        for (int i = 1; i <= boardSize; ++i) {
            char c;
            if (i < pow(10, current10Power)) {
                c = ' ';
            } else {
                // 48 : letter '0' in ascii table
                c = 48 + i / (int)pow(10, current10Power) % 10;
            }
            std::cout << " " << c << " ";
        }
        std::cout << std::endl;
    }

    std::string space = "";

    for (int i = 0; i < boardSize; ++i) {
        // On affiche les numeros des lignes
        int nbSpace = (int)log10(boardSize) - (int)log10(i + 1);
        for (int spaceCounter = 0; spaceCounter < nbSpace; ++spaceCounter)
            std::cout << " ";
        std::cout << (i + 1);

        space.append(" ");
        std::cout << space;
        for (int j = 0; j < boardSize; ++j) {
            std::cout << "[" << displayTile(m_board.at(i*boardSize+j)) << "]";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Printer::displayTurnInfo(int numTurn, Color color) {
    m_numTurnSaver.setNumTurn(numTurn);
    m_playerSaver.setColor(color);
    m_numTurnSaver.updateTerminal();
    m_playerSaver.updateTerminal();
}

void Printer::displayLastMove(Move move) {
    std::cout << "player's move : ";
    std::cout << "(" << move.i + 1 << "," << move.j + 1 << ")" << std::endl;
}

void Printer::displayWinner(Color color) {
    std::string winner;
    if (color == Color::White)
        winner = "White";
    else
        winner = "Black";
    std::cout << "Winner : " << winner << std::endl;
}

int Printer::convertCharToInt(char line) {
    return (int)(line)-97;
}


Move Printer::getPlayerMove() {
    Move move;
    std::string output;
    output = m_getTileSaver.getString();

    m_getTileSaver.deleteLine();

    move.j = convertCharToInt(output.c_str()[0]);
    move.i = std::stoi(&(output.c_str()[1]))-1;

    return move;
}
