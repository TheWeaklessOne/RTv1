/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:40:09 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/07 14:02:45 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

int					create_umask(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"umask\" "
		"keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content "
		"after \"umask\" keyword!\n", i + 1, conf);
	if ((ret = ft_atoi(split[1])) < 0)
		ft_crash("Error at [%d] line:\n%s\nUmask have to be positive integer"
		" number!\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}

void				create_end_codes(int codes[END_CODES_N], char *conf, int i)
{
	int				nb;
	int				len;
	register int	k;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"end_codes\""
		" keyword!\n", i + 1, conf);
	k = 0;
	len = ft_split_size(split);
	while (++k < len)
	{
		nb = ft_atoi(split[k]);
		if (nb < 0 || nb > 255)
			ft_crash("Error at [%d] line:\n%s\nEach end_code have to be positi"
			"ve integer number between 0 and 255 inclusive!\n", i + 1, conf);
		if (k >= END_CODES_N)
			ft_crash("Error at [%d] line:\n%s\nLimit for end_codes is exceeded"
			"! Maximum number of exit codes is %d\n", i + 1, conf, END_CODES_N);
		codes[k - 1] = nb;
	}
	ft_free_split(split);
}

int					create_stop_signal(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"stop_signal\" "
		"keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content "
		"after \"stop_signal\" keyword!\n", i + 1, conf);
	ret = ft_atoi(split[1]);
	if (ret <= 0 || ret >= NSIG)
		ft_crash("Error at [%d] line:\n%s\nStop_signal have to be positive "
		"non-zero integer"
		"number between 0 and %d inclusive!\n", i + 1, conf, NSIG - 1);
	ft_free_split(split);
	return (ret);
}

int					create_stop_waiting(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_strsplit(conf);
	if (!split[1])
		ft_crash("Error at [%d] line:\n%s\nNo content after \"stop_waiting\" "
		"keyword!\n", i + 1, conf);
	if (ft_split_size(split) > 2)
		ft_crash("Error at [%d] line:\n%s\nThere have to be only one content "
		"after \"stop_waiting\" keyword!\n", i + 1, conf);
	ret = ft_atoi(split[1]);
	if (ret < 0)
		ft_crash("Error at [%d] line:\n%s\nStop_waiting have to be positive "
		"integer number!\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}
