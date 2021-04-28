
#pragma once

typedef enum Color {
	Undefined, White, Black
} Color;

typedef struct Move {
	int i;
	int j;
	Color color;

	Move(Color color=Color::Undefined):
		i(-1),
		j(-1),
		color(color)
	{}

} Move;

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

Neighbour & operator++(Neighbour& n);