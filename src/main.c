/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 23:33:37 by jvoor             #+#    #+#             */
/*   Updated: 2020/10/02 13:13:57 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
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


int main()
{
    double x = ft_map_inline(-7, 10, 1, 20, -20);

    printf("%lf\n", x);

    return (0);
}