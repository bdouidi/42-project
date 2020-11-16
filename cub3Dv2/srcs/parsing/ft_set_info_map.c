/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_info_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:49:35 by othabchi          #+#    #+#             */
/*   Updated: 2020/11/16 13:05:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	count(char *str)
{
	int j;

	j = 0;
	while (ft_isdigit(str[j]))
		j++;
	return (j);
}

static int	f_c_loop(char *str)
{
	int i;
	int fc[3];

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	fc[0] = ft_atoi(str + i);
	i += count(&str[i]);
	while (!ft_isdigit(str[i]))
		i++;
	fc[1] = ft_atoi(str + i);
	i += count(&str[i]);
	while (!ft_isdigit(str[i]))
		i++;
	fc[2] = ft_atoi(str + i);
	if (fc[0] > 255 || fc[1] > 255 || fc[2] > 255)
		return (-1);
	return (create_trgb(1, fc[0], fc[1], fc[2]));
}

int			set_rfc(t_data *d)
{
	int i;

	i = 0;
	while (!ft_isdigit(d->resolution[i]))
		i++;
	d->res[0] = ft_atoi((d->resolution) + i);
	i += ft_nbrlen(d->res[0]);
	d->res[1] = ft_atoi((d->resolution) + i);
	if (((d->f_color = f_c_loop(d->floor)) == -1) ||
		((d->c_color = f_c_loop(d->ceiling)) == -1))
		return (-1);
	return (0);
}
