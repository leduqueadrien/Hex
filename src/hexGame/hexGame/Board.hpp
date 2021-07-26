
#pragma once

#include "HexGameLib_export.hpp"

#include <vector>
#include "gameUtils.hpp"
#include "Tile.hpp"

/**
 * @brief Class board
 */
class Board final
{
private:
	/**
	 * @brief size of the board
	 */
	int m_size;

	/**
	 * @brief board of the game. Compose of Tile
	 */
	std::vector<std::vector<Tile*>> m_board;

public:
	/**
	 * @brief Constructor
	 * @param size size of the board
	 */
	HEXGAMELIB_EXPORT Board(int size);

	/**
	 * @brief Destructor of the board
	 */
	HEXGAMELIB_EXPORT ~Board();

	/**
	 * @brief initialize the board
	 * Set each tile of the board to undefined and to uncheck
	 * @return void
	 */
	HEXGAMELIB_EXPORT void initBoard();

	/**
	 * @brief add a move to th board
	 * a player had made a valid move. Add this move to the board i.e. change the color of a tile
	 * @param move the made move
	 * @return void
	 */
	HEXGAMELIB_EXPORT void addMoveToBoard(Move move);

	/**
	 * @brief check whether a move is valid
	 * Check if the move is in the board and if any player had made a move on this tile
	 * @param move the move to check
	 * @return bool
	 */
	HEXGAMELIB_EXPORT bool isMoveValid(Move move) const;

	/**
	 * @brief set all tile to unchecked
	 * @return void
	 */
	HEXGAMELIB_EXPORT void resetCheckup();

	/**
	 * @brief delete the board property
	 * 
	 * @return void
	 */
	HEXGAMELIB_EXPORT void deleteBoard();


	/**
	 * @brief Get a tile from the board
	 * @param i line of the wanted tile
	 * @param j column of the wanted tile
	 * @return Tile *
	 */
	HEXGAMELIB_EXPORT Tile* getTile(int i, int j) const;

	/**
	 * @brief Get the Size property
	 * 
	 * @return int size
	 */
	HEXGAMELIB_EXPORT int getSize() const;


	/**
	 * @brief affectation operator
	 * @param board target board
	 * @return board & 
	 */
	HEXGAMELIB_EXPORT Board& operator=(const Board& board);
};


/*
To Do :
Constructeur par copie
*/
