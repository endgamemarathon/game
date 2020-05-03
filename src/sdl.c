#include "../inc/header.h"

void	initSDL(t_game *game) //активация
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_JPG);
	game->sdl.window = SDL_CreateWindow("Virus", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_ALLOW_HIGHDPI);
	game->sdl.renderer = SDL_CreateRenderer(game->sdl.window, -1,
			SDL_RENDERER_ACCELERATED);
}

void	destroySDL(t_game *game) //освобождение
{
	SDL_DestroyRenderer(game->sdl.renderer);
	SDL_DestroyWindow(game->sdl.window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void	render_clearSDL(t_game *game) //очистка
{
	SDL_SetRenderDrawColor(game->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(game->sdl.renderer);
}