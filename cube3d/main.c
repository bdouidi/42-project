/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:00:55 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/11 18:26:35 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void print_tab(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int main (int ac, char *av[])
{
	(void)ac;
	int 	fd = open(av[1], O_RDONLY);

	if (cub3d(fd) == -1)
	{
		printf("\nfail");
		close(fd);
		return (0);
	}
	close(fd);
	return (0);
}
