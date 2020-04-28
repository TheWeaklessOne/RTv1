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
	t_sphere *sphere;

	sphere = ft_malloc(sizeof(t_sphere));
	sphere->center = center;
	sphere->radius = radius;
	ret.type = SPHERE;
	ret.color = color;
	ret.object = sphere;
	ret.specular = specular;
	ret.intersect = &sphere_intersect;
	return (ret);
}

double			sphere_intersect(t_vec3f orig, t_vec3f dir, void *sphere_p)
{
	double		k[3];
	double		ret[2];
	double		discriminant;
	t_vec3f		oc;
	t_sphere	sphere;

	sphere = *((t_sphere*)sphere_p);
	oc = vec3f_sub(orig, sphere.center);
	k[0] = vec3f_dot(dir, dir);
	k[1] = 2 * vec3f_dot(oc, dir);
	k[2] = vec3f_dot(oc, oc) - sphere.radius * sphere.radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0)
		return (FLT_MAX);
	ret[0] = (-k[1] + SDL_sqrt(discriminant)) / (2 * k[0]);
	ret[1] = (-k[1] - SDL_sqrt(discriminant)) / (2 * k[0]);
	return ((ret[0] < ret[1]) ? ret[0] : ret[1]);
}
