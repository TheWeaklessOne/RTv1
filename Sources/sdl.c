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
	{
		if (e.key.keysym.sym == SDLK_ESCAPE)
			sdl->running = 0;
		sdl->keys[e.key.keysym.scancode] = 1;
	}
	else if (e.type == SDL_KEYUP)
		sdl->keys[e.key.keysym.scancode] = 0;
}

void			manage_keys(t_rt *rt, t_sdl *sdl)
{
	if (sdl->keys[SDL_SCANCODE_LEFT] || sdl->keys[SDL_SCANCODE_A])
		rt->camera.x -= 0.1f;
	if (sdl->keys[SDL_SCANCODE_RIGHT] || sdl->keys[SDL_SCANCODE_D])
		rt->camera.x += 0.1f;
	if (sdl->keys[SDL_SCANCODE_UP] || sdl->keys[SDL_SCANCODE_Q])
		rt->camera.y += 0.1f;
	if (sdl->keys[SDL_SCANCODE_DOWN] || sdl->keys[SDL_SCANCODE_E])
		rt->camera.y -= 0.1f;
	if (sdl->keys[SDL_SCANCODE_W])
		rt->camera.z += 0.1f;
	if (sdl->keys[SDL_SCANCODE_S])
		rt->camera.z -= 0.1f;
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
