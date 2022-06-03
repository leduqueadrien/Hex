
// Example program:
// Using SDL_Point in some places of your code

#include <SDL.h>
#include <stdio.h>

#define POINTS_COUNT 4

static SDL_Point points[POINTS_COUNT] = {
    {320, 200}, {300, 240}, {340, 240}, {320, 200}};

static SDL_Point points2[5000];

static int cpt = 0;

void putpixel(int x0, int y0, int) {
    points2[cpt].x = x0;
    points2[cpt].y = y0;
    cpt++;
}

void DrawCircle(int x0, int y0, int radius) {
    int x = 0, y = radius;
    int dp = 1 - radius;
    do {
        if (dp < 0)
            dp = dp + 2 * (++x) + 3;
        else
            dp = dp + 2 * (++x) - 2 * (--y) + 5;

        putpixel(x0 + x, y0 + y, 15); // For the 8 octants
        putpixel(x0 - x, y0 + y, 15);
        putpixel(x0 + x, y0 - y, 15);
        putpixel(x0 - x, y0 - y, 15);
        putpixel(x0 + y, y0 + x, 15);
        putpixel(x0 - y, y0 + x, 15);
        putpixel(x0 + y, y0 - x, 15);
        putpixel(x0 - y, y0 - x, 15);
    } while (x < y);
}

void MyDrawCircle(SDL_Renderer *renderer, int x0, int y0, int radius) {
    int x = 0, y = radius;
    int dp = 1 - radius;
    do {
        if (dp < 0)
            dp = dp + 2 * (++x) + 3;
        else
            dp = dp + 2 * (++x) - 2 * (--y) + 5;

        SDL_RenderDrawPoint(renderer, x0 + x,
                            y0 + y); // For the 8 octants
        SDL_RenderDrawPoint(renderer, x0 - x, y0 + y);
        SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);
        SDL_RenderDrawPoint(renderer, x0 - x, y0 - y);
        SDL_RenderDrawPoint(renderer, x0 + y, y0 + x);
        SDL_RenderDrawPoint(renderer, x0 - y, y0 + x);
        SDL_RenderDrawPoint(renderer, x0 + y, y0 - x);
        SDL_RenderDrawPoint(renderer, x0 - y, y0 - x);
    } while (x < y);
}

void drawCircles(SDL_Renderer *renderer) {
    SDL_RenderDrawLine(renderer, 50, 250, 450, 250); // barre horizontale
    SDL_RenderDrawLine(renderer, 250, 50, 250, 450); // barre verticale
    for (int j = 0; j < 200; j++) {
        SDL_SetRenderDrawColor(renderer, 50 * j % 255, 30 * j % 255,
                               35 * j % 255, SDL_ALPHA_OPAQUE);
        MyDrawCircle(renderer, 250, 250, j);
    }
}

// "hexagon horizontal"
void drawHexagon(SDL_Renderer *renderer, int x0, int y0, int radius) {
    SDL_Point hexagon[7];
    hexagon[0].x = (int)(x0 - radius);
    hexagon[0].y = (int)(y0);
    hexagon[1].x = (int)(x0 - radius / 2);
    hexagon[1].y = (int)(y0 - radius * sqrt(3) / 2);
    hexagon[2].x = (int)(x0 + radius / 2);
    hexagon[2].y = (int)(y0 - radius * sqrt(3) / 2);
    hexagon[3].x = (int)(x0 + radius);
    hexagon[3].y = (int)(y0);
    hexagon[4].x = (int)(x0 + radius / 2);
    hexagon[4].y = (int)(y0 + radius * sqrt(3) / 2);
    hexagon[5].x = (int)(x0 - radius / 2);
    hexagon[5].y = (int)(y0 + radius * sqrt(3) / 2);
    hexagon[6].x = (int)(x0 - radius);
    hexagon[6].y = (int)(y0);
    SDL_RenderDrawLines(renderer, hexagon, 7);
}

