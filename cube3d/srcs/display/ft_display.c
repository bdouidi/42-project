/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 19:30:36 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/24 20:39:18 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void			my_mlx_pixel_put(t_data *d, int i, int color)
{
	char *dst;

	dst = d->img.addr[i] + (d->y * d->img.line_length + d->x * (d->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static	void	drawsquare(t_data *d, int i, int color)
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

void			drawmap2d(t_data *d)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	if (!d->img.ptr[1])
	{
		d->img.ptr[1] = mlx_new_image(d->vars.mlx, d->square.width, d->square.height);
		d->img.addr[1] = mlx_get_data_addr(d->img.ptr[1], &d->img.bits_per_pixel,
				&d->img.line_length, &d->img.endian);
	}
	while (d->map[y])
	{
		while (d->map[y][x])
		{
			d->square.imgx = x * d->square.width;
			d->square.imgy = y * d->square.height;
			if (d->map[y][x] == '0')
				drawsquare(d, 1, 0x60FFFFFF);
			else if (d->map[y][x] == '2')
				drawsquare(d, 1, 0x60FF0000);
			else if (ft_isalpha(d->map[y][x]) == 1)
				drawsquare(d, 1, 0x60452152);
			x++;
		}
		x = 0;
		y++;
	}
}

void			ft_swap(char *a, char *b)
{
	char set;

	set = *a;
	*a = *b;
	*b = set;
}

static int		handlekeys(int keycode, t_data *d)
{
	static int	check = 0;
	int			*x;
	int			*y;

	x = &(d->player.pos_x);
	y = &(d->player.pos_y);
	if (keycode == 53)
	{
		mlx_destroy_window(d->vars.mlx, d->vars.win);
		exit(1);
	}
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img.ptr[0], 0, 0);
	if (keycode == 0)
		check++;
	if (keycode == 123 && d->map[*y][*x - 1] && d->map[*y][*x - 1] == '0')
	{
		ft_swap(&d->map[*y][*x], &d->map[*y][*x - 1]);
		(*x)--;
	}
	if (keycode == 124 && d->map[*y][*x + 1] && d->map[*y][*x + 1] == '0')
	{
		ft_swap(&d->map[*y][*x], &d->map[*y][*x + 1]);
		(*x)++;
	}
	if (keycode == 125 && d->map[*y + 1][*x] && d->map[*y + 1][*x] == '0')
	{
		ft_swap(&d->map[*y][*x], &d->map[*y + 1][*x]);
		(*y)++;
	}
	if (keycode == 126 && d->map[*y - 1][*x] && d->map[*y - 1][*x] == '0')
	{
		ft_swap(&d->map[*y][*x], &d->map[*y - 1][*x]);
		(*y)--;
	}
	if (check % 2 != 0)
		drawmap2d(d);
	return (0);
}

static void		display_floor_ceiling(t_data *d)
{

	d->x = 0;
	d->y = 0;
	while (d->y < d->res[1] / 2)
	{
		while (d->x < d->res[0])
		{
			my_mlx_pixel_put(d, 0, d->c_color);
			d->x++;
		}
		d->y++;
		d->x = 0;
	}
	while (d->y < d->res[1])
	{
		while (d->x < d->res[0])
		{
			my_mlx_pixel_put(d, 0, d->f_color);
			d->x++;
		}
		d->y++;
		d->x = 0;
	}
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img.ptr[0], 0, 0);
}


void			window(t_data *d)
{
	d->vars.mlx = mlx_init();
	d->vars.win = mlx_new_window(d->vars.mlx, d->res[0], d->res[1],
			"PAYPAL/BDOUIDI");
	d->img.ptr[0] = mlx_new_image(d->vars.mlx, d->res[0], d->res[1]);
	d->img.addr[0] = mlx_get_data_addr(d->img.ptr[0], &d->img.bits_per_pixel,
			&d->img.line_length, &d->img.endian);
	display_floor_ceiling(d);
	mlx_hook(d->vars.win, 2, (1L << 0), handlekeys, d);
	mlx_loop(d->vars.mlx);
}
