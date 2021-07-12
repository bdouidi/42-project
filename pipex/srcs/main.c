/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:38:20 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/12 12:27:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_env_var(t_data *d, char **envp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (envp[i])
	{
		d->new_ = malloc(sizeof(t_env));
		if (d->new_)
		{
			while (envp[i][j] && envp[i][j] != '=')
				j++;
			d->new_->name = ft_substr(envp[i], 0, j);
			 k = j + 1;
			 while (envp[i][k])
				k++;
			d->new_->value = ft_substr(envp[i], j + 1, k--);
			d->new_->next = d->head;
			d->head = d->new_;
		}
		i++;
		j = 0;
	}
}

int	main(int ac, char *av[], char *envp[])
{
	t_data	d;

	if (ac != 5)
	{
		showtab (av);
		printf("Usage: program [file1] [cmd1] [cmd2] [file2]\n");
		exit (EXIT_FAILURE);
	}
	d.head = NULL;
	init_env_var(&d, envp);
	if (pipex(&av[1], &d) == -1)
		exit (EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
