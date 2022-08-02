
#pragma once

#include "HexGameLib_export.hpp"
#include "gameUtils.hpp"
#include <list>
#include <memory>
#include <stdexcept>
#include <string>

class Parameter {
private:
    std::string m_name;

public:
    Parameter(const std::string &name) : m_name(name) {
    }
    ~Parameter() = default;
    std::string getName() const {
        return m_name;
    }
    void setName(const std::string &name) {
        m_name = name;
    }
    virtual std::string to_string() = 0;
};

class ParameterBoardSize : public Parameter {
private:
    int m_boardSize;

public:
    ParameterBoardSize(const std::string &name, int boardSize);
    int getBoardSize() {
        return m_boardSize;
    }
    void setBoardSize(int boardSize) {
        m_boardSize = boardSize;
    }
    std::string to_string() override {
        return "";
    }
};

class ParameterPlayer : public Parameter {
private:
    Color m_color;
    std::string m_playerType;
    int m_monteCarloNbGame;

public:
    ParameterPlayer(const std::string &name, Color color,
                    const std::string &playerType, int monteCarloNbGame);
    Color getColor() {
        return m_color;
    }
    void setColor(Color color) {
        m_color = color;
    }
    std::string getPlayerType() {
        return m_playerType;
    }
    void setPlayerType(const std::string &playerType) {
        m_playerType = playerType;
    }
    int getMonteCarloNbGame() {
        return m_monteCarloNbGame;
    }
    void setMonteCarloNbGame(int monteCarloNbGame) {
        m_monteCarloNbGame = monteCarloNbGame;
    }
    std::string to_string() override {
        return "";
    }
};

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

class ComparaisonStringParameter {
private:
    std::string m_name;

public:
    ComparaisonStringParameter(const std::string &name) : m_name(name) {
    }
    bool operator()(const std::shared_ptr<Parameter> &param) {
        return m_name == param->getName();
    }
};
