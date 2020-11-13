/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:00:55 by othabchi          #+#    #+#             */
/*   Updated: 2020/11/13 17:47:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		main(int ac, char **av)
{
	int		fd;
	t_data	d;

	if ((ac == 3 && (ft_strlen(av[2]) != ft_strlen("--save") ||
	ft_strncmp(av[2], "--save", ft_strlen("--save") != 0))) || ac > 3)
	{
		write(1, "you have too much argument or made a bad option call\n", 53);
		return (0);
	}
	d.save = (ac == 3) ? 1 : 0;
	fd = open(av[1], O_RDONLY);
	if (cub3d(fd, &d) == -1)
		printf("fail\n");
	clean(d);
	close(fd);
	return (0);
}
