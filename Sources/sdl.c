/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:23:06 by wstygg            #+#    #+#             */
/*   Updated: 2019/12/05 21:23:07 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			create_screen(t_screen *screen, t_sdl *sdl)
{
	screen->texture = SDL_CreateTexture(sdl->ren,
		SDL_GetWindowPixelFormat(sdl->win), SDL_TEXTUREACCESS_STREAMING,
		SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_LockTexture(screen->texture, NULL, (void*)&screen->pixels,
			&screen->pitch);
}

void			sdl_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (ft_error(SDL_GetError()));
	if (!(sdl->win = SDL_CreateWindow("SimpleText", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)))
		return (ft_error(SDL_GetError()));
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1,
										SDL_RENDERER_ACCELERATED)))
		return (ft_error(SDL_GetError()));
	SDL_SetRenderDrawColor(sdl->ren, 0x30, 0x30, 0x30, 0);
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		return (ft_error(SDL_GetError()));
	create_screen(&sdl->screen, sdl);
	sdl->running = 1;
}

void			manage_event(SDL_Event e, t_sdl *sdl)
{
	if (e.type == SDL_QUIT)
		sdl->running = 0;
	else if (e.type == SDL_KEYDOWN)
		sdl->keys[e.key.keysym.scancode] = 1;
	else if (e.type == SDL_KEYUP)
		sdl->keys[e.key.keysym.scancode] = 0;
}

void			manage_keys(t_sdl *sdl)
{
	if (sdl->keys[SDL_SCANCODE_ESCAPE])
		sdl->running = 0;
}

void			sdl_quit(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	sdl->win = NULL;
	sdl->ren = NULL;
	IMG_Quit();
	SDL_Quit();
}
