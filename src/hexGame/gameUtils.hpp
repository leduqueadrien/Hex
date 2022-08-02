
#pragma once

#include "HexGameLib_export.hpp"

/**
 * @brief enumerate the possible colors for a tile
 */
typedef enum Color { Undefined, White, Black } Color;

/**
 * @brief move that a player had made
 */
typedef struct Move {
    /**
     * @brief line of the move
     */
    int i;

    /**
     * @brief column of the move
     */
    int j;

    /**
     * @brief color of the move
     */
    Color color;

    /**
     * @brief Constructor
     * @param _color color of the move
     * @param _i line of the move
     * @param _j column of the move
     */
    Move(Color _color = Color::Undefined, int _i = -1, int _j = -1)
        : i(_i), j(_j), color(_color) {
    }

} Move;
