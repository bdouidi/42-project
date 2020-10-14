/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 03:12:26 by idouidi           #+#    #+#             */
/*   Updated: 2020/10/05 13:27:07 by othabchi         ###   ########.fr       */
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
	tmp.gap = d->spt[i].gap;

	d->spt[i].x[0] = d->spt[j].x[0];
	d->spt[i].y[0] = d->spt[j].y[0];
	d->spt[i].dist[0] = d->spt[j].dist[0];
	d->spt[i].johnny = d->spt[j].johnny;
	d->spt[i].gap = d->spt[j].gap;

	d->spt[j].x[0] = tmp.x[0];
	d->spt[j].y[0] = tmp.y[0];
	d->spt[j].dist[0] = tmp.dist[0];
	d->spt[j].johnny = tmp.johnny;
	d->spt[i].gap = tmp.gap;
}

void	struct_sort(t_data *d)
{
	int i;
	int j;

	i = -1;
	// 	if ((d->spt[i].dist[1] > 0 && d->spt[i].dist[1] < d->spt[i].dist[0]) ||
	// 		d->spt[i].dist[0] == 0)
	// 	{
	// 		d->spt[i].x[0] = d->spt[i].x[1];
	// 		d->spt[i].y[0] = d->spt[i].y[1];
	// 		d->spt[i].dist[0] = d->spt[i].dist[1];
	// 		d->spt[i].coordinate = 1;
	// 	}
	while (++i < d->texture.count_spt)
		d->spt[i].gap -= d->spt[i].johnny;
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

int		get_spt_color(t_data *d, int spriteHeight, int spriteWidth, int stripe, int spriteScreenX)
{
	char	*color;
	double	tex_y;
	double	tex_x;

	tex_y = (d->y * 2 - d->res[1] + spriteHeight) *
		(d->texture.height[0] / 2) / spriteHeight;
	tex_x = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * d->texture.width[0] / spriteWidth) / 256;
	color = d->texture.addr[0] + (abs((int)tex_y) * d->texture.szl[0] +
	(int)tex_x * (d->texture.bpp[0] / 8));
	return (*(unsigned int*)color);
	
	// tex_x = d->texture.width[0] - ((d->ray.x[0] - (int)d->ray.x[0]) *
	// 	d->texture.width[0]) - 1;
	// int color;
	// double	tex_y;

	// tex_y = (d->y * 2 - d->res[1] + line_height) *
	// 	(d->texture.height[0] / 2) / line_height;
	// d->tex_x = fabs(d->spt[i].x[0] - (int)d->spt[i].x[0]) * d->texture.width[0];
	// // d->spt[i].y[0] -= d->spt[i].gap[1];
	// // d->spt[i].x[0] -= d->spt[i].gap[0];
	// // printf("%f - %f\n", d->spt[i].gap[0], d->spt[i].gap[1]);
	// // if (d->spt[i].coordinate == 1)
	// // 	d->tex_x = d->texture.width[0] - ((d->spt[i].y[0] - (int)d->spt[i].y[0]) *
	// // 			d->texture.width[0]) - 1;
	// // else
	// // 	d->tex_x = d->texture.width[0] - ((d->spt[i].x[0] - (int)d->spt[i].x[0]) *
	// // 			d->texture.width[0]) - 1;
	// color = (int)d->texture.addr[0][abs((int)tex_y) * d->texture.szl[0] +
	// (int)d->tex_x * (d->texture.bpp[0] / 8)];
}

