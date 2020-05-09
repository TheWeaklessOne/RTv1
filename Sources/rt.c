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
	rt->lights = NULL;
	rt->objects = NULL;
	rt->z_min = DEFAULT_Z_MIN;
	rt->z_max = DEFAULT_Z_MAX;
	rt->camera = VEC3F_NULL;
	rt->rotation = VEC3F_NULL;
	conf_read("rt.conf", &rt->lights, &rt->objects);
}
