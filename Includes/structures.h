#ifndef RTV1_STRUCTURES_H
# define RTV1_STRUCTURES_H

# include "vec3f.h"
# include "shapes.h"
# include "list.h"


# define BUFF_SIZE		10
# define END_CODES_N	255

enum					e_restart
{
	NEVER = 0,
	ALWAYS,
	ON_CRASH
};

enum					e_params
{
	COMMAND = 0,
	DIR,
	UMASK,
	COPIES,
	STDOUT,
	STDERR,
	RESTART,
	RETRIES,
	ON_START,
	STOP_SIGNAL,
	STOP_WAITING,
	SUCCESS_WAITING,
	END_CODES,
	ENV,
	PARAMS_N
};

typedef struct			s_task
{
	int					remake;
	char				*name;
	char				*command;
	char				*directory;
	int					umask;
	int					copies;
	int					tstdout;
	int 				tstderr;
	int					restart;
	int					retries;
	int					on_start;
	int					stop_signal;
	int					stop_waiting;
	int					success_waiting;
	int					end_codes[END_CODES_N];
	char				**env;
}						t_task;

typedef struct			s_get_next_line
{
	char				*lp_cmp;
	char				*lp_prev;
	char				*line;
	size_t				line_count;
	size_t				interval;
	size_t				tmp;
	ssize_t				count;
	char				buffer[BUFF_SIZE];
}						t_get_next_line;

enum					e_light_types
{
	AMBIENT = 0,
	POINT,
	DIRECTIONAL
};

typedef struct			s_light
{
	int					type;
	float				intensity;
	t_vec3f				pos;
}						t_light;

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
	t_list				*lights;
	float				z_min;
	float				z_max;
	t_vec3f				camera;
	t_object			*objects;
	int					objects_n;
}						t_rt;

#endif
