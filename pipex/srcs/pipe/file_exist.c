/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:12:04 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/09 13:14:47 by idouidi          ###   ########.fr       */
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
	cmd = ft_leak(cmd);
	cmd = ft_strdup(tmp);
	tmp = ft_leak(tmp);
	return (cmd);
}

int	loop_check_if_file_exist(t_data *d, char *tab, char **s)
{
	while (d->entry)
	{
		if (ft_strcmp(*s, d->entry->d_name) == 0)
		{
			*s = join_path_cmd(tab, "/", *s);
			closedir(d->folder);
			return (1);
		}
		d->entry = readdir(d->folder);
	}
	return (0);
}

int	set_return(t_data *d, char ***tab, int ret, char *s)
{
	*tab = ft_leak_2(*tab);
	if (ret == 127)
		printf("minishell: %s: No such file or directory\n", s);
	return (ret);
}

int	file_exist(char **s, t_data *d)
{
	char			**tab;
	int				i;

	i = 0;
	if (s[0][0] == '/' || s[0][0] == '.')
		return (0);
	tab = ft_split(find_var("PATH", d), ":");
	if (tab != NULL)
	{
		while (tab[i])
		{
			d->folder = opendir(tab[i]);
			if (d->folder)
			{
				d->entry = readdir(d->folder);
				if (loop_check_if_file_exist(d, tab[i], &s[0]) == 1)
					return (set_return(d, &tab, 0, *s));
				closedir(d->folder);
			}
			i += 1;
		}
	}
	return (set_return(d, &tab, 127, *s));
}