/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:07:46 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/07 16:09:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	**pars_echo(char **s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		s[i] = adjust_str(s[i]);
		i++;
	}
	return (s);
}

void	exec_echo(t_data *d, char **s, int *i)
{
	int		space;
	char	*leak;

	space = 0;
	while (s[*i])
	{
		if (ft_strcmp(s[*i], ">") != 0 && ft_strcmp(s[*i], ">>") != 0
			&& ft_strcmp(s[*i], "<") != 0 && ft_strcmp(s[*i], "<<"))
		{
			s[*i] = adjust_str(s[*i]);
			if (space != 0)
			{
				leak = d->redir;
				d->redir = ft_strjoin(d->redir, " ");
				leak = ft_leak(leak);
			}
			leak = d->redir;
			d->redir = ft_strjoin(d->redir, s[*i]);
			leak = ft_leak(leak);
			space = 1;
			*i += 1;
		}
		else
			*i += 2;
	}
}

int	ft_echo(t_data *d, char **s)
{
	int		i;
	int		option;

	i = 1;
	option = 0;
	if (s[1] && ft_strcmp(s[1], "-n") == 0)
	{
		option = 1;
		while (s[i] && ft_strcmp(s[i], "-n") == 0)
			i++;
	}
	exec_echo(d, s, &i);
	ft_putstr_fd(d->redir, d->fd_stdout);
	if (option == 0)
		write(d->fd_stdout, "\n", 1);
	d->redir = ft_leak(d->redir);
	return (0);
}
