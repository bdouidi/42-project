/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_info_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:49:35 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/11 14:49:36 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	f_c_loop(char *str)
{
	int i;
	int fc[3];

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	fc[0] = ft_atoi(str + i);
	i += ft_nbrlen(fc[0]);
	while (!ft_isdigit(str[i]))
		i++;
	fc[1] = ft_atoi(str + i);
	i += ft_nbrlen(fc[1]);
	while (!ft_isdigit(str[i]))
		i++;
	fc[2] = ft_atoi(str + i);
	return (create_trgb(1, fc[0], fc[1], fc[2]));
}

void		set_rfc(t_data *d)
{
	int i;

	i = 0;
	while (!ft_isdigit(d->resolution[i]))
		i++;
	d->res[0] = ft_atoi((d->resolution) + i);
	i += ft_nbrlen(d->res[0]);
	d->res[1] = ft_atoi((d->resolution) + i);
	d->f_color = f_c_loop(d->floor);
	d->c_color = f_c_loop(d->ceiling);
	printf("[%x]\n[%x]", d->f_color, d->c_color);
}
