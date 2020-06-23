/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:49:39 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/23 02:00:20 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	cub3d(int fd)
{
	t_data d;

	if (fd < 0 || pars_file(fd, &d) == -1 || set_rfc(&d) == -1)
		return (-1);
	d.square.imgx = 0;
	d.square.imgy = 0;
	d.square.width = d.res[0] /100;
	d.square.height = d.res[0] / 100;
	//raycasting(&d);
	window(&d);
	return (0);
}
