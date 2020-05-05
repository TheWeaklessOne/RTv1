/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 16:56:26 by wstygg            #+#    #+#             */
/*   Updated: 2020/03/14 16:56:29 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object		sphere_create(t_vec3f center, double radius, t_vec3f color, double specular)
{
	t_object ret;

	ret.type = SPHERE;
	ret.color = color;
	ret.radius = radius;
	ret.center = center;
	ret.specular = specular;
	ret.intersect = &sphere_intersect;
	return (ret);
}

void			sphere_intersect(t_vec3f orig, t_vec3f dir, t_object sphere, double answ[2])
{
	double		k[3];
	double		discriminant;
	t_vec3f		oc;

	oc = vec3f_sub(orig, sphere.center);
	k[0] = vec3f_dot(dir, dir);
	k[1] = 2 * vec3f_dot(oc, dir);
	k[2] = vec3f_dot(oc, oc) - sphere.radius * sphere.radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0)
	{
		answ[0] = DBL_MAX;
		answ[1] = DBL_MAX;
		return ;
	}
	answ[0] = (-k[1] + SDL_sqrt(discriminant)) / (2 * k[0]);
	answ[1] = (-k[1] - SDL_sqrt(discriminant)) / (2 * k[0]);
}
