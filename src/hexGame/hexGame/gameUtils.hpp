
#pragma once

/**
 * @brief give the possible color for a tile
 */
typedef enum Color {
	Undefined, White, Black
} Color;

/**
 * @brief move that a player had made
 */
typedef struct Move {
	/**
	 * @brief i line of the move
	 */
	int i;
	/**
	 * @brief j column of the move
	 */
	int j;
	/**
	 * @brief color of the player that had made the move
	 */
	Color color;

	/**
	 * @brief Constructor
	 * 
	 * @param _color color of the move
	 * @param _i line of the move
	 * @param _j column of the move
	 */
	Move(Color _color=Color::Undefined, int _i=-1, int _j=-1):
		i(_i),
		j(_j),
		color(_color)
	{}

} Move;

/**
 * @brief give the possible neighbour for a tile
 */
typedef enum Neighbour {
	NOT_INIT,
	TOP_LEFT,
	TOP_RIGHT,
	RIGHT,
	BOTTOM_RIGHT,
	BOTTOM_LEFT,
	LEFT,
	END
} Neighbour;

/**
 * @brief incremental operator for the neighbour enum
 * @param n current neighbour
 * @return Neighbour& next neighbour
 */
Neighbour & operator++(Neighbour& n);