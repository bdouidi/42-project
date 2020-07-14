/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 03:12:26 by idouidi           #+#    #+#             */
/*   Updated: 2020/07/14 16:27:03 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	fisheye(t_data *d, double raydist)
{
	double	new_angle;

	new_angle = d->player.dir - d->player.fov;
	if (new_angle < 0)
		new_angle += 2 * M_PI;
	if (new_angle > 2 * M_PI)
		new_angle -= 2 * M_PI;
	return (raydist * cos(new_angle));
}

int		get_tex_color(t_data *d, int i, int tmp_y)
{
	char	*dst;
	double	ratio;
	double	posy;
	double	posx;

	ratio = d->ray.line_height / d->texture.height;
	posy = (d->y - tmp_y) / ratio;
	ratio = 200 / d->texture.width;
	posx = d->x / ratio;
	dst = d->texture.addr[i] + ((int)posy * d->texture.height + (int)posx *
	(d->texture.width / 8));
	// printf("%u\n", *(unsigned int*)dst);
	return (*(unsigned int*)dst);
}

void	draw_wall(t_data *d, double raydist, int i, int tmp_x)
{
	double	tmp_y;

	raydist = fisheye(d, raydist);
	d->x = tmp_x;
	d->ray.line_height = d->res[1] / raydist;
	if (d->ray.line_height > d->res[1])
		d->ray.line_height = d->res[1] - 1;
	d->y = (d->res[1] / 2 - d->ray.line_height / 2) - 1;
	tmp_y = d->y;
	if (i == 0)
		i = ((d->player.pos_y - d->ray.y[0]) > 0) ? 1 : 2;
	else if (i == 1)
		i = ((d->player.pos_x - d->ray.x[1]) > 0) ? 3 : 4;
	while (d->y <= d->ray.line_height + tmp_y)
	{
		if (i == 1 || i == 2)
			i == 1 ? my_mlx_pixel_put(d, get_tex_color(d, i, tmp_y)) :
			my_mlx_pixel_put(d, 0x144F2D);
		else if (i == 3 || i == 4)
			i == 3 ? my_mlx_pixel_put(d, 0xeff542) :
			my_mlx_pixel_put(d, 0xf59642);
		d->y++;
	}
}

void	raycasting(t_data *d)
{
	get_ray_size(d);
}
