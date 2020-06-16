/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 19:30:36 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/16 21:05:56 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		closewindow(int keycode, t_data *d)
{
	int x = 0;
	int y = 0;

	printf("[%p]\n", d->img);
	if (keycode == 0)
	{
		// d->img = mlx_new_image(d->vars.mlx, d->res[0], d->res[1]);
		// d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, &d->endian);
		while (y < d->res[1] / 2)
		{
			while (x < d->res[0])
			{
				my_mlx_pixel_put(d, x, y, 0x0FFFFFF);
				x++;
			}
			y++;
			x = 0;
		}
		while (y < d->res[1])
		{
			while (x < d->res[0])
			{
				my_mlx_pixel_put(d, x, y, 0x000FF00);
				x++;
			}
			y++;
			x = 0;
		}
		// mlx_destroy_image(vars.mlx, d->img);
		mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img, 0, 0);
		// mlx_destroy_window(v.mlx, v.win);
		// exit(1);
		printf("oui\n");
	}
		if (keycode == 1)
	{
		// d->img = mlx_new_image(d->vars.mlx, d->res[0], d->res[1]);
		// d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, &d->endian);
		y = 250;
		x = 0;
		while (y < d->res[1] * .75)
		{
			while (x < d->res[0])
			{
				my_mlx_pixel_put(d, x, y, 0x00FFFF);
				x++;
			}
			y++;
			x = 0;
		}
		while (y < d->res[1] * .75)
		{
			while (x < d->res[0])
			{
				my_mlx_pixel_put(d, x, y, 0xFFFF00);
				x++;
			}
			y++;
			x = 0;
		}
		// mlx_destroy_image(vars.mlx, d->img);
		mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img, 0, 0);
		// mlx_destroy_window(v.mlx, v.win);
		// exit(1);
		printf("oui\n");
	}
	return(0);
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
	d->vars.mlx = mlx_init();
	d->vars.win = mlx_new_window(d->vars.mlx, d->res[0], d->res[1], "PAYPAL/BDOUIDI");
	d->img = mlx_new_image(d->vars.mlx, d->res[0], d->res[1]);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, &d->endian);
			while (y < d->res[1] / 2)
		{
			while (x < d->res[0])
			{
				my_mlx_pixel_put(d, x, y, d->c_color);
				x++;
			}
			y++;
			x = 0;
		}
		while (y < d->res[1])
		{
			while (x < d->res[0])
			{
				my_mlx_pixel_put(d, x, y, d->f_color);
				x++;
			}
			y++;
			x = 0;
		}
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img, 0, 0);
	printf("[%p]\n", d->img);
	mlx_key_hook(d->vars.win, closewindow, d);
	mlx_loop(d->vars.mlx);
}
