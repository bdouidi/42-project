/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 19:30:36 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/23 06:07:25 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void			set_position(t_data *d)
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

static	void	drawsquare(t_data *d, int i, int color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < d->square.height)
	{
		while (x < d->square.width)
		{
			my_mlx_pixel_put(d, x, y, color);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img[i],
			d->square.imgx, d->square.imgy);
}

void			drawmap2d(t_data *d)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!d->img[1])
	{
		d->img[1] = mlx_new_image(d->vars.mlx, ft_strlen(d->map[0]), d->len);
		d->addr = mlx_get_data_addr(d->img[1], &d->bits_per_pixel,
				&d->line_length, &d->endian);
	}
	while (d->map[y])
	{
		while (d->map[y][x])
		{
			d->square.imgx = x * 10;
			d->square.imgy = y * 10;
			if (d->map[y][x] == '1')
				drawsquare(d, 1, 0x353535);
			else if (d->map[y][x] == '0')
				drawsquare(d, 1, 0xFFFFFF);
			else if (d->map[y][x] == '2')
				drawsquare(d, 1, 0xFF0000);
			else if (ft_isalpha(d->map[y][x]) == 1)
				drawsquare(d, 1, 0x452152);
			x++;
		}
		x = 0;
		y++;
	}
	d->square.imgx = 0;
	d->square.imgy = 0;
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
	if (keycode == 0)
		check = 1;
	if (check == 1)
	{
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
	}
	if (check == 1)
		drawmap2d(d);
	return (0);
}

static void		display_floor_ceiling(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < d->res[1] / 2)
	{
		while (x < d->res[0])
		{
			my_mlx_pixel_put(d, x, y, d->c_color);
			x++;
		}
		y++;
		x = 0;
	}
	while (y < d->res[1])
	{
		while (x < d->res[0])
		{
			my_mlx_pixel_put(d, x, y, d->f_color);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img[0], 0, 0);
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			window(t_data *d)
{
	d->vars.mlx = mlx_init();
	d->vars.win = mlx_new_window(d->vars.mlx, d->res[0], d->res[1],
			"PAYPAL/BDOUIDI");
	d->img[0] = mlx_new_image(d->vars.mlx, d->res[0], d->res[1]);
	d->addr = mlx_get_data_addr(d->img[0], &d->bits_per_pixel,
			&d->line_length, &d->endian);
	display_floor_ceiling(d);
	set_position(d);
	mlx_hook(d->vars.win, 2, (1L << 0), handlekeys, d);
	mlx_loop(d->vars.mlx);
}
