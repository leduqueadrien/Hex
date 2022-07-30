
#pragma once

#include <Mediator.hpp>
#include <Message.hpp>
#include <memory>
#include <Parameters.hpp>

#include "GameUI.hpp"
#include "Menu.hpp"
#include "Cursor.hpp"

class UI {
private:
    std::shared_ptr<Mediator> m_mediator;
    std::shared_ptr<GameUI> m_gameUI;
    std::shared_ptr<Cursor> m_cursor;
    Parameters m_parameters;
    
public:
    UI();
    ~UI() = default;
    void main();
    void mainMenu();
    void mainGame();
    void navigate(std::shared_ptr<Menu> current_menu);
    void gameProcessing();
    void waitingUntil(MESSAGE message);
    bool gameRunner();
    void display();
};
