
#pragma once

#include "HexGameLib_export.hpp"

#include "Tile.hpp"
#include "gameUtils.hpp"
#include <vector>

/**
 * @brief Class board
 */
class Board final {
  private:
    /**
     * @brief size of the board
     */
    int m_size;

    /**
     * @brief board of the game. Composed of Tile
     */
    std::vector<Tile *> m_board;

    /**
     * @brief number of occupied tiles
     */
    int m_nbOccupiedTIles;

  public:
    /**
     * @brief Constructor
     * @param size size of the board
     */
    HEXGAMELIB_EXPORT Board(int size);

    /**
     * @brief Copy constructor
     * @param board board to copy
     */
    HEXGAMELIB_EXPORT Board(Board *board);

    /**
     * @brief Destructor of the board
     */
    HEXGAMELIB_EXPORT ~Board();

    /**
     * @brief initialize the board
     * Set each tile of the board to undefined and to uncheck.
     * @return void
     */
    HEXGAMELIB_EXPORT void initBoard();

    /**
     * @brief add a move to th board
     * Add a valid move to the board i.e. change the color of a tile.
     * @param move the valid move
     * @return void
     */
    HEXGAMELIB_EXPORT void addMoveToBoard(Move move);

    /**
     * @brief check whether a move is valid
     * Check if the move is in the board and if any player had made a move on
     * it.
     * @param move the move to check
     * @return bool
     */
    HEXGAMELIB_EXPORT bool isMoveValid(Move move) const;

    /**
     * @brief is a player have win
     * @param color color of the player we want to know
     * @return bool
     */
    HEXGAMELIB_EXPORT bool hasPlayerWon(Color color);

    /**
     * @brief set all tiles to unchecked
     * @return void
     */
    HEXGAMELIB_EXPORT void resetCheckup();

    /**
     * @brief delete the board property
     * @return void
     */
    HEXGAMELIB_EXPORT void deleteBoard();

    /**
     * @brief Get a tile from the board
     * @param i line of the wanted tile
     * @param j column of the wanted tile
     * @return Tile *
     */
    HEXGAMELIB_EXPORT Tile *getTile(int i, int j) const;

    /**
     * @brief Get the Size property
     *
     * @return int size
     */
    HEXGAMELIB_EXPORT int size() const;

    /**
     * @brief Get the Nb Free Tiles object
     *
     * @return int
     */
    int getNbOccupiedTiles() const;

    /**
     * @brief Set the Nb Free Tiles object
     *
     * @param nbFreeTiles
     */
    void setNbOccupiedTiles(int nbFreeTiles);

    /**
     * @brief affectation operator
     * @param board target board
     * @return board &
     */
    HEXGAMELIB_EXPORT Board &operator=(const Board &board);

    /**
     * @brief iterator through the board
     */
    using iterator = std::vector<Tile*>::iterator;
    
    /**
     * @brief constant iterator though the board
     */
    using const_iterator = std::vector<Tile*>::const_iterator;

    /**
     * @brief begin the iteration
     * @return begin iterator
     */
    HEXGAMELIB_EXPORT iterator begin();
    
    /**
     * @brief begin the constant iteration
     * @return begin constant iterator
     */
    HEXGAMELIB_EXPORT const_iterator begin() const;

    /**
     * @brief end the iterator
     * @return end iterator
     */
    HEXGAMELIB_EXPORT iterator end();
    
    /**
     * @brief end the constant iterator
     * @return end constant iterator
     */
    HEXGAMELIB_EXPORT const_iterator end() const;

};
