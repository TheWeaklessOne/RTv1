/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:41:49 by wstygg            #+#    #+#             */
/*   Updated: 2020/03/16 21:41:51 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_light	*create_light(int type, float intensity, t_vec3f pos)
{
	t_light		*light;

	light = ft_malloc(sizeof(t_light));
	light->type = type;
	light->intensity = intensity;
	light->pos = pos;
	return (light);
}

void			rt_init(t_rt *rt)
{
	rt->lights = NULL;
	rt->z_min = DEFAULT_Z_MIN;
	rt->z_max = DEFAULT_Z_MAX;
	rt->camera = (t_vec3f){0, 0, 0};
	rt->objects_n = 4;
	rt->objects = ft_malloc(sizeof(t_object) * rt->objects_n);
	rt->lights = list_add_back(rt->lights, create_light(AMBIENT, 0.2f, VEC3F_NULL));
	rt->lights = list_add_back(rt->lights, create_light(POINT, 0.6f, (t_vec3f){2, 1, 0}));
	rt->lights = list_add_back(rt->lights, create_light(AMBIENT, 0.2f, (t_vec3f){1, 4, 4}));
	rt->objects[0] = sphere_create((t_vec3f){0, -1, 3}, 1, (t_vec3f){108, 224, 117}, 500);
	rt->objects[1] = sphere_create((t_vec3f){2, 0, 4}, 1, (t_vec3f){86, 221, 245}, 500);
	rt->objects[2] = sphere_create((t_vec3f){-2, 0, 4}, 1, (t_vec3f){227, 48, 155}, 10);
	rt->objects[3] = sphere_create((t_vec3f){0, -5001, 0}, 5000, (t_vec3f){207, 203, 123}, 1000);
}
