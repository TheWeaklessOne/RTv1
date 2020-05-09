/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:29:54 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/07 15:29:54 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static int			ft_nb_words(const char *str, const char *symbols)
{
	register int	i;
	register int	sym;
	register int	count;

	i = 0;
	sym = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (!ft_strchr(symbols, str[i]) && (sym = 1))
			i++;
		if (ft_strchr(symbols, str[i]))
		{
			count += (sym == 1) ? 1 : 0;
			sym = 0;
			i++;
		}
	}
	return (count);
}

static int			ft_ln_w(const char *str, const char *symbols)
{
	register int	i;

	i = 0;
	while (!ft_strchr(symbols, str[i]))
		i++;
	return (i);
}

char				**ft_split(char *str, char *symbols)
{
	register int	i;
	register int	j;
	register int	k;
	char			**res;

	i = 0;
	j = 0;
	res = ft_malloc(sizeof(char*) * (ft_nb_words(str, symbols) + 1));
	while (str[i])
	{
		while (str[i] && ft_strchr(symbols, str[i]))
			i++;
		if (str[i])
		{
			k = 0;
			res[j] = ft_malloc(sizeof(char) * ft_ln_w(str + i, symbols) + 1);
			while (str[i] && !(ft_strchr(symbols, str[i])))
				res[j][k++] = str[i++];
			j++;
		}
	}
	return (res);
}
