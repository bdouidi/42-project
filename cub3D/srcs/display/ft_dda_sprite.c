/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:40:52 by othabchi          #+#    #+#             */
/*   Updated: 2020/08/06 14:56:17 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	loop_tb_sprite(t_data *d)
{
	int	sign;

	sign = (d->ray.dir >= 0 && d->ray.dir <= M_PI) ? -1 : 0;
	while ((d->ray.x[0] > 1 && d->ray.x[0] < d->mapX) &&
			(d->ray.y[0] > 1 && d->ray.y[0] < d->mapY))
	{
		// if ((int)d->ray.y[0] == 12)
		// 	printf("[%f + %d][%f]\n", d->ray.y[0], sign, d->ray.x[0]);
		if (d->map[(int)d->ray.y[0] + sign][(int)d->ray.x[0]] &&
			d->map[(int)d->ray.y[0] + sign][(int)d->ray.x[0]] == '2')
			catch_sprite(d, 0);
		d->ray.y[0] += d->ray.yoffset;
		d->ray.x[0] += d->ray.xoffset;
	}
}

void	look_tb_sprite(t_data *d)
{
	d->ray.t = -1 / tan(d->ray.dir);
	d->ray.y[0] = (d->ray.dir > M_PI) ? (int)d->player.pos_y + 1 :
	(int)d->player.pos_y;
	d->ray.x[0] = (d->player.pos_y - d->ray.y[0]) * d->ray.t + d->player.pos_x;
	d->ray.yoffset = (d->ray.dir > M_PI) ? 1 : -1;
	d->ray.xoffset = -(d->ray.yoffset) * d->ray.t;
	loop_tb_sprite(d);
}

// void	loop_lr_sprite(t_data *d)
// {
// 	int sign;

// 	sign = (d->ray.dir >= M_PI_2 && d->ray.dir <= 3 * M_PI_2) ? -1 : 0;
// 	while ((d->ray.x[1] > 1 && d->ray.x[1] < d->mapX) &&
// 			(d->ray.y[1] > 1 && d->ray.y[1] < d->mapY))
// 	{
// 		if (d->map[(int)d->ray.y[1]][(int)d->ray.x[1] + sign] &&
// 			d->map[(int)d->ray.y[1]][(int)d->ray.x[1] + sign] == '2')
// 			catch_sprite(d, 1);
// 		d->ray.y[1] += d->ray.yoffset;
// 		d->ray.x[1] += d->ray.xoffset;
// 	}
// }
// void	look_lr_sprite(t_data *d)
// {
// 	d->ray.t = -tan(d->ray.dir);
// 	if (d->ray.dir > M_PI_2 && d->ray.dir < 3 * M_PI_2)
// 	{
// 		d->ray.x[1] = (int)d->player.pos_x + 1;
// 		d->ray.y[1] = (d->player.pos_x - d->ray.x[1]) * d->ray.t +
// 		d->player.pos_y;
// 		d->ray.xoffset = 1;
// 		d->ray.yoffset = -(d->ray.xoffset) * d->ray.t;
// 	}
// 	else if (d->ray.dir < M_PI_2 || d->ray.dir > 3 * M_PI_2)
// 	{
// 		d->ray.x[1] = (int)d->player.pos_x;
// 		d->ray.y[1] = (d->player.pos_x - d->ray.x[1]) * d->ray.t +
// 		d->player.pos_y;
// 		d->ray.xoffset = -1;
// 		d->ray.yoffset = -(d->ray.xoffset) * d->ray.t;
// 	}
// 	loop_lr_sprite(d);
// }
void	dda_sprite(t_data *d)
{
	look_tb_sprite(d);
	// look_lr_sprite(d);
}