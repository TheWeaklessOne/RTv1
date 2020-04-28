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
	t_vec3f				color;
	double				radius;
	t_vec3f				center;
	double				specular;
	double				(*intersect)(t_vec3f orig, t_vec3f dir, struct s_object obj);
}						t_object;

double					sphere_intersect(t_vec3f orig, t_vec3f dir, t_object sphere);

t_object				sphere_create(t_vec3f center, double radius,
			t_vec3f color, double specular);

#endif
