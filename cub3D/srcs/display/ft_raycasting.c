/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 03:12:26 by idouidi           #+#    #+#             */
/*   Updated: 2020/07/20 18:07:42 by idouidi          ###   ########.fr       */
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

int		get_tex_color(t_data *d, int i, int line_height)
{
	char	*color;
	double	tex_y;
	double	tex_x;

	tex_y = (d->y * 2 - d->res[1] + line_height) *
		(d->texture.height[i] / 2) / line_height;
	if (i == 1 || i == 2)
		tex_x = d->texture.width[i] - ((d->ray.x[0] - (int)d->ray.x[0]) *
		d->texture.width[i]) - 1;
	else
		tex_x = d->texture.width[i] - ((d->ray.y[1] - (int)d->ray.y[1]) *
		d->texture.width[i]) - 1;
	color = d->texture.addr[i] + (abs((int)tex_y) * d->texture.szl[i] +
	(int)tex_x * (d->texture.bpp[i] / 8));
	return (*(unsigned int*)color);
}

void	draw_wall(t_data *d, double raydist, int i, int tmp_x)
{
	double	tmp_y;
	int		true_line_height;

	raydist = fisheye(d, raydist);
	d->x = tmp_x;
	d->ray.line_height = d->res[1] / raydist;
	true_line_height = d->ray.line_height;
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
		my_mlx_pixel_put(d, get_tex_color(d, i, true_line_height));
		d->y++;
	}
}

void	raycasting(t_data *d)
{
	drawfov(d);
	//drawsprite(d);
}
