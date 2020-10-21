/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:39:38 by othabchi          #+#    #+#             */
/*   Updated: 2020/10/21 15:01:40 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	do_walls(t_data *d)
{
	d->x = 0;
	while (d->x < d->res[0])
	{
		d->cameraX = 2 * d->x / d->res[0] - 1;
		d->ray.dirX = d->player.dir_x + d->ray.planeX * d->cameraX;
		d->ray.dirY = d->player.dir_y + d->ray.planeY * d->cameraX;
		dda(d);
		d->x++;
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
}

void	sort_sprites(t_data *d)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < d->count_spt - 1)
	{
		j = i + 1;
		if (d->spt[i].dist < d->spt[j].dist)
		{
			tmp = d->spt[i];
			d->spt[i] = d->spt[j];
			d->spt[j] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	do_sprites(t_data *d)
{
	int z;

	z = 0;
	while (z < d->count_spt)
	{
		// printf("%d\n", z);
		d->spt[z].dist = (pow((d->player.pos_x - d->spt[z].x), 2) +
						pow((d->player.pos_y - d->spt[z].y), 2));
		z++;
	}
	sort_sprites(d);

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

	for (int i = 0; i < d->count_spt ; i++)
	{
		spriteX = d->spt[i].x - d->player.pos_x;
		spriteY = d->spt[i].y - d->player.pos_y;
		invDet = 1 / (d->ray.planeX * d->player.dir_y - d->player.dir_x * d->ray.planeY);
		transformX = invDet * (d->player.dir_y * spriteX - d->player.dir_x * spriteY);
		transformY = invDet * (-d->ray.planeY * spriteX + d->ray.planeX * spriteY);
		spriteScreenX = (int)((d->res[0] / 2) * (1 + transformX / transformY));
		spriteHeight = abs((int)(d->res[1] / transformY));
		spriteWidth = abs((int)(d->res[1] / transformY));
		drawStartY = -spriteHeight / 2 + d->res[1] /2;
		drawEndY = drawStartY + spriteHeight;
		drawStartX = -spriteWidth / 2 + spriteScreenX;
		drawEndX = spriteWidth / 2 + spriteScreenX;
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
			if (transformY > 0 && stripe > 0 && stripe < d->res[0]&& transformY < d->rays[stripe])
			{	
				for (int col = drawStartY; col < drawEndY; col++)
				{
					d->y = col;
					color = get_spt_color(d, spriteHeight, spriteWidth, stripe, spriteScreenX);
					if (color > 5)
						my_mlx_pixel_put(d, add_shade(d, color, transformY));
				}
			}
		}
	}	
}

int		get_color(t_data *d)
{
	char	*color;
	double	tex_y;
	double	tex_x;

	tex_y = d->y * d->texture.height[5] / d->res[1];	
	tex_x = d->x * d->texture.width[5] / d->res[0];
	color = d->texture.addr[5] + (abs((int)tex_y) * d->texture.szl[5] +
	(int)tex_x * (d->texture.bpp[5] / 8));
	return (*(unsigned int*)color);
}

void	do_gun(t_data *d)
{
	int color;

	color = 0;
	d->x = 0;
	d->y = 0;
	// int endx = d->x + d->texture.width[5];
	// int endy = d->y + d->texture.height[5];
	// printf("(%f, %f) - [%d, %d]\n", d->y, d->x, endx, endy);
	while (d->x < d->res[0])
	{
		d->y = 0;
		while (d->y < d->res[1])
		{
			color = get_color(d);
			if (color != 0x980088)
				my_mlx_pixel_put(d, color);
			d->y++;
		}
		d->x++;
	}
}

void raycasting(t_data *d)
{
	do_walls(d);
	do_sprites(d);
	do_gun(d);
	if (d->save == 1)
	{
		create_bitmap(d);
		//clean(d);
		exit(1);
	}
}