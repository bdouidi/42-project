/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:08:35 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/09 13:21:39 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	***ft_leak_3(char ***s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		s[i] = ft_leak_2(s[i]);
		i += 1;
	}
	free (s);
	s = NULL;
	return (s);
}

void	is_son(t_data *d, int i, int fd[2])
{
	dup2(d->fdd, d->fd_stdin);
	if (d->pipe[i + 1] != NULL)
			dup2(fd[1], d->fd_stdout);
	close(fd[0]);
	if (file_exist(&(*d->pipe[i]), d) == 0)
	{
		if (execve(d->pipe[i][0], d->pipe[i], NULL) == -1)
		{
			printf("pipex: %s : command was not found\n", d->pipe[i][0]);
			d->pipe[i] = ft_leak_2(d->pipe[i]);
			exit(EXIT_FAILURE);
		}
	}
	else
		exit(127);
}

void	is_father(t_data *d, int fd[2])
{
	d->fdd = fd[0];
	waitpid(d->pid, &(d->status), 0);
	close(fd[1]);
	close(d->fd_stdin);
	close(d->fd_stdout);
}

void	exec_pipex(char **s, t_data *d)
{
	int		fd[2];
	int		i;

	i = 0;
	d->status = 0;
	d->pid = 0;
	d->fdd = 0;
	d->pipe = split_each_cmd_btwn_pipe(s[1], s[2]);
	while (d->pipe[i])
	{
		pipe(fd);
		d->pid = fork();
		if (d->pid < 0)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (d->pid == 0)
			is_son(d, i, fd);
		else
			is_father(d, fd);
		i += 1;
	}
	d->pipe = ft_leak_3(d->pipe);
}