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

static char				**read_from_conf(const int fd)
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

void					get_info(const int fd, t_list **lights_p,
									t_list **objects_p)
{
	char				**conf;
	int					i;

	i = -1;
	conf = read_from_conf(fd);
	while (conf[++i])
	{
		if (str_is_empty(conf[i]))
			continue ;
		if (strstr(conf[i], "light"))
			*lights_p = list_add_back(*lights_p, create_light(conf, &i));
		else
			*objects_p = list_add_back(*objects_p, create_object(conf, &i));
	}
	while (--i != -1)
		free(conf[i]);
	free(conf);
}

void					conf_read(const char *path, t_list **lights_p,
									t_list **objects_p)
{
	int					conf_fd;

	conf_fd = open_conf(path);
	get_info(conf_fd, lights_p, objects_p);
	if (!*lights_p && !*objects_p)
		ft_crash("No objects in %s!\n", path);
}
