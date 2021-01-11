/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:00:55 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/11 15:06:17 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/cub3d_bonus.h"

int		iscub(char *s1, char *s2)
{
	int i;
	int j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
			return (-1);
		i--;
		j++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	t_data	d;

	fd = open(av[1], O_RDONLY);
	if ((ac == 3 && (ft_strlen(av[2]) != ft_strlen("--save") ||
	ft_strncmp(av[2], "--save", ft_strlen("--save") != 0))) || ac > 3 ||
	is_cub(av[1], ".cub") == -1 || fd < 0)
	{
		ft_putstr("Error\nCheck that there are no errors, you have may be:\
		\n-too much argument\
		\n-made a bad option call\n-a file extension which is not \".cub\"\
		\n-a file which does not exist\n");
		return (0);
	}
	d.save = (ac == 3) ? 1 : 0;
	cub3d(fd, &d);
	clean(d);
	close(fd);
	return (0);
}
