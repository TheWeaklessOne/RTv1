/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:03:34 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/10 16:03:34 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_test(const char *str, const char *to_find)
{
	int		i;

	i = 0;
	while (str[i] != 0 && to_find[i] != 0)
	{
		if (str[i] != to_find[i])
		{
			return (0);
		}
		i++;
	}
	if (str[i] == 0 && to_find[i] != 0)
	{
		return (0);
	}
	return (1);
}

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;

	if (to_find[0] == 0)
	{
		return ((char*)str);
	}
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == to_find[0])
		{
			if (ft_test((char*)str + i, (char*)to_find) != 0)
			{
				return ((char*)str + i);
			}
		}
		i++;
	}
	return (0);
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	n--;
	while (s1[i] != 0 && s1[i] == s2[i] && i < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		*((char*)dst + i) = *((char*)src + i);
		i++;
	}
	return (dst);
}

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)s + i) == (unsigned char)c)
			return ((void*)s + i);
		i++;
	}
	return (0);
}
