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

static char		*fn_free(char **array, size_t index)
{
	while (index > 0)
	{
		free(array[index]);
		index--;
	}
	free(array);
	return (0);
}

static char		*fn_add_str(char **array, size_t index, char const *s,
							char *pattern)
{
	size_t	i;
	size_t	size;
	char	*tmp;

	size = 0;
	while (s[size] != 0 && !ft_strchr(pattern, s[size]))
		size++;
	tmp = malloc(size + 1);
	if (tmp == 0)
		return (fn_free(array, index));
	array[index] = tmp;
	i = 0;
	while (i < size)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = 0;
	return ((char *)s + size);
}

static size_t	fn_size(char const *s, char *pattern)
{
	size_t	size;

	size = 0;
	while (s[0] != 0)
	{
		if (!ft_strchr(pattern, s[0]))
		{
			while (s[0] != 0 && !ft_strchr(pattern, s[0]))
				s++;
			size++;
		}
		else
			s++;
	}
	return (size);
}

char			**ft_split(char *s, char *pattern)
{
	char	**array;
	size_t	i;

	if (s == 0 || pattern == 0)
		return (0);
	if ((i = fn_size(s, pattern)) + 1 == 0)
		return (0);
	if ((array = malloc((i + 1) * sizeof(char *))) == 0)
		return (0);
	array[i] = 0;
	if (i == 0)
		return (array);
	i = 0;
	while (s[0] != 0)
	{
		if (!ft_strchr(pattern, s[0]))
		{
			if ((s = fn_add_str(array, i, s, pattern)) == 0)
				return (0);
			i++;
		}
		else
			s++;
	}
	return (array);
}
