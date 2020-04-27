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

int					create_on_start(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"on_start\" "
		"keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content "
		"after \"on_start\" keyword!\n", i + 1, conf);
	ret = ft_atoi(split[1]);
	if (ret != 0 && ret != 1)
		ft_crash("Error at [%d] line:\n%s\nOn_start flag have to be 1(true) or"
		" 0(false)!\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}

int					create_restart(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"restart\" "
		"keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content"
		" after \"restart\" keyword!\n", i + 1, conf);
	ret = ft_atoi(split[1]);
	if (ret < 0 || ret > 2)
		ft_crash("Error at [%d] line:\n%s\nRestart flag have to be a value"
		" between"
		"0 and 2 inclusive!\n    0 - Never\n    1 - Always\n    2 - On"
		" crash\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}

int					create_retries(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"retries\""
		" keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one "
		"content after \"retries\" keyword!\n", i + 1, conf);
	if ((ret = ft_atoi(split[1])) < 0)
		ft_crash("Error at [%d] line:\n%s\nRetries have to be positive"
		" integer number!\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}

int					create_stdout(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"stdout\""
		" keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one"
		" content after \"stdout\" keyword!\n", i + 1, conf);
	ret = ft_atoi(split[1]);
	if (ret < 0 || ret > 9)
		ft_crash("Error at [%d] line:\n%s\nStdout have to be "
		"positive integer"
		"number between 0 and 9 inclusive!\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}

int					create_stderr(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"stderr\""
		" keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one "
		"content after \"stderr\" keyword!\n", i + 1, conf);
	ret = ft_atoi(split[1]);
	if (ret < 0 || ret > 9)
		ft_crash("Error at [%d] line:\n%s\nStderr have to be "
		"positive integer"
		"number between 0 and 9 inclusive!\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}
