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

# include "rt.h"
# include "vec3f.h"

enum					e_objects
{
	SPHERE = 0,
	OBJECTS_N
};

typedef struct			s_object
{
	int					type;
	double				specular;
	t_vec3f				color;
	void				*object;
	double				(*intersect)(t_vec3f orig, t_vec3f dir, void *obj);
}						t_object;

typedef struct			s_sphere
{
	t_vec3f				center;
	double				radius;
}						t_sphere;

double					sphere_intersect(t_vec3f orig, t_vec3f dir, void *sph);

t_object				sphere_create(t_vec3f center, double radius,
			t_vec3f color, double specular);

#endif
