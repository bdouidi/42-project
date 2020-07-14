/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 03:12:26 by idouidi           #+#    #+#             */
/*   Updated: 2020/07/14 20:17:56 by othabchi         ###   ########.fr       */
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

int		get_tex_color(t_data *d, int i, int y)
{
	char	*dst;
	double	posy;
	double	posx;
	int		color;

	dst = NULL;
	posx = 0;
	if (d->ray.line_height > d->texture.height[y])
		posy = (d->y * 2 - d->res[1] + d->ray.line_height) * (d->texture.height[y] / 2)
	/ d->ray.line_height;
	else
		posy = (d->y * 2 - d->res[1] + d->ray.line_height) / (d->texture.height[y])
	/ d->ray.line_height;
	if (i == 0)
		posx = d->texture.width[y] - ((d->ray.x[i] - (int)d->ray.x[i]) * d->texture.width[y]) - 1;
	else if (i == 1)
		posx = d->texture.width[y] - ((d->ray.y[i] - (int)d->ray.y[i]) * d->texture.width[y]) - 1;
	if (d->texture.addr[y] + ((int)posy * d->texture.szl + (int)posx * (d->texture.bpp / 8)))
		dst = d->texture.addr[y] + ((int)posy * d->texture.szl + (int)posx * (d->texture.bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	draw_wall(t_data *d, double raydist, int i, int tmp_x)
{
	double	tmp_y;
	int		y;

	raydist = fisheye(d, raydist);
	d->x = tmp_x;
	d->ray.line_height = d->res[1] / raydist;
	if (d->ray.line_height > d->res[1])
		d->ray.line_height = d->res[1] - 1;
	d->y = (d->res[1] / 2 - d->ray.line_height / 2) - 1;
	tmp_y = d->y;
	if (i == 0)
		y = ((d->player.pos_y - d->ray.y[0]) > 0) ? 1 : 2;
	else if (i == 1)
		y = ((d->player.pos_x - d->ray.x[1]) > 0) ? 3 : 4;
	while (d->y <= d->ray.line_height + tmp_y)
	{
		my_mlx_pixel_put(d, get_tex_color(d, i, y));// y doit redevenir i;
		d->y++;
	}
}

void	raycasting(t_data *d)
{
	get_ray_size(d);
}