// "hexagon vertival"
void drawHexagon2(SDL_Renderer *renderer, int x0, int y0, int radius) {
    SDL_Point hexagon[7];
    hexagon[0].x = (int)(x0);
    hexagon[0].y = (int)(y0 - radius);
    hexagon[1].x = (int)(x0 + radius * sqrt(3) / 2);
    hexagon[1].y = (int)(y0 - radius / 2);
    hexagon[2].x = (int)(x0 + radius * sqrt(3) / 2);
    hexagon[2].y = (int)(x0 + radius / 2);
    hexagon[3].x = (int)(x0);
    hexagon[3].y = (int)(y0 + radius);
    hexagon[4].x = (int)(x0 - radius * sqrt(3) / 2);
    hexagon[4].y = (int)(y0 + radius / 2);
    hexagon[5].x = (int)(x0 - radius * sqrt(3) / 2);
    hexagon[5].y = (int)(y0 - radius / 2);
    hexagon[6].x = (int)(x0);
    hexagon[6].y = (int)(y0 - radius);
    SDL_RenderDrawLines(renderer, hexagon, 7);
}

// "hexagon horizontal"
void fillHexagon(SDL_Renderer *renderer, int xC, int yC, int radius) {
    float x = (float)(xC - radius / 2);
    float y = (float)(yC - radius * sqrt(3) / 2);
    int x0 = (int)x;
    int yF = (int)(yC + radius * sqrt(3) / 2);

    int rab = 0;

    int halfWidth = (int)(sqrt(radius / 2));

    while (y < yF) {

        SDL_RenderDrawLine(renderer, (int)x, (int)y, (int)(x + radius + rab),
                           (int)y);

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

#include <vector>

typedef struct point {
    int x;
    int y;
} point_t;

void determineHexaCenters(std::vector<point_t> hexaCenters, int nbHexa, int x0,
                          int y0, int radius, int apothem) {
    int x = x0;
    int y = y0;

    point_t center;

    for (int line = 0; line < nbHexa; line++) {
        x = x0 + radius;
        y = y0 + apothem + 2 * apothem * line;
        for (int col = 0; col < nbHexa; col++) {
            center.x = x;
            center.y = y;
            hexaCenters.push_back(center);
            x += radius + apothem / 2;
            y += apothem;
        }
    }
}

int main(int, char **) {
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = NULL;

        if (SDL_CreateWindowAndRenderer(800, 800, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            SDL_Rect board;
            board.x = 100;
            board.y = 100;
            board.w = 600;
            board.h = 600;

            int const nbHexa = 6;
            int hexaRadius = board.w / nbHexa / 2;

            int hexaApothem =
                static_cast<int>(sqrt(hexaRadius * hexaRadius -
                                      (hexaRadius / 2) * (hexaRadius / 2)) +
                                 1); // (+1)

            ///
            int x = board.x;
            int y = board.y;

            point_t hexaCenters[nbHexa][nbHexa];
            for (int line = 0; line < nbHexa; ++line) {
                x = board.x + hexaRadius;
                y = board.y + hexaApothem + 2 * hexaApothem * line;
                for (int col = 0; col < nbHexa; ++col) {
                    hexaCenters[line][col].x = x;
                    hexaCenters[line][col].y = y;
                    x += hexaRadius + hexaApothem / 2 + 1; // (+1)
                    y += hexaApothem + 1;                  // (+1)
                }
            }
            ///
            // std::vector<point_t> hexaCenters;
            // determineHexaCenters(hexaCenters, nbHexa, board.x,
            // board.y, hexaRadius, hexaApothem);

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 60, 60, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255,
                                       SDL_ALPHA_OPAQUE);
                SDL_RenderDrawRect(renderer, &board);

                for (int line = 0; line < nbHexa; line++) {
                    for (int col = 0; col < nbHexa; col++) {
                        drawHexagon(renderer, hexaCenters[line][col].x,
                                    hexaCenters[line][col].y, hexaRadius);
                        // drawHexagon(renderer,
                        // hexaCenters.at(line*nbHexa +
                        // col).x,
                        // hexaCenters.at(line*nbHexa +
                        // col).y, hexaRadius);
                    }
                }

                // x = board.x + hexaRadius;
                // y = board.y + hexaApothem + 1;

                // for (int i=0; i<nbHexa; i++) {
                // 	drawHexagon(renderer, x, y, hexaRadius);
                // 	y += hexaApothem * 2;
                // }

                // x = board.x + hexaRadius;
                // y = board.y + hexaApothem + 1;

                // for (int i=0; i<nbHexa; i++) {
                // 	drawHexagon(renderer, x, y, hexaRadius);
                // 	x += hexaRadius * 2;
                // }

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

// int main(int, char**)
// {
// 	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
// 		SDL_Window* window = NULL;
// 		SDL_Renderer* renderer = NULL;

// 		if (SDL_CreateWindowAndRenderer(500, 500, 0, &window,
// &renderer)
// == 0) { 			SDL_bool done = SDL_FALSE;

// 			/////
// 			DrawCircle(250, 250, 280);
// 			//////

// 			while (!done) {
// 				SDL_Event event;

// 				SDL_SetRenderDrawColor(renderer, 0, 0, 0,
// SDL_ALPHA_OPAQUE); 				SDL_RenderClear(renderer);

// 				SDL_SetRenderDrawColor(renderer, 255, 255, 255,
// SDL_ALPHA_OPAQUE);
// 				// SDL_RenderDrawLines(renderer, points,
// POINTS_COUNT);

// 				/////
// 				SDL_RenderDrawPoints(renderer, points2, cpt+1);
// 				/////

// 				drawHexagon(renderer, 250, 255, 50);
// 				drawHexagon(renderer, 330, 210, 50);
// 				drawHexagon2(renderer, 150, 155, 50);

// 				SDL_SetRenderDrawColor(renderer, 255, 0, 0,
// SDL_ALPHA_OPAQUE); 				fillHexagon(renderer, 250, 255,
// 50); 				fillHexagon(renderer, 350, 355, 50);
// 				// drawCircles(renderer);

// 				SDL_RenderPresent(renderer);

// 				while (SDL_PollEvent(&event)) {
// 					if (event.type == SDL_QUIT) {
// 						done = SDL_TRUE;
// 					}
// 				}
// 			}
// 		}

// 		if (renderer) {
// 			SDL_DestroyRenderer(renderer);
// 		}
// 		if (window) {
// 			SDL_DestroyWindow(window);
// 		}
// 	}
// 	SDL_Quit();
// 	return 0;
// }

// dans MainHexGraphic.cpp

// #include <SDL2/SDL.h>

// #include <stdio.h>
// #include "Graphic/Framework.hpp"

// int beige[3] = {255, 183, 138}; //beige
// SDL_Rect rect;

// void drawSquares(Framework fw)
// {
// 	bool running  = true;
// 	SDL_Event      event;

// 	while (running) {
// 		while (SDL_PollEvent(&event)) {
// 			switch (event.type)
// 			{
// 			case SDL_MOUSEBUTTONDOWN:
// 				printf("Appui : %d %d\n", event.button.x,
// event.button.y);

// 				// if(0 != SDL_RenderClear(g.renderer))
// 				// {
// 				// 	fprintf(stderr, "Erreur
// SDL_SetRenderDrawColor : %s", SDL_GetError());
// 				// }

// 				SDL_SetRenderDrawColor(fw.renderer, 0, 0, 0,
// 255); 				SDL_RenderClear(fw.renderer);
// SDL_SetRenderDrawColor(fw.renderer, beige[0], beige[1], beige[2], 255);
// rect.x = event.button.x; rect.y =
// event.button.y; 				rect.w = 20; rect.h = 20;
// SDL_RenderFillRect(fw.renderer, &rect);
// SDL_RenderPresent(fw.renderer);
// SDL_RenderFillRect(fw.renderer, &rect);
// SDL_RenderPresent(fw.renderer);

// 				break;

// 			case SDL_QUIT:
// 				running = false;
// 				SDL_RenderPresent(fw.renderer);
// 				SDL_Delay(3000);
// 				SDL_RenderPresent(fw.renderer);
// 				SDL_Delay(3000);
// 				SDL_RenderPresent(fw.renderer);
// 				SDL_Delay(3000);
// 				break;
// 			}
// 		}
// 		SDL_Delay(1);
// 	}

// }

// int main(int, char**)
// {
// 	Framework framework = Framework(800, 800);

// 	drawSquares(framework);

// 	return 0;
// }
