
#include "Printer.hpp"
#include <cmath>
#include <iostream>


Printer::Printer(int board_size) : m_board_size(board_size) {
    m_board.reserve(board_size*board_size);
    std::vector<Color>::iterator it;
    for(int i=0; i<m_board_size*m_board_size; ++i)
        m_board.push_back(Color::Undefined);
}

Printer::~Printer() {}

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
    std::cout << "Turn number " << numTurn << ", ";
    if (color == Color::White) {
        std::cout << "White";
    } else {
        std::cout << "Black";
    }
    std::cout << " turn" << std::endl;
}

void Printer::displayMove(Move move) {
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

Move Printer::getPlayerMove() {
    Move move;
    std::cout << "line number : ";
    std::cin >> move.i;

    std::cout << "colonne number : ";
    std::cin >> move.j;

    move.i -= 1;
    move.j -= 1;
    
    return move;
}
