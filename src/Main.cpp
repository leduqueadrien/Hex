#include <SDL2/SDL.h>

#include <stdio.h>


typedef struct gdata_s {
	SDL_Window   * window;
	SDL_Renderer * renderer;
	// TTF_Font     * font;
	int            width;
	int            height;
} gdata_t;

int beige[3] = {255, 183, 138}; //beige
SDL_Rect rect;

int main(int argc, char** argv)
{

	gdata_t         g;
	bool running  = true;
	bool graphics = true;

	SDL_Event      event;

	g.window     = 0;
	g.renderer   = 0;
	// g.font       = 0;
	g.width      = 800;
	g.height     = 800;


	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
		graphics = false;
	}
	else {
		g.window = SDL_CreateWindow("HEX GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_UNDEFINED, 
						g.width, g.height, SDL_WINDOW_SHOWN |  SDL_WINDOW_RESIZABLE); 

		if (g.window == 0) {
			fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
			graphics = false;
		}
		else {
			g.renderer = SDL_CreateRenderer(g.window, -1, SDL_RENDERER_ACCELERATED ); /* | SDL_RENDERER_PRESENTVSYNC */
			if (g.renderer == 0) {
				fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
				graphics = false;
			}
			// else {
			// 	if (TTF_Init() != 0){
			// 		fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError()); 
			// 		graphics = false;
			// 	}
			// 	else {
			// 		g.font = TTF_OpenFont("Arial.ttf", 20);

			// 		if (!g.font) {
			// 			graphics = false; 
			// 			fprintf(stderr, "La police ARIAL n'est pas chargee\n"); 
			// 		}
			// 	}
			// }
		}
	}

	if (graphics == false) {
		// if (g.font     != 0) TTF_CloseFont(g.font);
		if (g.renderer != 0) SDL_DestroyRenderer(g.renderer);
		if (g.window   != 0) SDL_DestroyWindow(g.window);
		// TTF_Quit();
		SDL_Quit();
		return 0;
	} 

	SDL_RenderPresent(g.renderer);


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

				SDL_SetRenderDrawColor(g.renderer, 0, 0, 0, 255);
				SDL_RenderClear(g.renderer);
				SDL_SetRenderDrawColor(g.renderer, beige[0], beige[1], beige[2], 255);
				rect.x = event.button.x; rect.y = event.button.y;
				rect.w = 20; rect.h = 20;
				SDL_RenderFillRect(g.renderer, &rect);
				SDL_RenderPresent(g.renderer);

				break;

			case SDL_QUIT:
				running = false;
				// SDL_RenderPresent(g.renderer);
				// SDL_Delay(3000);
				// SDL_RenderPresent(g.renderer);
				// SDL_Delay(3000);
				// SDL_RenderPresent(g.renderer);
				// SDL_Delay(3000);
				break;
			}
		}
		SDL_Delay(1);
	}


	// TTF_CloseFont(g.font);
	SDL_DestroyRenderer(g.renderer);
	SDL_DestroyWindow(g.window);
	// TTF_Quit();
	SDL_Quit();

	return 0;
}

// #include <SDL2/SDL.h>
// #include <iostream>
// #include <cmath>
// #include <vector>

// class Framework{
// public:
//     // Contructor which initialize the parameters.
//     Framework(int height_, int width_): height(height_), width(width_){
//         SDL_Init(SDL_INIT_VIDEO);       // Initializing SDL as Video
//         SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
//         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);      // setting draw color
//         SDL_RenderClear(renderer);      // Clear the newly created window
//         SDL_RenderPresent(renderer);    // Reflects the changes done in the
//                                         //  window.
//     }

//     // Destructor
//     ~Framework(){
//         SDL_DestroyRenderer(renderer);
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//     }

//     void draw_circle(int center_x, int center_y, int radius_){
//         // Setting the color to be RED with 100% opaque (0% trasparent).
//         SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

//         // Drawing circle
//         for(int x=center_x-radius_; x<=center_x+radius_; x++){
//             for(int y=center_y-radius_; y<=center_y+radius_; y++){
//                 if((std::pow(center_y-y,2)+std::pow(center_x-x,2)) <= 
//                     std::pow(radius_,2)){
//                     SDL_RenderDrawPoint(renderer, x, y);
//                 }
//             }
//         }

//         // Show the change on the screen
//         SDL_RenderPresent(renderer);
//     }

//     void move_circle(){
//         // Setting the color to be RED with 100% opaque (0% trasparent).
        
//         SDL_Event event;    // Event variable
//         while(!(event.type == SDL_QUIT)){

//             // Circle will go down!
//             for(int i=0; i<height/2; i++){
//                 SDL_Delay(10);  // setting some Delay
//                 SDL_PollEvent(&event);  // Catching the poll event.
//                 if(event.type == SDL_QUIT) return;
//                 SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//                 SDL_RenderClear(renderer);
//                 draw_circle(width/2, i*2, 25);
//             }

//             // Circle will go up!
//             for(int i=height; i>0; i--){
//                 SDL_Delay(10);  // setting some Delay
//                 SDL_PollEvent(&event);  // Catching the poll event.
//                 if(event.type == SDL_QUIT) return;
//                 SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//                 SDL_RenderClear(renderer);
//                 draw_circle(width/2, i, 25);
//             }
//         }
        
//     }

// private:
//     int height;     // Height of the window
//     int width;      // Width of the window
//     SDL_Renderer *renderer = NULL;      // Pointer for the renderer
//     SDL_Window *window = NULL;      // Pointer for the window
// };

// int main(int argc, char * argv[]){

//     // Creating the object by passing Height and Width value.
//     Framework fw(200, 400);
// 	int n;
// 	std::cin >> n;
//     // Starting the animation
//     fw.move_circle();
    
//     return 1;
// }