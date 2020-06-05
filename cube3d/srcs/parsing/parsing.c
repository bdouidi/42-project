/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:14:54 by othabchi          #+#    #+#             */
/*   Updated: 2020/05/31 05:46:21 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void print_tab(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int		is_pres(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '	')
			return (-1);
		i++;
	}
	return (0);
}

int		m_content(char **m, int len)
{
	int		i;
	int		j;
	int		check;

	i = 0;
	j = 0;
	check = 0;
	while (m[i])
	{
		while(m[i][j])
		{
			if (m[i][j] != '1' && m[i][j] != '2' && m[i][j] != '0' 
				&& m[i][j] != 'N' && m[i][j] != 'S' && m[i][j]
				 != 'E' && m[i][j] != 'W' && m[i][j] != ' ' &&
				  m[i][j] != '	')
				return (-1);
			if (m[i][j] == 'N' || m[i][j] == 'S' || m[i][j] == 'E'
				 || m[i][j] == 'W')
			{
				if (i == 0 || i == len)
					return (-1);
				check++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (check != 1)
		return (-1);
	return (0);
}

int		pars_map(char **m, int len)
{
	int		i;
	unsigned int	j;
	int 		k;

	i = 0;
	j = 1;
	i = 0;
	if (is_pres(m[0]) == -1 || is_pres(m[len]) == -1 ||
		 m_content(m, len) == -1)
		return (-1);
	while (m[i])
	{
		if (m[i][0] != '1' || m[i][ft_strlen(m[i]) - 1] != '1')
			return (-1);
		k = i;
		while (m[k][j] && j < (ft_strlen(m[k]) - 1))
		{
			if (m[k][j] == ' ' || m[k][j] == '	')
			{
				if ((m[k][j - 1] == '2' || m[k][j - 1] == '0')
					 || (m[k][j + 1] == '2' || m[k][j + 1]
					  == '0'))
					return (-1);
				if (k == 0 && (m[k + 1][j] == '2' || m[k + 1][j]
					 == '0'))
					return (-1);
				if (k == len && (m[k - 1][j] == '2' || m[k - 1]
					[j] == '0')) 
					return (-1);
			}
			j++;
		}
		i++;
		j = 1;
	}
	return (0);
}

int	flags(char c)
{
	if (c == 'R'|| c == 'F' || c == 'S' || c == 'C' || c == 'N' || c == 'W'
		 || c == 'E') 
		return (0);
	return (-1);
}
void	leak(char *str)
{
	free(str);
	str = NULL;
}

char *fill_str(char *s1, char *s2, int i, int j)
{
	int	k;

	k = 0;
	if(!(s2 = (char *)malloc(sizeof(char) * j)))
		return (NULL);
	while(i < j)
	{
		s2[k] = s1[i];
		i++;
		k++;
	}
	s2[k] = '\0';
	return(s2);
}

void info_map(t_data *d, char *s, int i)
{
	int	j;

	j = i;
	while(s[j] && s[j] != '\n')
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

int	is_flags(char *s, int i)
{
	if (flags(s[i]) == 0)
	{
		if (s[i + 1] == ' ' || s[i + 1] == '	')
			return (0);
		if ((s[i + 1] == 'O' || s[i + 1] == 'E' || s[i + 1] == 'A') &&
			 (s[i + 2] == ' ' || s[i + 2] == '	'))
			return (0);
	}
	return (-1);
}

int	config_map(t_data *d)
{
	int	i;
	char	*s;
	int	check;

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

void map(int fd, t_data *data)
{
	char	*line;

	line = NULL;
	data->tmp = ft_strdup("");
	while (get_next_line(fd, &line) > 0)
	{
		line  = ft_strtrim(line, " 	");
		data->tmp = ft_strjoin(data->tmp, line);
		leak(line);

	}
	config_map(data);
	data->map = ft_split((char *)data->tmp, '\n');
	leak(data->tmp);
}

int	r_f_c(char *s)
{
	int	i;
	int	check;
	int	comma;

	i = 1;
	comma = 0;
	check = 0;
	while(s[i])
	{
		if (s[0] == 'R' && ft_isdigit(s[i]) != 1 && s[i] != ' ' &&
			 s[i] != '	')
			return (-1);
		if ((s[0] == 'C' || s[0] == 'F') && (ft_isdigit(s[i]) != 1 &&
			 s[i] != ' ' && s[i] != '	' && s[i] != ','))
			return (-1);
		if (ft_isdigit(s[i]) == 1)
		{
			check++;
			while (s[i] && ft_isdigit(s[i]) == 1)
				i++; 
		}
		if (s[i] == ',')
			comma++;
		i++;
	}
	if ((s[0] == 'R' && check != 2) || ((s[0] == 'C' || s[0] == 'F') &&
		 (check != 3 || comma != 2)))
			return (-1);
	return (0);
}

int	pars_info_map(t_data *d)
{
	if (!d->resolution || !d->floor || !d->ceiling || !d->sprite ||
		 !d->north || !d->east || !d->south || !d->west ||
		  r_f_c(d->floor) == -1 || r_f_c(d->ceiling) == -1 ||
		   r_f_c(d->resolution) == -1)
		return (-1);
	return (0);
}
int	pars_file(int fd)
{
	t_data	data;
	int	len;

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
	while(data.map[len])
		len++;
	if (pars_info_map(&data) == -1)
	{
		ft_putstr("bad informartion to config the map\n");
		return (-1);
	}
	if (pars_map(data.map, len - 1))
	{
		ft_putstr("bad character or wrong character's place\n");
		return (-1);
	}
	return (0);
}

int main (int ac, char *av[])
{
	(void)ac;
	int 	fd = open(av[1], O_RDONLY);

	if (pars_file(fd) == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (0);
}
