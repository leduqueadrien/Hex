
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
class Parameter {
private:
    std::string m_name;

public:
    Parameter(const std::string &name);
    ~Parameter() = default;
    std::string getName() const;
    void setName(const std::string &name);
    virtual std::string to_string() = 0;
};

// ############################################################################
// ########################## ParameterBoardSize ##############################
// ############################################################################
class ParameterBoardSize : public Parameter {
private:
    int m_boardSize;

public:
    ParameterBoardSize(const std::string &name, int boardSize);
    int getBoardSize();
    void setBoardSize(int boardSize);
    std::string to_string() override;
};


// ############################################################################
// ########################## ParameterPlayer #################################
// ############################################################################
class ParameterPlayer : public Parameter {
private:
    Color m_color;
    std::string m_playerType;
    int m_monteCarloNbGame;

public:
    ParameterPlayer(const std::string &name, Color color,
                    const std::string &playerType, int monteCarloNbGame);
    Color getColor();
    void setColor(Color color);
    std::string getPlayerType();
    void setPlayerType(const std::string &playerType);
    int getMonteCarloNbGame();
    void setMonteCarloNbGame(int monteCarloNbGame);
    std::string to_string() override;
};


// ############################################################################
// ########################## Parameters ######################################
// ############################################################################
class Parameters {
private:
    std::list<std::shared_ptr<Parameter>> m_parameters;

public:
    Parameters();

    std::shared_ptr<Parameter> getParameter(const std::string &name);

    using const_iterator = std::list<std::shared_ptr<Parameter>>::iterator;

    const_iterator begin();
    const_iterator end();
};


// ############################################################################
// ########################## ComparaisonStringParameter ######################
// ############################################################################
class ComparaisonStringParameter {
private:
    std::string m_name;

public:
    ComparaisonStringParameter(const std::string &name);
    bool operator()(const std::shared_ptr<Parameter> &param);
};
