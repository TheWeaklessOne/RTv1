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

#if defined(unix) || defined(__unix__) || defined(__unix)
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
#else
# include <SDL.h>
# include <SDL_image.h>
#endif

# include "shapes.h"

# define WIDTH			2048
# define HEIGHT			864
# define WIDTH_H		(WIDTH / 2)
# define HEIGHT_H		(HEIGHT / 2)

# define BACKGROUND_C	0x656565

typedef struct			s_screen
{
	SDL_Texture			*texture;
	Uint32				*pixels;
	int					pitch;
}						t_screen;

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Renderer		*ren;
	int					running;
	t_screen			screen;
	int					keys[SDL_NUM_SCANCODES];
}						t_sdl;


typedef struct			s_rt
{
	float				z_min;
	float				z_max;
	t_vec3f				camera;
	t_object			*objects;
	int					objects_n;
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
