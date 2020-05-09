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


static void		list_delete(t_list **list_p)
{
	t_list		*lst;
	t_list		*to_del;

	lst = *list_p;
	while (lst)
	{
		to_del = lst;
		lst = lst->next;
		free(to_del->content);
		to_del->content = NULL;
		free(to_del);
		to_del = NULL;
	}
	*list_p = NULL;
}

void			conf_reload(const char *path, t_list **lights_p,
								t_list **objects_p)
{
	list_delete(lights_p);
	list_delete(objects_p);
	conf_read(path, lights_p, objects_p);
}
