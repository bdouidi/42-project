/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:49:39 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/24 22:48:27 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	cub3d(int fd)
{
	t_data d;

	if (fd < 0 || pars_file(fd, &d) == -1 || set_rfc(&d) == -1)
		return (-1);
	set_position(&d);
	d.square.imgx = 0;
	d.square.imgy = 0;
	d.square.width = ((d.res[0] * .50) / ft_strlen(d.map[0]));
	d.square.height = ((d.res[1] * .50) / ft_strlen(d.map[0]));
	window(&d);
	return (0);
}
