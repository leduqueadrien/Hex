
#pragma once

typedef enum Color {
	Undefined, White, Black
} Color;

typedef struct Move {
	int i = -1;
	int j = -1;
	Color color = Undefined;
} Move;