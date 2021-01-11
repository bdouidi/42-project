/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:57:11 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/11 15:08:37 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void		info_map(t_data *d, char *s, int i)
{
	int	j;
	int	k;

	info_map_setup(s, i, &j, &k);
	if (s[i] == 'R')
		d->resolution = fill_str(s, d->resolution, i, j);
	if (s[i] == 'F')
		d->floor = fill_str(s, d->floor, i, j);
	if (s[i] == 'C')
		d->ceiling = fill_str(s, d->ceiling, i, j);
	if (s[i] == 'N')
		d->north = fill_str(s, d->north, k, j);
	if (s[i] == 'W')
		d->west = fill_str(s, d->west, k, j);
	if (s[i] == 'E')
		d->east = fill_str(s, d->east, k, j);
	if (s[i] == 'S')
	{
		if (s[i + 1] == 'O')
			d->south = fill_str(s, d->south, k, j);
		else
			d->sprite = fill_str(s, d->sprite, k, j);
	}
}

static void	config_map(t_data *d)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (d->tmp[i])
	{
		if (d->tmp[i + 1] && d->tmp[i + 2] && is_flags(d->tmp, i) == 0)
		{
			info_map(d, d->tmp, i);
			check++;
		}
		if (check == 8)
		{
			while (d->tmp[i] && d->tmp[i] != '\n')
				i++;
			d->tmp1 = ft_substr(d->tmp, i + 1, ft_strlen(d->tmp));
			return ;
		}
		i++;
	}
}

char		*my_read(int fd)
{
	char	*antileak;
	char	*save;
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	ret = 0;
	save = NULL;
	antileak = NULL;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (!(antileak = ft_strjoin(save, buf)))
		{
			free(save);
			free(antileak);
			return (NULL);
		}
		save = antileak;
		antileak = NULL;
	}
	return (save);
}

int			map(int fd, t_data *data)
{
	data->tmp = my_read(fd);
	config_map(data);
	if (check_empty_line(data) == -2)
		return (-2);
	data->map = ft_split((char *)data->tmp1, "\n");
	adjust_map(data);
	return (0);
}

int			pars_file(int fd, t_data *data)
{
	int		len;

	len = 0;
	if (map(fd, data) == -2)
		return (-2);
	while (data->map[len])
		len++;
	if (pars_info_map(data) == -1 || check_textures(data) == -1 ||
		set_rfc(data) == -1)
		return (-1);
	if (pars_map(data, len - 1) == -1)
		return (-2);
	data->map = noblank_2(data->map, '1', "*");
	if (!(data->spt = malloc(sizeof(t_sprite) * (data->count_spt))))
		return (-1);
	set_position(data);
	data->map_y--;
	return (0);
}
