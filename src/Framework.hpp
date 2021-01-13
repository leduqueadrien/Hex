
#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

class Framework
{

public:
	SDL_Window * window;
	SDL_Renderer * renderer;
	// TTF_Font * font;
	int height;
	int width;

public:
	Framework(int, int);
	~Framework();
};

#endif
