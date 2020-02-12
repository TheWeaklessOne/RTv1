#include "guimp.h"
#include <stdio.h>

void			event_handler(SDL_Event e, t_sdl *sdl)
{
	float		f;

	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_KP_PLUS)
		{
			SDL_GetWindowOpacity(sdl->win, &f);
			SDL_SetWindowOpacity(sdl->win, f + 0.01f);
		}
		if (e.key.keysym.sym == SDLK_KP_MINUS)
		{
			SDL_GetWindowOpacity(sdl->win, &f);
			SDL_SetWindowOpacity(sdl->win, f - 0.01f);
		}
		if (e.key.keysym.sym == SDLK_ESCAPE)
			sdl->running = 0;
	}
	else if (e.type == SDL_WINDOWEVENT)
	{
		if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
			SDL_GetWindowSize(sdl->win, &sdl->width, &sdl->height);
	}
	else if (e.type == SDL_QUIT)
		sdl->running = 0;
}

int				main(void)
{
	t_sdl		sdl;
	SDL_Event	e;

	sdl_init(&sdl);
	while (sdl.running)
	{
		while (SDL_PollEvent(&e))
			event_handler(e, &sdl);
		SDL_SetRenderDrawColor(sdl.ren, 0x30, 0x30, 0x30, 0xFF);
		SDL_RenderClear(sdl.ren);
		SDL_SetRenderDrawColor(sdl.ren, 0xFF, 0x00, 0x00, 0x00);
		SDL_RenderPresent(sdl.ren);
	}
	sdl_quit(&sdl);
	exit(0);
}