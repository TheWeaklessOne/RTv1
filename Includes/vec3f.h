/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:41:36 by wstygg            #+#    #+#             */
/*   Updated: 2020/03/16 21:41:37 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_VEC3F_H
# define RTV1_VEC3F_H

# include <math.h>

typedef struct	s_vec3f
{
	float		x;
	float		y;
	float		z;
}				t_vec3f;

float			vec3f_dtr(float nb);
float			vec3f_length(t_vec3f vec);
float			vec3f_length2(t_vec3f vec);
float			vec3f_scalar(t_vec3f a, t_vec3f b);

t_vec3f			vec3f_norm(t_vec3f vec);
t_vec3f			vec3f_add(t_vec3f a, t_vec3f b);
t_vec3f			vec3f_sub(t_vec3f a, t_vec3f b);
t_vec3f			vec3f_rot(t_vec3f a, t_vec3f b);
t_vec3f			vec3f_rot_x(t_vec3f vec, float nb);
t_vec3f			vec3f_rot_y(t_vec3f vec, float nb);
t_vec3f			vec3f_rot_z(t_vec3f vec, float nb);
t_vec3f			vec3f_scale(t_vec3f vec, float scale);

#endif
