
#pragma once

#include "HexGameLib_export.hpp"
#include "gameUtils.hpp"
#include <list>
#include <memory>
#include <stdexcept>
#include <string>

// ############################################################################
// ########################## Parameter #######################################
// ############################################################################
/**
 * @brief Based class for every parameter
 * It is a virtual pur class
 */
class Parameter {
private:
    /**
     * @brief Name of the parameter
     */
    std::string m_name;

public:
    /**
     * @brief Construct a new Parameter object
     * @param name Name of the parameter
     */
    Parameter(const std::string &name);

    /**
     * @brief Destroy the Parameter object
     */
    ~Parameter() = default;

    /**
     * @brief Get the Name object
     * @return Name of the parameter
     */
    std::string getName() const;

    /**
     * @brief Set the Name object
     * @param name New name of the parameter
     */
    void setName(const std::string &name);

    /**
     * @brief Contert the parameter to a string
     * It is a virtual method
     * @return String corresponding to the object
     */
    virtual std::string to_string() = 0;
};

// ############################################################################
// ########################## ParameterBoardSize ##############################
// ############################################################################
/**
 * @brief Class for the board size parameter
 * Inherit from Parameter class
 */
class ParameterBoardSize : public Parameter {
private:
    /**
     * @brief Board size
     */
    int m_boardSize;

public:
    /**
     * @brief Construct a new Parameter Board Size object
     * @param name Name of the parameter
     * @param boardSize Default value of the board size
     */
    ParameterBoardSize(const std::string &name, int boardSize);

    /**
     * @brief Get the Board Size object
     * @return Value of the board size
     */
    int getBoardSize();

    /**
     * @brief Set the Board Size object
     * @param boardSize New board size
     */
    void setBoardSize(int boardSize);

    /**
     * @brief Contert the parameter to a string
     * @return String corresponding to the object
     */
    std::string to_string() override;
};


// ############################################################################
// ########################## ParameterPlayer #################################
// ############################################################################
/**
 * @brief Class for the player parameters
 * Inherit from Parameter class
 */
class ParameterPlayer : public Parameter {
private:
    /**
     * @brief Color of the player
     */
    Color m_color;

    /**
     * @brief Player type
     * Can be a Human, Random, MonteCarlo or MonteCarloCrossGame
     */
    std::string m_playerType;

    /**
     * @brief Number of game played during the research of a move
     * Only for MonteCarlo and MonteCarloCrossGame AI
     */
    int m_monteCarloNbGame;

public:
    /**
     * @brief Construct a new Parameter Player object
     * @param name Name of the parameter
     * @param color Default color of the player
     * @param playerType Default type of player
     * @param monteCarloNbGame Default number of research game
     */
    ParameterPlayer(const std::string &name, Color color,
                    const std::string &playerType, int monteCarloNbGame);

    /**
     * @brief Get the Color object
     * @return Player's color
     */
    Color getColor();

    /**
     * @brief Set the Color object
     * @param color New player's color
     */
    void setColor(Color color);

    /**
     * @brief Get the Player Type object
     * @return Player type
     */
    std::string getPlayerType();

    /**
     * @brief Set the Player Type object
     * @param playerType New player type
     */
    void setPlayerType(const std::string &playerType);

    /**
     * @brief Get the Monte Carlo Nb Game object
     * @return Number of explored game
     */
    int getMonteCarloNbGame();

    /**
     * @brief Set the Monte Carlo Nb Game object
     * @param monteCarloNbGame New number of explored game
     */
    void setMonteCarloNbGame(int monteCarloNbGame);

    /**
     * @brief Contert the parameter to a string
     * @return String corresponding to the object
     */
    std::string to_string() override;
};


// ############################################################################
// ########################## Parameters ######################################
// ############################################################################
/**
 * @brief Class for contain all the parameters of the game
 */
class Parameters {
private:
/**
 * @brief Container for the parameters
 */
    std::list<std::shared_ptr<Parameter>> m_parameters;

public:
    /**
     * @brief Construct a new Parameters object
     */
    Parameters();

    /**
     * @brief Get the Parameter object
     * @param name Name of the parameter wanted
     * @return Parameter wanted if he existe
     */
    std::shared_ptr<Parameter> getParameter(const std::string &name);

    /**
     * @brief Iterator for the parameters
     */
    using const_iterator = std::list<std::shared_ptr<Parameter>>::iterator;

    /**
     * @brief begin the iteration on the container
     * @return iterator that began the iteration on the container
     */
    const_iterator begin();

    /**
     * @brief end the iteration on the container
     * @return iterator that ended the iteration on the container
     */
    const_iterator end();
};


// ############################################################################
// ########################## ComparaisonStringParameter ######################
// ############################################################################
/**
 * @brief Functor for compared a parameter with a string
 */
class ComparaisonStringParameter {
private:
    /**
     * @brief String to compare with a parameter
     */
    std::string m_name;

public:
    /**
     * @brief Construct a new Comparaison String Parameter object
     * @param name String to compare with a parameter
     */
    ComparaisonStringParameter(const std::string &name);

    /**
     * @brief Comparaison operator
     * @param param Parameter to compare to the string
     * @return Whether the string is equal to the name of the parameter
     */
    bool operator()(const std::shared_ptr<Parameter> &param);
};
