/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:30:38 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/07 15:30:38 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

char				*skip_emptiness(char *str)
{
	register int	i;

	i = -1;
	while (str[++i])
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			break ;
	return (str + i);
}

char				**add_to_text(char **text, char *add)
{
	register size_t	len;
	register size_t	i;
	char			**ret;

	len = 0;
	i = 0;
	if (text)
		while (text[len])
			len++;
	ret = ft_malloc(sizeof(char*) * (len + 2));
	while (i < len)
	{
		ret[i] = text[i];
		i++;
	}
	ret[i] = add;
	ret[i + 1] = NULL;
	text ? free(text) : NULL;
	return (ret);
}

int					tab_count(const char *str)
{
	int				count;
	int				spaces;
	register int	i;

	count = 0;
	spaces = 0;
	i = -1;
	while (str && str[++i])
	{
		if (str[i] == '\t')
			count++;
		else if (str[i] == ' ')
		{
			if (spaces == TAB_SIZE - 1)
			{
				spaces = 0;
				count++;
			}
			else
				spaces++;
		}
		else
			break ;
	}
	return (count);
}
