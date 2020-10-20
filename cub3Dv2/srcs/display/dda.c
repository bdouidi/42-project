/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:46:21 by othabchi          #+#    #+#             */
/*   Updated: 2020/10/16 15:03:11 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		get_tex_color(t_data *d, int i)
{
	char	*color;
	double	tex_y;
	double	tex_x;
	double	wallX;

	tex_y = (d->y * 2 - d->res[1] + d->ray.line_height) *
		(d->texture.height[i] / 2) / d->ray.line_height;	
	if (d->ray.hit_side == 0)
		wallX = d->player.pos_y + d->ray.perpWallDist * d->ray.dirY;
	else
		wallX = d->player.pos_x + d->ray.perpWallDist * d->ray.dirX;
	wallX -= (int)wallX;
	tex_x = (int)(wallX * d->texture.width[i]);
	if	((d->ray.hit_side == 0 && d->ray.dirX > 0) || (d->ray.hit_side == 1 && d->ray.dirY < 0))
		tex_x = d->texture.width[i] - tex_x - 1;
	color = d->texture.addr[i] + (abs((int)tex_y) * d->texture.szl[i] +
	(int)tex_x * (d->texture.bpp[i] / 8));
	return (*(unsigned int*)color);
}

void	draw_wall(t_data *d)
{
	int	drawStart;
	int drawEnd;
	int side = 0;
	
	d->ray.line_height = (int)(d->res[1] / d->ray.perpWallDist);
	drawStart = -d->ray.line_height / 2 + d->res[1] / 2;
	drawEnd = d->ray.line_height / 2 + d->res[1] / 2;
	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= d->res[1])
		drawEnd = d->res[1] - 1;
	
	side = (d->ray.hit_side == 0) ? d->player.map_x - d->player.pos_x :
									d->player.map_y - d->player.pos_y;
	while (drawStart < drawEnd)
	{
		d->y = drawStart;
		if (d->ray.hit_side)
			side < 0 ? my_mlx_pixel_put(d, add_shade(d, get_tex_color(d, 1), d->rays[(int)d->x])) : 
			my_mlx_pixel_put(d, add_shade(d, get_tex_color(d, 2), d->rays[(int)d->x]));
		else
			side < 0 ?  my_mlx_pixel_put(d, add_shade(d, get_tex_color(d, 3), d->rays[(int)d->x])) : 
			 my_mlx_pixel_put(d, add_shade(d, get_tex_color(d, 4), d->rays[(int)d->x]));
		drawStart++;
	}
}

void	initDist(t_data *d)
{
	if (d->ray.dirX < 0)
      {
        d->ray.stepX = -1;
        d->ray.sideDistX = (d->player.pos_x - d->player.map_x) * d->ray.deltaDistX;
      }
      else
      {
        d->ray.stepX = 1;
        d->ray.sideDistX = (d->player.map_x + 1.0 - d->player.pos_x) * d->ray.deltaDistX;
      }
      if (d->ray.dirY < 0)
      {
        d->ray.stepY = -1;
        d->ray.sideDistY = (d->player.pos_y - d->player.map_y) * d->ray.deltaDistY;
      }
      else
      {
        d->ray.stepY = 1;
        d->ray.sideDistY = (d->player.map_y + 1.0 - d->player.pos_y) * d->ray.deltaDistY;
      }
}

void	dda(t_data *d)
{
	d->ray.hit = 0;
	d->player.map_x = (int)(d->player.pos_x);
	d->player.map_y = (int)(d->player.pos_y);

	if (d->ray.dirY != 0)
		d->ray.deltaDistX = (d->ray.dirX == 0) ? 1 : fabs(1 / d->ray.dirX);
	else
		d->ray.deltaDistX = 0;
	if (d->ray.dirX != 0)
		d->ray.deltaDistY = (d->ray.dirY == 0) ? 1 : fabs(1 / d->ray.dirY);
	else
		d->ray.deltaDistY = 0;
	
	initDist(d);
	while (d->ray.hit == 0)
	{
		if (d->ray.sideDistX < d->ray.sideDistY)
		{
			d->ray.sideDistX += d->ray.deltaDistX;
			d->player.map_x += d->ray.stepX;
			d->ray.hit_side = 0;
		}
		else
		{
			d->ray.sideDistY += d->ray.deltaDistY;
			d->player.map_y += d->ray.stepY;
			d->ray.hit_side = 1;
		}
		if (d->map[d->player.map_y][d->player.map_x] == '1')
			d->ray.hit = 1;
	}
	if (d->ray.hit_side == 0)
		d->ray.perpWallDist = (d->player.map_x - d->player.pos_x + (1 - d->ray.stepX) / 2) / d->ray.dirX;
	else
		d->ray.perpWallDist = (d->player.map_y - d->player.pos_y + (1 - d->ray.stepY) / 2) / d->ray.dirY;
	d->rays[(int)d->x] = d->ray.perpWallDist;
	// printf("%f\n", d->rays[(int)d->x]);
	draw_wall(d);
}
