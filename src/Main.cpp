#include <SDL2/SDL.h>

#include <stdio.h>

int main(int argc, char** argv)
{
	/* Initialisation simple */
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
		return -1;
	}

	bool running = true;
	SDL_Event event;

	/* Création de la fenêtre */
	SDL_Window* pWindow = NULL;
	pWindow = SDL_CreateWindow("Ma première application SDL2", SDL_WINDOWPOS_UNDEFINED,
																SDL_WINDOWPOS_UNDEFINED,
																640,
																480,
																SDL_WINDOW_SHOWN);

	if (!pWindow) {
		fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
		running = false;
	}

	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}
		SDL_Delay(16);
	}


	SDL_DestroyWindow(pWindow);
	SDL_Quit();

	return 0;
}
