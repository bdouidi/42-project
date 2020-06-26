/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:39:55 by idouidi           #+#    #+#             */
/*   Updated: 2020/06/26 07:04:13 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_data *d, int color)
{
	char *dst;

	dst = d->img.addr[0] + (d->y * d->img.line_length + d->x *
	(d->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
				d->player.pos_y = d->len + .5;
				d->player.pos_x = i + .5;
				d->player.letter = d->map[d->len][i];
				d->map[d->len][i] = '0';
			}
			i++;
		}
		i = 0;
		d->len++;
	}
	d->len--;
}

void	drawline(t_data *d, int color)
{
	int count;
	double *dir;

	count = 0;
	dir = &d->player.dir;
	d->x = d->square.imgx + d->square.width / 2;
	d->y = d->square.imgy + d->square.height / 2;
	while (count < 35)
	{
		my_mlx_pixel_put(d, color);
		if (*dir >= 0 && *dir <= M_PI)
		{
			if (*dir >= 0 && *dir <= (M_PI / 2))
			{
				d->x += cos(*dir);
				d->y -= sin(*dir);
			}
			else
			{
				d->x -= cos(*dir);
				d->y -= sin(*dir);
			}
		}
		else
		{
			if (*dir >= M_PI && *dir <= (3 * M_PI / 2))
			{
				d->x -= cos(*dir);
				d->y += sin(*dir);
			}
			else
			{
				d->x += cos(*dir);
				d->y += sin(*dir);
			}
		}
		count++;
	}
}

void	drawsquare(t_data *d, int color)
{
	d->x = d->square.imgx;
	d->y = d->square.imgy;
	while (d->y < (d->square.height + d->square.imgy))
	{
		while (d->x < (d->square.width + d->square.imgx))
		{
			my_mlx_pixel_put(d, color);
			d->x++;
		}
		d->y++;
		d->x = d->square.imgx;
	}
}

void	create_img(t_data *d, int i, int width, int height)
{
	d->img.ptr[i] = mlx_new_image(d->vars.mlx, width, height);
	d->img.addr[i] = mlx_get_data_addr(d->img.ptr[i], &d->img.bits_per_pixel,
				&d->img.line_length, &d->img.endian);
}
