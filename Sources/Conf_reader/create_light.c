/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:40:09 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/21 17:24:58 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static t_light	*check_light_by_type(t_light *light, const int line)
{
	if (light->intensity == UNDEFINED)
		ft_crash("Light at [%d] line error: you did not"
				 " defined light intensity!\n", line);
	if (light->type != AMBIENT)
	{
		if (vec3f_equal(light->pos, UNDEFINED_V))
			ft_crash("Light at [%d] line error: you did not"
					 " defined light position!\n", line);
	}
	return (light);
}

static void		fill_light(char **conf, const int *i, t_light *light,
							 int uniq[PARAMS_N])
{
	char		*str;

	str = skip_emptiness(conf[*i]);
	if (tab_count(conf[*i]) != 1)
		ft_crash("Error at [%d] line:\n%s\nThere have to be 1 tab depth before "
					"light's keyword!\n", *i + 1, conf[*i]);
	if (!strchr(str, ':'))
		ft_crash("Error at [%d] line: %s\nLight's keyword have to be followed"
					"by ':' symbol!\n", *i + 1, conf);
	if (!strncmp(str, "position:", 9) && uck(POSITION, uniq, *i, conf[*i]))
		light->pos = create_pos(conf[*i], *i);
	else if (!strncmp(str, "intensity:", 10) &&
				uck(INTENSITY, uniq, *i, conf[*i]))
		light->intensity = create_intensity(conf[*i], *i);
	else
		ft_crash("Error at [%d] line: %s\nUnknown light's keyword!\n",
				 *i + 1, conf[*i]);
}

static int			check_light_type(const char *conf, const int i)
{
	const size_t	len = strlen(conf);

	if (tab_count(conf) != 0)
		ft_crash("Error at [%d] line: %s\nLight type field must have zero "
				 "tab depth!\n", i + 1, conf);
	if (conf[len - 1] != ':')
		ft_crash("Error at [%d] line: %s\nLight type field must ends with "
				 "':' symbol!\n", i + 1, conf);
	if (!ft_strcmp(conf, "point_light:"))
		return (POINT);
	if (!ft_strcmp(conf, "ambient_light:"))
		return (AMBIENT);
	if (!ft_strcmp(conf, "directional_light:"))
		return (DIRECTIONAL);
	ft_crash("Error at [%d] line: %s\nUnknown light type!\n", i + 1, conf);
}

t_light				*create_light(char **conf, int *i)
{
	int				k;
	int				line;
	t_light			*light;
	int				params_uniq[PARAMS_N];

	k = -1;
	while (++k < PARAMS_N)
		params_uniq[k] = 0;
	light = ft_malloc(sizeof(t_light));
	*light = (t_light)
	{
		.pos = UNDEFINED_V, .intensity = UNDEFINED
	};
	light->type = check_light_type(conf[*i], *i);
	line = *i;
	while (tab_count(conf[++(*i)]) != 0)
		fill_light(conf, i, light, params_uniq);
	(*i)--;
	return (check_light_by_type(light, line + 1));
}
