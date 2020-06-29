/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:39:55 by idouidi           #+#    #+#             */
/*   Updated: 2020/06/29 22:37:52 by othabchi         ###   ########.fr       */
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

void	create_img(t_data *d, int i, int width, int height)
{
	d->img.ptr[i] = mlx_new_image(d->vars.mlx, width, height);
	d->img.addr[i] = mlx_get_data_addr(d->img.ptr[i], &d->img.bits_per_pixel,
				&d->img.line_length, &d->img.endian);
}
