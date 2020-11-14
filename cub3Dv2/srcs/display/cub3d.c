/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:04:08 by othabchi          #+#    #+#             */
/*   Updated: 2020/11/14 19:25:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clean(t_data d)
{
	leak_2(d.map);
	leak(d.resolution);
	leak(d.floor);
	leak(d.ceiling);
	leak(d.north);
	leak(d.south);
	leak(d.west);
	leak(d.east);
	leak(d.sprite);
	leak(d.rays);
	leak(d.spt);
	leak(d.tmp);
	leak(d.tmp1);
}

void	error_msg(int error)
{
	if (error == -1)
		ft_putstr("Error\nBad file: You made a mistake in the map information.\
		\nCheck that there are no errors on:\n-identifiers.\
		\n-render sizes (100 <= X < X MAX && 100 <= Y < Y MAX).\
		\n-texture paths.\
		\n-the RGB color format(three numbers between 0 and 255, each separeted\
by a comma).\n");
	if (error == -2)
		ft_putstr("Error\nBad file: you made a mistake in the map. Check \
that there are no errors:\n-the only authorized digits are (0, 1, 2, N, S, \
E, W).\n-zeros and twos must be surrounded by ones.\n-the map must be \
surrounded by ones.\n-that there is no empty line once the map has been \
identified until the end of the file.\n-there must be one letter and \
only one among (N, S, E, W)\n");
}

int		cub3d(int fd, t_data *d)
{
	int	error;

	error = 0;
	set_var(d);
	if ((error = pars_file(fd, d)) != 0 ||
	(!(d->rays = malloc(sizeof(double) * d->res[0]))))
	{
		error_msg(error);
		return (0);
	}
	window(d);
	return (0);
}
