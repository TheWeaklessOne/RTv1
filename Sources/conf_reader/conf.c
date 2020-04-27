/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:09:40 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/21 16:36:22 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static int				open_conf(const char *path)
{
	unsigned long long	len;
	int					ret;

	len = path ? strlen(path) : 0;
	if (!path)
		ft_crash("Bad path provided!\n");
	if (len < 6 || !(path[len - 1] == 'f' && path[len - 2] == 'n' &&
	path[len - 3] == 'o' && path[len - 4] == 'c' && path[len - 5] == '.'))
		ft_crash("You provided not a *.conf file!\n");
	if (check_file(path, IS_E) <= 0)
		ft_crash("No such file - %s!\n", path);
	if ((ret = open(path, O_RDONLY)) < 0)
		ft_crash("Can't open that file - %s!\n", path);
	if (!check_file(path, IS_R))
		ft_crash("Can't read from that file - %s!\n", path);
	if (check_file(path, IS_D))
		ft_crash("It's a directory - %s!\n", path);
	return (ret);
}

static char				**read_from_conf(int fd)
{
	char				**ret;
	char				*str;

	ret = NULL;
	str = NULL;
	while (get_nl(fd, &str) == 1)
		ret = add_to_text(ret, str);
	if (!ret)
		ft_crash("File is empty!\n");
	return (ret);
}

t_list					*get_tasks(int fd)
{
	t_list				*ret;
	char				**conf;
	int					i;

	i = -1;
	ret = NULL;
	conf = read_from_conf(fd);
	while (conf[++i])
	{
		if (str_is_empty(conf[i]))
			continue ;
		ret = list_add_back(ret, create_task(conf, &i));
	}
	while (--i != -1)
		free(conf[i]);
	free(conf);
	return (ret);
}

void					print_tasks(t_list *tasks)
{
	int					count;
	t_task				*task;
	register int		i;

	count = 1;
	while (tasks && (i = -1))
	{
		task = tasks->task;
		printf("Job #%i:\nName - %s\nCommand - %s\nDirectory - %s\nUmask - "
		"%d\nCopies - %d\nStdout - %d\nStderr - %d\nRestart - %d\nRetries - "
		"%d\nOn_start - %d\nStop_signal - %d\nStop_waiting - %d\n"
		"Success_waiting - %d\nEnd_codes: ", count++, task->name, task->command,
		task->directory, task->umask, task->copies, task->tstdout,
		task->tstderr, task->restart, task->retries, task->on_start,
		task->stop_signal, task->stop_waiting, task->success_waiting);
		while (task->end_codes[++i] != -1 && i < END_CODES_N)
			printf("%i%c", task->end_codes[i],
					(task->end_codes[i + 1] != -1) ? ' ' : '\n');
		(task->env) ? printf("Env:\n") : 0;
		if (task->env && (i = -1))
			while (task->env[++i])
				printf("    %s\n", task->env[i]);
		(tasks->next) ? printf("\n") : 0;
		tasks = tasks->next;
	}
}

t_list					*conf_read(const char *path)
{
	int					conf_fd;
	t_list				*task_list;

	conf_fd = open_conf(path);
	task_list = get_tasks(conf_fd);
	if (!task_list)
		ft_crash("No tasks in %s!\n", path);
	return (task_list);
}
