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
		(p == COMMAND) ? ft_crash("Duplicate \"command\" parameter!\n") : 0;
		(p == DIR) ? ft_crash("Duplicate \"directory\" parameter!\n") : 0;
		(p == UMASK) ? ft_crash("Duplicate \"umask\" parameter!\n") : 0;
		(p == COPIES) ? ft_crash("Duplicate \"copies\" parameter!\n") : 0;
		(p == STDOUT) ? ft_crash("Duplicate \"stdout\" parameter!\n") : 0;
		(p == STDERR) ? ft_crash("Duplicate \"stderr\" parameter!\n") : 0;
		(p == RESTART) ? ft_crash("Duplicate \"restart\" parameter!\n") : 0;
		(p == RETRIES) ? ft_crash("Duplicate \"retries\" parameter!\n") : 0;
		(p == ON_START) ? ft_crash("Duplicate \"on_start\" parameter!\n") : 0;
		(p == STOP_SIGNAL) ? ft_crash("Duplicate \"stop_signal\" "
			"parameter!\n") : 0;
		(p == STOP_WAITING) ? ft_crash("Duplicate \"stop_waiting\" "
			"parameter!\n") : 0;
		(p == SUCCESS_WAITING) ? ft_crash("Duplicate \"success_waiting\" "
			"parameter!\n") : 0;
		(p == END_CODES) ? ft_crash("Duplicate \"end_codes\" parameter!\n") : 0;
		(p == ENV) ? ft_crash("Duplicate \"env\" parameter!\n") : 0;
	}
	uniq[p] = 1;
	return (1);
}
