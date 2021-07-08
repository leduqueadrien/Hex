
#pragma once

#include "Board.hpp"
#include "GameUI.hpp"
#include "Player.hpp"
#include "HexGameLib_export.hpp"

// Convention : blanc : haut en bas
//				noire : gauche droite

// Without HEXGAMELIB_EXPORT, we get : error LNK2019 or : fatal error LNK1104
// https://docs.microsoft.com/fr-fr/cpp/error-messages/tool-errors/linker-tools-error-lnk2019?view=msvc-160
// https://docs.microsoft.com/fr-fr/cpp/error-messages/compiler-errors-1/fatal-error-c1083?view=msvc-160

/**
 * @brief class game
 */
class Game final
{
private:

	/**
	 * @brief size of the board game
	 */
	int m_boardSize;

	/**
	 * @brief board of the game
	 */
	Board* m_board = nullptr;

	/**
	 * @brief user interface use on the game
	 */
	GameUI* m_gameUI = nullptr;

	/**
	 * @brief player 1
	 */
	Player* m_player1 = nullptr;

	/**
	 * @brief player 2
	 */
	Player* m_player2 = nullptr;

	/**
	 * @brief the number of the current tunr
	 */
	int m_numTurn;

	/**
	 * @brief pointer on the player who had to play
	 */
	Player* m_player_turn = nullptr;

public:
	/**
	 * @brief constructor
	 * @param gameUI user interface use on the game
	 * @param player1 player 1
	 * @param player2 player 2
	 */
	HEXGAMELIB_EXPORT Game(GameUI* gameUI, Player * player1, Player * player2, int boardSize = 11);
	
	/**
	 * @brief destructor
	 */
	HEXGAMELIB_EXPORT ~Game();

	/**
	 * @brief Get the Board object
	 * @return Board * getter of the game's board
	 */
	HEXGAMELIB_EXPORT Board* getBoard() const;

	/**
	 * @brief Get the Num Turn object
	 * @return  int, number of the current turn
	 */
	HEXGAMELIB_EXPORT int getNumTurn() const;

	/**
	 * @brief Get the Player Turn object
	 * @return player who had to play 
	 */
	HEXGAMELIB_EXPORT Player* getPlayerTurn() const;

	/**
	 * @brief display the board through the user iterface
	 */
	HEXGAMELIB_EXPORT void displayBoard() const;

	/**
	 * @brief increment the turn number
	 */
	HEXGAMELIB_EXPORT void incrementNumTurn();

	/**
	 * @brief change the player who had to play
	 */
	HEXGAMELIB_EXPORT void changePlayerTurn();

	/**
	 * @brief initialize the game
	 */
	HEXGAMELIB_EXPORT void initGame();

	/**
	 * @brief launch the game
	 */
	HEXGAMELIB_EXPORT void launchGame();

	/**
	 * @brief is the game is finished
	 * @return bool 
	 */
	HEXGAMELIB_EXPORT bool isGameFinished();

	/**
	 * @brief is a player have win
	 * @param color color of the player we want to know
	 * @return bool 
	 */
	HEXGAMELIB_EXPORT bool hasPlayerWon(Color color);

	/**
	 * @brief convert a player's code to a player
	 * @param code player code
	 * @param color player color
	 * @return Player 
	 */
	HEXGAMELIB_EXPORT Player* ConvertCodeToPlayer(int code, Color color);
};
