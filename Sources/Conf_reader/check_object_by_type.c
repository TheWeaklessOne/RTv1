#include "conf.h"

static t_object	*check_cone(const t_object info, const int line)
{
	if (vec3f_equal(info.center, UNDEFINED_V))
		ft_crash("Object at [%d] line error: you did not"
				 " defined cone position(center)!\n", line);
	if (info.radius == UNDEFINED)
		ft_crash("Object at [%d] line error: you did not"
				 " defined cone radius!\n", line);
	if (vec3f_equal(info.normal, UNDEFINED_V))
		ft_crash("Object at [%d] line error: you did not"
				 " defined cone normal!\n", line);
	return (cone_create(info));
}

static t_object	*check_plane(const t_object info, const int line)
{
	if (vec3f_equal(info.center, UNDEFINED_V))
		ft_crash("Object at [%d] line error: you did not"
					" defined plane position!\n", line);
	if (vec3f_equal(info.normal, UNDEFINED_V))
		ft_crash("Object at [%d] line error: you did not"
					" defined plane normal!\n", line);
	return (plane_create(info));
}

static t_object	*check_sphere(const t_object info, const int line)
{
	if (vec3f_equal(info.center, UNDEFINED_V))
		ft_crash("Object at [%d] line error: you did not"
				 " defined sphere position(center)!\n", line);
	if (info.radius == UNDEFINED)
		ft_crash("Object at [%d] line error: you did not"
				 " defined sphere radius!\n", line);
	return (sphere_create(info));
}

static t_object	*check_cylinder(const t_object info, const int line)
{
	if (vec3f_equal(info.center, UNDEFINED_V))
		ft_crash("Object at [%d] line error: you did not"
				 " defined cylinder position(center)!\n", line);
	if (info.radius == UNDEFINED)
		ft_crash("Object at [%d] line error: you did not"
				 " defined cylinder radius!\n", line);
	if (vec3f_equal(info.normal, UNDEFINED_V))
		ft_crash("Object at [%d] line error: you did not"
				 " defined cylinder normal!\n", line);
	return (cylinder_create(info));
}

t_object		*check_object_by_type(const int type, const t_object info,
										const int line)
{
	if (type == CONE)
		return (check_cone(info, line));
	if (type == PLANE)
		return (check_plane(info, line));
	else if (type == SPHERE)
		return (check_sphere(info, line));
	else
		return (check_cylinder(info, line));
}