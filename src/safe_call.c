//
// Created by Hugor Chau on 10/1/20.
//

#include "../includes/rtv1.h"

#define ERROR			"\033[38;2;200;0;30m"
#define EOC				"\033[38;2;0m"

void	quit_program(t_data *data)
{
	ft_memdel((void **)&data->sdl);
	exit(0);
}

int		safe_call_int(int res, char *message, t_data *data)
{
	if (res == 0)
		return (res);
	ft_putstr_fd(ERROR, 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd(EOC, 2);
	quit_program(data);
	exit(0);
}

void	*safe_call_ptr(void *res, char *message, t_data *data)
{
	if (res != NULL)
		return (res);
	ft_putstr_fd(ERROR, 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd(EOC, 2);
	quit_program(data);
	exit(0);
}
