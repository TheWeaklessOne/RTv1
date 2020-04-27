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

void			rt_init(t_rt *rt)
{
	rt->z_min = 1;
	rt->z_max = FLT_MAX;
	rt->camera = (t_vec3f){0, 0, 0};
	rt->objects_n = 3;
	rt->objects = ft_malloc(sizeof(t_object) * rt->objects_n);
	rt->objects[0] = sphere_create((t_vec3f){0, 1, 3}, 1, 0x69DB9D);
	rt->objects[1] = sphere_create((t_vec3f){2, 0, 4}, 1, 0x6bb7e3);
	rt->objects[2] = sphere_create((t_vec3f){-2, 0, 4}, 1, 0xf2a35e);
}
