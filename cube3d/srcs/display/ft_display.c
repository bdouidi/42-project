/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 19:30:36 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/16 19:00:06 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		closewindow(int keycode, t_data *d)
{
	int x = 0;
	int y = 0;
	if (keycode == 0)
	{
		if (!(d->img = mlx_new_image(d->mlx, 1000, 1000)))
		{
			printf("wow c chaud");
			exit(1);
		}
		d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, &d->endian);
		my_mlx_pixel_put(d, x/2, y/2, 0x0FFFFFF);
		mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
		// mlx_destroy_window(v->mlx, v->win);
		// exit(0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	window(t_data *d)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->res[0], d->res[1], "PAYPAL/BDOUIDI");
	// d->img = mlx_new_image(d->mlx, d->res[0], d->res[1]);
	// d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, &d->endian);
	// while (y < d->res[1] / 2)
	// {
	// 	while (x < d->res[0])
	// 	{
	// 		my_mlx_pixel_put(d, x, y, d->c_color);
	// 		x++;
	// 	}
	// 	y++;
	// 	x = 0;
	// }
	// while (y < d->res[1])
	// {
	// 	while (x < d->res[0])
	// 	{
	// 		my_mlx_pixel_put(d, x, y, d->f_color);
	// 		x++;
	// 	}
	// 	y++;
	// 	x = 0;
	// }
	// mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	mlx_hook(d->win, 2, 1L<<15, closewindow, &d);
	mlx_loop(d->mlx);
}
