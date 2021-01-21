
// Example program:
// Using SDL_Point in some places of your code

#include "SDL2/SDL.h"
#include <stdio.h>

#define POINTS_COUNT 4

static SDL_Point points[POINTS_COUNT] = {
	{320, 200},
	{300, 240},
	{340, 240},
	{320, 200}
};

static SDL_Point points2[5000];

static int cpt = 0;

void putpixel(int x0, int y0, int i) {
	(void)i;
	points2[cpt].x = x0;
	points2[cpt].y = y0;
	cpt++;
}

void DrawCircle(int x0, int y0, int radius)
{
	int x = 0, y = radius;
	int dp = 1 - radius;
	do
	{
		if (dp < 0)
			dp = dp + 2 * (++x) + 3;
		else
			dp = dp + 2 * (++x) - 2 * (--y) + 5;

		putpixel(x0 + x, y0 + y, 15); //For the 8 octants
		putpixel(x0 - x, y0 + y, 15);
		putpixel(x0 + x, y0 - y, 15);
		putpixel(x0 - x, y0 - y, 15);
		putpixel(x0 + y, y0 + x, 15);
		putpixel(x0 - y, y0 + x, 15);
		putpixel(x0 + y, y0 - x, 15);
		putpixel(x0 - y, y0 - x, 15);

	} while (x < y);
}


void MyDrawCircle(SDL_Renderer* renderer, int x0, int y0, int radius)
{
	int x = 0, y = radius;
	int dp = 1 - radius;
	do
	{
		if (dp < 0)
			dp = dp + 2 * (++x) + 3;
		else
			dp = dp + 2 * (++x) - 2 * (--y) + 5;

		SDL_RenderDrawPoint(renderer, x0 + x, y0 + y); //For the 8 octants
		SDL_RenderDrawPoint(renderer, x0 - x, y0 + y);
		SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);
		SDL_RenderDrawPoint(renderer, x0 - x, y0 - y);
		SDL_RenderDrawPoint(renderer, x0 + y, y0 + x);
		SDL_RenderDrawPoint(renderer, x0 - y, y0 + x);
		SDL_RenderDrawPoint(renderer, x0 + y, y0 - x);
		SDL_RenderDrawPoint(renderer, x0 - y, y0 - x);

	} while (x < y);
}

void drawCircles(SDL_Renderer * renderer)
{
	SDL_RenderDrawLine(renderer, 50, 250, 450, 250); //barre horizontale
	SDL_RenderDrawLine(renderer, 250, 50, 250, 450); //barre verticale
	for (int j=0; j<200; j++) {
		SDL_SetRenderDrawColor(renderer, 50*j%255, 30*j%255, 35*j%255, SDL_ALPHA_OPAQUE);
		MyDrawCircle(renderer, 250, 250, j);
	}
}

// "hexagon horizontal"
void drawHexagon(SDL_Renderer * renderer, int x0, int y0, int radius)
{
	SDL_Point hexagon[7];
	hexagon[0].x = x0 - radius;     hexagon[0].y = y0;
	hexagon[1].x = x0 - radius / 2; hexagon[1].y = y0 - radius * sqrt(3) / 2;
	hexagon[2].x = x0 + radius / 2; hexagon[2].y = y0 - radius * sqrt(3) / 2;
	hexagon[3].x = x0 + radius;     hexagon[3].y = y0;
	hexagon[4].x = x0 + radius / 2; hexagon[4].y = y0 + radius * sqrt(3) / 2;
	hexagon[5].x = x0 - radius / 2; hexagon[5].y = y0 + radius * sqrt(3) / 2;
	hexagon[6].x = x0 - radius;     hexagon[6].y = y0;
	SDL_RenderDrawLines(renderer, hexagon, 7);

}

// "hexagon vertival"
void drawHexagon2(SDL_Renderer * renderer, int x0, int y0, int radius)
{
	SDL_Point hexagon[7];
	hexagon[0].x = x0;                        hexagon[0].y = y0 - radius;
	hexagon[1].x = x0 + radius * sqrt(3) / 2; hexagon[1].y = y0 - radius / 2;
	hexagon[2].x = x0 + radius * sqrt(3) / 2; hexagon[2].y = x0 + radius / 2;
	hexagon[3].x = x0;                        hexagon[3].y = y0 + radius;
	hexagon[4].x = x0 - radius * sqrt(3) / 2; hexagon[4].y = y0 + radius / 2;
	hexagon[5].x = x0 - radius * sqrt(3) / 2; hexagon[5].y = y0 - radius / 2;
	hexagon[6].x = x0;                        hexagon[6].y = y0 - radius;
	SDL_RenderDrawLines(renderer, hexagon, 7);

}

// "hexagon horizontal"
void fillHexagon(SDL_Renderer * renderer, int xC, int yC, int radius)
{
	float x = xC - radius / 2; float y = yC - radius * sqrt(3) / 2;
	int x0 = (int)x;
	int yF = yC + radius * sqrt(3) / 2;

	int rab = 0;

	int halfWidth = sqrt(radius / 2);

	while (y < yF) {

		SDL_RenderDrawLine(renderer, (int)x, (int)y, (int)(x + radius + rab), (int)y);

		// On descend chaque pixel
		y++;
		// premiere moitiee de la descente
		if (y <= yC) {
			x = x - 0.5;
			rab += 1;
		} else {
			x = x + 0.5;
			rab -= 1;
		}

	}

}

int main(int, char**)
{
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;

		if (SDL_CreateWindowAndRenderer(500, 500, 0, &window, &renderer) == 0) {
			SDL_bool done = SDL_FALSE;

			/////
			DrawCircle(250, 250, 280);
			//////

			while (!done) {
				SDL_Event event;

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
				// SDL_RenderDrawLines(renderer, points, POINTS_COUNT);

				/////
				SDL_RenderDrawPoints(renderer, points2, cpt+1);
				/////

				drawHexagon(renderer, 250, 255, 50);
				drawHexagon2(renderer, 150, 155, 50);

				SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
				fillHexagon(renderer, 250, 255, 50);
				fillHexagon(renderer, 350, 355, 50);
				// drawCircles(renderer);

				SDL_RenderPresent(renderer);

				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						done = SDL_TRUE;
					}
				}
			}
		}

		if (renderer) {
			SDL_DestroyRenderer(renderer);
		}
		if (window) {
			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();
	return 0;
}
