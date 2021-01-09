/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:39:38 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/09 15:58:24 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	do_walls(t_data *d)
{
	d->x = 0;
	while (d->x < d->res[0])
	{
		d->camera_x = 2 * d->x / d->res[0] - 1;
		d->ray.dir_x = d->player.dir_x + d->ray.plane_x * d->camera_x;
		d->ray.dir_y = d->player.dir_y + d->ray.plane_y * d->camera_x;
		dda(d);
		d->x++;
	}
}

void	raycasting(t_data *d)
{
	do_walls(d);
	do_sprites(d);
	if (d->save == 1)
	{
		create_bitmap(d);
		exit(1);
	}
}
