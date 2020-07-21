/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:08:43 by idouidi           #+#    #+#             */
/*   Updated: 2020/07/21 20:57:08 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	loop_tb(t_data *d)
{
	int sign;

	while (d->ray.hit == 0 && d->ray.x[0] > 1 && d->ray.x[0] < d->mapX)
	{
		sign = (d->ray.dir >= 0 && d->ray.dir <= M_PI) ? -1 : 0;
		if (d->map[(int)d->ray.y[0] + sign][(int)d->ray.x[0]] &&
			d->map[(int)d->ray.y[0] + sign][(int)d->ray.x[0]] == '2')
				catch_sprite(d, 0);
		if (d->map[(int)d->ray.y[0] + sign][(int)d->ray.x[0]] &&
			d->map[(int)d->ray.y[0] + sign][(int)d->ray.x[0]] == '1')
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
	int sign;

	while (d->ray.hit == 0 && d->ray.y[1] > 1 && d->ray.y[1] < d->mapY)
	{
		sign = (d->ray.dir >= M_PI_2 && d->ray.dir <= 3 * M_PI_2) ? 0 : -1;
		if (d->map[(int)d->ray.y[1]][(int)d->ray.x[1] + sign] &&
			d->map[(int)d->ray.y[1]][(int)d->ray.x[1] + sign] == '2')
			catch_sprite(d, 1);
		if (d->map[(int)d->ray.y[1]][(int)d->ray.x[1] + sign] &&
			d->map[(int)d->ray.y[1]][(int)d->ray.x[1] + sign] == '1')
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

void	check_dist(t_data *d, double dist)
{
	int i;
	int j;

	j = 2;
	i = 0;
	while (j--)
		while (i < d->texture.count_spt)
		{
			while (d->spt[i].dist[j] < 0 && i < d->texture.count_spt)
				i++;
			if (d->spt[i].dist[j] > dist && d->spt[i].flag == 0)
			{
				d->spt[i].dist[j] = 0;
				d->spt[i].x[j] = 0;
				d->spt[i].y[j] = 0;
				d->spt[i].flag = 1;
			}
			else
			{
				d->spt[i].flag = 1;
				i++;
			} 
		}
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
	i == 0 ? check_dist(d, dist1) : check_dist(d, dist2);
	for (int j = 0; j < d->texture.count_spt ; j++)
		printf("Index %d:\n- x = [0]%f - [1]%f\n- y = [0]%f - [1]%f\n- dist = [0]%f - [1]%f\n\n ---------------- \n",
		 j, d->spt[j].x[0], d->spt[j].x[1], d->spt[j].y[0], d->spt[j].y[1]
		 , d->spt[j].dist[0], d->spt[j].dist[1]);
	i == 0 ? draw_wall(d, dist1, i, tmp_x) : draw_wall(d, dist2, i, tmp_x);
	tmp_x++;
}