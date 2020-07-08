/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 03:12:26 by idouidi           #+#    #+#             */
/*   Updated: 2020/07/08 05:35:01 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void    draw_wall(t_data *d, float raydist, int i, int tmp_x)
{
    float	tmp_y;

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

void	raycasting(t_data *d, int keycode)
{
	 if (keycode == 12 || keycode == 14)
        rotation(d, keycode);
	get_ray_size(d);
}
