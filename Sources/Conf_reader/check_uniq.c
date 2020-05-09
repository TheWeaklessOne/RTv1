/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_uniq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 15:38:21 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/21 17:24:16 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

int		uck(int p, int uniq[PARAMS_N], int i, char *str)
{
	if (uniq[p])
	{
		fprintf(stderr, "Error at [%d] line:\n%s\n", i + 1, str);
		(p == POSITION) ? ft_crash("Duplicate \"position\" parameter!\n") : 0;
		(p == RADIUS) ? ft_crash("Duplicate \"radius\" parameter!\n") : 0;
		(p == COLOR) ? ft_crash("Duplicate \"color\" parameter!\n") : 0;
		(p == INTENSITY) ? ft_crash("Duplicate \"intensity\" parameter!\n") : 0;
		(p == NORMAL) ? ft_crash("Duplicate \"normal\" parameter!\n") : 0;
		(p == SPECULAR) ? ft_crash("Duplicate \"specular\" parameter!\n") : 0;
	}
	uniq[p] = 1;
	return (1);
}
