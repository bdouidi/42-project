/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:57:33 by idouidi           #+#    #+#             */
/*   Updated: 2020/11/16 23:54:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	which_dir2(t_data *d, int keycode)
{
	if (keycode == 100)
	{
		d->w_x = (int)(d->player.pos_x - d->player.dir_y * d->player.sp);
		d->w_y = (int)(d->player.pos_y + d->player.dir_x * d->player.sp);
		if (d->map[(int)d->player.pos_y][d->w_x] &&
		d->map[(int)d->player.pos_y][d->w_x] == '0')
			d->player.pos_x -= d->player.dir_y * d->player.sp;
		if (d->map[d->w_y][(int)d->player.pos_x] &&
		d->map[d->w_y][(int)d->player.pos_x] == '0')
			d->player.pos_y += d->player.dir_x * d->player.sp;
	}
	if (keycode == 97)
	{
		d->w_x = (int)(d->player.pos_x + d->player.dir_y * d->player.sp);
		d->w_y = (int)(d->player.pos_y - d->player.dir_x * d->player.sp);
		if (d->map[(int)d->player.pos_y][d->w_x] &&
		d->map[(int)d->player.pos_y][d->w_x] == '0')
			d->player.pos_x += d->player.dir_y * d->player.sp;
		if (d->map[d->w_y][(int)d->player.pos_x] &&
		d->map[d->w_y][(int)d->player.pos_x] == '0')
			d->player.pos_y -= d->player.dir_x * d->player.sp;
	}
}

void	which_dir(t_data *d, int keycode)
{
	if (keycode == 119)
	{
		d->w_x = (int)(d->player.pos_x + d->player.dir_x * d->player.sp);
		d->w_y = (int)(d->player.pos_y + d->player.dir_y * d->player.sp);
		if (d->map[(int)d->player.pos_y][d->w_x] &&
		d->map[(int)d->player.pos_y][d->w_x] == '0')
			d->player.pos_x += d->player.dir_x * d->player.sp;
		if (d->map[d->w_y][(int)d->player.pos_x] &&
		d->map[d->w_y][(int)d->player.pos_x] == '0')
			d->player.pos_y += d->player.dir_y * d->player.sp;
	}
	if (keycode == 115)
	{
		d->w_x = (int)(d->player.pos_x - d->player.dir_x * d->player.sp);
		d->w_y = (int)(d->player.pos_y - d->player.dir_y * d->player.sp);
		if (d->map[(int)d->player.pos_y][d->w_x] &&
		d->map[(int)d->player.pos_y][d->w_x] == '0')
			d->player.pos_x -= d->player.dir_x * d->player.sp;
		if (d->map[d->w_y][(int)d->player.pos_x] &&
		d->map[d->w_y][(int)d->player.pos_x] == '0')
			d->player.pos_y -= d->player.dir_y * d->player.sp;
	}
	which_dir2(d, keycode);
}

void	rotation(t_data *d, int keycode)
{
	double	old_dir;
	double	oldplane_x;

	old_dir = d->player.dir_x;
	oldplane_x = d->ray.plane_x;
	if (keycode == 65361)
	{
		d->player.dir_x = d->player.dir_x * cos(-.15) -
		d->player.dir_y * sin(-.15);
		d->player.dir_y = old_dir * sin(-.15) + d->player.dir_y * cos(-.15);
		d->ray.plane_x = d->ray.plane_x * cos(-.15) - d->ray.plane_y *
		sin(-.15);
		d->ray.plane_y = oldplane_x * sin(-.15) + d->ray.plane_y * cos(-.15);
	}
	if (keycode == 65363)
	{
		d->player.dir_x = d->player.dir_x * cos(.15) -
		d->player.dir_y * sin(.15);
		d->player.dir_y = old_dir * sin(.15) + d->player.dir_y * cos(.15);
		d->ray.plane_x = d->ray.plane_x * cos(.15) - d->ray.plane_y * sin(.15);
		d->ray.plane_y = oldplane_x * sin(.15) + d->ray.plane_y * cos(.15);
	}
}

int		cross_window(t_data *d)
{
	write(1, "Exit\n", 5);
	mlx_destroy_window(d->vars.mlx, d->vars.win);
	exit(1);
}

int		checksizemap(t_data *d, int **check)
{
	if (d->square.width > d->res[0] / 25 || d->square.height > d->res[1] / 25
	|| d->res[0] < 300 || d->res[1] < 300 || d->square.height < 4 ||
	d->square.width < 4)
	{
		ft_putstr("Sorry your map is too big to be print or your resolution is \
not adapted to print the map :/\n");
		**check = 2;
		return (-1);
	}
	return (0);
}
