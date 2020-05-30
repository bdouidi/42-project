/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:14:54 by othabchi          #+#    #+#             */
/*   Updated: 2020/05/30 21:29:48 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*pars_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		if (str[j] && (str[j] == ' ' || str[j] == '	'))
			if (str[i] == '0' || str[i] == '2')
				return (NULL);
		while(str[j] && (str[j] == ' ' || str[j] == '	'))
		{
			str[j] = '*';
			if (str[j] == '0' || str[j] == '2')
				return (NULL);
		}
		i++;
	}
	return (str);
}

char **pars_map(int fd)
{
	char	*tmp;
	char	*line;
	char 	**tab;
	//int		i = 0;
	
	tab = NULL;
	line = NULL;
	tmp = ft_strdup("");
	while (get_next_line(fd, &line) > 0)
	{
		line  = ft_strtrim(line, " 	");
		if (line[0] == '1')
		{
			tmp = ft_strjoin(tmp, line);
		}
		//free(line);
	}
	tab = ft_split((char *)tmp, "\n");
	free(tmp);
	return(tab);
}

void	print_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(tab[i])
	{
		while (tab[i][j])
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

int main (int ac, char *av[])
{
	(void)ac;
	char 	**tab;
	int 	fd_map = open(av[1], O_RDONLY);

	if ((tab = pars_map(fd_map)) == NULL)
	{
		printf("error in the grill\n");
		return (0);
	}
	print_tab(tab);
	close(fd_map);
	return (0);
}
