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

static unsigned		clamp(double nb)
{
	if (nb > 255)
		return (255);
	if (nb < 0)
		return (0);
	return ((unsigned int)nb);
}

static t_vec3f		canvas_to_viewport(const int x, const int y)
{
	t_vec3f			ret;

	ret.x = (double)x * WIDTH / HEIGHT / WIDTH;
	ret.y = -(double)y * 1 / HEIGHT;
	ret.z = 1;
	return (ret);
}

static void			pixel_put(int w, int h, t_vec3f rgb, Uint32 *pixels)
{
	Uint32			color;

	color = ((clamp(rgb.x) << 16) + (clamp(rgb.y) << 8) + clamp(rgb.z));
	pixels[WIDTH_H + w + (HEIGHT_H + h) * WIDTH] = color;
}

static void			raytrace(const t_rt rt, const t_sdl sdl)
{
	register int	w;
	register int	h;
	t_vec3f			direction;
	t_vec3f 		colour;

	h = -HEIGHT_H -1;
	while (++h < HEIGHT_H && (w = -WIDTH_H - 1))
		while (++w < WIDTH_H)
		{
			direction = vec3f_norm(vec3f_rot(canvas_to_viewport(w, h), rt.rotation));
			colour = trace_ray((t_data){rt.camera, direction, rt.z_min, rt.z_max}, rt);
			pixel_put(w, h, colour, sdl.screen.pixels);
		}
}

int					main(int argc, char *argv[])
{
	t_sdl			sdl;
	t_rt			rt;
	SDL_Event		e;

	rt_init(argc, argv, &rt);
	conf_reload(argv[1], &rt.lights, &rt.objects);
//	sdl_init(&sdl);
//	while (sdl.running)
//	{
//		create_screen(&sdl.screen, &sdl);
//		raytrace(rt, sdl);
//		SDL_UnlockTexture(sdl.screen.texture);
//		SDL_RenderCopy(sdl.ren, sdl.screen.texture, NULL, NULL);
//		SDL_RenderPresent(sdl.ren);
//		while (SDL_PollEvent(&e))
//			manage_event(e, &sdl, argv[1], &rt);
//		manage_keys(&rt, &sdl);
//	}
//	sdl_quit(&sdl);
	exit(0);
}
