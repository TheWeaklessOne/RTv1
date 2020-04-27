/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:52:19 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/09 17:28:18 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static char			*read_content(char *content, int i)
{
	char			*ret;
	char			**split;

	split = ft_strsplit(content);
	if (split[0][strlen(split[0]) - 1] != ':')
		ft_crash("Error at [%d] line:\n%s\n"
		"\':\' symbol have to be in the end of %s!", i + 1, content, split[0]);
	split[0][strlen(split[0]) - 1] = '\0';
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after "
		"\"%s\"!\n", i + 1, content, split[0]);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content"
		" after \"%s\"!\n", i + 1, content, split[0]);
	ret = ft_strjoin(ft_strjoin(split[0], " = ", 0), split[1], 1);
	ft_free_split(split);
	return (ret);
}

static int			count_content(char **conf, int i)
{
	int				ret;

	ret = 0;
	while (tab_count(conf[i++]) == 2)
		ret++;
	return (ret);
}

void				create_env(t_task *task, char **conf, int *i)
{
	char			**split;
	char			**env;
	register int	k;

	split = ft_strsplit(conf[*i]);
	if (ft_split_size(split) != 1)
		ft_crash("Error at [%d] line:\n%s\nContent for env should have 2 tab"
		" depth!\n", *i + 1, conf[*i]);
	k = -1;
	(*i)++;
	env = ft_malloc(sizeof(char*) * (count_content(conf, *i) + 1));
	while (tab_count(conf[*i]) > 1)
	{
		if (tab_count(conf[*i]) > 2)
			ft_crash("Error at [%d] line:\n%s\nContent for env should have 2"
			" tab depth!\n", *i + 1, conf[*i]);
		env[++k] = read_content(conf[*i], *i);
		(*i)++;
	}
	if (!env[0])
		ft_crash("Env content not provided!\n");
	task->env = env;
	(*i)--;
	ft_free_split(split);
}
