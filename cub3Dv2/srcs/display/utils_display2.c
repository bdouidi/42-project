/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:57:33 by othabchi          #+#    #+#             */
/*   Updated: 2020/10/16 15:54:56 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	which_dir2(t_data *d, int keycode, int x, int y)
{
	if (keycode == 2)
	{
		x = (int)(d->player.pos_x - d->player.dir_y * d->player.sp);
		y = (int)(d->player.pos_y + d->player.dir_x * d->player.sp);
		if (d->map[(int)d->player.pos_y][x] && d->map[(int)d->player.pos_y][x] == '0')
			d->player.pos_x -= d->player.dir_y * d->player.sp;
		else
			write(1, "\a", 1);
		if (d->map[y][(int)d->player.pos_x] && d->map[y][(int)d->player.pos_x] == '0')
			d->player.pos_y += d->player.dir_x * d->player.sp;
		else
			write(1, "\a", 1);
	}
	if (keycode == 0)
	{
		x = (int)(d->player.pos_x + d->player.dir_y * d->player.sp);
		y = (int)(d->player.pos_y - d->player.dir_x * d->player.sp);
		if (d->map[(int)d->player.pos_y][x] && d->map[(int)d->player.pos_y][x] == '0')
			d->player.pos_x += d->player.dir_y * d->player.sp;
		else
			write(1, "\a", 1);
		if (d->map[y][(int)d->player.pos_x] && d->map[y][(int)d->player.pos_x] == '0')
			d->player.pos_y -= d->player.dir_x * d->player.sp;
		else
			write(1, "\a", 1);
	}
}

void which_dir(t_data *d, int keycode)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	if (keycode == 13)
	{
		x = (int)(d->player.pos_x + d->player.dir_x * d->player.sp);
		y = (int)(d->player.pos_y + d->player.dir_y * d->player.sp);
		if (d->map[(int)d->player.pos_y][x] && d->map[(int)d->player.pos_y][x] == '0')
			d->player.pos_x += d->player.dir_x * d->player.sp;
		else
			write(1, "\a", 1);
		if (d->map[y][(int)d->player.pos_x] && d->map[y][(int)d->player.pos_x] == '0')
			d->player.pos_y += d->player.dir_y * d->player.sp;
		else
			write(1, "\a", 1);
	}
	if (keycode == 1)
	{
		x = (int)(d->player.pos_x - d->player.dir_x * d->player.sp);
		y = (int)(d->player.pos_y - d->player.dir_y * d->player.sp);
		if (d->map[(int)d->player.pos_y][x] && d->map[(int)d->player.pos_y][x] == '0')
			d->player.pos_x -= d->player.dir_x * d->player.sp;
		else
			write(1, "\a", 1);
		if (d->map[y][(int)d->player.pos_x] && d->map[y][(int)d->player.pos_x] == '0')
			d->player.pos_y -= d->player.dir_y * d->player.sp;
		else
			write(1, "\a", 1);
	}
	which_dir2(d, keycode, x, y);
}

void	rotation(t_data *d, int keycode)
{
	double	oldDir;
	double	oldplaneX;

	oldDir = d->player.dir_x;
	oldplaneX = d->ray.planeX;
	if (keycode == 12)
	{
		d->player.dir_x = d->player.dir_x * cos(-.15) - d->player.dir_y * sin(-.15);
		d->player.dir_y = oldDir * sin(-.15) + d->player.dir_y * cos(-.15);
		d->ray.planeX = d->ray.planeX * cos(-.15) - d->ray.planeY * sin(-.15);
		d->ray.planeY = oldplaneX * sin(-.15) + d->ray.planeY * cos(-.15);
	}
	if (keycode == 14)
	{
		d->player.dir_x = d->player.dir_x * cos(.15) - d->player.dir_y * sin(.15);
		d->player.dir_y = oldDir * sin(.15) + d->player.dir_y * cos(.15);
		d->ray.planeX = d->ray.planeX * cos(.15) - d->ray.planeY * sin(.15);
		d->ray.planeY = oldplaneX * sin(.15) + d->ray.planeY * cos(.15);
	}
}