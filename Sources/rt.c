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

static t_light	*create_light(int type, double intensity, t_vec3f pos)
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
	rt->objects = NULL;
	rt->z_min = DEFAULT_Z_MIN;
	rt->z_max = DEFAULT_Z_MAX;
	rt->camera = VEC3F_NULL;
	rt->rotation = VEC3F_NULL;
//	rt->lights = list_add_back(rt->lights, create_light(AMBIENT, 0.2, VEC3F_NULL));
	rt->lights = list_add_back(rt->lights, create_light(POINT, 1, (t_vec3f){0, 10, 0}));
//	rt->lights = list_add_back(rt->lights, create_light(DIRECTIONAL, 0.2, (t_vec3f){1, 4, 4}));
	rt->objects = list_add_back(rt->objects, sphere_create((t_vec3f){0, -1, 7}, 1, (t_vec3f){148, 65, 196}, 500));
	rt->objects = list_add_back(rt->objects, sphere_create((t_vec3f){2, 0, 8}, 1, (t_vec3f){105, 156, 250}, 500));
	rt->objects = list_add_back(rt->objects, sphere_create((t_vec3f){-2, 0, 8}, 1, (t_vec3f){89, 237, 59}, 10));
	rt->objects = list_add_back(rt->objects, plane_create((t_vec3f){0, -2, 0}, 0, (t_vec3f){194, 110, 110}, (t_vec3f){0, 0, 0}, 400));
}
