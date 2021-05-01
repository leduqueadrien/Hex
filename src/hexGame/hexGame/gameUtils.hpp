
#pragma once

typedef enum Color {
	Undefined, White, Black
} Color;

typedef struct Move {
	int i;
	int j;
	Color color;

	Move(Color _color=Color::Undefined, int _i=-1, int _j=-1):
		i(_i),
		j(_j),
		color(_color)
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