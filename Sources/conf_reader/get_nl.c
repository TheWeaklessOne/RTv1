/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:30:06 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/21 12:16:37 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static int		fn_free(t_get_next_line *gnl, const int fd, char **lp)
{
	if (gnl->line_count != 0)
		free(gnl->line);
	if (lp[fd] != 0)
	{
		free(lp[fd]);
		lp[fd] = 0;
	}
	return (-1);
}

static int		fn_while(t_get_next_line *gnl)
{
	gnl->interval = gnl->lp_cmp == 0 ? gnl->count : gnl->lp_cmp - gnl->buffer;
	if (gnl->interval == 0 && gnl->line_count != 0)
		return (0);
	gnl->lp_prev = (char *)malloc(gnl->interval + gnl->line_count + 1);
	if (gnl->lp_prev == 0)
	{
		gnl->count = -1;
		return (0);
	}
	if (gnl->interval != 0)
	{
		if (gnl->line_count != 0)
		{
			memcpy(gnl->lp_prev, gnl->line, gnl->line_count);
			free(gnl->line);
		}
		memcpy(gnl->lp_prev + gnl->line_count, gnl->buffer, gnl->interval);
		gnl->line_count += gnl->interval;
	}
	gnl->line = gnl->lp_prev;
	return (1);
}

static int		fn_exit(t_get_next_line *gnl, const int fd, char **line,
					char **lp)
{
	gnl->interval++;
	if (gnl->lp_cmp != 0 && (size_t)gnl->count > gnl->interval)
	{
		gnl->tmp = gnl->count - gnl->interval;
		gnl->lp_cmp = malloc(gnl->tmp + sizeof(size_t));
		if (gnl->lp_cmp == 0)
			return (fn_free(gnl, fd, lp));
		if (lp[fd] != 0)
			free(lp[fd]);
		lp[fd] = gnl->lp_cmp;
		*((size_t *)gnl->lp_cmp) = gnl->tmp;
		gnl->lp_cmp += sizeof(size_t);
		memcpy(gnl->lp_cmp, &gnl->buffer[gnl->interval], gnl->tmp);
	}
	else if (lp[fd] != 0)
	{
		free(lp[fd]);
		lp[fd] = 0;
	}
	gnl->line[gnl->line_count] = 0;
	*line = gnl->line;
	return (1);
}

int				get_nl(const int fd, char **line)
{
	static char			*lp[0x400];
	t_get_next_line		gnl;

	if (line == 0 || (unsigned)fd > 0x400)
		return (-1);
	gnl.line_count = 0;
	if (lp[fd] != 0)
	{
		gnl.count = *((size_t *)lp[fd]);
		memcpy(gnl.buffer, lp[fd] + sizeof(size_t), gnl.count);
	}
	else
		gnl.count = read(fd, gnl.buffer, BUFF_SIZE);
	while (gnl.count > 0)
	{
		gnl.lp_cmp = memchr(gnl.buffer, '\n', gnl.count);
		if (fn_while(&gnl) == 0 || gnl.lp_cmp != 0)
			break ;
		gnl.count = read(fd, gnl.buffer, BUFF_SIZE);
	}
	if (gnl.count < 0)
		return (fn_free(&gnl, fd, lp));
	if (gnl.count == 0 && gnl.line_count == 0)
		return (0);
	return (fn_exit(&gnl, fd, line, lp));
}
