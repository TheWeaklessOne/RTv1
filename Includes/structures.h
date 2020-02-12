/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:45:12 by wstygg            #+#    #+#             */
/*   Updated: 2020/02/09 16:45:13 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIMP_STRUCTURES_H
# define GUIMP_STRUCTURES_H

# include <SDL.h>

typedef struct			s_size
{
	int					w;
	int					h;
}						t_size;

typedef struct			s_label_rgb
{
	SDL_Point			pos;
	t_size				size;
	struct SDL_Color	rgb;
}						t_label_rgb;

#endif
