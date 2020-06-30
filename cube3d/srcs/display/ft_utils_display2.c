/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_display2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 22:31:39 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/30 02:55:19 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	rotation(t_data *d, int keycode)
{
	if (keycode == 12)
	{
		d->player.dir -= (M_PI / 180);
		if (d->player.dir > 2 * M_PI)
			d->player.dir -= 2 * M_PI;
	}
	if (keycode == 14)
	{
		d->player.dir += (M_PI / 180);
		if (d->player.dir < 0)
			d->player.dir += 2 * M_PI;
	}
}

void	drawline(t_data *d, double dir, int color)
{
	int	size;

	size = 0;
	d->x = d->square.imgx + d->square.width / 2;
	d->y = d->square.imgy + d->square.height / 2;
	while (size < 100)
	{
		d->x -= cos(dir);
		d->y -= sin(dir);
		my_mlx_pixel_put(d, color);
		size++;
	}
}

void	drawfov(t_data *d, int color)
{
	d->player.fov[0] = d->player.dir - (M_PI / 6);
	d->player.fov[1] = d->player.dir + (M_PI / 6);
	while (d->player.fov[0] < d->player.fov[1])
	{
		drawline(d, d->player.fov[0], color);
		d->player.fov[0] += (M_PI / 180);
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

void	drawplayer(t_data *d, int keycode)
{
	d->square.imgx = (d->player.pos_x * d->square.width) - ((((d->res[0] * .45)
	/ ft_strlen(d->map[0])) / 3) / 2);
	d->square.imgy = (d->player.pos_y * d->square.height) - ((((d->res[1] * .45)
	/ ft_strlen(d->map[0])) / 3) / 2);
	d->square.width = (((d->res[0] * .45) / ft_strlen(d->map[0])) / 2);
	d->square.height = (((d->res[1] * .45) / ft_strlen(d->map[0])) / 2);
	drawsquare(d, 0x00FF00);
	if (keycode == 12 || keycode == 14)
	{
		rotation(d, keycode);
		drawfov(d, 0xF9E79F);
		drawline(d, d->player.dir, 0x0FF0000);
	}
	else
	{
		drawfov(d, 0xF9E79F);
		drawline(d, d->player.dir, 0x0FF0000);
	}
}
