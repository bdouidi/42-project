/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 03:12:26 by idouidi           #+#    #+#             */
/*   Updated: 2020/08/06 15:07:44 by othabchi         ###   ########.fr       */
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

void	struct_swap(t_data *d, int i, int j)
{
	t_sprite tmp;

	tmp.x[0] = d->spt[i].x[0];
	tmp.y[0] = d->spt[i].y[0];
	tmp.dist[0] = d->spt[i].dist[0];
	tmp.johnny = d->spt[i].johnny;

	d->spt[i].x[0] = d->spt[j].x[0];
	d->spt[i].y[0] = d->spt[j].y[0];
	d->spt[i].dist[0] = d->spt[j].dist[0];
	d->spt[i].johnny = d->spt[j].johnny;

	d->spt[j].x[0] = tmp.x[0];
	d->spt[j].y[0] = tmp.y[0];
	d->spt[j].dist[0] = tmp.dist[0];
	d->spt[j].johnny = tmp.johnny;
}

void	struct_sort(t_data *d)
{
	int i;
	int j;

	// i = -1;
	// while (++i < d->texture.count_spt)
	// 	if ((d->spt[i].dist[1] > 0 && d->spt[i].dist[1] < d->spt[i].dist[0]) ||
	// 		d->spt[i].dist[0] == 0)
	// 	{
	// 		d->spt[i].x[0] = d->spt[i].x[1];
	// 		d->spt[i].y[0] = d->spt[i].y[1];
	// 		d->spt[i].dist[0] = d->spt[i].dist[1];
	// 		d->spt[i].coordinate = 1;
	// 	}
	i = 0;
	while (i < d->texture.count_spt - 1)
	{
		j = i + 1;
		if (d->spt[i].dist[0] < d->spt[j].dist[0])
		{
			struct_swap(d, i, j);
			i = 0;
		}
		else
			i++;
	}
}

int		get_spt_color(t_data *d, int i, int line_height)
{
	char	*color;
	double	tex_y;

	tex_y = (d->y * 2 - d->res[1] + line_height) *
		(d->texture.height[0] / 2) / line_height;
	d->tex_x = (d->spt[i].x[0] - (int)d->spt[i].x[0]) * d->texture.width[0];
	printf("%f = (%f - %d) * %d\n", d->tex_x, d->spt[i].x[0], (int)d->spt[i].x[0], d->texture.width[0]);
	// d->spt[i].y[0] -= d->spt[i].gap[1];
	// d->spt[i].x[0] -= d->spt[i].gap[0];
	// printf("%f - %f\n", d->spt[i].gap[0], d->spt[i].gap[1]);
	// if (d->spt[i].coordinate == 1)
	// 	d->tex_x = d->texture.width[0] - ((d->spt[i].y[0] - (int)d->spt[i].y[0]) *
	// 			d->texture.width[0]) - 1;
	// else
	// 	d->tex_x = d->texture.width[0] - ((d->spt[i].x[0] - (int)d->spt[i].x[0]) *
	// 			d->texture.width[0]) - 1;
	color = d->texture.addr[0] + (abs((int)tex_y) * d->texture.szl[0] +
	(int)d->tex_x * (d->texture.bpp[0] / 8));
	return (*(unsigned int*)color);
}

void	drawsprite(t_data *d, int i)
{
	int		trueheight;
	float	tmp_y;
	int		k;
	float	j;
	float	z;
	int		def;
	int		abc;

	d->x = (d->spt[i].johnny - d->player.rayone) /
			((M_PI / 3) / d->res[0]);
	d->spt[i].height = d->res[1] / d->spt[i].dist[0];
	trueheight = d->spt[i].height;
	// printf("\n****************\nIndex = %d\nd->x = %f	d->y = %f\nheight = %d		trueheight = %d\n", i, d->x, d->y, d->spt[i].height, trueheight);
	if (d->spt[i].height > d->res[1])
		d->spt[i].height = d->res[1] - 1;
	d->y = d->res[1] * .5 - d->spt[i].height * .5;
	tmp_y = d->y;
	j = (int)d->spt[i].x[0] + 1;
	abc = d->spt[i].height / j;
	z = (int)d->spt[i].y[0] + 1;
	def = d->spt[i].height / z;
	if (d->spt[i].coordinate == 0)
		while (abc-- && d->x < d->res[0])
		{
			d->y = tmp_y;
			k = d->spt[i].height;
		// printf("1 - %f = (%f - %f) / ((%f) / %d)\n",
		// d->x, d->spt[i].johnny, d->player.rayone, M_PI / 3, (int)d->res[0]);
			if (d->x > 0 && d->spt[i].dist[0] < d->rays[(int)d->x])
				while (k)
				{
					my_mlx_pixel_put(d, get_spt_color(d, i, trueheight));
					d->y++;
					k--;
				}
			d->spt[i].x[0] += abc / j;
			d->x++;
		}
	else
		while (def-- && d->x < d->res[0])
		{
			d->y = tmp_y;
			k = d->spt[i].height;
		// printf("2 - %f = (%f - %f) / ((%f) / %d)\n",
		// d->x, d->spt[i].johnny, d->player.rayone, M_PI / 3, (int)d->res[0]);
			if (d->x > 0 && d->spt[i].dist[0] < d->rays[(int)d->x])
				while (k)
				{
					my_mlx_pixel_put(d, get_spt_color(d, i, trueheight));
					d->y++;
					k--;
				}
			d->spt[i].y[0] += def / z;
			d->x++;
		}
		
}

void	clearstruct(t_data *d)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (b < 2)
	{
		while (i < d->texture.count_spt)
		{
			d->spt[i].x[b] = 0;
			d->spt[i].y[b] = 0;
			d->spt[i].gap[b] = 0;
			d->spt[i].dist[b] = 0;
			d->spt[i].flag[b] = 0;
			d->spt[i].coordinate = 0;
			i++;
		}
		i = 0;
		b++;
	}
}

void	raycasting(t_data *d)
{
	int i;

	i = 0;
	clearstruct(d);
	drawfov(d);
	struct_sort(d);
	for (int j = 0; j < d->texture.count_spt ; j++)
		printf("Index %d:\n- x = [0]%f - [1]%f\n- y = [0]%f - [1]%f\n\n ---------------- \n",
		 j, d->spt[j].x[0], d->spt[j].x[1], d->spt[j].y[0], d->spt[j].y[1]);
	while (d->spt[i].dist[0] > 0)
	{
	// printf("%f = (%f - %f) / (%f)\n", d->x, d->spt[i].johnny, d->player.rayone, (M_PI / 3) / d->res[0]);
		drawsprite(d, i);
		i++;
	}
}

		// printf("Index %d:\n- x = [0]%f - [1]%f\n- y = [0]%f - [1]%f\n- dist = [0]%f - [1]%f\n       johnny = %f\n\n ---------------- \n",
		//  j, d->spt[j].x[0], d->spt[j].x[1], d->spt[j].y[0], d->spt[j].y[1]
		//  , d->spt[j].dist[0], d->spt[j].dist[1], d->spt[j].johnny);