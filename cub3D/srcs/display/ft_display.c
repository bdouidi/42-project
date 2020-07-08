/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 19:30:36 by othabchi          #+#    #+#             */
/*   Updated: 2020/07/08 07:40:02 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void			drawmap2d(t_data *d)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	d->square.width = ((d->res[0] * .45) / ft_strlen(d->map[0]));
	d->square.height = d->square.width;
	while (d->map[y])
	{
		while (d->map[y][x])
		{
			d->square.imgx = x * d->square.width;
			d->square.imgy = y * d->square.height;
			if (d->map[y][x] == '1')
				drawsquare(d, 0x00458A);
			if (d->map[y][x] == '0')
				drawsquare(d, 0x83C0FC);
			else if (d->map[y][x] == '2')
				drawsquare(d, 0xFF0000);
			x++;
		}
		x = 0;
		y++;
	}
}

void			which_dir(t_data *d, float spd, int keycode)
{
	int		x;
	int		y;

	if (keycode == 123)
	{
		x = (int)(d->player.pos_x + cos(d->player.dir + M_PI_2) * spd);
		y = (int)(d->player.pos_y + sin(d->player.dir + M_PI_2) * spd);
		if (d->map[y][x] && d->map[y][x] == '0')
		{
			d->player.pos_x += cos(d->player.dir + M_PI_2) * spd;
			d->player.pos_y += sin(d->player.dir + M_PI_2) * spd;
		}
	}
	if (keycode == 124)
	{
		x = (int)(d->player.pos_x - cos(d->player.dir + M_PI_2) * spd);
		y = (int)(d->player.pos_y - sin(d->player.dir + M_PI_2) * spd);
		if (d->map[y][x] && d->map[y][x] == '0')
		{
			d->player.pos_x -= cos(d->player.dir + M_PI_2) * spd;
			d->player.pos_y -= sin(d->player.dir + M_PI_2) * spd;
		}
	}
	which_dir2(d, spd, keycode);
}

static void		display_floor_ceiling(t_data *d)
{
	d->x = -1;
	d->y = -1;
	while (d->y++ < d->res[1] / 2)
	{
		while (d->x++ < d->res[0])
			my_mlx_pixel_put(d, d->c_color);
		d->x = 0;
	}
	while (d->y < d->res[1])
	{
		while (d->x < d->res[0])
		{
			my_mlx_pixel_put(d, d->f_color);
			d->x++;
		}
		d->y++;
		d->x = 0;
	}
}

static int		handlekeys(int keycode, t_data *d)
{
	static int	check = 0;
	float		spd;

	spd = .1;
	if (keycode == 53)
	{
		mlx_destroy_window(d->vars.mlx, d->vars.win);
		exit(1);
	}
	if (keycode == 0)
		check++;
	if (keycode == 123 || keycode == 124 || keycode == 125
		|| keycode == 126)
		which_dir(d, spd, keycode);
	if (keycode == 12 || keycode == 14)
		rotation(d, keycode);
	if (check % 2 != 0)
	{
		mlx_clear_window(d->vars.mlx, d->vars.win);
		display_floor_ceiling(d);
		drawfov(d);
		drawmap2d(d);
		drawplayer(d);
	}
	else
	{
		display_floor_ceiling(d);
		drawfov(d);
	}
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img.ptr[0], 0, 0);
	return (0);
}

void			window(t_data *d)
{
	d->vars.mlx = mlx_init();
	d->vars.win = mlx_new_window(d->vars.mlx, d->res[0], d->res[1],
			"PAYPAL/BDOUIDI");
	if (!d->img.ptr[0])
		create_img(d, 0, d->res[0], d->res[1]);
	init_player(d);
	display_floor_ceiling(d);
	drawfov(d);
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img.ptr[0], 0, 0);
	mlx_hook(d->vars.win, 2, (1L << 0), handlekeys, d);
	mlx_loop(d->vars.mlx);
}
