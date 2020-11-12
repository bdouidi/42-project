/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:04:08 by othabchi          #+#    #+#             */
/*   Updated: 2020/11/12 22:21:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clean(t_data *d)
{
	leak_2(d->map);
	leak(d->resolution);
	leak(d->floor);
	leak(d->ceiling);
	leak(d->north);
	leak(d->south);
	leak(d->west);
	leak(d->east);
	leak(d->sprite);
	leak(d->rays);
}

int		cub3d(int fd, t_data *d)
{
	if (fd < 0)
		return (-1);
	if (pars_file(fd, d) == -1 || set_rfc(d) == -1 ||
		(!(d->rays = malloc(sizeof(double) * d->res[0]))))
	{
		clean(d);
		return (-1);
	}
	window(d);
	leak(d->spt);
	return (0);
}
