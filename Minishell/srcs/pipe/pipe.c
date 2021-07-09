/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:31:14 by user42            #+#    #+#             */
/*   Updated: 2021/07/09 11:13:22 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	is_son(t_data *d, int i, int fd[2], char **envp)
{
	if (d->fd_stdin != 0)
		dup2(d->fdd, d->fd_stdin);
	else
		dup2(d->fdd, 0);
	if (redirection(d, d->pipe[i]) == -1)
		exit(EXIT_FAILURE);
	if (d->pipe[i + 1] != NULL)
	{
		if (d->fd_stdout != 1)
			dup2(fd[1], d->fd_stdout);
		else
			dup2(fd[1], 1);
	}
	close(fd[0]);
	if (builtin(d, d->pipe[i]) == -1 && file_exist(&(*d->pipe[i]), d) == 0)
	{
		d->pipe[i] = expression_without_redir(d->pipe[i]);
		if (execve(d->pipe[i][0], d->pipe[i], envp) == -1)
		{
			printf("minishell: %s : command was not found\n", d->pipe[i][0]);
			d->pipe[i] = ft_leak_2(d->pipe[i]);
			exit(EXIT_FAILURE);
		}
	}
	exit(d->ret);
}

void	is_father(t_data *d, int fd[2])
{
	char	*tmp;

	tmp = NULL;
	d->fdd = fd[0];
	if (d->fd_stdin != 0)
	{
		close(d->fd_stdin);
		d->fd_stdin = 0;
	}
	if (d->fd_stdout != 1)
	{
		close(d->fd_stdout);
		d->fd_stdout = 1;
	}
	if (WIFEXITED(d->status) != 0)
	{
		if (WEXITSTATUS(d->status) == 1)
			tmp = ft_itoa(1);
		else
			tmp = ft_itoa(WEXITSTATUS(d->status));
	}
	else if (WIFSIGNALED(d->status) == 1)
		tmp = ft_itoa(d->status);
	update_return_cmd("?", tmp, d);
	tmp = ft_leak(tmp);
}

void	init_var(t_data *d, int *i, char **expression)
{
	d->status = 0;
	d->pid = 0;
	d->fdd = 0;
	d->sys_func = 1;
	*i = 0;
	d->pipe = split_each_cmd_btwn_pipe(expression);
}

void	exec_pipe(t_data *d, char **expression, char **envp)
{
	int		fd[2];
	int		i;

	init_var(d, &i, expression);
	while (d->pipe[i])
	{
		pipe(fd);
		d->pid = fork();
		d->ret = 0;
		if (d->pid < 0)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (d->pid == 0)
			is_son(d, i, fd, envp);
		else
		{
			waitpid(d->pid, &(d->status), 0);
			close(fd[1]);
			is_father(d, fd);
		}
		i += 1;
	}
	d->pipe = ft_leak_3(d->pipe);
}
