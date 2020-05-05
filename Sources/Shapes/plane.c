#include "rt.h"

t_object		*plane_create(t_vec3f center, double radius, t_vec3f color, t_vec3f rot, double specular)
{
	t_object	*ret;

	ret = ft_malloc(sizeof(t_object));
	ret->type = PLANE;
	ret->color = color;
	ret->radius = radius;
	ret->center = center;
	ret->specular = specular;
	ret->intersect = &plane_intersect;
	ret->view = vec3f_rot((t_vec3f){0, 1, 0}, rot);
	return (ret);
}

void			plane_intersect(t_vec3f orig, t_vec3f dir, t_object plane, double answ[2])
{
	double		t;
	double		a;
	double		b;

	answ[1] = DBL_MAX;
	a = vec3f_dot(vec3f_sub(orig, plane.center), plane.view);
	b = vec3f_dot(dir, plane.view);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
	{
		answ[0] = DBL_MAX;
		return ;
	}
	t = -a / b;
	if (t > 0)
		answ[0] = t;
	else
		answ[0] = DBL_MAX;
}