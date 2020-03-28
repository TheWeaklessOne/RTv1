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
	rt->objects_n = 6;
	rt->objects = ft_malloc(sizeof(t_object) * 6); //лучше использать везде ft_malloc
	rt->objects[0] = sphere_create((t_vec3f){-3, 0, -16}, 1, 0xa5db48);
	rt->objects[1] = sphere_create((t_vec3f){-3, -3, -16}, 1, 0xa5db48);
	rt->objects[2] = sphere_create((t_vec3f){-4, -1, -14}, 2, 0x3ac5c7);
	rt->objects[3] = sphere_create((t_vec3f){-5, -0.3f, -14}, 0.2f, 0xdba240);
	rt->objects[4] = sphere_create((t_vec3f){-5, -1.7f, -14}, 0.2f, 0xdba240);
	rt->objects[5] = sphere_create((t_vec3f){-3.2f, -0.8f, -13}, 0.6f, 0xb57d16);
}
