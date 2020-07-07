/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 03:12:26 by idouidi           #+#    #+#             */
/*   Updated: 2020/07/07 19:03:09 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_ray_size(t_data *d)
{
	int i = 0;
	float xoffset, yoffset, aTan, nTan;

	d->ray.hit = 0;
	d->ray.dir = d->player.fov[0];
	aTan = -1 / tan(d->ray.dir);
	d->square.width = ((d->res[0] * .45) / ft_strlen(d->map[0]));
	if ((d->ray.dir > -0.01 && d->ray.dir < 0.01) ||
		(d->ray.dir > 3.13 && d->ray.dir < 3.15))
	{
		d->ray.x[0] = d->player.pos_x;
		d->ray.y[0] = d->player.pos_y;
		d->ray.hit = 1;
		i = 1;
	}
	else if (d->ray.dir > M_PI) // regarde en bas
	{
		d->ray.y[0] = (int)d->player.pos_y + 1;
		d->ray.x[0] = (d->player.pos_y - d->ray.y[0]) * aTan + d->player.pos_x;
		// printf("ray_y/x[%f, %f]\ni = %d\n", d->ray.y[i], d->ray.x[i], i);
		yoffset = 1;
		xoffset = -yoffset * aTan;
	}
	else if (d->ray.dir < M_PI) // regarde en haut
	{
		d->ray.y[0] = (int)d->player.pos_y;
		d->ray.x[0] = (d->player.pos_y - d->ray.y[0]) * aTan + d->player.pos_x;
		yoffset = -1;
		xoffset = -yoffset * aTan;
	}
	while (d->ray.hit == 0 &&  d->ray.x[0] > 1 && d->ray.x[0] < d->mapX)
	{
		if ((d->map[(int)d->ray.y[0]][(int)d->ray.x[0]] &&
			d->map[(int)d->ray.y[0]][(int)d->ray.x[0]] == '1') ||
			(d->map[(int)d->ray.y[0] - 1][(int)d->ray.x[0]] &&
			d->map[(int)d->ray.y[0] - 1][(int)d->ray.x[0]] == '1'))
			d->ray.hit = 1;
		else
		{
		d->ray.y[0] += yoffset;
		d->ray.x[0] += xoffset;
		}
	}
	// drawline(d, d->ray.dir, 0x0FF0000);
	/*************************************/
	d->ray.hit = 0;
	nTan = -tan(d->ray.dir);
	if ((d->ray.dir > 1.56 && d->ray.dir < 1.58) ||
		(d->ray.dir > 4.70 && d->ray.dir < 4.72))
	{
		d->ray.x[0] = d->player.pos_x;
		d->ray.y[0] = d->player.pos_y;
		d->ray.hit = 1;
		i = 2;
	}
	else if (d->ray.dir > M_PI_2 && d->ray.dir < 3 * M_PI_2)// regarde a droite
	{
		d->ray.x[1] = (int)d->player.pos_x + 1;
		d->ray.y[1] = (d->player.pos_x - d->ray.x[1]) * nTan + d->player.pos_y;
		xoffset = 1;
		yoffset = -xoffset * nTan;
	}
	else if (d->ray.dir < M_PI_2 || d->ray.dir > 3 * M_PI_2) // regarde a gauche
	{
		d->ray.x[1] = (int)d->player.pos_x;
		d->ray.y[1] = (d->player.pos_x - d->ray.x[1]) * nTan + d->player.pos_y;
		xoffset = -1;
		yoffset = -xoffset * nTan;
	}
	// printf("0 : [%f, %f]\n1 : [%f, %f]\n -------------------- \n", d->ray.y[0], d->ray.x[0], d->ray.y[1], d->ray.x[1]);
	while (d->ray.hit == 0 &&  d->ray.y[1] > 1 && d->ray.y[1] < d->mapY)
	{
		if ((d->map[(int)d->ray.y[1]][(int)d->ray.x[1]] &&
			d->map[(int)d->ray.y[1]][(int)d->ray.x[1]] == '1') ||
			(d->map[(int)d->ray.y[1]][(int)d->ray.x[1] - 1] &&
			d->map[(int)d->ray.y[1]][(int)d->ray.x[1] - 1] == '1'))
			d->ray.hit = 1;
		else
		{
			d->ray.y[1] += yoffset;
			d->ray.x[1] += xoffset;
		}
	}
	// printf("0 : [%f, %f]\n1 : [%f, %f]\n -------------------- \n\n ----------------- \n", d->ray.y[0], d->ray.x[0], d->ray.y[1], d->ray.x[1]);

	double dist1, dist2;
	dist1 = sqrt((d->ray.x[0] - d->player.pos_x) * (d->ray.x[0] - d->player.pos_x)
	+ (d->ray.y[0] - d->player.pos_y) * (d->ray.y[0] - d->player.pos_y));
	dist2 = sqrt((d->ray.x[1] - d->player.pos_x) * (d->ray.x[1] - d->player.pos_x)
	+ (d->ray.y[1] - d->player.pos_y) * (d->ray.y[1] - d->player.pos_y));
	// printf("[[[%f vs %f]]]\n", dist1, dist2);
	if (i != 2 && dist1 > dist2)
		i = 1;
	i = (i == 2 ? 0 : i);
	// printf("-{%f | %f}-\ni = %d\n", d->ray.dir, d->player.dir, i);
	drawline(d, d->ray.dir, i, 0x422180);
}

void	raycasting(t_data *d)
{
	get_ray_size(d);
}
