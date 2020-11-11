/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_info_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:32:23 by idouidi           #+#    #+#             */
/*   Updated: 2020/11/11 20:04:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_rfc_content(char *s, int i)
{
	if ((s[0] == 'R' && ft_isdigit(s[i]) != 1 && s[i] != ' ' && s[i] != '\t') ||
			((s[0] == 'C' || s[0] == 'F') && (ft_isdigit(s[i]) != 1 &&
				s[i] != ' ' && s[i] != '\t' && s[i] != ',')))
		return (-1);
	return (0);
}

int			r_f_c(char *s)
{
	int	i;
	int	check;
	int	comma;

	i = 1;
	comma = 0;
	check = 0;
	while (s[i])
	{
		if (check_rfc_content(s, i) != 0)
			return (-1);
		if (ft_isdigit(s[i]) == 1 && s[i])
		{
			check++;
			while (s[i] && ft_isdigit(s[i]) == 1)
				i++;
		}
		if (s[i] == ',')
			comma++;
		(s[i]) ? i++ : 0;
	}
	if ((s[0] == 'R' && check != 2) || ((s[0] == 'C' || s[0] == 'F') &&
				(check != 3 || comma != 2)))
		return (-1);
	return (0);
}

int			pars_info_map(t_data *d)
{
	if (!d->resolution || !d->floor || !d->ceiling || !d->sprite ||
			!d->north || !d->east || !d->south || !d->west ||
			r_f_c(d->floor) == -1 || r_f_c(d->ceiling) == -1 ||
			r_f_c(d->resolution) == -1)
		return (-1);
	return (0);
}
