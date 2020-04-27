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

int					create_copies(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"copies\" keyword!"
		"\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content "
		"after \"copies\" keyword!\n", i + 1, conf);
	if ((ret = ft_atoi(split[1])) <= 0)
		ft_crash("Error at [%d] line:\n%s\nCopies count have to be positive "
		"non-zero integer number!\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}

int					create_success_waiting(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"success_waiting\""
		" keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content "
		"after \"success_waiting\" keyword!\n", i + 1, conf);
	ret = ft_atoi(split[1]);
	if (ret < 0)
		ft_crash("Error at [%d] line:\n%s\nSuccess_waiting have to be positive"
		" integer number!\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}

char				*create_directory(char *conf, int i)
{
	char			*ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"directory\" "
		"keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content "
		"after \"directory\" keyword!\n", i + 1, conf);
	if (!(ret = strdup(split[1])))
		ft_crash("Strdup malloc error!\n");
	ft_free_split(split);
	return (ret);
}

char				*create_command(char *conf, int i)
{
	char			*ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"command\" "
		"keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content"
		" after \"command\" keyword!\n", i + 1, conf);
	if (!(ret = strdup(split[1])))
		ft_crash("Strdup malloc error!\n");
	ft_free_split(split);
	return (ret);
}

char				*create_name(char *conf, int i)
{
	char			*ret;
	const size_t	len = strlen(conf);

	if (tab_count(conf) != 0)
		ft_crash("Error at [%d] line: %s\nJob name field must have zero "
		"tab depth!\n", i + 1, conf);
	if (conf[len - 1] != ':')
		ft_crash("Error at [%d] line: %s\nJob name field must ends with "
		"':' symbol!\n", i + 1, conf);
	ret = ft_malloc(len);
	ret = strncpy(ret, conf, len - 1);
	return (ret);
}
