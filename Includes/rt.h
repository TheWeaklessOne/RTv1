/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:36:19 by wstygg            #+#    #+#             */
/*   Updated: 2020/03/14 12:36:20 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_RT_H
# define RTV1_RT_H

# include <float.h>
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

# if defined(unix) || defined(__unix__) || defined(__unix)
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_image.h>
# else
#  include <SDL.h>
#  include <SDL_image.h>
# endif

# include "list.h"
# include "shapes.h"

# define WIDTH			512
# define HEIGHT			512
# define WIDTH_H		(WIDTH / 2)
# define HEIGHT_H		(HEIGHT / 2)
# define WIDTH_HEIGHT	(WIDTH * HEIGHT)

# define DEFAULT_Z_MIN	0.0001
# define DEFAULT_Z_MAX	DBL_MAX

# define EPSILON		0.001

# define VEC3F_NULL		(t_vec3f){.x = 0, .y = 0, .z = 0}
# define BACKGROUND_C	(t_vec3f){.x = 65, .y = 65, .z = 65}

enum					e_light_types
{
	POINT = 0,
	AMBIENT,
	DIRECTIONAL
};

typedef struct			s_light
{
	t_vec3f				pos;
	int					type;
	double				intensity;
}						t_light;

typedef struct			s_screen
{
	int					pitch;
	Uint32				*pixels;
	SDL_Texture			*texture;
}						t_screen;

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Renderer		*ren;
	t_screen			screen;
	int					running;
	int					keys[SDL_NUM_SCANCODES];
}						t_sdl;

typedef struct			s_rt
{
	double				z_min;
	double				z_max;
	t_vec3f				camera;
	t_list				*lights;
	t_list				*objects;
	t_vec3f				rotation;
}						t_rt;

typedef struct			s_tvec
{
	t_vec3f				point;
	t_vec3f				normal;
	t_vec3f				view;
}						t_tvec;

typedef struct			s_data
{
	const t_vec3f		orig;
	const t_vec3f		dir;
	const double		z_min;
	const double		z_max;
}						t_data;

void					sdl_init(t_sdl *sdl);
void					manage_event(SDL_Event e, t_sdl *sdl, char *path, t_rt *rt);
void					manage_keys(t_rt *rt, t_sdl *sdl);
void					sdl_quit(t_sdl *sdl);

void					rt_init(int argc, char **argv, t_rt *rt);

void					create_screen(t_screen *screen, t_sdl *sdl);

t_vec3f					trace_ray(t_data data, t_rt rt);
t_object				*get_object(t_data data, double *closest_p, t_rt rt);

int						ft_strcmp(const char *s1, const char *s2);
void					*ft_malloc(size_t size);
int						is_double(const char *str);

void					conf_help(void);
void					conf_read(const char *path, t_list **lights_p, t_list **objects_p);
void					conf_reload(const char *path, t_list **lights_p, t_list **objects_p);

#endif