void	drawsprite(t_data *d)
{
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		spriteHeight;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
	int		drawStartY;
	int		drawEndY;
	int		color = 0;
	float	planeX, planeY, nine;

	nine = d->player.dir + M_PI_2;
	planeX = cos(nine);
	planeY = sin(nine);
	for (int i = 0; i < d->texture.count_spt ; i++)
	{
		spriteX = (int)d->spt[i].x[0] - d->player.pos_x;
		spriteY = (int)d->spt[i].y[0] - d->player.pos_y;
		invDet = 1 / (planeX * sin(d->player.dir) - cos(d->player.dir) * planeY);
		transformX = invDet * (sin(d->player.dir) * spriteX - cos(d->player.dir) * spriteY);
		transformY = invDet * (-planeY * spriteX + planeX * spriteY);
		spriteScreenX = (int)((d->res[0] / 2) * (1 + transformX / transformY));
		spriteHeight = abs((int)(d->res[1] / transformY));
		spriteWidth = abs((int)(d->res[1] / transformY));
		drawStartY = -spriteHeight / 2 + d->res[1] / 2;
		drawEndY = spriteHeight / 2 + d->res[1] / 2;
		drawStartX = -spriteWidth / 2 + spriteScreenX;
		drawEndX = spriteWidth / 2 + spriteScreenX;
		printf("planeX = %f, planeY = %f\ndir = %f | dirX = %f, dirY = %f\nstartY = %d, endY = %d\n", planeX, planeY, d->player.dir, cos(d->player.dir), sin(d->player.dir), drawStartX, drawEndY);
		if (drawStartY < 0)
			drawStartY = 0;
		if (drawEndY >= d->res[1])
			drawEndY = d->res[1] - 1;
		if (drawStartX < 0)
			drawStartX = 0;
		if (drawEndX >= d->res[0])
			drawEndX = d->res[0] - 1;
		for	(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			d->x = stripe;
			d->y = drawStartY;
			if (d->x > 0 && d->spt[i].dist[0] < d->rays[(int)d->x])
			{	
				for (int col = drawStartY; col < drawEndY; col++)
				{
					d->y = col;
					color = get_spt_color(d, spriteHeight, spriteWidth, stripe, spriteScreenX);
					if (color > 5)
					// -
					// dans rotation ajouter fonction qui gere les vecteurs
					// + corriger le bail de planeXY
					// + mettre ca propre dans un .h
					// -
						my_mlx_pixel_put(d, color);
				}
			}
		}
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
			d->spt[i].dist[b] = 0;
			d->spt[i].flag[b] = 0;
			d->spt[i].gap = 0;
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
	drawsprite(d);
	if (d->save == 1)
	{
		create_bitmap(d);
		exit(1);
	}
}
	// printf("%f = (%f - %f) / (%f)\n", d->x, d->spt[i].johnny, d->player.rayone, (M_PI / 3) / d->res[0]);
	// for (int j = 0; j < d->texture.count_spt ; j++)
	// 	printf("Index %d:\n- x = [0]%f - [1]%f\n- y = [0]%f - [1]%f\n		%f\n\n ---------------- \n",
	// 	 j, d->spt[j].x[0], d->spt[j].x[1], d->spt[j].y[0], d->spt[j].y[1], d->spt[i].gap);

		// printf("Index %d:\n- x = [0]%f - [1]%f\n- y = [0]%f - [1]%f\n- dist = [0]%f - [1]%f\n       johnny = %f\n\n ---------------- \n",
		//  j, d->spt[j].x[0], d->spt[j].x[1], d->spt[j].y[0], d->spt[j].y[1]
		//  , d->spt[j].dist[0], d->spt[j].dist[1], d->spt[j].johnny);
	
	
                    	/*****************************/

// void	drawsprite(t_data *d, int i)
// {
// 	double	hx;
// 	double	hy;
// 	double	p;
// 	double	sprite_screenx, sprite_screeny;
//	double	angledir;
	
//	angledir = d->player.dir * (180 / M_PI);
// 	hx = (int)d->spt[i].x[0] - (int)d->player.pos_x;
// 	hy = (int)d->spt[i].y[0] - (int)d->player.pos_y;

// 	p = atan2f(-hy, hx);
// 	p *= (180 / M_PI);
// 	printf("1 %f\n", p);
// 	if (p < 0)
// 		p += 360;
// 	printf("2 %f\n", p);

// 	if (p < 0)
// 		p += 360;
// 	if (p > 360)
// 		p -= 360;

// 	// if (p <= 360 && p > 270)
// 	// 	p -= ((p - 270) * 2);
// 	// else if (p >= 180 && p < 270)
// 	// 	p += ((270 - p) * 2);
// 	// else if (p < 180 && p > 90)
// 	// 	p -= ((p - 90) * 2);
// 	// else if (p >= 0 && p < 90)
// 	// 	p += ((90 - p) * 2);
		
// 	sprite_screenx = p - (d->player.rayone * (180 / M_PI));
// 	printf("3 %f, %f\n", p, sprite_screenx);


// 	if (angledir > 90 && p < 270)
// 		sprite_screenx = angledir + 30 - p + 360;
// 	if (angledir > 270 && p < 90)
// 		sprite_screenx = angledir + 30 - p - 360;
// 	if (sprite_screenx < 0)
// 		sprite_screenx += 360;

// 	sprite_screeny = d->res[1] * .5;
// 	printf("%f | %f : %f - %f\n", sprite_screenx, p, hx, hy);

	
// 	int		trueheight;
// 	float	tmp_y;
// 	float	tmp_x;
// 	int		k;

// 	d->spt[i].height = d->res[1] / d->spt[i].dist[0];
// 	trueheight = d->spt[i].height;
	
// 	// printf("\n****************\nIndex = %d\nd->x = %f	d->y = %f\nheight = %d		trueheight = %d\n", i, d->x, d->y, d->spt[i].height, trueheight);
	
// 	if (d->spt[i].height > d->res[1])
// 		d->spt[i].height = d->res[1] - 1;

// 	d->x = fabs(sprite_screenx) + d->spt[i].height * .5;

// 	// d->x = (d->spt[i].johnny - d->player.rayone) /
// 	// 		((M_PI / 3) / d->res[0]);
	
// 	tmp_x = d->x;
// 	d->y = d->res[1] * .5 - d->spt[i].height * .5;
// 	d->spt[i].width = d->spt[i].height;
// 	tmp_y = d->y;

// 	// printf("[%f]	%f = %f - %f\n", d->x, sprite_screenx, d->player.rayone * (180 / M_PI), p);
// 	while (d->x < tmp_x + d->spt[i].width && d->x < d->res[0])
// 	{
// 		d->y = tmp_y;
// 		k = d->spt[i].height;
// 	// printf("1 - %f = (%f - %f) / ((%f) / %d)\n",
// 	// d->x, d->spt[i].johnny, d->player.rayone, M_PI / 3, (int)d->res[0]);
// 		if (d->x > 0 && d->spt[i].dist[0] < d->rays[(int)d->x])
// 			while (k)
// 			{
// 				// printf("[%d] %f = (%f - %d) * %d\n", i, d->tex_x, d->spt[i].x[0], (int)d->spt[i].x[0], d->texture.width[0]);
// 				my_mlx_pixel_put(d, get_spt_color(d, i, trueheight));
// 				d->y++;
// 				k--;
// 			}
// 		d->spt[i].x[0] += d->spt[i].gap;
// 		d->x++;
// 	}
// }

                         /*********////*******************//