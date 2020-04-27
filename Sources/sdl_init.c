#include "rt.h"

static void			keys_init(int keys[SDL_NUM_SCANCODES])
{
	register int	i;

	i = -1;
	while (++i < SDL_NUM_SCANCODES)
		keys[i] = 0;
}

static void			create_screen(t_screen *screen, t_sdl *sdl)
{
	screen->texture = SDL_CreateTexture(sdl->ren,
	SDL_GetWindowPixelFormat(sdl->win), SDL_TEXTUREACCESS_STREAMING,
	WIDTH, HEIGHT);
	SDL_LockTexture(screen->texture, NULL, (void*)&screen->pixels,
		&screen->pitch);
}

void				sdl_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (ft_error(SDL_GetError()));
	if (!(sdl->win = SDL_CreateWindow("SimpleText", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		return (ft_error(SDL_GetError()));
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1, SDL_RENDERER_ACCELERATED)))
		return (ft_error(SDL_GetError()));
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		return (ft_error(SDL_GetError()));
	create_screen(&sdl->screen, sdl);
	keys_init(sdl->keys);
	sdl->running = 1;
}
