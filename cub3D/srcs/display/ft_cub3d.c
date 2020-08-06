/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:49:39 by othabchi          #+#    #+#             */
/*   Updated: 2020/08/06 16:42:54 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	cub3d(int fd, t_data *d)
{
	if (fd < 0 || pars_file(fd, d) == -1 || set_rfc(d) == -1)
		return (-1);
	set_position(d);
	window(d);
	return (0);
}
