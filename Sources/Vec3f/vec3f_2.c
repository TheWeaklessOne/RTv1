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
#include "rt.h"

t_vec3f		vec3f_rot_x(const t_vec3f vec, const double nb)
{
	t_vec3f	ret;

	ret.x = vec.x;
	ret.y = vec.y * SDL_cos(nb) - vec.z * SDL_sin(nb);
	ret.z = vec.y * SDL_sin(nb) + vec.z * SDL_cos(nb);
	return (ret);
}

t_vec3f		vec3f_rot_y(const t_vec3f vec, const double nb)
{
	t_vec3f	ret;

	ret.x = vec.x * SDL_cos(nb) + vec.z * SDL_sin(nb);
	ret.y = vec.y;
	ret.z = vec.z * SDL_cos(nb) - vec.x * SDL_sin(nb);
	return (ret);
}

t_vec3f		vec3f_rot_z(const t_vec3f vec, const double nb)
{
	t_vec3f	ret;

	ret.x = vec.x * SDL_cos(nb) - vec.y * SDL_sin(nb);
	ret.y = vec.x * SDL_sin(nb) + vec.y * SDL_cos(nb);
	ret.z = vec.z;
	return (ret);
}

t_vec3f		vec3f_rot(t_vec3f a, const t_vec3f b)
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
