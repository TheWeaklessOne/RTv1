#include "rt.h"

t_object			*get_object(const t_data data, double *closest_p, const t_rt rt)
{
	t_object		*ret;
	t_object		*object;
	double			answ[2];
	t_list			*objects;
	double			closest_t;

	ret = NULL;
	closest_t = DBL_MAX;
	objects = rt.objects;
	while (objects)
	{
		object = objects->content;
		object->intersect(data.orig, data.dir, *object, answ);
		if (answ[0] < closest_t && data.z_min < answ[0] && answ[0] <
				data.z_max && (ret = object))
			closest_t = answ[0];
		if (answ[1] < closest_t && data.z_min < answ[1] && answ[1] <
				data.z_max && (ret = object))
			closest_t = answ[1];
		objects = objects->next;
	}
	if (closest_p)
		*closest_p = closest_t;
	return (ret);
}
