/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:05:29 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/21 16:54:57 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

t_vec3f				create_normal(char *conf, int i)
{
	int				k;
	int				len;
	double			nb[3];
	char			**split;

	split = ft_split(conf, " \t,");
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"normal\""
				 " keyword!\n", i + 1, conf);
	k = 0;
	if ((len = ft_split_size(split)) != 4)
		ft_crash("Error at [%d] line:\n%s\nIn content of \"normal\" have to be a 3"
				 " numbers for x, y and z respectively!\n", i + 1, conf);
	while (++k < len)
	{
		if (!is_double(split[k]))
			ft_crash("Error at [%d] line:\n%s\n\"normal\" content have to be"
					 " integer or floating number!\n", i + 1, conf);
		nb[k - 1] = SDL_atof(split[k]);
	}
	ft_free_split(split);
	return ((t_vec3f){nb[0], nb[1], nb[2]});
}

t_vec3f				create_color(char *conf, int i)
{
	int				k;
	int				len;
	double			nb[3];
	char			**split;

	split = ft_split(conf, " \t,");
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"color\""
				 " keyword!\n", i + 1, conf);
	k = 0;
	if ((len = ft_split_size(split)) != 4)
		ft_crash("Error at [%d] line:\n%s\nIn content of \"color\' have to be a 3"
				 " numbers for r, g and b respectively!\n", i + 1, conf);
	while (++k < len)
	{
		if (!is_double(split[k]) || SDL_atof(split[k]) < 0.0 ||
				SDL_atof(split[k]) > 255.0)
			ft_crash("Error at [%d] line:\n%s\n\"color\" content have to be"
					 " integer or floating number between 0 and 255!\n", i + 1, conf);
		nb[k - 1] = SDL_atof(split[k]);
	}
	ft_free_split(split);
	return ((t_vec3f){nb[0], nb[1], nb[2]});
}

t_vec3f				create_pos(char *conf, int i)
{
	int				k;
	int				len;
	double			nb[3];
	char			**split;

	split = ft_split(conf, " \t,");
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"position\""
				 " keyword!\n", i + 1, conf);
	k = 0;
	if ((len = ft_split_size(split)) != 4)
		ft_crash("Error at [%d] line:\n%s\nIn content of \"position\" have to be a 3"
					" numbers for x, y and z respectively!\n", i + 1, conf);
	while (++k < len)
	{
		if (!is_double(split[k]))
			ft_crash("Error at [%d] line:\n%s\n\"position\" content have to be"
						" integer or floating number!\n", i + 1, conf);
		nb[k - 1] = SDL_atof(split[k]);
	}
	ft_free_split(split);
	return ((t_vec3f){nb[0], nb[1], nb[2]});
}

double				create_specular(char *conf, int i)
{
	double			nb;
	char			**split;

	split = ft_split(conf, " \t,");
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"specular\" "
				 "keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content"
				 " after \"specular\" keyword!\n", i + 1, conf);
	if (!is_double(split[1]) || (nb = SDL_atof(split[1])) < 0.0)
		ft_crash("Error at [%d] line:\n%s\n\"specular\" content have to be"
				 " zero or positive integer or floating number\n", i + 1, conf);
	ft_free_split(split);
	return (nb);
}

double				create_intensity(char *conf, int i)
{
	double			nb;
	char			**split;

	split = ft_split(conf, " \t,");
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"intensity\" "
		"keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content"
		" after \"intensity\" keyword!\n", i + 1, conf);
	if (!is_double(split[1]) || (nb = SDL_atof(split[1])) < 0.0)
		ft_crash("Error at [%d] line:\n%s\n\"intensity\" content have to be"
				 " positive non-zero integer or floating number\n", i + 1, conf);
	ft_free_split(split);
	return (nb);
}
