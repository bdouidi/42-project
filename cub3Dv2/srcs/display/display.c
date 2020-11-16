/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:28:33 by idouidi           #+#    #+#             */
/*   Updated: 2020/11/16 23:48:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			drawmap2d(t_data *d, int *check)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	d->square.width = ((d->res[0] * .65) / d->map_x);
	d->square.height = d->square.width;
	if (checksizemap(d, &check) == -1)
		return ;
	while (d->map[y])
	{
		while (d->map[y][x])
		{
			d->square.imgx = x * d->square.width;
			d->square.imgy = y * d->square.height;
			if (d->map[y][x] == '0')
				drawsquare(d, 0xFFFFFF);
			else if (d->map[y][x] == '2')
				drawsquare(d, 0xFF0000);
			x++;
		}
		x = 0;
		y++;
	}
	drawplayer(d);
}

void			load_texture(t_data *d, char *tex_path, int i)
{
	d->texture.tex[i] = mlx_xpm_file_to_image(d->vars.mlx, tex_path,
					&d->texture.width[i], &d->texture.height[i]);
	d->texture.addr[i] = mlx_get_data_addr(d->texture.tex[i],
						&d->texture.bpp[i], &d->texture.szl[i],
						&d->texture.endian[i]);
}

static void		display(t_data *d)
{
	d->x = -1;
	d->y = -1;
	while (d->y++ < d->res[1] / 2)
	{
		while (d->x++ < d->res[0])
		{
			my_mlx_pixel_put(d, d->c_color);
		}
		d->x = 0;
	}
	while (d->y < d->res[1])
	{
		while (d->x < d->res[0])
		{
			my_mlx_pixel_put(d, d->f_color);
			d->x++;
		}
		d->y++;
		d->x = 0;
	}
	raycasting(d);
}

static int		handlekeys(int keycode, t_data *d)
{
	static int	check = 0;

	if (keycode == 65307)
	{
		mlx_destroy_window(d->vars.mlx, d->vars.win);
		write(1, "Exit\n", 5);
		exit(1);
	}
	if (keycode == 109)
		check++;
	if (keycode == 119 || keycode == 100 || keycode == 97 || keycode == 115)
		which_dir(d, keycode);
	if (keycode == 65361 || keycode == 65363)
		rotation(d, keycode);
	if (check % 2 != 0)
	{
		mlx_clear_window(d->vars.mlx, d->vars.win);
		display(d);
		drawmap2d(d, &check);
	}
	else
		display(d);
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img.ptr[0], 0, 0);
	return (0);
}

void			window(t_data *d)
{
	d->sizex = 0;
	d->sizey = 0;
	d->vars.mlx = mlx_init();
	mlx_get_screen_size(d->vars.mlx, &d->sizex, &d->sizey);
	d->res[0] = (d->res[0] > d->sizex) ? d->sizex : d->res[0];
	d->res[1] = (d->res[1] > d->sizey) ? d->sizey : d->res[1];
	d->vars.win = mlx_new_window(d->vars.mlx, d->res[0], d->res[1],
			"Cub3d");
	if (!d->img.ptr[0])
		create_img(d, 0, d->res[0], d->res[1]);
	load_texture(d, d->sprite, 0);
	load_texture(d, d->north, 1);
	load_texture(d, d->south, 2);
	load_texture(d, d->east, 3);
	load_texture(d, d->west, 4);
	load_texture(d, "./files/textures/epee.xpm", 5);
	init_player(d);
	display(d);
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img.ptr[0], 0, 0);
	mlx_hook(d->vars.win, 2, (1L << 0), handlekeys, d);
	mlx_hook(d->vars.win, 33, 1L << 17, cross_window, d);
	mlx_loop(d->vars.mlx);
}
