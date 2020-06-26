/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 19:30:36 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/26 07:20:33 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_player(t_data *d)
{
	d->player.height = 0.5 * d->res[1];
	d->player.fov = (M_PI / 3) * (180 / M_PI);
	if (d->player.letter == 'N')
		d->player.dir = M_PI / 2;
	else if (d->player.letter == 'E')
		d->player.dir = 0;
	else if (d->player.letter == 'S')
		d->player.dir = (3 * M_PI) / 2;
	else if (d->player.letter == 'W')
		d->player.dir = M_PI;
}

void 	rotation(t_data *d, int keycode)
{
	if (keycode == 12)
	{
		printf("[%f]\n", d->player.dir);
		d->player.dir = (d->player.dir) + .1;
		if (d->player.dir > 2 * M_PI)
			d->player.dir -= 2 * M_PI;
		printf("[%f]\n", d->player.dir);
		// d->ray.delta_x = cos(d->player.dir) * 5;
		// d->ray.delta_y = sin(d->player.dir) * 5;
		drawline(d, 0x0FF8000);
	}
	if (keycode == 14)
	{
		d->player.dir -= .1;
		if (d->player.dir < 0)
			d->player.dir += 2 * M_PI;
		// d->ray.delta_x = cos(d->player.dir) * 5;
		// d->ray.delta_y = sin(d->player.dir) * 5;
		printf("[%f]\n", d->player.dir);
		drawline(d, 0x0FF8000);
	}
}

void			drawplayer(t_data *d, int keycode)
{
	d->square.imgx = (d->player.pos_x * d->square.width) - ((((d->res[0] * .45)
	/ ft_strlen(d->map[0])) / 3) / 2);
	d->square.imgy = (d->player.pos_y * d->square.height) - ((((d->res[1] * .45)
	/ ft_strlen(d->map[0])) / 3) / 2);
	d->square.width = (((d->res[0] * .45) / ft_strlen(d->map[0])) / 2);
	d->square.height = (((d->res[1] * .45) / ft_strlen(d->map[0])) / 2);
	if (keycode == 12 || keycode == 14)
	{
		rotation(d, keycode);
		drawsquare(d, 0x00FF00);
	}
	else
	{
		drawline(d, 0x0FF8000);
		drawsquare(d, 0x00FF00);
	}
}

void			drawmap2d(t_data *d)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	d->square.width = ((d->res[0] * .45) / ft_strlen(d->map[0]));
	d->square.height = ((d->res[1] * .45) / ft_strlen(d->map[0]));
	while (d->map[y])
	{
		while (d->map[y][x])
		{
			d->square.imgx = x * d->square.width;
			d->square.imgy = y * d->square.height;
			if (d->map[y][x] == '0')
				drawsquare(d, 0xFFFFFF);
			else if (d->map[y][x] == '2')
				drawsquare(d, 0xFF0000);
			x++;
		}
		x = 0;
		y++;
 	}
}

void			which_dir(t_data *d, float spd, int dir)
{
	int		x;
	int		y;

	x = d->player.map_x;
	y = d->player.map_y;
	if (dir == 0 && (d->player.map_x =(int)((d->player.pos_x) - spd)))
		if (d->map[y][x] && d->map[y][x] == '0')
			d->player.pos_x -= spd;
	if (dir == 1 && (d->player.map_x =(int)((d->player.pos_x) + spd)))
		if (d->map[y][x] && d->map[y][x] == '0')
			d->player.pos_x += spd;
	if (dir == 2 && (d->player.map_y =(int)((d->player.pos_y) + spd)))
		if (d->map[y][x] && d->map[y][x] == '0')
			d->player.pos_y += spd;
	if (dir == 3 && (d->player.map_y =(int)(((d->player.pos_y * 10) - (spd * 10))/10)))
		if (d->map[y][x] && d->map[y][x] == '0')
			d->player.pos_y -= spd;
	printf("[%f][%f]\n", d->player.pos_x, d->player.pos_y);
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

	spd = .075;
	mlx_clear_window(d->vars.mlx, d->vars.win);
	// raycasting(d);
	if (keycode == 53)
	{
		mlx_destroy_window(d->vars.mlx, d->vars.win);
		exit(1);
	}
	if (keycode == 0)
		check++;
	if (keycode == 123)
		which_dir(d, spd, 0);
	if (keycode == 124)
		which_dir(d, spd, 1);
	if (keycode == 125)
		which_dir(d, spd, 2);
	if (keycode == 126)
		which_dir(d, spd, 3);
	if (check % 2 != 0)
	{
		// display_floor_ceiling(d);
		// drawmap2d(d);
		// drawplayer(d, keycode);
		mlx_clear_window(d->vars.mlx, d->vars.win);
		rotation(d, keycode);
	}
	else
		display_floor_ceiling(d);
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img.ptr[0], 0, 0);
	return (0);
}

void			window(t_data *d)
{
	d->vars.mlx = mlx_init();
	d->vars.win = mlx_new_window(d->vars.mlx, d->res[0], d->res[1],
			"PAYPAL/BDOUIDI");
	if	(!d->img.ptr[0])
		create_img(d, 0, d->res[0], d->res[1]);
	init_player(d);
	// display_floor_ceiling(d);
	// mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img.ptr[0], 0, 0);
	mlx_hook(d->vars.win, 2, (1L << 0), handlekeys, d);
	mlx_loop(d->vars.mlx);
}
