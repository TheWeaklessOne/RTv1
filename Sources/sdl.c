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

void			manage_event(SDL_Event e, t_sdl *sdl, char *path, t_rt *rt)
{
	if (e.type == SDL_QUIT)
		sdl->running = 0;
	else if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_ESCAPE)
			sdl->running = 0;
		else if (e.key.keysym.sym == SDLK_r)
			conf_reload(path, &rt->lights, &rt->objects, rt);
		if (!sdl->keys[e.key.keysym.scancode])
			sdl->keys[e.key.keysym.scancode] = 1;
	}
	else if (e.type == SDL_KEYUP)
		sdl->keys[e.key.keysym.scancode] = 0;
}

void			manage_keys(t_rt *rt, t_sdl *sdl)
{
	if (sdl->keys[SDL_SCANCODE_LEFT])
		rt->rotation.y -= 5;
	if (sdl->keys[SDL_SCANCODE_RIGHT])
		rt->rotation.y += 5;
	if (sdl->keys[SDL_SCANCODE_UP])
		rt->rotation.x -= 5;
	if (sdl->keys[SDL_SCANCODE_DOWN])
		rt->rotation.x += 5;
	if (sdl->keys[SDL_SCANCODE_A])
		rt->camera.x -= 0.25;
	if (sdl->keys[SDL_SCANCODE_D])
		rt->camera.x += 0.25;
	if (sdl->keys[SDL_SCANCODE_Q])
		rt->camera.y += 0.25;
	if (sdl->keys[SDL_SCANCODE_E])
		rt->camera.y -= 0.25;
	if (sdl->keys[SDL_SCANCODE_W])
		rt->camera.z += 0.25;
	if (sdl->keys[SDL_SCANCODE_S])
		rt->camera.z -= 0.25;
}

void			sdl_quit(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	sdl->win = NULL;
	sdl->ren = NULL;
	SDL_Quit();
}
