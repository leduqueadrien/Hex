
#pragma once

#include <Mediator.hpp>
#include <memory>
#include <Parameters.hpp>

#include "Printer.hpp"

class GameUI {
private:
    std::shared_ptr<Mediator> m_mediator;
    std::shared_ptr<Printer> m_gamePrinter;
    
public:
    GameUI();
    ~GameUI() = default;
    void main();
    Parameters menuHandler();
    void gameProcessing();
    void waitingUntil(MESSAGE message);
    bool gameRunner();
    void display();
};
