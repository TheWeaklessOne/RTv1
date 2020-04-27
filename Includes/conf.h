/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:30:10 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/21 16:31:37 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONF_H
# define CONF_H

# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "structures.h"
# include "list.h"

# define IS_E		0
# define IS_R		1
# define IS_W		2
# define IS_X		4
# define IS_D		8

# define TAB_SIZE	4

char				*create_name(char *conf, int i);
char				*create_command(char *conf, int i);
char				*create_directory(char *conf, int i);
int					create_umask(char *conf, int i);
int					create_copies(char *conf, int i);
int					create_stdout(char *conf, int i);
int					create_stderr(char *conf, int i);
int					create_restart(char *conf, int i);
int					create_retries(char *conf, int i);
int					create_on_start(char *conf, int i);
int					create_stop_signal(char *conf, int i);
int					create_stop_waiting(char *conf, int i);
int					create_success_waiting(char *conf, int i);
void				create_end_codes(int codes[END_CODES_N],
						char *conf, int i);
void				create_env(t_task *task, char **conf, int *i);
t_task				*create_task(char **conf, int *i_p);

int					check_file(const char *file, unsigned check);
int					uck(int p, int uniq[PARAMS_N],
								  int i, char *str);
int					tab_count(const char *str);
char				*skip_emptiness(char *str);
char				**add_to_text(char **text, char *add);

int					get_nl(int fd, char **line);
int					str_is_empty(const char *str);
void				ft_crash(const char *msg, ...);
void				*ft_malloc(size_t size);
int					ft_split_size(char **split);
void				ft_free_split(char **split);
char				**ft_strsplit(char *str);
int					ft_atoi(const char *str);
char				*ft_strjoin(const char *str, const char *str2,
						int to_free);

void				conf_help(void);
void				task_delete(t_task **task_p);
void				print_tasks(t_list *task_list);
void				task_list_delete(t_list *task_list);
t_list				*conf_read(const char *path);
t_list				*conf_reload(const char *path, t_list *old_tasks);

#endif
