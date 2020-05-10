/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:03:19 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/10 16:03:19 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_free_split(char **split)
{
	int				i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int					ft_split_size(char **split)
{
	int				ret;

	ret = 0;
	while (split[ret])
		ret++;
	return (ret);
}

int					ft_strcmp(const char *s1, const char *s2)
{
	register int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int					is_double(const char *str)
{
	register int	i;
	char			c;
	int				dot;

	i = -1;
	dot = 0;
	while ((str[0] >= 9 && str[0] <= 13) || str[0] == ' ')
		str++;
	if (str[0] == '+' || str[0] == '-')
		str++;
	while (str[++i])
	{
		c = str[i];
		if (c < '0' || c > '9')
		{
			if (c == '.')
				dot++;
			else
				return (0);
		}
	}
	return (dot < 2);
}

size_t				ft_strlen(const char *str)
{
	register size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
