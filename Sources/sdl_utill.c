#include "guimp.h"

void				sdl_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (ft_error(SDL_GetError()));
	if (!(sdl->win = SDL_CreateWindow("Push_swap", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE)))
		return (ft_error(SDL_GetError()));
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		return (ft_error(SDL_GetError()));
	SDL_SetRenderDrawColor(sdl->ren, 0xFF, 0xFF, 0xFF, 0xFF);
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		return (ft_error(SDL_GetError()));
	if (TTF_Init() == -1)
		return (ft_error(SDL_GetError()));
	sdl->running = 1;
}

void				sdl_quit(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	sdl->win = NULL;
	sdl->ren = NULL;

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
