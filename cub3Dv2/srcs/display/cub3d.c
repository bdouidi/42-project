/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:04:08 by othabchi          #+#    #+#             */
/*   Updated: 2020/11/13 19:00:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clean(t_data d)
{
	leak_2(d.map);
	leak(d.resolution);
	leak(d.floor);
	leak(d.ceiling);
	leak(d.north);
	leak(d.south);
	leak(d.west);
	leak(d.east);
	leak(d.sprite);
	leak(d.rays);
	leak(d.spt);
	leak(d.tmp);
	leak(d.tmp1);
}

int		cub3d(int fd, t_data *d)
{
	set_var(d);
	if (fd < 0)
		return (-1);
	if (pars_file(fd, d) == -1 || set_rfc(d) == -1 ||
		(!(d->rays = malloc(sizeof(double) * d->res[0]))))
		return (-1);
	window(d);
	return (0);
}
