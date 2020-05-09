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


//t_list			*conf_reload(const char *path, t_list *old_tasks)
//{
//	t_list		*new_tasks;
//	t_list		*new_tasks_t;
//	t_list		*old_tasks_t;
//
//	new_tasks = conf_read(path);
//	new_tasks_t = new_tasks;
//	while (new_tasks_t)
//	{
//		old_tasks_t = old_tasks;
//		while (old_tasks_t)
//		{
//			if (!strcmp(old_tasks_t->task->name, new_tasks_t->task->name))
//			{
//				new_tasks_t->task->remake = compare_tasks(old_tasks_t->task,
//					new_tasks_t->task);
//			}
//			old_tasks_t = old_tasks_t->next;
//		}
//		new_tasks_t = new_tasks_t->next;
//	}
//	task_list_delete(old_tasks);
//	return (new_tasks);
//}
