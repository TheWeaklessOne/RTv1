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
	ret.y = -(float)y * 1 / HEIGHT;
	ret.z = 1;
	return (ret);
}

static float		compute_light(t_vec3f point, t_vec3f normal, const t_rt rt)
{
	float			intensity;
	t_list			*lights;
	t_light			*light;
	t_vec3f			vec_l;
	float			scalar_l;
	const float		nor_len = vec3f_length(normal);

	intensity = 0;
	lights = rt.lights;
	while (lights)
	{
		light = lights->content;
		if (light->type == AMBIENT)
			intensity += light->intensity;
		else
		{
			if (light->type == POINT)
				vec_l = vec3f_sub(light->pos, point);
			else
				vec_l = light->pos;
			scalar_l = vec3f_scalar(normal, vec_l);
			if (scalar_l > 0)
				intensity += light->intensity * scalar_l / (nor_len * vec3f_length(vec_l));
		}
		lights = lights->next;
	}
	return (intensity);
}

static t_vec3f		add_light(const t_vec3f dir, const float t_min,
							   const t_object obj, const t_rt rt)
{
	t_vec3f			point;
	t_vec3f			normal;

	point = vec3f_add(rt.camera, vec3f_scale(dir, t_min));
	normal = vec3f_sub(point, ((t_sphere*)obj.object)->center);
	normal = vec3f_norm(normal);
	return (vec3f_scale(obj.color, compute_light(point, normal, rt)));
}

static Uint32		vec3f_to_uint32(t_vec3f rgb)
{
	Uint32			ret;

	ret = (int)rgb.x;
	ret = (ret << 8) + (int)rgb.y;
	ret = (ret << 8) + (int)rgb.z;
	return (ret);
}

static t_vec3f		get_colour(const t_vec3f dir, const t_rt rt)
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
		if (inter < t_min && rt.z_min < inter && inter < rt.z_max)
		{
			t_min = inter;
			to_draw = &rt.objects[i];
		}
	}
	if (to_draw)
		return (add_light(dir, t_min, *to_draw, rt));
	return (BACKGROUND_C);
}

void				raytrace(t_rt rt, t_sdl sdl)
{
	register int	w;
	register int	h;
	t_vec3f			direction;
	Uint32			colour;

	h = -HEIGHT_H -1;
	while (++h < HEIGHT_H && (w = -WIDTH_H - 1))
		while (++w < WIDTH_H)
		{
			direction = canvas_to_viewport(w, h);
			colour = vec3f_to_uint32(get_colour(direction, rt));
			sdl.screen.pixels[WIDTH_H + w + (HEIGHT_H + h) * WIDTH]	= colour;
		}
}

int					main()
{
	t_sdl			sdl;
	t_rt			rt;
	SDL_Event		e;

	sdl_init(&sdl);
	rt_init(&rt);
	while (sdl.running)
	{
		create_screen(&sdl.screen, &sdl);
		raytrace(rt, sdl);
		SDL_UnlockTexture(sdl.screen.texture);
		SDL_RenderCopy(sdl.ren, sdl.screen.texture, NULL, NULL);
		SDL_RenderPresent(sdl.ren);
		while (SDL_PollEvent(&e))
			manage_event(e, &sdl);
		manage_keys(&rt, &sdl);
	}
	sdl_quit(&sdl);
	exit(0);
}
