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

t_object			*get_object(const t_data data, double *closest_p, t_rt rt)
{
	t_object		*ret;
	t_object		*object;
	double			answ[2];
	t_list			*objects;
	double			closest_t;

	ret = NULL;
	closest_t = DBL_MAX;
	objects = rt.objects;
	while (objects)
	{
		object = objects->content;
		object->intersect(data.orig, data.dir, *object, answ);
		if (answ[0] < closest_t && data.z_min < answ[0] && answ[0] < data.z_max)
		{
			closest_t = answ[0];
			ret = object;
		}
		if (answ[1] < closest_t && data.z_min < answ[1] && answ[1] < data.z_max)
		{
			closest_t = answ[1];
			ret = object;
		}
		objects = objects->next;
	}
	if (closest_p)
		*closest_p = closest_t;
	return (ret);
}

static double		calc_spelular(const t_tvec tvec, const double intensity, const double length_v, const double specular)
{
	const t_vec3f	vec_r = vec3f_sub(vec3f_scale(tvec.normal, 2 * vec3f_dot(tvec.normal, tvec.point)), tvec.point);
	const double	r_dot_v = vec3f_dot(vec_r, tvec.view);

	if (r_dot_v > 0)
		 return (intensity * SDL_pow(r_dot_v / (vec3f_length(vec_r) * length_v), specular));
	return (0);
}

static double		compute_light(const t_tvec tvec, double specular, const t_rt rt)
{
	double			intensity;
	t_list			*lights;
	t_light			*light;
	t_vec3f			vec_l;
	t_vec3f			vec_r;
	double			n_dot_l;
	double			r_dot_v;
	const double	length_n = vec3f_length(tvec.normal);
	const double	length_v = vec3f_length(tvec.view);
	double			t_max;

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
			{
				vec_l = vec3f_sub(light->pos, tvec.point);
				t_max = 1.0;
			}
			else
			{
				vec_l = light->pos;
				t_max = DBL_MAX;
			}
			if (get_object((t_data){tvec.point, vec_l, 0.001, t_max}, NULL, rt))
			{
				lights = lights->next;
				continue ;
			}
			n_dot_l = vec3f_dot(tvec.normal, vec_l);
			if (n_dot_l > 0)
				intensity += light->intensity * n_dot_l / (length_n * vec3f_length(vec_l));
			if (specular)
			{
				vec_r = vec3f_sub(vec3f_scale(tvec.normal, 2 * vec3f_dot(tvec.normal, vec_l)), vec_l);
				r_dot_v = vec3f_dot(vec_r, tvec.view);
				if (r_dot_v > 0)
					intensity += light->intensity * SDL_pow(r_dot_v / (vec3f_length(vec_r) * length_v), specular);
			}
		}
		lights = lights->next;
	}
	return (intensity);
}


static unsigned		clamp(double nb)
{
	if (nb > 255)
		return (255);
	if (nb < 0)
		return (0);
	return ((unsigned int)nb);
}

static t_vec3f		get_colour(const t_data data, const t_rt rt)
{
	t_object		*object;
	double			closest_t;
	t_tvec			tvec;

	object = get_object(data, &closest_t, rt);
	if (!object)
		return (BACKGROUND_C);
	tvec.point = vec3f_add(rt.camera, vec3f_scale(data.dir, closest_t));
	tvec.normal = vec3f_norm(vec3f_sub(tvec.point, object->center));
	tvec.view = vec3f_scale(data.dir, -1);
	return (vec3f_scale(object->color, compute_light(tvec, object->specular, rt)));
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
			direction = vec3f_rot(canvas_to_viewport(w, h), rt.rotation);
			colour = get_colour((t_data){rt.camera, direction, rt.z_min, rt.z_max}, rt);
			pixel_put(w, h, colour, sdl.screen.pixels);
		}
}

int					main()
{
	t_sdl			sdl;
	t_rt			rt;
	SDL_Event		e;

	rt_init(&rt);
	sdl_init(&sdl);
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
