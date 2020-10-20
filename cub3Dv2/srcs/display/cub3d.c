/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:04:08 by othabchi          #+#    #+#             */
/*   Updated: 2020/10/20 17:01:39 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	cub3d(int fd, t_data *d)
{
	if (fd < 0 || pars_file(fd, d) == -1 || set_rfc(d) == -1 ||
		(!(d->rays = malloc(sizeof(double) * d->res[0]))))
	{
		clean(d);
		return (-1);
	}
	window(d);
	return (0);
}