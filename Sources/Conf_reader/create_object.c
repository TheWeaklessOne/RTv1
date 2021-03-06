/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:56:02 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/10 15:57:14 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static void			fill_info(char **conf, const int *i, t_object *info,
								int uniq[PARAMS_N])
{
	char			*str;

	str = skip_emptiness(conf[*i]);
	if (tab_count(conf[*i]) != 1)
		ft_crash("Error at [%d] line:\n%s\nThere have to be 1 tab depth before "
					"object's keyword!\n", *i + 1, conf[*i]);
	if (!ft_strchr(str, ':'))
		ft_crash("Error at [%d] line: %s\nObject's keyword have to be followed"
					"by ':' symbol!\n", *i + 1, conf[*i]);
	if (!ft_strncmp(str, "position:", 9) && uck(POSITION, uniq, *i, conf[*i]))
		info->center = create_pos(conf[*i], *i);
	else if (!ft_strncmp(str, "color:", 6) && uck(COLOR, uniq, *i, conf[*i]))
		info->color = create_color(conf[*i], *i);
	else if (!ft_strncmp(str, "specular:", 9) &&
			uck(SPECULAR, uniq, *i, conf[*i]))
		info->specular = create_specular(conf[*i], *i);
	else if (!ft_strncmp(str, "normal:", 7) && uck(NORMAL, uniq, *i, conf[*i]))
		info->normal = create_normal(conf[*i], *i);
	else if (!ft_strncmp(str, "radius:", 7) && uck(RADIUS, uniq, *i, conf[*i]))
		info->radius = create_radius(conf[*i], *i);
	else
		ft_crash("Error at [%d] line: %s\nUnknown object's keyword!\n",
					*i + 1, conf[*i]);
}

static int			check_object_type(const char *conf, const int i)
{
	const size_t	len = ft_strlen(conf);

	if (tab_count(conf) != 0)
		ft_crash("Error at [%d] line: %s\nObject type field must have zero "
					"tab depth!\n", i + 1, conf);
	if (conf[len - 1] != ':')
		ft_crash("Error at [%d] line: %s\nObject type field must ends with "
					"':' symbol!\n", i + 1, conf);
	if (!ft_strcmp(conf, "cone:"))
		return (CONE);
	if (!ft_strcmp(conf, "plane:"))
		return (PLANE);
	if (!ft_strcmp(conf, "sphere:"))
		return (SPHERE);
	if (!ft_strcmp(conf, "cylinder:"))
		return (CYLINDER);
	ft_crash("Error at [%d] line: %s\nUnknown object type!\n", i + 1, conf);
}

t_object			*create_object(char **conf, int *i)
{
	int				k;
	int				type;
	int				line;
	t_object		info;
	int				params_uniq[PARAMS_N];

	k = -1;
	while (++k < PARAMS_N)
		params_uniq[k] = 0;
	info = (t_object)
	{
		.color = (t_vec3f){42, 42, 42}, .radius = UNDEFINED,
		.center = UNDEFINED_V, .specular = 0,
		.normal = UNDEFINED_V
	};
	type = check_object_type(conf[*i], *i);
	line = *i;
	while (tab_count(conf[++(*i)]) != 0)
		fill_info(conf, i, &info, params_uniq);
	(*i)--;
	return (check_object_by_type(type, info, line + 1));
}
