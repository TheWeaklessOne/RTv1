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
