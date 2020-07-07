/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_display2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 22:31:39 by othabchi          #+#    #+#             */
/*   Updated: 2020/07/07 19:13:34 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	rotation(t_data *d, int keycode)
{
	if (keycode == 12)
	{
		d->player.dir -= (M_PI / 180);
		if (d->player.dir < 0)
			d->player.dir = 2 * M_PI;
	}
	if (keycode == 14)
	{
		d->player.dir += (M_PI / 180);
		if (d->player.dir > 2 * M_PI)
			d->player.dir = 0;
	}
}

void	drawline(t_data *d, double dir, int i, int color)
{
	d->x = d->player.pos_x * d->square.width;
	d->y = d->player.pos_y * d->square.width;
	if (i == 1)
		color = 0x0FF0000;
	// printf("x/y[%f, %f]\nrayx/y[%d, %d]\n", d->x, d->y, (int)(d->ray.x[i] * d->square.width), (int)(d->ray.y[i] * d->square.width));
	printf("\n\nDebut du rayon\n");
	while ((int)d->x != (int)(d->ray.x[i] * d->square.width))
	// for (int size = 0; size < 50; size++)
	{
		if (d->x < 0)
			break;
		// printf("[d->y :%f != d->ray.y :%f]\n[d->x :%f != d->ray.x :%f]\n------------------------\n", 
		// d->y, d->ray.y[i] * d->square.width, d->x, d->ray.x[i] * d->square.width);
		// printf("[%f != %f]\n", d->x, d->ray.x[i] * d->square.width);
		my_mlx_pixel_put(d, color);
		d->x -= cos(dir);
		d->y -= sin(dir);

	}
}

void	drawfov(t_data *d)
{
	int count;

	count = 60;
	d->player.fov[0] = ((d->player.dir - (M_PI / 6)) < 0) ? (11 * M_PI / 6) + d->player.dir :
	d->player.dir - (M_PI / 6);
	printf("-{%f | %f}-\n", d->player.fov[0], d->player.dir);
	while (count--)
	{
		d->player.fov[0] = (d->player.fov[0] > 2 * M_PI) ? 0 : d->player.fov[0];
		raycasting(d);
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
			//mlx_pixel_put(d->vars.mlx, d->vars.win, d->x, d->y, color);
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
	d->square.height = d->square.width;
	drawsquare(d, 0x00FF00);
	if (keycode == 12 || keycode == 14)
	{
		rotation(d, keycode);
		drawfov(d);
		// drawline(d, d->player.dir, 0x0FF0000);
	}
	else
	{
		drawfov(d);
		// drawline(d, d->player.dir, 0x0FF0000);
	}
}
