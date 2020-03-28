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
	SPHERE = 0
};

typedef struct			s_object
{
	int					type;
	Uint32				color;
	void				*object;
	int					(*intersect)(t_vec3f vec, t_vec3f vec2,
			float *flt, void *vid);
}						t_object;

typedef struct			s_sphere
{
	t_vec3f				center;
	float				radius;
}						t_sphere;

int						sphere_intersect(t_vec3f orig, t_vec3f dir,
			float *t0, void *sphere);

t_object				sphere_create(t_vec3f center, float radius,
			Uint32 color);

#endif
