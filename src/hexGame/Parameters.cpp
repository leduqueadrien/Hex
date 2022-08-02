
#include "Parameters.hpp"
#include <algorithm>

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

ParameterBoardSize::ParameterBoardSize(const std::string &name, int boardSize)
    : Parameter(name), m_boardSize(boardSize) {
}

ParameterPlayer::ParameterPlayer(const std::string &name, Color color,
                                 const std::string &playerType,
                                 int monteCarloNbGame)
    : Parameter(name), m_color(color), m_playerType(playerType),
      m_monteCarloNbGame(monteCarloNbGame) {
}
