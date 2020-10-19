/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:57:33 by othabchi          #+#    #+#             */
/*   Updated: 2020/10/13 20:24:42 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	which_dir2(t_data *d, int keycode, int x, int y)
{
	if (keycode == 100)
	{
		x = (int)(d->player.pos_x - d->player.dir_y * d->player.sp);
		y = (int)(d->player.pos_y + d->player.dir_x * d->player.sp);
		if (d->map[(int)d->player.pos_y][x] && d->map[(int)d->player.pos_y][x] == '0')
			d->player.pos_x -= d->player.dir_y * d->player.sp;
		if (d->map[y][(int)d->player.pos_x] && d->map[y][(int)d->player.pos_x] == '0')
			d->player.pos_y += d->player.dir_x * d->player.sp;
	}
	if (keycode == 97)
	{
		x = (int)(d->player.pos_x + d->player.dir_y * d->player.sp);
		y = (int)(d->player.pos_y - d->player.dir_x * d->player.sp);
		if (d->map[(int)d->player.pos_y][x] && d->map[(int)d->player.pos_y][x] == '0')
			d->player.pos_x += d->player.dir_y * d->player.sp;
		if (d->map[y][(int)d->player.pos_x] && d->map[y][(int)d->player.pos_x] == '0')
			d->player.pos_y -= d->player.dir_x * d->player.sp;
	}
}

void which_dir(t_data *d, int keycode)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	if (keycode == 119)
	{
		x = (int)(d->player.pos_x + d->player.dir_x * d->player.sp);
		y = (int)(d->player.pos_y + d->player.dir_y * d->player.sp);
		if (d->map[(int)d->player.pos_y][x] && d->map[(int)d->player.pos_y][x] == '0')
			d->player.pos_x += d->player.dir_x * d->player.sp;
		if (d->map[y][(int)d->player.pos_x] && d->map[y][(int)d->player.pos_x] == '0')
			d->player.pos_y += d->player.dir_y * d->player.sp;
	}
	if (keycode == 115)
	{
		x = (int)(d->player.pos_x - d->player.dir_x * d->player.sp);
		y = (int)(d->player.pos_y - d->player.dir_y * d->player.sp);
		if (d->map[(int)d->player.pos_y][x] && d->map[(int)d->player.pos_y][x] == '0')
			d->player.pos_x -= d->player.dir_x * d->player.sp;
		if (d->map[y][(int)d->player.pos_x] && d->map[y][(int)d->player.pos_x] == '0')
			d->player.pos_y -= d->player.dir_y * d->player.sp;
	}
	which_dir2(d, keycode, x, y);
}

void	rotation(t_data *d, int keycode)
{
	double	oldDir;
	double	oldplaneX;

	oldDir = d->player.dir_x;
	oldplaneX = d->ray.planeX;
	if (keycode == 113)
	{
		d->player.dir_x = d->player.dir_x * cos(-.15) - d->player.dir_y * sin(-.15);
		d->player.dir_y = oldDir * sin(-.15) + d->player.dir_y * cos(-.15);
		d->ray.planeX = d->ray.planeX * cos(-.15) - d->ray.planeY * sin(-.15);
		d->ray.planeY = oldplaneX * sin(-.15) + d->ray.planeY * cos(-.15);
	}
	if (keycode == 101)
	{
		d->player.dir_x = d->player.dir_x * cos(.15) - d->player.dir_y * sin(.15);
		d->player.dir_y = oldDir * sin(.15) + d->player.dir_y * cos(.15);
		d->ray.planeX = d->ray.planeX * cos(.15) - d->ray.planeY * sin(.15);
		d->ray.planeY = oldplaneX * sin(.15) + d->ray.planeY * cos(.15);
	}
}