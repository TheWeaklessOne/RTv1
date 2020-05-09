/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:45:06 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/07 17:14:37 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

void		conf_help(void)
{
	printf("Each *.conf file must contain at least one task.\nEach task must"
		" contain \"name\" and \"command\" field.\nShort description of all"
		" keywords:\n"
		"command - what command to use to launch the program.\n"
		"directory - working directory for task. By default - "
		"current directory.\n"
		"umask - umask for task. By default - 022.\n"
		"copies - number of process to start. By default - 1.\n"
		"stdout - where to redirect task's stdout. By default - 1.\n"
		"stderr - where to redirect task's stderr. By default - 2.\n"
		"restart - whether the program should be restarted always(0), never(1),"
		" or on unexpected exits only(2). By default - 2.\n"
		"retries - how many times a restart should be attempted before "
		"aborting. By default - 1.\n"
		"on_start - whether to start this program at launch or not."
		" By default - 1.\nstop_signal - which signal should be used to stop "
		"(i.e. exit gracefully) the program. By default - 2.\n"
		"stop_waiting - how long to wait in seconds after a graceful stop"
		" before killing the program. By default - 5.\n"
		"success_waiting - how long the program should be running in seconds"
		" after it\'s started for it to be considered \"successfully started\"."
		" By default - 10.\n"
		"end_codes - which return codes represent an \"expected\" exit status."
		" By default - 0.\n"
		"env - environment variables to set before launching the program.\n");
}
