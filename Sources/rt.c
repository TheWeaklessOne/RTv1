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

void			rt_init(const int argc, char **argv, t_rt *rt)
{
	if (argc != 2)
		ft_crash("RTv1 using: ./RTv1 *.conf. Type ./RTv1 -help for more "
					"about *.conf files.\n");
	if (!ft_strcmp(argv[1], "-help"))
	{
		conf_help();
		exit(0);
	}
	rt->lights = NULL;
	rt->objects = NULL;
	rt->z_min = DEFAULT_Z_MIN;
	rt->z_max = DEFAULT_Z_MAX;
	rt->camera = VEC3F_NULL;
	rt->rotation = VEC3F_NULL;
	conf_read(argv[1], &rt->lights, &rt->objects);
}
