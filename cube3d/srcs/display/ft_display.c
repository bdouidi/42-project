/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 19:30:36 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/17 20:00:22 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static	void	drawsquare(t_data *d, int i, int color, int z) /* pour des tests, la fonction va etre supprimee a la fin */
{
	int x = 0;
	int y = 0;

	if (z == 1)
	{
		mlx_clear_window(d->vars.mlx, d->vars.win);
		mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img[0], 0, 0);
		mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img[1], 0, 0);
	}
	d->img[i] = mlx_new_image(d->vars.mlx, d->square.width, d->square.height);
	d->addr = mlx_get_data_addr(d->img[i], &d->bits_per_pixel, &d->line_length, &d->endian);
	while (y < d->square.height)
	{
		while (x < d->square.width)
		{
			my_mlx_pixel_put(d, x, y, color);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img[i], d->square.imgx, d->square.imgy);
	// printf("[%d, %d]\n", d->square.imgx, d->square.imgy);
}

void	drawmap2D(t_data *d)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img[0], 0, 0);
	while (d->map[y])
	{
		while (d->map[y][x])
		{
			d->square.imgx = x * 10;
			d->square.imgy = y * 10;
			if (d->map[y][x] == '1')
			{
				drawsquare(d, 1, 0x353535, 0);
				x++;
			}
			else if (d->map[y][x] == '0')
			{
				drawsquare(d, 1, 0xFFFFFF, 0);
				x++;
			}
			else if (d->map[y][x] == '2')
			{
				drawsquare(d, 1, 0xFF0000, 0);
				x++;
			}
			else if (d->map[y][x] == 'N' || d->map[y][x] == 'S' ||
					d->map[y][x] == 'E' || d->map[y][x] == 'W')
			{
				drawsquare(d, 1, 0x00FF00, 0);
				d->player.pos_x = x * 10;
				d->player.pos_y = y * 10;
				x++;
				printf("[%d, %d]\n", d->player.pos_x, d->player.pos_y);
			}
		}
		x = 0;
		y++;
	}
}

static int		handlekeys(int keycode, t_data *d)
{
	if (keycode == 53)
	{
		mlx_destroy_window(d->vars.mlx, d->vars.win);
		exit(1);
	}
	if (keycode == 0)
		drawmap2D(d);
	if (keycode == 123)
	{
		d->square.imgx = d->player.pos_x -= 10;
		printf("[%d, %d]\n", d->square.imgx, d->square.imgy);
		drawsquare(d, 2, 0x00FF00, 1);
	}
	if (keycode == 124)
	{
		d->square.imgx = d->player.pos_x += 10;
		printf("[%d, %d]\n", d->square.imgx, d->square.imgy);
		drawsquare(d, 2, 0xFFFF00, 1);
	}
	if (keycode == 125)
	{
		d->square.imgy = d->player.pos_y += 10;
		printf("[%d, %d]\n", d->square.imgx, d->square.imgy);
		drawsquare(d, 2, 0xBBFFAA, 1);
	}
	if (keycode == 126)
	{
		d->square.imgy = d->player.pos_y -= 10;
		printf("[%d, %d]\n", d->square.imgx, d->square.imgy);
		drawsquare(d, 2, 0x00FFFF, 1);
	}
	return (0);
}

static void	display_floor_ceiling(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img[0], 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	window(t_data *d)
{
	d->vars.mlx = mlx_init();
	d->vars.win = mlx_new_window(d->vars.mlx, d->res[0], d->res[1], "PAYPAL/BDOUIDI");
	d->img[0] = mlx_new_image(d->vars.mlx, d->res[0], d->res[1]);
	d->addr = mlx_get_data_addr(d->img[0], &d->bits_per_pixel, &d->line_length, &d->endian);
	display_floor_ceiling(d);
	mlx_hook(d->vars.win, 2, (1L<<0), handlekeys, d);
	mlx_loop(d->vars.mlx);
}
