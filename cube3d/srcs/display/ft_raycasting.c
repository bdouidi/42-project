/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 03:12:26 by idouidi           #+#    #+#             */
/*   Updated: 2020/06/26 07:12:15 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// void	init_player(t_data *d)
// {
// 	d->player.height = 0.5 * d->res[1];
// 	d->player.fov = (M_PI / 3) * (180 / M_PI);
// 	if (d->player.letter == 'N')
// 		d->player.dir = M_PI / 2;
// 	else if (d->player.letter == 'E')
// 		d->player.dir = 0;
// 	else if (d->player.letter == 'S')
// 		d->player.dir = (3 * M_PI) / 2;
// 	else if (d->player.letter == 'W')
// 		d->player.dir = M_PI;
// }

void	raycasting(t_data *d)
{
	int		x;

	x = 0;
	d= 0;
	// init_player(d);
	// d->ray.dir = d->player.dir;

	/*d->r.hit = 0;
	while (x < d->res[0])
	{
		d->r.camera_x = 2 * x / (double)d->res[0] - 1;
		d->r.ray_dir_x = d->player.dir_x + d->player.plan_x * d->r.camera_x;
		d->r.ray_dir_y = d->player.dir_y + d->player.plan_y * d->r.camera_x;
		x++;
	}
	d->r.map_x = (int)d->player.pos_x;
	d->r.map_y = (int)d->player.pos_y;
	d->r.delta_dist_x = sqrt(1+ ((d->r.ray_dir_y * d->r.ray_dir_y) / (d->r.ray_dir_y * d->r.ray_dir_y)));
	d->r.delta_dist_y = sqrt(1+ ((d->r.ray_dir_y * d->r.ray_dir_y) / (d->r.ray_dir_y * d->r.ray_dir_y)));
	if (d->r.ray_dir_x < 0)
	{
		d->r.step_x = -1;
		d->r.side_dist_x = (d->player.pos_x - d->r.map_x) * d->r.delta_dist_x;
	}
	else
	{
		d->r.step_x = 1;
		d->r.side_dist_x = (d->r.map_x + 1.0 - d->player.pos_x) * d->r.delta_dist_x;
	}
	if (d->r.ray_dir_y < 0)
	{
		d->r.step_y = -1;
		d->r.side_dist_y = (d->player.pos_y - d->r.map_y) * d->r.delta_dist_y;
	}
	else
	{
		d->r.step_y = 1;
		d->r.side_dist_y = (d->r.map_y + 1.0 - d->player.pos_y) * d->r.delta_dist_y;
	}
	while (d->r.hit == 0)
	{
		if (d->r.side_dist_x < d->r.side_dist_y)
		{
			d->r.side_dist_x += d->r.delta_dist_x;
			d->r.map_x += d->r.step_x;
			d->r.hit_side = 0;
		}
		else
		{
			d->r.side_dist_y += d->r.delta_dist_y;
			d->r.map_y += d->r.step_y;
			d->r.hit_side = 1;
		}
		if (d->map[d->r.map_x][d->r.map_y] != '0' || d->map[d->r.map_x][d->r.map_y] != '2' || d->map[d->r.map_x][d->r.map_y] != set)
			d->r.hit = 1;
	}
	if (d->r.hit_side == 0)
		d->r.perp_wall_dist = (d->r.map_x - d->player.pos_x + (1 - d->r.step_x) / 2) / d->r.ray_dir_x;
	else
		d->r.perp_wall_dist = (d->r.map_y - d->player.pos_y + (1 - d->r.step_y) / 2) / d->r.ray_dir_y;
	d->r.line_height = (int)(d->res[1] / d->r.perp_wall_dist);
	d->r.drawstart = -d->r.line_height / 2 + d->res[1] / 2;
	if (d->r.drawstart < 0)
		d->r.drawstart = 0;
	d->r.drawend = d->r.line_height / 2 + d->res[1] / 2;
	if (d->r.drawend > d->res[1])
		d->r.drawend = d->res[1] - 1;*/
}

//tqt pas meme moi j'ai presque pas compris mais apparement le raycasting c'est ca loooool
