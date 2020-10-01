#ifndef RTV1_H
# define RTV1_H
#include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../SDL/include/SDL.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# define SCREEN_WIDTH	600
# define SCREEN_HEIGHT	500
# define WIN_TITLE "HAIL TO THE KING"

/*
**		structs declarations
*/

typedef struct s_data		t_data;
typedef struct s_fonts		t_fonts;
typedef struct s_texture	t_texture;
typedef struct s_layers		t_layers;
typedef struct s_sdl		t_sdl;
typedef struct s_test		t_test;

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_event_type
{
	KEY_UP = FALSE,
	KEY_DOWN = TRUE
}				t_event_type;

typedef enum	e_keycode
{
	LEFT_ARROW,
	RIGHT_ARROW,
	TOP_ARROW,
	DOWN_ARROW,
	CONTROL,
	SHIFT,
	ENTER,
	ESCAPE,
	MAX_KEYCODE = 256
}				t_keycode;

struct			s_fonts
{
	int				pref;
};

struct			s_texture
{
	uint32_t		width;
	uint32_t		height;
	uint32_t		*bit_map;
	char			*text_name;
};

struct			s_layers
{
	t_texture		*main_frame;
};

struct			s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Rect		*rect;
	t_layers		*layers;
	SDL_Texture		*target_texture;
	SDL_Surface		*surf;
	SDL_Texture		*tex;
	int				indian;
	uint32_t		*color_buffer;
	int				key_pressed[MAX_KEYCODE];
};

struct			s_test
{
	void			(*condition)(t_data *data);
};

struct			s_data
{
	t_sdl			*sdl;
	void			(*condition)(t_data *);
	t_test			*test;
};

/*
**		error management
*/

int				safe_call_int(int res, char *message, t_data *data);
void			*safe_call_ptr(void *res, char *message, t_data *data);
void			quit_program(t_data *data);

/*
**		memory management
*/
void			init_sdl(t_data *data, char *name);
void			remove_sdl(t_sdl **remove);
void			init_sdl_layers(t_data *data);
void			remove_layers(t_layers **layers);

/*
**		main functions
*/

void			main_loop(t_data *data);

/*
**		test function (I want you to read this, because it's basic
**		sdl-management)
*/

void	test_colors(t_data *data);
int		test_entry_point();

# endif
