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
# include <float.h>

# if defined(unix) || defined(__unix__) || defined(__unix)
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_image.h>
# else
#  include <SDL.h>
#  include <SDL_image.h>
# endif

# include "conf.h"
# include "list.h"
# include "shapes.h"
# include "structures.h"

# define WIDTH			600
# define HEIGHT			600
# define WIDTH_H		(WIDTH / 2)
# define HEIGHT_H		(HEIGHT / 2)

# define DEFAULT_Z_MIN	1.0f
# define DEFAULT_Z_MAX	FLT_MAX

# define VEC3F_NULL		(t_vec3f){.x = 0, .y = 0, .z = 0}
# define BACKGROUND_C	(t_vec3f){.x = 65, .y = 65, .z = 65}

void					sdl_init(t_sdl *sdl);
void					manage_event(SDL_Event e, t_sdl *sdl);
void					manage_keys(t_rt *rt, t_sdl *sdl);
void					sdl_quit(t_sdl *sdl);

void					rt_init(t_rt *rt);

void					create_screen(t_screen *screen, t_sdl *sdl);

size_t					ft_strlen(const char *str);
void					*ft_malloc(size_t size);

#endif
