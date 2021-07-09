/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:38:20 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/09 13:10:31 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char *av[])
{
	t_data	d;
	if (ac != 5)
	{
		printf("Usage: program [file1] [cmd1] [cmd2] [file2]\n");
		exit (EXIT_FAILURE);
	}
	if (pipex(av, &d) == -1)
		exit (EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}