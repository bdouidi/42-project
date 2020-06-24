/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:39:55 by idouidi           #+#    #+#             */
/*   Updated: 2020/06/24 22:46:56 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_position(t_data *d)
{
	int	i;

	i = 0;
	d->len = 0;
	while (d->map[d->len])
	{
		while (d->map[d->len][i])
		{
			if (ft_isalpha(d->map[d->len][i]) == 1)
			{
				d->player.pos_y = d->len;
				d->player.pos_x = i;
			}
			i++;
		}
		i = 0;
		d->len++;
	}
	d->len--;
}

void	drawsquare(t_data *d, int i, int color)
{
	d->x = 0;
	d->y = 0;
	while (d->y < d->square.height)
	{
		while (d->x < d->square.width)
		{
			my_mlx_pixel_put(d, i, color);
			d->x++;
		}
		d->y++;
		d->x = 0;
	}
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img.ptr[i],
			d->square.imgx, d->square.imgy);
}

void	my_mlx_pixel_put(t_data *d, int i, int color)
{
	char *dst;

	dst = d->img.addr[i] + (d->y * d->img.line_length + d->x *
	(d->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	create_img(t_data *d, int i, int width, int height)
{
	d->img.ptr[i] = mlx_new_image(d->vars.mlx, width, height);
	d->img.addr[i] = mlx_get_data_addr(d->img.ptr[i], &d->img.bits_per_pixel,
				&d->img.line_length, &d->img.endian);
}
