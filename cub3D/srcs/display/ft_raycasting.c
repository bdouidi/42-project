/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 03:12:26 by idouidi           #+#    #+#             */
/*   Updated: 2020/07/08 07:51:00 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	fisheye(t_data *d, double raydist)
{
	double   new_angle;

	new_angle = d->player.dir - d->player.fov;
	if (new_angle < 0)
		new_angle += 2 * M_PI;
	if (new_angle > 2 * M_PI)
		new_angle -= 2 * M_PI;
	return (raydist * cos(new_angle));
}

void	draw_wall(t_data *d, double raydist, int i, int tmp_x)
{
	double	tmp_y;
	
	raydist = fisheye(d, raydist);
	d->x = tmp_x;
	d->ray.line_height = d->res[1] / raydist;
	if (d->ray.line_height > d->res[1])
		d->ray.line_height = d->res[1] - 1;
	d->y = d->res[1] / 2 - d->ray.line_height / 2;
	tmp_y = d->y;
	while (d->y < d->ray.line_height + tmp_y)
	{
		i == 0 ? my_mlx_pixel_put(d, 0x034EB83) : my_mlx_pixel_put(d, 0x0144F2D);
		d->y++;
	}
}

void	raycasting(t_data *d)
{
	get_ray_size(d);
}
