/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 19:30:36 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/11 19:36:37 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	window(t_data *d)
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, d->res[0], d->res[1], "PAYPAL/BDOUIDI");
	d->img = mlx_new_image(mlx, d->res[0], d->res[1]);
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
	mlx_put_image_to_window(mlx, mlx_win, d->img, 0, 0);
	mlx_loop(mlx);
}
