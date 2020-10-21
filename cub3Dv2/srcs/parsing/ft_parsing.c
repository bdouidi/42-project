/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:57:11 by idouidi           #+#    #+#             */
/*   Updated: 2020/10/21 14:46:43 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void		info_map_setup(char *s, int i, int *j, int *k)
{
	*j = i;
	*k = i;
	while (s[*k] && s[*k] != '.')
		*k += 1;
	while (s[*j] && s[*j] != '\n')
		*j += 1;
}

void		info_map(t_data *d, char *s, int i)
{
	int	j;
	int k;

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

char	*handlebackslash(t_data *d, int i, int len)
{
	char *res;
	int j;

	len = 0;
	if (!(res = malloc(sizeof(char) * ft_strlen(d->tmp1) + 2)))
		return (NULL);
	j = 0;
	while (j < i)
	{
		res[j] = d->tmp1[j];
		j++;
	}
	res[j] = '1';
	j++;
	while (d->tmp1[j])
	{
		res[j] = d->tmp1[j - 1];
		j++;
	}
	res[j] = d->tmp1[j];
	res[j] = 0;
	return (res);
}

static void	config_map(t_data *d)
{
	int		i;
	char	*s;
	int		check;
	int		len;

	i = 0;
	s = d->tmp;
	check = 0;
	while (s[i])
	{
		if (s[i + 1] && s[i + 2] && is_flags(s, i) == 0)
		{
			info_map(d, s, i);
			check++;
		}
		if (check == 8)
		{
			while (s[i] && s[i] != '\n')
				i++;
			d->tmp1 = ft_substr(s, i + 1, ft_strlen(s));
			i = 0;
			len = (int)ft_strlen(d->tmp1);
			while (i < len)
			{
				if (d->tmp1[i] == '\n' && d->tmp1[i + 1] == '\n')
				{
					d->tmp1 = handlebackslash(d, i + 1, len);
					i = -1;
				}
				i++;
			}
			printf("%s\n", d->tmp1);
			return ;
		}
		i++;
	}
	leak(d->tmp);
}
char	*my_read(int fd)
{
	char		*antileak;
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	char		*save;

	ret = 0;
	save = NULL;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(antileak = ft_strjoin(save, buf)))
			return (NULL);
		free(save);
		save = antileak;
	}
	return (save);
}

void		map(int fd, t_data *data)
{
	data->tmp = my_read(fd);
	config_map(data);
	data->map = ft_split((char *)data->tmp1, '\n');
	adjust_map(data);
	leak(data->tmp1);
}

int			check_textures(t_data *d)
{
	if (open(d->sprite, O_RDONLY) < 0 || open(d->north, O_RDONLY) < 0 ||
	open(d->east, O_RDONLY) < 0 || open(d->south, O_RDONLY) < 0 ||
	open(d->west, O_RDONLY) < 0)
	{
		ft_putstr("incorrect texture path\n");
		return (-1);
	}
	return (0);
}

void	set_var(t_data *d)
{
	d->map = NULL;
	d->resolution = NULL;
	d->floor = NULL;
	d->ceiling = NULL;
	d->sprite = NULL;
	d->north = NULL;
	d->east = NULL;
	d->south = NULL;
	d->west = NULL;
	d->x = 0;
	d->y = 0;
	d->mapX = 0;
	d->mapY = 0;
	d->player.pos_x = 0;
	d->player.pos_y = 0;
	d->player.letter = 0;
}

void	set_position(t_data *d)
{
	int i;

	i = 0;
	while (d->map[d->mapY])
	{
		d->mapX = 0;
		while (d->map[d->mapY][d->mapX])
		{
			if (d->map[d->mapY][d->mapX] == '2')
			{
				d->spt[i].x = d->mapX + 0.5;
				d->spt[i].y = d->mapY + 0.5;
				i++;
			}
			if (ft_isalpha(d->map[d->mapY][d->mapX]) == 1)
			{
				d->player.pos_y = d->mapY + .5;
				d->player.pos_x = d->mapX + .5;
				d->player.letter = d->map[d->mapY][d->mapX];
				d->map[d->mapY][d->mapX] = '0';
			}
			d->mapX++;
		}
		d->mapY++;
	}
	d->mapY--;

}

int			pars_file(int fd, t_data *data)
{
	int		len;

	len = 0;
	set_var(data);
	map(fd, data);
	while (data->map[len])
		len++;
	if (pars_info_map(data) == -1 || pars_map(data, len - 1) == -1 ||
		check_textures(data) == -1)
		return (-1);
	data->map = noblank_2(data->map, '1', "*");
	if (!(data->spt = malloc(sizeof(t_sprite) * (data->count_spt))))
		return (-1);
	set_position(data);
	return (0);
}
