/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:08:52 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/10 15:40:47 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

t_vec3f				create_rotation(char *conf, int i)
{
	int				k;
	int				len;
	double			nb[3];
	char			**split;

	split = ft_split(conf, " \t,");
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"rotation\""
				" keyword!\n", i + 1, conf);
	k = 0;
	if ((len = ft_split_size(split)) != 4)
		ft_crash("Error at [%d] line:\n%s\nIn content of \"rotation\" have to "
				"be a 3 numbers for x, y and z respectively!\n", i + 1, conf);
	while (++k < len)
	{
		if (!is_double(split[k]))
			ft_crash("Error at [%d] line:\n%s\n\"rotation\" content have to be"
				" integer or floating number!\n", i + 1, conf);
		nb[k - 1] = SDL_atof(split[k]);
	}
	ft_free_split(split);
	return ((t_vec3f){-nb[1], nb[0], nb[2]});
}

double				create_radius(char *conf, int i)
{
	double			nb;
	char			**split;

	split = ft_split(conf, " \t,");
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"radius\" "
			"keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content"
			" after \"radius\" keyword!\n", i + 1, conf);
	if (!is_double(split[1]) || (nb = SDL_atof(split[1])) <= 0.0)
		ft_crash("Error at [%d] line:\n%s\n\"radius\" content have to be"
			" non-zero positive integer or floating number\n", i + 1, conf);
	ft_free_split(split);
	return (nb);
}
