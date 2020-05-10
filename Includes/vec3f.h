/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:41:36 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/10 15:46:17 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_VEC3F_H
# define RTV1_VEC3F_H

typedef struct	s_vec3f
{
	double		x;
	double		y;
	double		z;
}				t_vec3f;

double			vec3f_dtr(double nb);
double			vec3f_length(t_vec3f vec);
double			vec3f_dot(t_vec3f a, t_vec3f b);

int				vec3f_equal(t_vec3f v1, t_vec3f v2);

t_vec3f			vec3f_norm(t_vec3f vec);
t_vec3f			vec3f_add(t_vec3f a, t_vec3f b);
t_vec3f			vec3f_sub(t_vec3f a, t_vec3f b);
t_vec3f			vec3f_rot(t_vec3f a, t_vec3f b);
t_vec3f			vec3f_rot_x(t_vec3f vec, double nb);
t_vec3f			vec3f_rot_y(t_vec3f vec, double nb);
t_vec3f			vec3f_rot_z(t_vec3f vec, double nb);
t_vec3f			vec3f_scale(t_vec3f vec, double scale);

#endif
