/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:36:13 by wstygg            #+#    #+#             */
/*   Updated: 2020/03/14 12:36:14 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

void				*ft_malloc(size_t size)
{
	char			*ret;
	register size_t	i;

	if (!(ret = malloc(size)))
		ft_error("Malloc error");
	i = 0;
	while (i < size)
		ret[i++] = 0;
	return (ret);
}

void				ft_error(const char *str)
{
	if (!str)
		exit(1);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(str[0]);
}
