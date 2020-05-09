#include "rt.h"

static t_vec3f		plane_normal(const t_vec3f point, const t_vec3f dir,
									const t_object plane, t_rt rt)
{
	(void)point;
	return (EPSILON < vec3f_dot(dir, plane.normal) ?
			vec3f_scale(plane.normal, -1) :
			plane.normal);
}

static double		plane_intersect(const t_vec3f orig, const t_vec3f dir,
										const t_object plane)
{
	const double	denom = vec3f_dot(plane.normal, dir);

	if (SDL_fabs(denom) > EPSILON)
		return (vec3f_dot(vec3f_sub(plane.center, orig), plane.normal) / denom);
	return (DBL_MAX);
}

t_object			*plane_create(const t_object info)
{
	t_object		*ret;

	ret = ft_malloc(sizeof(t_object));
	ret->color = info.color;
	ret->radius = info.radius;
	ret->center = info.center;
	ret->specular = info.specular;
	ret->normal = info.normal;
	ret->get_normal = &plane_normal;
	ret->intersect = &plane_intersect;
	return (ret);
}