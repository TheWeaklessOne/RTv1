#include "rt.h"

t_object			*get_object(const t_data data, double *closest_p, const t_rt rt)
{
	t_object		*ret;
	t_object		*object;
	double			answ;
	t_list			*objects;
	double			closest_t;

	ret = NULL;
	closest_t = DBL_MAX;
	objects = rt.objects;
	while (objects)
	{
		object = objects->content;
		answ = object->intersect(data.orig, data.dir, *object);
		if (answ < closest_t && data.z_min < answ && answ < data.z_max)
		{
			closest_t = answ;
			ret = object;
		}
		objects = objects->next;
	}
	if (closest_p)
		*closest_p = closest_t;
	return (ret);
}
