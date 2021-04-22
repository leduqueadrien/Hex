
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