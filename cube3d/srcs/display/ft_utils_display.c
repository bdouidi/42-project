/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:39:55 by idouidi           #+#    #+#             */
/*   Updated: 2020/07/01 16:31:05 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_data *d, int color)
{
	char *dst;

	dst = d->img.addr[0] + ((int)d->y * d->img.line_length + (int)d->x *
	(d->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_player(t_data *d)
{
	d->player.height = 0.5 * d->res[1];
	if (d->player.letter == 'N')
		d->player.dir = M_PI / 2;
	else if (d->player.letter == 'E')
		d->player.dir = 0;
	else if (d->player.letter == 'S')
		d->player.dir = (3 * M_PI) / 2;
	else if (d->player.letter == 'W')
		d->player.dir = M_PI;
}

void	which_dir2(t_data *d, float spd, int keycode)
{
	int	x;
	int	y;

	if (keycode == 125)
	{
		x = (int)(d->player.pos_x + cos(d->player.dir) * spd);
		y = (int)(d->player.pos_y + sin(d->player.dir) * spd);
		if (d->map[y][x] && d->map[y][x] == '0')
		{
			d->player.pos_x += cos(d->player.dir) * spd;
			d->player.pos_y += sin(d->player.dir) * spd;
		}
	}
	if (keycode == 126)
	{
		x = (int)(d->player.pos_x - cos(d->player.dir) * spd);
		y = (int)(d->player.pos_y - sin(d->player.dir) * spd);
		if (d->map[y][x] && d->map[y][x] == '0')
		{
			d->player.pos_x -= cos(d->player.dir) * spd;
			d->player.pos_y -= sin(d->player.dir) * spd;
		}
	}
}

void	set_position(t_data *d)
{
	int	i;

	i = 0;
	d->mapY = 0;
	while (d->map[d->mapY])
	{
		while (d->map[d->mapY][i])
		{
			if (ft_isalpha(d->map[d->mapY][i]) == 1)
			{
				d->player.pos_y = d->mapY + .5;
				d->player.pos_x = i + .5;
				d->player.letter = d->map[d->mapY][i];
				d->map[d->mapY][i] = '0';
			}
			i++;
		}
		d->mapX = i;
		i = 0;
		d->mapY++;
	}
	d->mapY--;
}

void	create_img(t_data *d, int i, int width, int height)
{
	d->img.ptr[i] = mlx_new_image(d->vars.mlx, width, height);
	d->img.addr[i] = mlx_get_data_addr(d->img.ptr[i], &d->img.bits_per_pixel,
				&d->img.line_length, &d->img.endian);
}
