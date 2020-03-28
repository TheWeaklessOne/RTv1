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

float		vec3f_dtr(float nb)
{
	return (nb * (float)(M_PI / 180));
}

float		vec3f_length2(const t_vec3f vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
