/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 03:12:26 by idouidi           #+#    #+#             */
/*   Updated: 2020/07/01 21:04:00 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_ray_size(t_data *d)
{
        // side = 0;
        d->ray.hit = 0;
		d->ray.x = cos(d->player.fov[0]);
		d->ray.y = sin(d->player.fov[0]);
		d->ray.delta_x = fabs(1 / d->ray.x);
		d->ray.delta_y = fabs(1 / d->ray.y);
        if (d->ray_x < 0)
        {
            d->ray.step_x = -1;
            d->ray.side_dist_x = (d->player.pos_x - (int)d->player.pos_x) * d->ray.delta_x;
        }
        else
        {
            d->ray.step_x = 1;
            d->ray.side_dist_x = (d->player.pos_x - + 1 - (int)d->player.pos_x)* d->ray.delta_x;
        }
        if (d->ray.y < 0)
        {
			d->ray.step_y = -1;
			d->ray.side_dist_y = (d->player.pos_y - (int)d->player.pos_y);
        }
        else
        {
			d->ray.step_x = 1;
			d->ray.side_dist_y = (d->player.pos_y + 1 - (int)d->player.pos_y) * d->ray.delta_y; 
        }
		while (d->ray.hit == 0)
        {
            if (d->ray.side_dist_x < d->ray.side_dist_y)
            {
				d->ray.side_dist_x += d->ray.x;
				(int)d->player.pos_x += d->ray.step_x;
                side = 0;
            }
            else
            {
				d->ray.side_dist_y += d->ray.y;
				(int)d->player.pos_y += d->ray.step_y;
                data.mapY += data.stepY;
                side = 1;
            }
            if (map[(int)data.mapY][(int)data.mapX] == ‘1’ )
                hit = 1;
        }
}
	// int count;
	// float xoffset, yoffset, aTan;

	// d->ray.dir = d->player.fov[0];
	// count = 0;
	// aTan = -1 / tan(d->ray.dir);
	// d->square.width = ((d->res[0] * .45) / ft_strlen(d->map[0]));
	// if (d->ray.dir > M_PI) // regarde en bas
	// {
	// 	d->ray.y = (d->player.pos_y - (int)d->player.pos_y) < .5 ? (int)d->player.pos_y  : (int)d->player.pos_y + 1; 
	// 	d->ray.x = (d->player.pos_y - d->ray.y) * aTan + d->player.pos_x;
	// 	yoffset = -1;
	// 	xoffset = -yoffset * aTan;
	// }
	// if (d->ray.dir < M_PI) // regarde en haut
	// {
	// 	d->ray.y = (d->player.pos_y - (int)d->player.pos_y) < .5 ? (int)d->player.pos_y  : (int)d->player.pos_y + 1;
	// 	d->ray.x = (d->player.pos_y - d->ray.y) * aTan + d->player.pos_x;
	// 	printf("ici %f %f\n", d->ray.y, d->ray.x);
	// 	yoffset = 1;
	// 	xoffset = -yoffset * aTan;
	// }
	// if (d->ray.dir == 0 || d->ray.dir == M_PI)
	// {
	// 	d->ray.y = d->player.pos_y;
	// 	d->ray.x = d->player.pos_x;
	// 	count = d->mapY;
	// }
	// while (count < d->mapY)
	// {
	// 	if (d->map[(int)d->ray.y][(int)d->ray.x] &&
	// 		d->map[(int)d->ray.y][(int)d->ray.x] == '1')
	// 	{
	// 		count = d->mapY;
	// 	}
	// 	else
	// 	{
	// 		d->ray.y -= yoffset;
	// 		d->ray.x += xoffset;
	// 		count++;
	// 	}
	// }
	// printf("ici %d %d %f\n", (int)d->ray.y, (int)d->ray.x, yoffset);
	// drawline(d, d->ray.dir, 0x0FF0000);
// }

void	raycasting(t_data *d)
{
	get_ray_size(d);
}