
#pragma once

#include <Mediator.hpp>
#include <memory>
#include <Parameters.hpp>

#include "GamePrinter.hpp"

class GameUI {
private:
    std::shared_ptr<Mediator> m_mediator;
    std::shared_ptr<GamePrinter> m_gamePrinter;
    
public:
    GameUI();
    ~GameUI() = default;
    void main();
    Parameters menuHandler();
    void gameProcessing();
    bool waitingUntil(MESSAGE);
    void display();
};
