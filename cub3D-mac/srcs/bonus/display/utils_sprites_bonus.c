/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sprites_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:35:26 by idouidi           #+#    #+#             */
/*   Updated: 2020/11/16 23:54:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

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

void	adjust_sprites_order(t_data *d)
{
	int z;

	z = 0;
	while (z < d->count_spt)
	{
		d->spt[z].dist = (pow((d->player.pos_x - d->spt[z].x), 2) +
						pow((d->player.pos_y - d->spt[z].y), 2));
		z++;
	}
	sort_sprites(d);
}
