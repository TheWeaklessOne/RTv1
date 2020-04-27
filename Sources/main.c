/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:36:06 by wstygg            #+#    #+#             */
/*   Updated: 2020/03/14 12:36:08 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vec3f		canvas_to_viewport(const int x, const int y)
{
	t_vec3f			ret;

	ret.x = (float)x * WIDTH / HEIGHT / WIDTH;
	ret.y = (float)y * 1 / HEIGHT;
	ret.z = 1;
	return (ret);
}

static Uint32		get_colour(t_vec3f dir, float z_min, float z_max, t_rt rt)
{
	register int	i;
	float			t_min;
	t_object		*to_draw;
	float			inter;

	to_draw = NULL;
	t_min = FLT_MAX;
	i = -1;
	while (++i < rt.objects_n)
	{
		inter = rt.objects[i].intersect(rt.camera, dir, rt.objects[i].object);
		if (inter < t_min && z_min < inter && inter < z_max)
		{
			t_min = inter;
			to_draw = &rt.objects[i];
		}
	}
	if (to_draw)
		return (to_draw->color);
	return (BACKGROUND_C);
}

void				raytrace(t_rt rt, t_sdl sdl)
{
	register int	w;
	register int	h;

	h = -HEIGHT_H -1;
	while (++h < HEIGHT_H && (w = -WIDTH_H - 1))
		while (++w < WIDTH_H)
			sdl.screen.pixels[WIDTH_H + w + (HEIGHT_H + h) * WIDTH] =
					get_colour
					(
							canvas_to_viewport(w, h),
							rt.z_min,
							rt.z_max,
							rt
					);
}

int					main()
{
	t_sdl			sdl;
	t_rt			rt;
	SDL_Event		e;

	sdl_init(&sdl);
	rt_init(&rt);
	raytrace(rt, sdl);
	SDL_UnlockTexture(sdl.screen.texture);
	SDL_RenderCopy(sdl.ren, sdl.screen.texture, NULL, NULL);
	while (sdl.running)
	{
		SDL_RenderPresent(sdl.ren);
		while (SDL_PollEvent(&e))
			manage_event(e, &sdl);
		manage_keys(&sdl);
	}
	sdl_quit(&sdl);
	exit(0);
}
