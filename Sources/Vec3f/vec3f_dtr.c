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

double		vec3f_dtr(double nb)
{
	return (nb * (M_PI / 180));
}

double		vec3f_length2(const t_vec3f vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
