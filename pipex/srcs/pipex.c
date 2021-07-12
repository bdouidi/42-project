/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:49:40 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/10 15:20:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_list(t_data *d)
{
	t_env	*tmp;

	tmp = NULL;
	while (d->head)
	{
		tmp = d->head;
		ft_leak(d->head->name);
		ft_leak(d->head->value);
		d->head = d->head->next;
		free(tmp);
	}
}

int	pipex(char **s, t_data *d)
{
	d->fd_stdin = 0;
	d->fd_stdout = 1;
	if (redirection(s[0], s[3], d) == -1)
		return (-1);
	exec_pipex(s, d);
	close(d->fd_stdout);
	close (d->fd_stdin);
	free_list(d);
	return (0);
}
