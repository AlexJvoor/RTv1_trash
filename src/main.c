/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 23:33:37 by jvoor             #+#    #+#             */
/*   Updated: 2020/10/05 20:26:43 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			esc_exit(int kw)
{
	if (kw == 53)
	{
		exit(0);
	}
}

t_mlx				init_mlx()
{
	t_mlx		mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "RTv1");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.data = (int *)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.endn);

	return(mlx);
}

t_cam			init_cam()
{
	t_cam		cam;
	
	cam.pos = vec3(0, 0, 0);
	cam.dir = vec3(1, 0, 0);
	cam.deg = vec3(0, 0, 1);

	return(cam);
}

t_plane			init_plane()
{
	t_plane		plane;
	
	plane.coords = vec3(20, 20, 20);
	plane.norm	= vec3(0, 0, 1);
}

// void			draw_plane(t_plane plane, int *img)
// {
	
// }

int				main()
{
	int i = 0;
	t_plane		plane = init_plane();
	t_mlx		mlx = init_mlx();
	t_cam 		cam = init_cam();
	
	while (i++ < 1000000)
	{
		mlx.data[i] = 0xFFFF00;
	}
	// draw_plane(plane, mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_key_hook(mlx.win, esc_exit, NULL);
	mlx_loop(mlx.mlx);

    return (0);
}
