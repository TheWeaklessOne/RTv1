/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_dtr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:47:55 by wstygg            #+#    #+#             */
/*   Updated: 2020/03/16 21:47:56 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3f.h"
#include "math.h"

int			vec3f_equal(const t_vec3f v1, const t_vec3f v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

double		vec3f_dtr(double nb)
{
	return (nb * (M_PI / 180));
}
