/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:40:41 by othabchi          #+#    #+#             */
/*   Updated: 2021/07/01 13:12:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_redir(char *s, t_data *d)
{
	if (ft_strcmp(s, ">") == 0 || ft_strcmp(s, ">>") == 0)
		close(d->fd_stdout);
	else
		close (d->fd_stdin);
}

int	fd_stdin(t_data *d, char *s)
{
	d->fd_stdin = open(s, O_RDONLY);
	if (d->fd_stdin < 0)
	{
		printf("bash: %s: No such file or directory\n", s);
		return (-1);
	}
	return (0);
}

void	fd_stdout(t_data *d, char *s, char *path)
{
	if (ft_strcmp(s, ">>") == 0)
		d->fd_stdout = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		d->fd_stdout = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
}

int	redirection(t_data *d, char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strcmp(s[i], ">") == 0 || ft_strcmp(s[i], ">>") == 0
			|| ft_strcmp(s[i], "<") == 0)
		{
			if (d->fd_stdout >= 3 || d->fd_stdin >= 3)
				close_redir(s[i], d);
			if (ft_strcmp(s[i], ">") == 0 || ft_strcmp(s[i], ">>") == 0)
				fd_stdout(d, s[i], s[i + 1]);
			else
				if (fd_stdin(d, s[i + 1]) == -1)
					return (-1);
		}
		i += 1;
	}
	if (d->fd_stdout != 1 && d->is_builtin == 0)
		dup2(d->fd_stdout, 1);
	if (d->fd_stdin != 0 && d->is_builtin == 0)
		dup2(d->fd_stdin, 0);
	return (0);
}
