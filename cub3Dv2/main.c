/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:00:55 by othabchi          #+#    #+#             */
/*   Updated: 2020/11/11 20:04:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	clean(t_data *d)
{
	leak_2(d->map);
	leak(d->resolution);
	leak(d->floor);
	leak(d->ceiling);
	leak(d->north);
	leak(d->south);
	leak(d->west);
	leak(d->east);
	leak(d->sprite);
	leak(d->spt);
	leak(d->rays);
}

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
		printf("fail\n");
		close(fd);
		return (0);
	}
	clean(&d);
	close(fd);
	return (0);
}
