
#include <stdio.h>
#include <SDL.h>
#include <hexGame/Game.hpp>
#include <hexGame/Human.hpp>
#include "framework/Framework.hpp"
#include "graphicUI/GraphicUI.hpp"

int beige[3] = {255, 183, 138}; //beige
SDL_Rect rect;


void drawSquares(Framework fw)
{
	bool running  = true;
	SDL_Event      event;

	int mouse_x, mouse_y;
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
				// SDL_RenderClear(fw.renderer);
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

			SDL_GetMouseState(&mouse_x, &mouse_y);

			SDL_SetRenderDrawColor(fw.renderer, 255, 0, 0, 255);
			rect.x = mouse_x; rect.y = mouse_y;
			rect.w = 10; rect.h = 10;
			SDL_RenderFillRect(fw.renderer, &rect);

			SDL_RenderPresent(fw.renderer);

		}
		SDL_Delay(1);
	}

}

int main(int, char**)
{

	GameUI* gameUI = new GraphicUI();
	Human* player1 = new Human(Color::White, gameUI);
	Human* player2 = new Human(Color::Black, gameUI);
	Game* game = new Game(gameUI, player1, player2, 11);


	SDL_Event event;

	while (!game->isGameFinished()) {
		
		SDL_PollEvent(&event);
		
		game->displayBoard();

		if (event.type == SDL_QUIT) {
			break;
		}

		SDL_Delay(1);
	}




	return 0;
}
