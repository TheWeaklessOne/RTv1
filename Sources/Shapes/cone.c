#include "rt.h"


static t_vec3f		cone_normal(const t_vec3f point, const t_vec3f dir,
									  const t_object cone, t_rt rt)
{
	return (vec3f_sub(vec3f_sub(point, cone.center), vec3f_scale(vec3f_scale(cone.normal,
			1.0 + SDL_pow(SDL_tan(cone.radius / 2.0), 2.0)), vec3f_dot(dir, cone.normal) *
			rt.closest_t + vec3f_dot(vec3f_sub(rt.camera, cone.center), cone.normal))));
}

static double		cone_intersect(const t_vec3f orig, const t_vec3f dir,
										const t_object cone)
{
	double		t1;
	double		t2;
	double		k[3];
	double		discriminant;
	t_vec3f		oc;
	const double	p = 1 + SDL_pow(SDL_tan(cone.radius / 2.0), 2.0);

	oc = vec3f_sub(orig, cone.center);
	k[0] = vec3f_dot(dir, dir) - p * SDL_pow(vec3f_dot(dir, cone.normal), 2.0);
	k[1] = 2 * (vec3f_dot(dir, oc) - p * vec3f_dot(dir, cone.normal) * vec3f_dot(oc, cone.normal));
	k[2] = vec3f_dot(oc, oc) - p * SDL_pow(vec3f_dot(oc, cone.normal), 2.0);
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

t_object			*cone_create(const t_object info)
{
	t_object		*ret;

	ret = ft_malloc(sizeof(t_object));
	ret->color = info.color;
	ret->radius = info.radius;
	ret->center = info.center;
	ret->specular = info.specular;
	ret->normal = vec3f_norm(info.normal);
	ret->get_normal = &cone_normal;
	ret->intersect = &cone_intersect;
	return (ret);
}
