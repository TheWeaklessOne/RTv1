#include "rt.h"

static double		calc_shine(const t_vec3f normal, const t_vec3f vec_l,
								const double intensity)
{
	double			n_dot_l;

	n_dot_l = vec3f_dot(normal, vec_l);
	if (n_dot_l > 0)
		return (intensity * n_dot_l / (vec3f_length(normal) *
				vec3f_length(vec_l)));
	return (0);
}

static double		calc_specular(const double specular, const double intensity,
									const t_tvec tvec, const t_vec3f vec_l)
{
	t_vec3f			vec_r;
	double			r_dot_v;

	if (specular)
	{
		vec_r = vec3f_sub(vec3f_scale(tvec.normal, 2 *
			vec3f_dot(tvec.normal, vec_l)), vec_l);
		r_dot_v = vec3f_dot(vec_r, tvec.view);
		if (r_dot_v > 0)
			return (intensity * SDL_pow(r_dot_v / (vec3f_length(vec_r) *
						vec3f_length(tvec.view)), specular));
	}
	return (0);
}

static double		get_intensity(const t_tvec tvec, const t_light light,
									const double specular, const t_rt rt)
{
	t_vec3f			vec_l;
	double			z_max;
	double			intensity;

	intensity = 0;
	if (light.type == POINT)
	{
		vec_l = vec3f_sub(light.pos, tvec.point);
		z_max = 1.0;
	}
	else
	{
		vec_l = light.pos;
		z_max = DBL_MAX;
	}
	if (get_object((t_data){tvec.point, vec_l, EPSILON, z_max}, NULL, rt))
		return (0);
	intensity += calc_shine(tvec.normal, vec_l, light.intensity);
	intensity += calc_specular(specular, light.intensity, tvec, vec_l);
	return (intensity);
}

static double		compute_light(const t_tvec tvec, const double specular,
									const t_rt rt)
{
	double			intensity;
	t_list			*lights;
	t_light			*light;

	intensity = 0;
	lights = rt.lights;
	while (lights)
	{
		light = lights->content;
		if (light->type == AMBIENT)
			intensity += light->intensity;
		else
			intensity += get_intensity(tvec, *light, specular, rt);
		lights = lights->next;
	}
	return (intensity);
}


t_vec3f				trace_ray(const t_data data, t_rt rt)
{
	t_object		*object;
	double			closest_t;
	t_tvec			tvec;

	object = get_object(data, &closest_t, rt);
	if (!object)
		return (BACKGROUND_C);
	rt.closest_t = closest_t;
	tvec.point = vec3f_add(rt.camera, vec3f_scale(data.dir, closest_t));
	tvec.normal = vec3f_norm(object->get_normal(tvec.point, data.dir, *object, rt));
	tvec.view = vec3f_scale(data.dir, -1);
	return (vec3f_scale(object->color, compute_light(tvec, object->specular, rt)));
}
