
#include "gameUtils.hpp"

#include "Game.hpp"
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

Game::Game(std::shared_ptr<Player> playerWhite, std::shared_ptr<Player> playerBlack, int boardSize, Mediator* mediator)
    : m_boardSize(boardSize), m_board(nullptr),
      m_playerWhite(playerWhite), m_playerBlack(playerBlack), m_numTurn(0),
      m_player_turn(nullptr), m_last_move(), m_mediator(mediator) {
    m_board = new Board(boardSize);
}

Game::~Game() {
    delete m_board;
}

void Game::initGame() {
    (*m_board).initBoard();
    (*m_playerWhite).initPlayer(m_board);
    (*m_playerBlack).initPlayer(m_board);
    m_numTurn = 1;
    // On definie le joueur qui commence : blanc
    m_player_turn = m_playerWhite;
}

void Game::gameRunner() {
    bool isGameFinished = false;
    Move move;

    initGame();

    // boucle de jeu
    while(!isGameFinished) {
    // while (!(*m_board).hasPlayerWon((*m_player_turn).getColor())) {

        // on recupere le move et on verifie qu'il soit correct
        do {
            move = (*m_player_turn).makeMove(m_board);
        } while (!(*m_board).isMoveValid(move));

        // On joue le coup
        (*m_board).addMoveToBoard(move);
        m_last_move = move;

        // On verifie si le joueur a gagne
        isGameFinished = m_board->hasPlayerWon(m_player_turn->getColor());


        if (!isGameFinished) {
            // On change le joueur qui a le trait
            changePlayerTurn();

            // On change le numero du tour
            incrementNumTurn();
        }
        m_mediator->sendMessageToUI(MESSAGE::TURN_MAKE);
        waitingUntil(MESSAGE::END_DISPLAY);
    }
    m_mediator->setWinnerPlayer(m_player_turn->getColor());
    m_mediator->sendMessageToUI(MESSAGE::END_GAME);
}

bool Game::isGameFinished() {
    return (*m_board).hasPlayerWon(Color::White) ||
           (*m_board).hasPlayerWon(Color::Black);
}

void Game::incrementNumTurn() {
    if ((*m_player_turn).getColor() == Color::White) {
        ++m_numTurn;
    }
}

void Game::changePlayerTurn() {
    if ((*m_playerWhite).getColor() == (*m_player_turn).getColor()) {
        m_player_turn = m_playerBlack;
    } else {
        m_player_turn = m_playerWhite;
    }
}

Board * Game::getBoard() const { return m_board; }

int Game::getNumTurn() const { return m_numTurn; }

 std::shared_ptr<Player> Game::getPlayerTurn() const { return m_player_turn; }

void Game::waitingUntil(MESSAGE message) {
    MESSAGE current_message = MESSAGE::NONE;

    while (current_message != message){
        current_message = m_mediator->getRemoveFirstMessageToGame();
        switch (current_message)
        {
        case MESSAGE::ASK_FOR_NUM_TURN:
            m_mediator->setNumTurn(m_numTurn);
            m_mediator->sendMessageToUI(MESSAGE::SEND_NUM_TURN);
            break;
        case MESSAGE::ASK_FOR_PLAYER_TURN:
            m_mediator->setPlayerTurn(m_player_turn->getColor());
            m_mediator->sendMessageToUI(MESSAGE::SEND_PLAYER_TURN);
            break;
        case MESSAGE::ASK_FOR_LAST_MOVE:
            m_mediator->setLastMove(m_last_move);
            m_mediator->sendMessageToUI(MESSAGE::SEND_LAST_MOVE);
            break;
        default:
            break;
        }
        #ifdef _WIN32
            Sleep(50);
        #else
            sleep(1);
        #endif
    }
    
}
