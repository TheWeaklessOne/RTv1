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

# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include <SDL.h>
# include <SDL_image.h>

# include "shapes.h"

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080

# define BACKGROUND_C	0x303030

# define RAY_T_MIN		0.0001f;
# define RAY_T_MAX		MAXFLOAT;

typedef struct			s_screen
{
	SDL_Texture			*texture;
	Uint32				*pixels;
	int					pitch;
}						t_screen;

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Surface			*surf;
	SDL_Renderer		*ren;
	int					running;
	t_screen			screen;
	int					keys[SDL_NUM_SCANCODES];
}						t_sdl;

typedef struct			s_ray
{
	t_vec3f				position;
	t_vec3f				direction;
	float				t_max;
}						t_ray;

typedef struct			s_rt
{
	int					objects_n;
	t_object			*objects;
}						t_rt;

void					sdl_init(t_sdl *sdl);
void					manage_event(SDL_Event e, t_sdl *sdl);
void					manage_keys(t_sdl *sdl);
void					sdl_quit(t_sdl *sdl);

void					rt_init(t_rt *rt);

size_t					ft_strlen(const char *str);
void					*ft_malloc(size_t size);
void					ft_error(const char *error);

#endif
