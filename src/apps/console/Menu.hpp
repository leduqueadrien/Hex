
#pragma once

#include "Cursor.hpp"

#include <AI/MonteCarlo.hpp>
#include <Parameters.hpp>
#include <gameUtils.hpp>
#include <list>
#include <memory>
#include <string>

// ############################################################################
// ################################### MENU ###################################
// ############################################################################
/**
 * @brief Based class for a Menu
 * Virtual pur class
 */
class Menu {
protected:
    
    /**
     * @brief Cursor of the screen
     */
    std::shared_ptr<Cursor> m_cursor;
    
    /**
     * @brief Question of the menu
     */
    std::string m_question;
    
    /**
     * @brief List of possible answer
     */
    std::list<std::string> m_answers;

public:
    /**
     * @brief Construct a new Menu object
     * @param cursor Cursor of the screen
     */
    Menu(std::shared_ptr<Cursor> cursor);

    /**
     * @brief Make the action in function of the answer choose
     * Virtual method
     * @param choice Choice make by the user
     * @param param Parameters of the game
     * @param current_menu Current menu
     * @return Is the given answer valid
     */
    virtual bool action(int choice, Parameters &param,
                        std::shared_ptr<Menu> &current_menu) = 0;

    /**
     * @brief Display the menu
     */
    void display();

    /**
     * @brief Get the user answer
     * @return User answer
     */
    int select();

    /**
     * @brief Iterator for the answers
     */
    using const_iterator = std::list<std::string>::const_iterator;

    /**
     * @brief begin the iteration on the answer's container
     * @return iterator that began the iteration on the container
     */
    const_iterator begin() const;

    /**
     * @brief end the iteration on the container
     * @return iterator that ended the iteration on the container
     */
    const_iterator end() const;
};

// ############################################################################
// ################################# MENU HOME ################################
// ############################################################################
/**
 * @brief Class for the home menu
 * Inherit from Menu class
 */
class MenuHome : public Menu {
public:
    /**
     * @brief Construct a new Menu Home object
     * @param cursor Cursor of the screen
     */
    MenuHome(std::shared_ptr<Cursor> cursor);

    /**
     * @brief Make the action in function of the answer choose
     * @param choice Choice make by the user
     * @param param Parameters of the game
     * @param current_menu Current menu
     * @return Is the given answer valid
     */
    bool action(int choice, Parameters &param,
                std::shared_ptr<Menu> &current_menu) override;
};

// ############################################################################
// ################################ MENU BOARD ################################
// ############################################################################
/**
 * @brief Class for the board menu
 * Inherit from Menu class
 */
class MenuBoard : public Menu {
public:
    /**
     * @brief Construct a new Menu Board object
     * @param cursor Cursor of the screen
     */
    MenuBoard(std::shared_ptr<Cursor> cursor);
    
    /**
     * @brief Make the action in function of the answer choose
     * @param choice Choice make by the user
     * @param param Parameters of the game
     * @param current_menu Current menu
     * @return Is the given answer valid
     */
    bool action(int choice, Parameters &param,
                std::shared_ptr<Menu> &current_menu) override;
};

// ############################################################################
// ############################### MENU PLAYER ################################
// ############################################################################
/**
 * @brief Class for the player menu
 * Inherit from Menu class
 */
class MenuPlayer : public Menu {
private:
    /**
     * @brief Player color
     */
    Color m_player_color;

public:
    /**
     * @brief Construct a new Menu Player object
     * @param player_color Player color
     * @param cursor Cursor of the screen
     */
    MenuPlayer(Color player_color, std::shared_ptr<Cursor> cursor);

    /**
     * @brief Make the action in function of the answer choose
     * @param choice Choice make by the user
     * @param param Parameters of the game
     * @param current_menu Current menu
     * @return Is the given answer valid
     */
    bool action(int choice, Parameters &param,
                std::shared_ptr<Menu> &current_menu) override;
};


// ############################################################################
// ############################# MENU MONTECARLO ##############################
// ############################################################################
/**
 * @brief 
 * Inherit from Menu class
 */
class MenuMonteCarlo : public Menu {
private:
    /**
     * @brief Player color
     */
    Color m_player_color;

public:
    /**
     * @brief Construct a new Menu Monte Carlo object
     * @param player_color Player color
     * @param cursor Cursor of the screen
     */
    MenuMonteCarlo(Color player_color, std::shared_ptr<Cursor> cursor);
    
    /**
     * @brief Make the action in function of the answer choose
     * @param choice Choice make by the user
     * @param param Parameters of the game
     * @param current_menu Current menu
     * @return Is the given answer valid
     */
    bool action(int choice, Parameters &param,
                std::shared_ptr<Menu> &current_menu) override;
};
