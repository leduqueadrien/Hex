
#include "ConsoleUI.hpp"
#include <AI/MonteCarlo.hpp>
#include <AI/RandomAI.hpp>
#include <hexGame/Game.hpp>
#include <hexGame/Human.hpp>
#include <iostream>
#include <string>

int main(int, char const **) {
    std::cout << "Starting Game" << std::endl;

    GameUI *gameUI = new ConsoleUI();
    Player *player1 = new MonteCarlo(Color::White);
    Player *player2 = new MonteCarlo(Color::Black);
    // Player *player2 = new Human(Color::Black, gameUI);
    int board_size = 7;

    Game *game = new Game(gameUI, player1, player2, board_size);

    (*game).initGame();
    (*game).launchGame();

    std::cout << "End Game" << std::endl;

    delete game;
    delete gameUI;

    return 0;
}
