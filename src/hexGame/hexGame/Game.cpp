
#include "Game.hpp"
#include "gameUtils.hpp"
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

Game::Game( std::shared_ptr<Player> playerWhite,  std::shared_ptr<Player> playerBlack, int boardSize, const std::shared_ptr<Mediator>& mediator)
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
    m_numTurn = 0;
    // On definie le joueur qui ne commence pas : noire
    m_player_turn = m_playerWhite;
}

void Game::launchGame() {

    // boucle de jeu
    while (!(*m_board).hasPlayerWon((*m_player_turn).getColor())) {

        // On change le joueur qui a le trait
        changePlayerTurn();

        // On change le numero du tour
        incrementNumTurn();

        // on recupere le move et on verifie qu'il soit correct
        Move move;
        do {
            move = (*m_player_turn).makeMove(m_board);
        } while (!(*m_board).isMoveValid(move));

        // On joue le coup
        (*m_board).addMoveToBoard(move);

    }
}

bool Game::nextTurn(Move move) {
    if (!(*m_board).isMoveValid(move)) {
        // Lunch exception
    } else {
        // On place le move
        m_last_move = move;
        (*m_board).addMoveToBoard(move);

        bool isHadPlayerWin = m_board->hasPlayerWon(m_player_turn->getColor());

        if (isHadPlayerWin) {
            m_mediator->sendMessageToUI(MESSAGE::END_GAME);
            return true;
        } else {
            // On change le joueur qui a le trait
            changePlayerTurn();

            // On change le numero du tour
            incrementNumTurn();
        }
    }
    return false;
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

void Game::WaitingInstruction() {
    MESSAGE current_message = MESSAGE::NONE;
    // m_mediator->sendMessageToUI(MESSAGE::SEND_PLAYER_TURN);
    // m_mediator->sendMessageToUI(MESSAGE::SEND_PLAYER_TURN);


    while (current_message != ACK_END_GAME){
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
        case MESSAGE::ASK_FOR_GAME_INIT:
            initGame();
            m_mediator->sendMessageToUI(MESSAGE::DONE_GAME_INIT);
            break;
        case MESSAGE::ASK_NEXT_TURN:
            nextTurn(m_player_turn->makeMove(m_board));
            m_mediator->sendMessageToUI(MESSAGE::DONE_NEXT_TURN);
            break;
        case MESSAGE::ASK_FOR_LAST_MOVE:
            m_mediator->setLastMove(m_last_move);
            m_mediator->sendMessageToUI(MESSAGE::SEND_LAST_MOVE);
            break;
        
        default:
            break;
        }
        Sleep(10);
    }
    
}
