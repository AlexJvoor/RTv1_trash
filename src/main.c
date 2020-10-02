/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 23:33:37 by jvoor             #+#    #+#             */
/*   Updated: 2020/10/02 17:56:11 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// double ft_map_inline(double x, double in_start, double in_end, double out_start, double out_end)
// {
//     return (fabs((x - in_start) / (in_end - in_start)) * ((out_end - out_start)) + out_start);
// }

// double ft_map(double x, double in_start, double in_end, double out_start, double out_end)
// {
//     double x_tmp;

//     x_tmp = x - in_start;
//     x_tmp /= (in_end - in_start);
//     x_tmp *= (out_end - out_start);
//     x_tmp += out_start;

//     return (x_tmp);
// }


// void		file_read()
// {
	
// }

void esc_exit(int kw)
{
	if (kw == 53)
	{
		exit(0);
	}
}

int			main()
{
	int			bpp;
	int			sl;
	int			endn;

    void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 1000, 1000, "RTv1");
	void *img = mlx_new_image(mlx, 1000, 1000);
	int *data = (int *)mlx_get_data_addr(img, &bpp, &sl, &endn);

	mlx_key_hook(win, esc_exit, NULL);
	mlx_loop(mlx);
        
    // double x = ft_map_inline(-7, 10, 1, 20, -20);

    // printf("%lf\n", x);

    return (0);
}