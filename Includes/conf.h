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

# include "rt.h"

# define IS_E			0
# define IS_R			1
# define IS_W			2
# define IS_X			4
# define IS_D			8

# define TAB_SIZE		4

# define BUFF_SIZE		10

# define UNDEFINED		-1337
# define UNDEFINED_V	(t_vec3f){-2.28, -1.337, -42}

enum					e_restart
{
	NEVER = 0,
	ALWAYS,
	ON_CRASH
};

enum					e_params
{
	POSITION = 0,
	RADIUS,
	COLOR,
	INTENSITY,
	NORMAL,
	SPECULAR,
	PARAMS_N
};

typedef struct		s_get_next_line
{
	char			*lp_cmp;
	char			*lp_prev;
	char			*line;
	size_t			line_count;
	size_t			interval;
	size_t			tmp;
	ssize_t			count;
	char			buffer[BUFF_SIZE];
}					t_get_next_line;

t_light				*create_light(char **conf, int *i);
t_object			*create_object(char **conf, int *i);


t_vec3f				create_pos(char *conf, int i);
t_vec3f				create_color(char *conf, int i);
t_vec3f				create_normal(char *conf, int i);
double				create_radius(char *conf, int i);
double				create_specular(char *conf, int i);
double				create_intensity(char *conf, int i);


int					check_file(const char *file, unsigned check);
int					uck(int p, int uniq[PARAMS_N],
								  int i, char *str);
int					tab_count(const char *str);
char				*skip_emptiness(char *str);
char				**add_to_text(char **text, char *add);

int					get_nl(int fd, char **line);
int					str_is_empty(const char *str);
void				*ft_malloc(size_t size);
int					ft_split_size(char **split);
void				ft_free_split(char **split);
char				**ft_split(char *str, char *charset);
char				*ft_strchr(const char *s, int c);
t_object			*check_object_by_type(int type, t_object info, int line);

#endif
