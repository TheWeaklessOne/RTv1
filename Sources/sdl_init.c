/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:06:04 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/10 16:06:06 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			keys_init(int keys[SDL_NUM_SCANCODES])
{
	register int	i;

	i = -1;
	while (++i < SDL_NUM_SCANCODES)
		keys[i] = 0;
}

void				create_screen(t_screen *screen, t_sdl *sdl)
{
	if (screen->texture)
		SDL_DestroyTexture(screen->texture);
	screen->texture = SDL_CreateTexture(sdl->ren,
	SDL_GetWindowPixelFormat(sdl->win), SDL_TEXTUREACCESS_STREAMING,
	WIDTH, HEIGHT);
	SDL_LockTexture(screen->texture, NULL, (void*)&screen->pixels,
		&screen->pitch);
}

void				sdl_init(t_sdl *sdl)
{
	sdl->screen.texture = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (ft_crash(SDL_GetError()));
	if (!(sdl->win = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		return (ft_crash(SDL_GetError()));
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1,
			SDL_RENDERER_ACCELERATED)))
		return (ft_crash(SDL_GetError()));
	keys_init(sdl->keys);
	sdl->running = 1;
}
