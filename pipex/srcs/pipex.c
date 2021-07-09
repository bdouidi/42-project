/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:49:40 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/09 15:43:07 by idouidi          ###   ########.fr       */
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
	if (redirection(s[0], s[3], d) == -1)
		return (-1);
	exec_pipex(s, d);
	close(d->fd_stdout);
	close (d->fd_stdin);
	free_list(d);
	return (0);
}
