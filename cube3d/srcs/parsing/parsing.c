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

int	is_blank(char c)
{
	if (c == ' ' || c == '	')
		return (0);
	return (-1);
}
void print_tab(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int		is_present(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && is_blank(str[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

/*int		check_map_content(char **tab, int len)
{
	int		i;
	int		j;
	int		check;

	i = 0;
	j = 0;
	check = 0;
	while (tab[i])
	{
		while(tab[i][j])
		{
			if (tab[i][j] != '1' && tab[i][j] != '2' && tab[i][j] != '0' 
				&& tab[i][j] != 'N' && tab[i][j] != 'S' && tab[i][j] != 'E' 
				&& tab[i][j] != 'W' && is_blank(tab[i][j]) == -1)
				return (-1);
			if (tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E' || tab[i][j] == 'W')
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
}*/

/*int		pars_map(char **tab)
{
	int	i;
	int	j;
	int k;
	int	len;

	i = 0;
	while (tab[i])
		i++;
	len = i - 1;
	if (is_present(tab[0]) == -1 || is_present(tab[len]) == -1 || check_map_content(tab, len) == -1)
		return (-1);
	j = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] != '1' || tab[i][ft_strlen(tab[i]) - 1] != '1')
			return (-1);
		k = i;
		while (tab[k][j])
		{
			if (is_blank(tab[k][j] == 0))
			{
				if ((tab[k][j - 1] == '2' || tab[k][j - 1] == '0') || (tab[k][j + 1] == '2' || tab[k][j + 1] == '0'))
					return (-1);
				if (k == 0 && (tab[k + 1][j] == '2' || tab[k + 1][j] == '0'))
					return (-1);
				if (k == len && (tab[k - 1][j] == '2' || tab[k - 1][j] == '0')) 
					return (-1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}*/

t_data 	*info_map(t_data *d, int i)
{
	int	j;
	j = i;
	while (d->tmp[j] && d->tmp[j] != '\n')
		j++;
	if (d->tmp[i] == 'R')
		d->resolution = ft_substr(d->tmp, i, j--);
	if (d->tmp[i] == 'F')
		d->floor = ft_substr(d->tmp, i, j--);
	if (d->tmp[i] == 'S')
		d->sprite = ft_substr(d->tmp, i, j--);
	if (d->tmp[i] == 'C')
		d->ceiling = ft_substr(d->tmp, i, j--);
	if (d->tmp[i + 1] && d->tmp[i] == 'N' && is_blank(d->tmp[i + 2]) == 0)
		d->north = ft_substr(d->tmp, i, j--);
	if (d->tmp[i + 1] && d->tmp[i] == 'E' && is_blank(d->tmp[i + 2]) == 0)
		d->east = ft_substr(d->tmp, i, j--);
	if (d->tmp[i + 1] && d->tmp[i] == 'S' && is_blank(d->tmp[i + 2]) == 0)
		d->south = ft_substr(d->tmp, i, j--);
	if (d->tmp[i + 1] && d->tmp[i] == 'W' && is_blank(d->tmp[i + 2]) == 0)
		d->west = ft_substr(d->tmp, i, j--);
	return (d);
}

int config_map(t_data *d)
{
	int		i;
	int		j;
	int		stock;
	char		*s;
	int		check;

	j = 0;
	i = 0;
	stock = 0;
	s = d->tmp;
	check = 0;
	while (s[i])
	{
		if (s[i + 1] && ((s[i] == '\n' && ft_isdigit(s[i + 1])) || ft_isdigit(s[0])) && check == 0)
		{
			stock = (ft_isdigit(s[0])) ? i : i + 1;
			j = stock;
			while(s[j] && (ft_isdigit(s[j]) == 1 || s[j] == 'N' || s[j] == 'S' ||
				 s[j] == 'E' || s[j] == 'W' || s[j] == '\n' || s[j] == ' ' || s[j] == '	'))
				j++;
			d->tmp = ft_substr(s, stock, j--);
			i = (i < j) ? j : i;
			check = 1;
		}
		/*if (s[i + 1] && (((s[i] == 'R' || s[i] == 'F' || s[i] == 'R' || s[i] == 'C' ||
			 s[i] == 'S') && (s[j] == ' ' || s[j] == '	')) || (s[i] == 'N' && s[i + 1] == 'O')
			  || (s[i] == 'E' && s[i + 1] == 'A') || (s[i] == 'S' && s[i + 1] == 'O') ||
			   (s[i] == 'W' && s[i + 1] == 'E')))*/
		if (s[i] == 'R' || s[i] == 'F')
			d = info_map(d, i);
		i++;
	}
	free(s);
	s = NULL;
	return (0);
}

void map(int fd, t_data *data)
{
	char	*line;

	line = NULL;
	data->map = NULL;
	data->tmp = ft_strdup("");
	while (get_next_line(fd, &line) > 0)
	{
		line  = ft_strtrim(line, " 	");
		data->tmp = ft_strjoin(data->tmp, line);
		free(line);
	}
	config_map(data);
	data->map = ft_split((char *)data->tmp, '\n');
	free(data->tmp);
	data->tmp = NULL;
}

int	pars_file(int fd)
{
	t_data data;
	
	map(fd, &data);
	print_tab(data.map);
	printf("%s\n", data.resolution);
	printf("%s\n", data.floor);
	/*if (pars_map(tab) == -1)
		return (-1);*/
	return (0);

}

int main (int ac, char *av[])
{
	(void)ac;
	int 	fd = open(av[1], O_RDONLY);

	if (pars_file(fd) == -1)
	{
		printf("mauvais format de map\n");
		return (0);
	}
	close(fd);
	return (0);
}
