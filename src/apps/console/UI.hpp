
#pragma once

#include <Mediator.hpp>
#include <Message.hpp>
#include <Parameters.hpp>
#include <memory>

#include "Cursor.hpp"
#include "GameUI.hpp"
#include "Menu.hpp"

/**
 * @brief Class for the user interface
 */
class UI {
private:
    
    /**
     * @brief Mediator of the game
     */
    std::shared_ptr<Mediator> m_mediator;
    
    /**
     * @brief UI of the game
     */
    std::shared_ptr<GameUI> m_gameUI;
    
    /**
     * @brief Cursor of the screen
     */
    std::shared_ptr<Cursor> m_cursor;
    
    /**
     * @brief Parameters of the game
     */
    Parameters m_parameters;

public:
    
    /**
     * @brief Construct a new UI object
     */
    UI();
    
    /**
     * @brief Destroy the UI object
     */
    ~UI() = default;
    
    /**
     * @brief Entry point of the program
     */
    void main();
    
    /**
     * @brief Entry point for the menuing
     */
    void mainMenu();
    
    /**
     * @brief Entry point for the game
     */
    void mainGame();
    
    /**
     * @brief Navigate into menus
     * @param current_menu Current menu
     */
    void navigate(std::shared_ptr<Menu> current_menu);
    
    /**
     * @brief Wait until a Message can from the game
     * @param message Message to expect 
     */
    void waitingUntil(MESSAGE message);
    
    /**
     * @brief Runner of the game UI
     * @return Is the game finished ?
     */
    bool gameRunner();
    
    /**
     * @brief Display informations bewteen each turn
     */
    void display();
};
