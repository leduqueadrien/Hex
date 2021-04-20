
#include <stdio.h>
#include <SDL2/SDL.h>
#include <framework/Framework.hpp>


int beige[3] = {255, 183, 138}; //beige
SDL_Rect rect;


void drawSquares(Framework fw)
{
	bool running  = true;
	SDL_Event      event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				printf("Appui : %d %d\n", event.button.x, event.button.y);

				// if(0 != SDL_RenderClear(g.renderer))
				// {
				// 	fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
				// }

				SDL_SetRenderDrawColor(fw.renderer, 0, 0, 0, 255);
				SDL_RenderClear(fw.renderer);
				SDL_SetRenderDrawColor(fw.renderer, beige[0], beige[1], beige[2], 255);
				rect.x = event.button.x; rect.y = event.button.y;
				rect.w = 20; rect.h = 20;
				SDL_RenderFillRect(fw.renderer, &rect);
				SDL_RenderPresent(fw.renderer);

				break;

			case SDL_QUIT:
				running = false;
				// SDL_RenderPresent(fw.renderer);
				// SDL_Delay(3000);
				// SDL_RenderPresent(fw.renderer);
				// SDL_Delay(3000);
				// SDL_RenderPresent(fw.renderer);
				// SDL_Delay(3000);
				break;
			}
		}
		SDL_Delay(1);
	}

}

int main(int, char**)
{
	Framework framework = Framework(800, 800);

	drawSquares(framework);

	return 0;
}
