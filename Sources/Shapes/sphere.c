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

t_object		sphere_create(t_vec3f center, float radius, Uint32 color)
{
	t_object ret;
	t_sphere *sphere;

	sphere = ft_malloc(sizeof(t_sphere));
	sphere->center = center;
	sphere->radius = radius;
	ret.type = SPHERE;
	ret.color = color;
	ret.object = sphere;
	ret.intersect = &sphere_intersect;
	return (ret);
}

//непонятная фигня с сайта
int				sphere_intersect(t_vec3f orig, t_vec3f dir,
		float *t0, void *sphere)
{
	t_vec3f		l;
	float		tca;
	float		d2;
	float		thc;
	float		t1;

	l = vec3f_sub(((t_sphere*)sphere)->center, orig);
	tca = vec3f_scalar(l, dir);
	d2 = vec3f_scalar(l, l) - tca * tca;
	if (d2 > ((t_sphere*)sphere)->radius * ((t_sphere*)sphere)->radius)
		return (0);
	thc = sqrtf(((t_sphere*)sphere)->radius *
			((t_sphere*)sphere)->radius - d2);
	*t0 = tca - thc;
	t1 = tca + thc;
	if (*t0 < 0)
		*t0 = t1;
	if (*t0 < 0)
		return (0);
	return (1);
}
