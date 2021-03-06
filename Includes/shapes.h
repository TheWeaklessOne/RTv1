/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:41:41 by wstygg            #+#    #+#             */
/*   Updated: 2020/03/16 21:41:42 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "vec3f.h"

enum					e_objects
{
	CONE = 0,
	PLANE,
	SPHERE,
	CYLINDER,
	OBJECTS_N
};

typedef struct s_rt		t_rt;

typedef struct			s_object
{
	t_vec3f				color;
	t_vec3f				normal;
	double				radius;
	t_vec3f				center;
	double				specular;
	t_vec3f				(*get_normal)(t_vec3f point, t_vec3f dir,
							struct s_object obj, t_rt rt);
	double				(*intersect)(t_vec3f orig, t_vec3f dir,
							struct s_object obj);
}						t_object;

t_object				*cone_create(t_object info);
t_object				*plane_create(t_object info);
t_object				*sphere_create(t_object info);
t_object				*cylinder_create(t_object info);

#endif
