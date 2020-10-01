//
// Created by Hugor Chau on 10/1/20.
//

#include "../includes/rtv1.h"

/*
**		I guess it would be an entry point of renderer
*/

void	raytracer(t_data *data)
{

}

/*
**
*/

void	init_data(t_data *data)
{
	init_sdl(data, WIN_TITLE);
	data->condition = &raytracer;
	data->test = safe_call_ptr(ft_memalloc(sizeof(t_test)), "Malloc crashed: "
															"file \"src/main.c\", function \"init_data\".", data);
	data->test->condition = &test_colors;
}

/*
**	it was my main, cause I didn't see
**	your commit till today's morning :D
*/

int		test_entry_point()
{
	t_data	data;

	init_data(&data);
	main_loop(&data);
}
