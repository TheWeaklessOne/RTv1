/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 14:59:16 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/10 15:53:56 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static void			fill_camera(char **conf, const int *i, t_rt *rt,
								int uniq[PARAMS_N])
{
	char			*str;

	str = skip_emptiness(conf[*i]);
	if (tab_count(conf[*i]) != 1)
		ft_crash("Error at [%d] line:\n%s\nThere have to be 1 tab depth before "
			"camera's keyword!\n", *i + 1, conf[*i]);
	if (!ft_strchr(str, ':'))
		ft_crash("Error at [%d] line: %s\nCamera's keyword have to be followed"
			"by ':' symbol!\n", *i + 1, conf[*i]);
	if (!ft_strncmp(str, "position:", 9) && uck(POSITION, uniq, *i, conf[*i]))
		rt->camera = create_pos(conf[*i], *i);
	else if (!ft_strncmp(str, "rotation:", 9) &&
				uck(ROTATION, uniq, *i, conf[*i]))
		rt->rotation = create_rotation(conf[*i], *i);
	else
		ft_crash("Error at [%d] line: %s\nUnknown camera's keyword!\n",
					*i + 1, conf[*i]);
}

void				create_camera(char **conf, int *i, t_rt *rt)
{
	int				k;
	int				params_uniq[PARAMS_N];

	k = -1;
	while (++k < PARAMS_N)
		params_uniq[k] = 0;
	while (tab_count(conf[++(*i)]) != 0)
		fill_camera(conf, i, rt, params_uniq);
	(*i)--;
}
