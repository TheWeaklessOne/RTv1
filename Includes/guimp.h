/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:45:01 by wstygg            #+#    #+#             */
/*   Updated: 2020/02/09 16:45:01 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_GUIMP_H
# define GUIMP_GUIMP_H

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>

# include <unistd.h>
# include <stdlib.h>

# include "struct.h"

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Renderer		*ren;
	int					running;
	int					width;
	int					height;
}						t_sdl;

void					sdl_init(t_sdl *sdl);
void					sdl_quit(t_sdl *sdl);

int						ft_strlen(const char *src);
void					ft_putstr(char const *str, int new_str);
void					ft_error(const char *error);
#endif
