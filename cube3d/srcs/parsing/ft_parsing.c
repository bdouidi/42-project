/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:57:11 by idouidi           #+#    #+#             */
/*   Updated: 2020/06/08 16:40:29 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void		info_map(t_data *d, char *s, int i)
{
	int	j;

	j = i;
	while (s[j] && s[j] != '\n')
		j++;
	if (s[i] == 'R')
		d->resolution = fill_str(s, d->resolution, i, j);
	if (s[i] == 'F')
		d->floor = fill_str(s, d->resolution, i, j);
	if (s[i] == 'C')
		d->ceiling = fill_str(s, d->ceiling, i, j);
	if (s[i] == 'N')
		d->north = fill_str(s, d->north, i, j);
	if (s[i] == 'W')
		d->west = fill_str(s, d->west, i, j);
	if (s[i] == 'E')
		d->east = fill_str(s, d->east, i, j);
	if (s[i] == 'S')
	{
		if (s[i + 1] == 'O')
			d->south = fill_str(s, d->south, i, j);
		else
			d->sprite = fill_str(s, d->sprite, i, j);
	}
}

static int	config_map(t_data *d)
{
	int		i;
	char	*s;
	int		check;

	i = 0;
	check = 0;
	s = d->tmp;
	while (s[i])
	{
		if (s[i + 1] && s[i + 2] && is_flags(s, i) == 0)
			info_map(d, s, i);
		if (s[i + 1] && s[i] == '\n' && ft_isdigit(s[i + 1]) &&
				check == 0)
		{
			d->tmp = ft_substr(s, i + 1, ft_strlen(s));
			check = 1;
		}
		i++;
	}
	return (0);
}

void		map(int fd, t_data *data)
{
	char	*line;

	line = NULL;
	data->tmp = ft_strdup("");
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_strtrim(line, " 	");
		data->tmp = ft_strjoin(data->tmp, line);
		leak(line);
	}
	config_map(data);
	data->map = ft_split((char *)data->tmp, '\n');
	leak(data->tmp);
}

int			pars_file(int fd)
{
	t_data	data;
	int		len;

	len = 0;
	data.map = NULL;
	data.resolution = NULL;
	data.floor = NULL;
	data.ceiling = NULL;
	data.sprite = NULL;
	data.north = NULL;
	data.east = NULL;
	data.south = NULL;
	data.west = NULL;
	map(fd, &data);
	while (data.map[len])
		len++;
	if (pars_info_map(&data) == -1)
		return (-1);
	if (pars_map(data.map, len - 1))
		return (-1);
	return (0);
}
