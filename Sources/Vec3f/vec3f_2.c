/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:48:07 by wstygg            #+#    #+#             */
/*   Updated: 2020/03/15 12:48:08 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3f.h"

t_vec3f		vec3f_rot_x(const t_vec3f vec, float nb)
{
	t_vec3f	ret;

	ret.x = vec.x;
	ret.y = vec.y * cosf(nb) - vec.z * sinf(nb);
	ret.z = vec.y * sinf(nb) + vec.z * cosf(nb);
	return (ret);
}

t_vec3f		vec3f_rot_y(const t_vec3f vec, float nb)
{
	t_vec3f	ret;

	ret.x = vec.x * cosf(nb) + vec.z * sinf(nb);
	ret.y = vec.y;
	ret.z = vec.z * cosf(nb) - vec.x * sinf(nb);
	return (ret);
}

t_vec3f		vec3f_rot_z(const t_vec3f vec, float nb)
{
	t_vec3f	ret;

	ret.x = vec.x * cosf(nb) - vec.y * sinf(nb);
	ret.y = vec.x * sinf(nb) + vec.y * cosf(nb);
	ret.z = vec.z;
	return (ret);
}

t_vec3f		vec3f_rot(t_vec3f a, t_vec3f b)
{
	a = vec3f_rot_x(a, vec3f_dtr(b.x));
	a = vec3f_rot_y(a, vec3f_dtr(b.y));
	a = vec3f_rot_z(a, vec3f_dtr(b.z));
	return (a);
}

t_vec3f		vec3f_sub(t_vec3f a, const t_vec3f b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}
