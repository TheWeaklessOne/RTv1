/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_reload.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:02 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/09 17:20:08 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static int		compare_env(char **a, char **b)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (!a && !b)
		return (0);
	if ((a && !b) || (b && !a))
		return (1);
	while (a[i] && b[i])
	{
		ret += (strcmp(a[i], b[i]) != 0);
		i++;
	}
	if ((a[i] && !b[i]) || (b[i] && !a[i]))
		return (1);
	return (ret);
}

static int		compare_tasks(const t_task *a, const t_task *b)
{
	int			ret;
	int			i;

	ret = 0;
	ret += (strcmp(a->command, b->command) != 0);
	ret += (strcmp(a->directory, b->directory) != 0);
	ret += (a->umask != b->umask);
	ret += (a->copies != b->copies);
	ret += (a->tstdout != b->tstdout);
	ret += (a->tstderr != b->tstderr);
	ret += (a->restart != b->restart);
	ret += (a->retries != b->retries);
	ret += (a->on_start != b->on_start);
	ret += (a->stop_signal != b->stop_signal);
	ret += (a->stop_waiting != b->stop_waiting);
	i = -1;
	while (++i < END_CODES_N && (a->end_codes[i] != -1 ||
			b->end_codes[i] != -1))
		ret += (a->end_codes[i] != b->end_codes[i]);
	ret += compare_env(a->env, b->env);
	return (ret != 0);
}

t_list			*conf_reload(const char *path, t_list *old_tasks)
{
	t_list		*new_tasks;
	t_list		*new_tasks_t;
	t_list		*old_tasks_t;

	new_tasks = conf_read(path);
	new_tasks_t = new_tasks;
	while (new_tasks_t)
	{
		old_tasks_t = old_tasks;
		while (old_tasks_t)
		{
			if (!strcmp(old_tasks_t->task->name, new_tasks_t->task->name))
			{
				new_tasks_t->task->remake = compare_tasks(old_tasks_t->task,
					new_tasks_t->task);
			}
			old_tasks_t = old_tasks_t->next;
		}
		new_tasks_t = new_tasks_t->next;
	}
	task_list_delete(old_tasks);
	return (new_tasks);
}
