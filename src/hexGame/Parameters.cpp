
#include "Parameters.hpp"
#include <algorithm>


// ############################################################################
// ########################## Parameter #######################################
// ############################################################################
Parameter::Parameter(const std::string &name) : m_name(name) {
}

std::string Parameter::getName() const {
    return m_name;
}

void Parameter::setName(const std::string &name) {
    m_name = name;
}


// ############################################################################
// ########################## ParameterBoardSize ##############################
// ############################################################################
    
ParameterBoardSize::ParameterBoardSize(const std::string &name, int boardSize)
    : Parameter(name), m_boardSize(boardSize) {
}

int ParameterBoardSize::getBoardSize() {
    return m_boardSize;
}

void ParameterBoardSize::setBoardSize(int boardSize) {
    m_boardSize = boardSize;
}

std::string ParameterBoardSize::to_string() {
    return "";
}


// ############################################################################
// ########################## ParameterPlayer #################################
// ############################################################################
ParameterPlayer::ParameterPlayer(const std::string &name, Color color,
                                 const std::string &playerType,
                                 int monteCarloNbGame)
    : Parameter(name), m_color(color), m_playerType(playerType),
      m_monteCarloNbGame(monteCarloNbGame) {
}

Color ParameterPlayer::getColor() {
    return m_color;
}

void ParameterPlayer::setColor(Color color) {
    m_color = color;
}

std::string ParameterPlayer::getPlayerType() {
    return m_playerType;
}

void ParameterPlayer::setPlayerType(const std::string &playerType) {
    m_playerType = playerType;
}

int ParameterPlayer::getMonteCarloNbGame() {
    return m_monteCarloNbGame;
}

void ParameterPlayer::setMonteCarloNbGame(int monteCarloNbGame) {
    m_monteCarloNbGame = monteCarloNbGame;
}

std::string ParameterPlayer::to_string() {
    return "";
}


// ############################################################################
// ########################## Parameters ######################################
// ############################################################################
Parameters::Parameters() {

    std::shared_ptr<ParameterBoardSize> paramBoardSize =
        std::make_shared<ParameterBoardSize>("BoardSize", 3);
    m_parameters.push_front(std::move(paramBoardSize));

    std::shared_ptr<ParameterPlayer> paramPlayerWhite =
        std::make_shared<ParameterPlayer>("PlayerWhite", Color::White, "Random",
                                          100);
    m_parameters.push_front(std::move(paramPlayerWhite));

    std::shared_ptr<ParameterPlayer> paramPlayerBlack =
        std::make_shared<ParameterPlayer>("PlayerBlack", Color::Black, "Random",
                                          100);
    m_parameters.push_front(std::move(paramPlayerBlack));
}

std::shared_ptr<Parameter> Parameters::getParameter(const std::string &name) {
    ComparaisonStringParameter compare(name);
    return *std::find_if(begin(), end(), compare);
}

Parameters::const_iterator Parameters::begin() {
    return m_parameters.begin();
}

Parameters::const_iterator Parameters::end() {
    return m_parameters.end();
}


// ############################################################################
// ########################## ComparaisonStringParameter ######################
// ############################################################################
ComparaisonStringParameter::ComparaisonStringParameter(const std::string &name) : m_name(name) {
}

bool ComparaisonStringParameter::operator()(const std::shared_ptr<Parameter> &param) {
    return m_name == param->getName();
}
