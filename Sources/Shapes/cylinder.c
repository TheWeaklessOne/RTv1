#include "rt.h"

static t_vec3f		cylinder_normal(const t_vec3f point, const t_vec3f dir,
								   const t_object cylinder, t_rt rt)
{
	return (vec3f_sub(vec3f_sub(point, cylinder.center),
			vec3f_scale(cylinder.normal, vec3f_dot(dir, cylinder.normal)
			* rt.closest_t + vec3f_dot(rt.camera, cylinder.normal))));
}


static double		cylinder_intersect(const t_vec3f orig, const t_vec3f dir,
									 const t_object cylinder)
{
	double		t1;
	double		t2;
	double		k[3];
	double		discriminant;
	t_vec3f		oc;

	oc = vec3f_sub(orig, cylinder.center);
	k[0] = vec3f_dot(dir, dir) - SDL_pow(vec3f_dot(dir, cylinder.normal), 2);
	k[1] = 2 * (vec3f_dot(oc, dir) - vec3f_dot(oc, cylinder.normal) * vec3f_dot(dir, cylinder.normal));
	k[2] = vec3f_dot(oc, oc) - SDL_pow(vec3f_dot(oc, cylinder.normal), 2.0) - cylinder.radius * cylinder.radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0)
		return (DBL_MAX);
	t1 = (-k[1] + SDL_sqrt(discriminant)) / (2 * k[0]);
	t2 = (-k[1] - SDL_sqrt(discriminant)) / (2 * k[0]);
	if (t1 > EPSILON && t2 > EPSILON)
		return (t1 <= t2 ? t1 : t2);
	if (t1 > EPSILON ||  t2 > EPSILON)
		return (t1 <= t2 ? t2 : t1);
	return (DBL_MAX);
}

t_object			*cylinder_create(const t_object info)
{
	t_object		*ret;

	ret = ft_malloc(sizeof(t_object));
	ret->color = info.color;
	ret->radius = info.radius;
	ret->center = info.center;
	ret->specular = info.specular;
	ret->normal = vec3f_norm(info.normal);
	ret->get_normal = &cylinder_normal;
	ret->intersect = &cylinder_intersect;
	return (ret);
}
