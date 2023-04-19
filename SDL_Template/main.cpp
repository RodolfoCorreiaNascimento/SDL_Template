#include <iostream>
#include <SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

Uint32 r_color = 0;
Uint32 g_color = 0;
Uint32 b_color = 255;

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("SDL_Template", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	bool running = true;

	SDL_Event e;

	while (running) {

		// Event loop
		while (SDL_PollEvent(&e) != 0) {
			// check event type
			switch (e.type)
			{
			case SDL_QUIT:
				// shut down
				running = false;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_a:
					r_color = 255;
					g_color = 0;
					b_color = 0;
					break;
				case SDLK_d:
					r_color = 0;
					g_color = 255;
					b_color = 0;
				default:
					break;
				}
			default:
				break;
			}
		}
		SDL_SetRenderDrawColor(renderer, r_color, g_color, b_color, 255);

		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);

		//SDL_Delay(10000);

	}
	std::cout << "Hello, world!" << std::endl;
	return 0;
}