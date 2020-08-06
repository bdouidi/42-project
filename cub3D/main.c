/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:00:55 by othabchi          #+#    #+#             */
/*   Updated: 2020/08/06 16:44:54 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

int main (int ac, char **av)
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
		ft_putstr("bad option call\n");
		return (0);
	}
	d.save = (ac == 3) ? 1 : 0;
	fd = open(av[1], O_RDONLY);
	if (cub3d(fd, &d) == -1)
	{
		printf("\nfail");
		close(fd);
		return (0);
	}
	close(fd);
	return (0);
}
