/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:08:35 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/14 00:06:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	is_son(t_data *d, int i, int fd[2])
{
	if (d->fd_stdin < 0 || d->fd_stdout < 0)
		exit (EXIT_FAILURE);
	if (i == 0 && d->fd_stdin >= 3)
		dup2(d->fdd, d->fd_stdin);
	else
		dup2(d->fdd, 0);
	if (i == 1)
		dup2(fd[1], d->fd_stdout);
	else
		dup2(fd[1], 1);
	close(fd[0]);
	if (file_exist(&d->pipe[i][0], d) == 0)
	{
		if (execve(d->pipe[i][0], d->pipe[i], NULL) == -1)
		{
			d->pipe[i] = ft_leak_2(d->pipe[i]);
			exit(EXIT_FAILURE);
		}
	}
	else
		exit(127);
}

void	is_father(t_data *d, int i, int fd[2])
{
	waitpid(d->pid, &(d->status), 0);
	close(fd[1]);
	if (i != 0 && d->fd_stdin >= 3)
	{
		close(d->fd_stdin);
		d->fd_stdin = 0;
	}
	d->fdd = fd[0];
}

void	check_state_of_redir(t_data *d)
{
	if (d->fd_stdin < 0)
		d->fd_stdin = 0;
	if (d->fd_stdout < 0)
		d->fd_stdout = 1;
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
			is_father(d, i, fd);
		check_state_of_redir(d);
		i += 1;
	}
	d->pipe = ft_leak_3(d->pipe);
}
