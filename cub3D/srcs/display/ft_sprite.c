/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:26:11 by othabchi          #+#    #+#             */
/*   Updated: 2020/07/24 17:14:27 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	stock_sprite(t_data *d, int i, t_sprite tmp, int *check, int b, int f)
{
	d->spt[i].x[b] = tmp.x[b];
	d->spt[i].y[b] = tmp.y[b];
	d->spt[i].dist[b] = tmp.dist[b];
	*check = 1;
	d->spt[i].flag[b] = 0;
	if (f == 0)
	{
		d->spt[i].johnny = d->player.fov;
		printf("i=%d %f\n", i, d->spt[i].johnny);
	}
}

void	catch_sprite(t_data *d, int b)
{
	 int		i;
	t_sprite	tmp;
	int			check;
	
	i = 0;
	tmp.x[b] = d->ray.x[b];
	tmp.y[b] = d->ray.y[b];
	tmp.dist[b] = sqrt((d->ray.x[b] - d->player.pos_x) * (d->ray.x[b] -
			d->player.pos_x) + (d->ray.y[b] - d->player.pos_y) *
			(d->ray.y[b] - d->player.pos_y));
	check = 0;
	while (check == 0 && i < d->texture.count_spt)
	{
		if (b == 1)
		{
			while (((int)d->spt[i].x[0] != (int)tmp.x[1] ||
				(int)d->spt[i].y[0] != (int)tmp.y[1]) && 
				i < d->texture.count_spt)
				i++;
		}
		((int)d->spt[i].x[b] == 0) ? stock_sprite(d, i, tmp, &check, b, 0) : 0;
		if ((int)d->spt[i].x[b] == (int)tmp.x[b] &&
			(int)d->spt[i].y[b] == (int)tmp.y[b])
		{
			if (tmp.dist[b] < d->spt[i].dist[b])
				stock_sprite(d, i, tmp, &check, b, 1);
			else
				check = 1;
		}
		else
			i++;
	}
}
