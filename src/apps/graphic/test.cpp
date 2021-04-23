
#include <SDL.h>
#include <stdio.h>

int beige[3] = {255, 183, 138}; //beige
SDL_Rect rect;
int w; int h;
int size = 6;
int tileSize;
int winW = 800;
int winH = 800;

void drawRectGrid(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    int start_x = 100;
    int start_y = 100;
    for (int i=0; i<=size+1; ++i) {
        SDL_RenderDrawLine(renderer, start_x, start_y * i, start_x + 600, start_y * i);
    }
    for (int i=0; i<=size+1; ++i) {
        SDL_RenderDrawLine(renderer, start_x * i, start_y, start_x * i, start_y + 600);
    }
}

bool isOnGrid(int x, int y)
{
    return (x>100 && x<700 && y>100 && y<700);
}

void drawHoverMouse(SDL_Renderer* renderer)
{
    int x; int y;
    SDL_GetMouseState(&x, &y);

    if (isOnGrid(x, y)) {
    	SDL_SetRenderDrawColor(renderer, beige[0], beige[1], beige[2], SDL_ALPHA_OPAQUE);
        rect.x = (x / tileSize) * tileSize; rect.y = (y / tileSize) * tileSize;
        rect.w = tileSize; rect.h = tileSize;
		SDL_RenderFillRect(renderer, &rect);
    }
}

int main(int, char**)
{
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = NULL;

		if (SDL_CreateWindowAndRenderer(winW, winH, 0, &window, &renderer) == 0) {
			SDL_bool done = SDL_FALSE;

            tileSize = 100;

			while (!done) {
				SDL_Event event;

				SDL_SetRenderDrawColor(renderer, 60, 60, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);

                drawRectGrid(renderer);
                drawHoverMouse(renderer);

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