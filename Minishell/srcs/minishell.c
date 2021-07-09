/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:55:57 by othabchi          #+#    #+#             */
/*   Updated: 2021/07/09 11:13:06 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sig_handler(int signal)
{
	if (signal == 3)
		 return ;
	else if (signal == -1)
	{
		 printf("exit\n");
		 exit (0);
	}
	else if (signal == 2)
	{
		g_data->line = ft_leak(g_data->line);
		update_return_cmd("?", "130", g_data);
		if (g_data->open_the_door == 0)
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			if (g_data->sys_func != 1)
				rl_redisplay();
		}
		else
		{
			g_data->open_the_door = 2;
			if (g_data->pid_open_the_door == 0)
			{
				write(1, "\n", 1);
				exit(0);
			}
		}
	}
}

void	next_cmd(t_data *d, char **envp)
{
	int		i;
	char	**expression;

	i = 0;
	expression = NULL;
	if (open_the_door(d) == -1)
		return ;
	while (d->linespt[i])
	{
		expression = split_expression(&d->linespt[i], d);
		if (*expression)
		{
			if (there_is_pipe(expression))
				exec_pipe(d, expression, envp);
			else if (builtin(d, expression) == -1)
				exec_pipe(d, expression, envp);
		}
		while (d->linespt[i] && ft_strcmp(d->linespt[i], ";") != 0)
			i++;
		if (d->linespt[i])
			i++;
		expression = ft_leak_2(expression);
		d->is_builtin = 0;
		d->sys_func = 0;
		d->ret = 0;
	}
}

void	minishell(t_data *d, char **envp)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	while (1)
	{
		d->line = readline("$> ");
		add_history(d->line);
		if (d->line && check_line(d) == 0)
		{
			d->linespt = ft_split_minishell(d, d->line);
			if (d->linespt != NULL)
				next_cmd(d, envp);
		}
		else
			sig_handler(-1);
		d->fd_stdout = 1;
		d->fd_stdin = 0;
		d->line = ft_leak(d->line);
		d->linespt = ft_leak_2(d->linespt);
	}
}
