/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:08:43 by idouidi           #+#    #+#             */
/*   Updated: 2020/07/14 20:01:20 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	loop_tb(t_data *d)
{
	while (d->ray.hit == 0 && d->ray.x[0] > 1 && d->ray.x[0] < d->mapX)
	{
		if ((d->map[(int)d->ray.y[0]][(int)d->ray.x[0]] &&
			d->map[(int)d->ray.y[0]][(int)d->ray.x[0]] == '1') ||
			(d->map[(int)d->ray.y[0] - 1][(int)d->ray.x[0]] &&
			d->map[(int)d->ray.y[0] - 1][(int)d->ray.x[0]] == '1'))
			d->ray.hit = 1;
		else
		{
			d->ray.y[0] += d->ray.yoffset;
			d->ray.x[0] += d->ray.xoffset;
		}
	}
}

void	loop_lr(t_data *d)
{
	while (d->ray.hit == 0 && d->ray.y[1] > 1 && d->ray.y[1] < d->mapY)
	{
		if ((d->map[(int)d->ray.y[1]][(int)d->ray.x[1]] &&
			d->map[(int)d->ray.y[1]][(int)d->ray.x[1]] == '1') ||
			(d->map[(int)d->ray.y[1]][(int)d->ray.x[1] - 1] &&
			d->map[(int)d->ray.y[1]][(int)d->ray.x[1] - 1] == '1'))
			d->ray.hit = 1;
		else
		{
			d->ray.y[1] += d->ray.yoffset;
			d->ray.x[1] += d->ray.xoffset;
		}
	}
}

void	look_top_botom(t_data *d, int *i)
{
	d->ray.hit = 0;
	d->ray.t = -1 / tan(d->ray.dir);
	d->ray.y[0] = (d->ray.dir > M_PI) ? (int)d->player.pos_y + 1 :
	(int)d->player.pos_y;
	d->ray.x[0] = (d->player.pos_y - d->ray.y[0]) * d->ray.t + d->player.pos_x;
	d->ray.yoffset = (d->ray.dir > M_PI) ? 1 : -1;
	d->ray.xoffset = -(d->ray.yoffset) * d->ray.t;
	if ((d->ray.dir > -0.01 && d->ray.dir < 0.01) ||
		(d->ray.dir > 3.13 && d->ray.dir < 3.15))
	{
		d->ray.x[0] = d->player.pos_x;
		d->ray.y[0] = d->player.pos_y;
		d->ray.hit = 1;
		*i = 1;
	}
	loop_tb(d);
}

void	look_left_right(t_data *d, int *i)
{
	if ((d->ray.dir > 1.56 && d->ray.dir < 1.58) ||
		(d->ray.dir > 4.70 && d->ray.dir < 4.72))
	{
		d->ray.x[1] = d->player.pos_x;
		d->ray.y[1] = d->player.pos_y;
		d->ray.hit = 1;
		*i = 2;
	}
	else if (d->ray.dir > M_PI_2 && d->ray.dir < 3 * M_PI_2)
	{
		d->ray.x[1] = (int)d->player.pos_x + 1;
		d->ray.y[1] = (d->player.pos_x - d->ray.x[1]) * d->ray.t +
		d->player.pos_y;
		d->ray.xoffset = 1;
		d->ray.yoffset = -(d->ray.xoffset) * d->ray.t;
	}
	else if (d->ray.dir < M_PI_2 || d->ray.dir > 3 * M_PI_2)
	{
		d->ray.x[1] = (int)d->player.pos_x;
		d->ray.y[1] = (d->player.pos_x - d->ray.x[1]) * d->ray.t +
		d->player.pos_y;
		d->ray.xoffset = -1;
		d->ray.yoffset = -(d->ray.xoffset) * d->ray.t;
	}
	loop_lr(d);
}

void	get_ray_size(t_data *d)
{
	int			i;
	double		dist1;
	double		dist2;
	static int	tmp_x = 0;

	i = 0;
	d->ray.dir = d->player.fov;
	d->square.width = ((d->res[0] * .45) / ft_strlen(d->map[0]));
	look_top_botom(d, &i);
	d->ray.hit = 0;
	d->ray.t = -tan(d->ray.dir);
	look_left_right(d, &i);
	dist1 = sqrt((d->ray.x[0] - d->player.pos_x) * (d->ray.x[0] -
	d->player.pos_x)
	+ (d->ray.y[0] - d->player.pos_y) * (d->ray.y[0] - d->player.pos_y));
	dist2 = sqrt((d->ray.x[1] - d->player.pos_x) * (d->ray.x[1] -
	d->player.pos_x)
	+ (d->ray.y[1] - d->player.pos_y) * (d->ray.y[1] - d->player.pos_y));
	i = (i != 2 && dist1 > dist2) ? 1 : i;
	i = (i == 2 ? 0 : i);
	tmp_x = (tmp_x == d->res[0]) ? 0 : tmp_x;
	i == 0 ? draw_wall(d, dist1, i, tmp_x) : draw_wall(d, dist2, i, tmp_x);
	tmp_x++;
}
