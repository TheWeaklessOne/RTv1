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

	ret.x = (double)x * WIDTH / HEIGHT / WIDTH;
	ret.y = -(double)y * 1 / HEIGHT;
	ret.z = 1;
	return (ret);
}

static double		compute_light(t_vec3f point, t_vec3f normal, t_vec3f view, double specular, const t_rt rt)
{
	double			intensity;
	t_list			*lights;
	t_light			*light;
	t_vec3f			vec_l;
	t_vec3f			vec_r;
	double			n_dot_l;
	double			r_dot_v;
	const double	length_n = vec3f_length(normal);
	const double	length_v = vec3f_length(view);

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
			n_dot_l = vec3f_dot(normal, vec_l);
			if (n_dot_l > 0)
				intensity += light->intensity * n_dot_l / (length_n * vec3f_length(vec_l));
			if (specular)
			{
				vec_r = vec3f_sub(vec3f_scale(normal, 2 * vec3f_dot(normal, vec_l)), vec_l);
				r_dot_v = vec3f_dot(vec_r, view);
				if (r_dot_v > 0)
					intensity += light->intensity * SDL_pow(r_dot_v / (vec3f_length(vec_r) * length_v), specular);
			}
		}
		lights = lights->next;
	}
	return (intensity);
}

static t_vec3f		add_light(const t_vec3f dir, const double t_min,
								const t_object obj, const t_rt rt)
{
	t_vec3f			point;
	t_vec3f			normal;
	t_vec3f			view;
	double			light;

	point = vec3f_add(rt.camera, vec3f_scale(dir, t_min));
	normal = vec3f_sub(point, obj.center);
	normal = vec3f_norm(normal);

	view = vec3f_scale(dir, -1);
	light = compute_light(point, normal, view, obj.specular, rt);
	return (vec3f_scale(obj.color, light));
}


unsigned int		clamp(double nb)
{
	if (nb > 255)
		return (255);
	if (nb < 0)
		return (0);
	return ((unsigned int)nb);
}

static t_vec3f		get_colour(const t_vec3f dir, const t_rt rt)
{
	register int	i;
	double			t_min;
	t_object		*to_draw;
	double			inter;

	to_draw = NULL;
	t_min = FLT_MAX;
	i = -1;
	while (++i < rt.objects_n)
	{
		inter = rt.objects[i].intersect(rt.camera, dir, rt.objects[i]);
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

void				pixel_put(int w, int h, t_vec3f rgb, Uint32 *pixels)
{
	Uint32			color;

	color = ((clamp(rgb.x) << 16) + (clamp(rgb.y) << 8) + clamp(rgb.z));
	pixels[WIDTH_H + w + (HEIGHT_H + h) * WIDTH] = color;
}

void				raytrace(t_rt rt, t_sdl sdl)
{
	register int	w;
	register int	h;
	t_vec3f			direction;
	t_vec3f 		colour;

	h = -HEIGHT_H -1;
	while (++h < HEIGHT_H && (w = -WIDTH_H - 1))
		while (++w < WIDTH_H)
		{
			direction = canvas_to_viewport(w, h);
			colour = get_colour(direction, rt);
			pixel_put(w, h, colour, sdl.screen.pixels);
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
