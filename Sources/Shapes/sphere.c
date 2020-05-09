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

static t_vec3f	sphere_normal(const t_vec3f point, const t_vec3f dir,
								const t_object sphere, t_rt rt)
{
	(void)dir;
	return (vec3f_sub(point, sphere.center));
}

static double	sphere_intersect(const t_vec3f orig, const t_vec3f dir,
									const t_object sphere)
{
	double		t1;
	double		t2;
	double		k[3];
	double		discriminant;
	t_vec3f		oc;

	oc = vec3f_sub(orig, sphere.center);
	k[0] = vec3f_dot(dir, dir);
	k[1] = 2 * vec3f_dot(oc, dir);
	k[2] = vec3f_dot(oc, oc) - sphere.radius * sphere.radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0)
		return (DBL_MAX);
	t1 = (-k[1] + SDL_sqrt(discriminant)) / (2 * k[0]);
	t2 = (-k[1] - SDL_sqrt(discriminant)) / (2 * k[0]);
	if (t1 > EPSILON && t2 > EPSILON)
		return (t1 <= t2 ? t1 : t2);
	if (t1 > EPSILON ||  t2 > EPSILON)
		return (t1 <= t2 ? t2 : t1);
	return (DBL_MAX);
}

t_object		*sphere_create(const t_object info)
{
	t_object	*ret;

	ret = ft_malloc(sizeof(t_object));
	ret->color = info.color;
	ret->radius = info.radius;
	ret->center = info.center;
	ret->specular = info.specular;
	ret->normal = vec3f_norm(info.normal);
	ret->get_normal = &sphere_normal;
	ret->intersect = &sphere_intersect;
	return (ret);
}
