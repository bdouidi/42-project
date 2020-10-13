/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:39:38 by othabchi          #+#    #+#             */
/*   Updated: 2020/10/13 19:46:49 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	wall_loop(t_data *d)
{
	d->x = 0;
	while (d->x < d->res[0])
	{
		d->cameraX = 2 * d->x / d->res[0] - 1;
		d->ray.dirX = d->player.dir_x + d->ray.planeX * d->cameraX;
		d->ray.dirY = d->player.dir_y + d->ray.planeY * d->cameraX;
		dda(d);
		//dda_sprite(d);
		d->x++;
	}
}

void raycasting(t_data *d)
{
	wall_loop(d);
}