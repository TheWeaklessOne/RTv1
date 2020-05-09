/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:08:52 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/21 17:01:31 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

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
