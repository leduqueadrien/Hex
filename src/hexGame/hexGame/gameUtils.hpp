
#pragma once

typedef enum Color {
	Undefined, White, Black
} Color;

typedef struct Move {
	int i;
	int j;
	Color color;
} Move;