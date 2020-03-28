/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:48:00 by wstygg            #+#    #+#             */
/*   Updated: 2020/03/15 12:48:04 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3f.h"

float		vec3f_scalar(const t_vec3f a, const t_vec3f b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float		vec3f_length(const t_vec3f vec)
{
	return (sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec3f		vec3f_scale(t_vec3f vec, const float scale)
{
	vec.x *= scale;
	vec.y *= scale;
	vec.z *= scale;
	return (vec);
}

t_vec3f		vec3f_norm(const t_vec3f vec)
{
	return (vec3f_scale(vec, 1 / vec3f_length(vec)));
}

t_vec3f		vec3f_add(t_vec3f a, t_vec3f b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}
