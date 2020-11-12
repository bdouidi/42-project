/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:00:55 by othabchi          #+#    #+#             */
/*   Updated: 2020/11/12 22:28:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		main(int ac, char **av)
{
	int		fd;
	t_data	d;

	if (ac > 3)
	{
		ft_putstr("too much argument\n");
		return (0);
	}
	if (ac == 3 && (ft_strlen(av[2]) != ft_strlen("--save") ||
	ft_strncmp(av[2], "--save", ft_strlen("--save") != 0)))
	{
		write(1, "bad option call\n", 16);
		return (0);
	}
	d.save = (ac == 3) ? 1 : 0;
	fd = open(av[1], O_RDONLY);
	if (cub3d(fd, &d) == -1)
		write(1, "fail\n", 5);
	clean(&d);
	leak(d.spt);
	close(fd);
	return (0);
}
