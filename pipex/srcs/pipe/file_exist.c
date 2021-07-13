/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:12:04 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/13 21:06:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*join_path_cmd(char *path, char *slash, char *cmd)
{
	char	*leak;
	char	*tmp;

	tmp = ft_strjoin(path, slash);
	leak = tmp;
	tmp = ft_strjoin(tmp, cmd);
	leak = ft_leak(leak);
	return (tmp);
}

int	set_return(char ***tab, int ret, t_data *d)
{
	*tab = ft_leak_2(*tab);
	if (ret == 127)
		ft_putstr_fd("pipex: command was not found\n", d->save_stdout);
	return (ret);
}

int	loop_check_if_file_exist(char **cmd, char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		tmp = join_path_cmd(tab[i], "/", *cmd);
		if (!access(tmp, X_OK))
		{
			*cmd = ft_leak(*cmd);
			*cmd = ft_strdup(tmp);
			tmp = ft_leak(tmp);
			return (1);
		}
		tmp = ft_leak(tmp);
		i += 1;
	}
	return (0);
}

char	*find_var(char *s, t_data *d)
{
	t_env	*tmp;

	tmp = d->head;
	while (tmp)
	{
		if (strcmp(s, tmp->name) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int	file_exist(char **s, t_data *d)
{
	char			**tab;

	tab = NULL;
	if (!ft_strcmp("", s[0]))
		return (set_return(&tab, 127, d));
	if (s[0][0] == '/' || s[0][0] == '.')
		return (0);
	tab = ft_split(find_var("PATH", d), ":");
	if (loop_check_if_file_exist(&s[0], tab))
		return (set_return(&tab, 0, d));
	return (set_return(&tab, 127, d));
}
