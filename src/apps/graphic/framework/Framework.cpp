
#include "Framework.hpp"
#include <SDL.h>
#include <iostream>

// regarder les options de creation du renderer
// et regarder les options de mix des pixels du renderer

Framework::Framework(int height, int width) : m_height(height), m_width(width) {
    bool graphics = true;

    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",
                SDL_GetError());
        graphics = false;
    } else {
        window = SDL_CreateWindow("HEX GAME", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_UNDEFINED, width, height,
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

        if (window == 0) {
            fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",
                    SDL_GetError());
            graphics = false;
        } else {
            renderer = SDL_CreateRenderer(
                window, -1,
                SDL_RENDERER_ACCELERATED); /* |
                                              SDL_RENDERER_PRESENTVSYNC
                                            */
            if (renderer == 0) {
                fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",
                        SDL_GetError());
                graphics = false;
            }
            // else {
            // 	if (TTF_Init() != 0){
            // 		fprintf(stderr, "Erreur d'initialisation TTF :
            // %s\n", TTF_GetError()); 		graphics = false;
            // 	}
            // 	else {
            // 		font = TTF_OpenFont("Arial.ttf", 20);

            // 		if (!font) {
            // 			graphics = false;
            // 			fprintf(stderr, "La police ARIAL n'est
            // pas chargee\n");
            // 		}
            // 	}
            // }
        }
    }

    if (graphics == false) {
        // if (g.font     != 0) TTF_CloseFont(g.font);
        if (renderer != 0)
            SDL_DestroyRenderer(renderer);
        if (window != 0)
            SDL_DestroyWindow(window);
        // TTF_Quit();
        SDL_Quit();

        // throw Exception ?
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // setting draw color
    SDL_RenderClear(renderer);   // Clear the newly created window
    SDL_RenderPresent(renderer); // Reflects the changes done in the window.
}

Framework::~Framework() {
    // TTF_CloseFont(g.font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    // TTF_Quit();
    SDL_Quit();
}
