/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_display2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 22:31:39 by othabchi          #+#    #+#             */
/*   Updated: 2020/07/30 04:52:57 by othabchi         ###   ########.fr       */
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
	d->player.rayone = d->player.dir - M_PI / 6;
	if (d->player.rayone < 0)
		d->player.rayone += 2 * M_PI;
	if (d->player.rayone > 2 * M_PI)
		d->player.rayone -= 2 * M_PI;
}

void	drawline(t_data *d, double dir, int i, int color)
{
	d->x = d->player.pos_x * d->square.width;
	d->y = d->player.pos_y * d->square.width;
	// if (i == 1)
	i = 0;
	color = 0x000FF00;
	// while ((int)d->x != (int)(d->ray.x[i] * d->square.width))
	for (int z = 0; z < 50; z++)
	{
		my_mlx_pixel_put(d, color);
		d->x -= cos(dir);
		d->y -= sin(dir);
	}
}

void	drawfov(t_data *d)
{
	int	fov;

	fov = 1.5 * d->res[0];
	d->player.fov = d->player.dir - M_PI_4;
	while (fov--)
	{
		if (d->player.fov < 0)
			d->player.fov += 2 * M_PI;
		if (d->player.fov > 2 * M_PI)
			d->player.fov -= 2 * M_PI;
		if (fov <= d->res[0]*1.25 && fov > d->res[0] * .25)
			get_ray_size(d);
		dda_sprite(d);
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
	drawsquare(d, 0x0);
}
