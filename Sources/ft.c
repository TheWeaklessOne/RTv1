/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:29:31 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/21 17:09:44 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					*ft_malloc(const size_t size)
{
	char				*ret;
	size_t				i;

	if (!(ret = (char*)malloc(size)))
		ft_crash("Malloc error");
	i = 0;
	while (i < size)
		ret[i++] = 0;
	return ((void*)ret);
}

int						str_is_empty(const char *str)
{
	register size_t		i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

char					*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s != (char)c)
		return (NULL);
	else
		return ((char*)s);
}

void					ft_crash(const char *msg, ...)
{
	va_list				args;

	va_start(args, msg);
	vfprintf(stderr, msg, args);
	va_end(args);
	exit(msg ? msg[0] : 255);
}
