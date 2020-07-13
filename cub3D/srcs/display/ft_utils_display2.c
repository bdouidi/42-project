/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_display2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 22:31:39 by othabchi          #+#    #+#             */
/*   Updated: 2020/07/13 16:06:53 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	rotation(t_data *d, int keycode)
{
	if (keycode == 12)
	{
		d->player.dir -= (M_PI / 180) * 3;
		if (d->player.dir < 0)
			d->player.dir = 2 * M_PI;
	}
	if (keycode == 14)
	{
		d->player.dir += (M_PI / 180) * 3;
		if (d->player.dir > 2 * M_PI)
			d->player.dir = 0;
	}
}

// void	drawline(t_data *d, double dir, int i, int color)
// {
// 	d->x = d->player.pos_x * d->square.width;
// 	d->y = d->player.pos_y * d->square.width;
// 	if (i == 1)
// 		color = 0x0FF0000;
// 	while ((int)d->x != (int)(d->ray.x[i] * d->square.width))
// 	{
// 		my_mlx_pixel_put(d, color);
// 		d->x -= cos(dir);
// 		d->y -= sin(dir);
// 	}
// }

void	drawfov(t_data *d)
{
	int	fov;

	fov = d->res[0];
	d->player.fov = d->player.dir - (M_PI / 6);
	while (fov--)
	{
		if (d->player.fov < 0)
			d->player.fov += 2 * M_PI;
		if (d->player.fov > 2 * M_PI)
			d->player.fov -= 2 * M_PI;
		raycasting(d);
		d->player.fov += ((M_PI / 3) / d->res[0]);
	}
}

void	drawsquare(t_data *d, int color)
{
	d->x = d->square.imgx;
	d->y = d->square.imgy;
	while (d->y < (d->square.height + d->square.imgy - 1))
	{
		while (d->x < (d->square.width + d->square.imgx - 1))
		{
			my_mlx_pixel_put(d, color);
			d->x++;
		}
		d->y++;
		d->x = d->square.imgx;
	}
}

void	drawplayer(t_data *d)
{
	d->square.imgx = (d->player.pos_x * d->square.width) - ((((d->res[0] * .45)
	/ ft_strlen(d->map[0])) / 3) / 2);
	d->square.imgy = (d->player.pos_y * d->square.height) - ((((d->res[1] * .45)
	/ ft_strlen(d->map[0])) / 3) / 2);
	d->square.width = (((d->res[0] * .45) / ft_strlen(d->map[0])) / 2);
	d->square.height = d->square.width;
	drawsquare(d, 0x00FF00);
}
