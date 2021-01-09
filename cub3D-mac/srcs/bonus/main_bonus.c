/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:00:55 by idouidi           #+#    #+#             */
/*   Updated: 2020/11/17 18:17:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/cub3d_bonus.h"

int		is_present(char *s1, char *s2)
{
	if (ft_strlen(s1) < ft_strlen(s2))
		return (-1);
	while (*s1)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, 4) == 0)
			return (0);
		else
			s1++;
	}
	return (-1);
}

int		main(int ac, char **av)
{
	int		fd;
	t_data	d;

	fd = open(av[1], O_RDONLY);
	if ((ac == 3 && (ft_strlen(av[2]) != ft_strlen("--save") ||
	ft_strncmp(av[2], "--save", ft_strlen("--save") != 0))) || ac > 3 ||
	is_present(av[1], ".cub") == -1 || fd < 0)
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
