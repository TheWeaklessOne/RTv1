/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:36:06 by wstygg            #+#    #+#             */
/*   Updated: 2020/03/14 12:36:08 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

Uint32			get_color(t_vec3f orig, t_vec3f dir, t_rt *rt)
{
	Uint32		color;
	int			i;

	i = -1;
	float dst = FLT_MAX; //на сколько понимаю, это дальность полета луча, и ее можно сделать и поменьше
	color = BACKGROUND_C;
	//проходит по всем обьектам, если луч тыкается в какой-то из них, то закрашивает в цвет. Если за все время луч тыкнется в несколько фигур, то будет цвет последнего (а должно быть, чтобы он реагировал в зависимости от координаты  Z
	while (++i < rt->objects_n)
	{
		if (!(rt->objects[i].intersect(orig, dir, &dst, rt->objects[i].object))) //основная фигня, где обращение идет по функции, и поэтому нам плевать, какой конкретно тип будет в объекте, вызовется правильная функция
			continue ;
		color = rt->objects[i].color;
	}
	return (color);
}

void			raytrace(Uint32 *pixels, t_rt *rt)
{
	t_vec3f		camera;
	const int fov = M_PI/2; //так было на сайте, понятия не имею, почему так

	camera = (t_vec3f){.x = 0, .y = 5, .z = 0}; //временная рандомная структура с камерой.
	for (int i = 0; i < SCREEN_HEIGHT; i++)
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			//откуда все это - тоже не понимаю
			float x =  (2*(i + 0.5)/(float)SCREEN_WIDTH  - 1)*tanf(fov/2.)*SCREEN_WIDTH/(float)SCREEN_HEIGHT;
			float y = -(2*(j + 0.5)/(float)SCREEN_HEIGHT - 1)*tanf(fov/2.);
			t_vec3f dir = vec3f_norm((t_vec3f){x, y, -1});
			pixels[j + i * SCREEN_WIDTH] = get_color(camera, dir, rt); //здесь получает цвет для каждого пикселя
		}
}

int				main()
{
	t_sdl		sdl;
	t_rt		rt;
	SDL_Event	e;

	sdl_init(&sdl); //для сдл, не обращай внимания
	rt_init(&rt); //тут должна проходить валидация карты и возвращаться заполненная структура со всеми фигурами, но пока тупа вручную
	raytrace(sdl.screen.pixels, &rt); //тут все и должно происходить
	SDL_UnlockTexture(sdl.screen.texture); //для отображения
	SDL_RenderCopy(sdl.ren, sdl.screen.texture, NULL, NULL); //для отображения
	//основной цикл, который обрабатывает нажатия на кнопки. Пока только эскейп и крестик
	while (sdl.running)
	{
		SDL_RenderPresent(sdl.ren);
                SDL_Delay(200);
		while (SDL_PollEvent(&e))
			manage_event(e, &sdl);
		manage_keys(&sdl);
	}
}
