/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:49:04 by user42            #+#    #+#             */
/*   Updated: 2021/06/04 03:54:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_cd(t_data *d, char **s)
{
	int		i;
	char	*tmp;

	tmp = find_var("HOME", d);
	i = arg_cancel_redir(s);
	if (i == 0)
	{
		i = chdir(tmp);
		if (i != 0)
		{
			update_return_cmd("?", "1", d);
			perror("cd");
		}
	}
	else
	{
		s[i] = adjust_str(s[i]);
		if (chdir(s[i]) != 0 && ft_strcmp(s[i], "") != 0)
		{
			update_return_cmd("?", "1", d);
			perror("cd");
		}
	}
	return (0);
}
/*
**
** char	*ft_strjoinsep(char const *s1, char const *s2, char sep)
** {
** 	char	*newstr;
** 	size_t	i;
** 	size_t	j;
** 
** 	i = 0;
** 	j = 0;
** 	newstr = NULL;
** 	if (!(newstr = (char*)malloc(sizeof(char) *
** 					(ft_strlen(s1) + ft_strlen(s2) + 2))))
** 		return (NULL);
** 	while (i < ft_strlen(s1))
** 	{
** 		newstr[i] = s1[i];
** 		i++;
** 	}
** 	newstr[i] = sep;
** 	i++;
** 	while (s2[j])
** 	{
** 		newstr[i] = s2[j];
** 		i++;
** 		j++;
** 	}
** 	newstr[i] = '\0';
** 	return (newstr);
** }
** 
**	path relatif
**
** char	*setpath(t_data *d, char *path, int i)
** {
** 	int j;
** 
** 	j = 0;
** 	d->ptcount = 0;
** 	if (d->linespt[i][j] && d->linespt[i][j] == 46 &&
** 	d->linespt[i][j + 1] == 46)
** 	{
** 		path = ft_substr(d->linespt[i], 2, ft_strlen(d->linespt[i]) - 2);
** 		d->ptcount = 1;
** 		return (path);
** 	}
** 	while (d->linespt[i][j] && d->linespt[i][j] == 46)
** 	{
** 		if (d->linespt[i][j + 1] != 46)
** 		{
** 			path = ft_substr(d->linespt[i], 2, ft_strlen(d->linespt[i]) - 2);
** 			return (path);
** 		}
** 		else
** 		{
** 			d->ptcount++;
** 			while (d->linespt[i][j] == 46)
** 				j++;
** 		}
** 		j++;
** 	}
** 	path = ft_substr(d->linespt[i], d->ptcount * 3,
** 	ft_strlen(d->linespt[i]) - d->ptcount * 3);
** 	return (path);
** }
** 
** char	*getpath(t_data *d)
** {
** 	int		i;
** 	char	*path;
** 
** 	i = 0;
** 	d->abs_or_rel = 0;
** 	path = NULL;
** 	while (strcmp(d->linespt[i], "cd") != 0)
** 		i++;
** 	if (d->linespt[i + 1])
** 	{
** 		if (d->linespt[i + 1][0] == 46)
** 			path = setpath(d, path, i + 1);
** 		else
** 		{
** 			path = d->linespt[i + 1];
** 			d->abs_or_rel = 1;
** 		}
** 	}
** 	else
** 		path = "";
** 	return (path);
** }
**
**	char *newpath;
**	char *oldpath;
**	int i = 0;
**	int error
**	error = 0;
**	oldpath = NULL;
**	newpath = getpath(d);
**	if (d->abs_or_rel == 0)
**	{
**		oldpath = getcwd(oldpath, 1024);
**		i = ft_strlen(oldpath) - 1;
**		while (d->ptcount > 0)
**		{
**			while(oldpath[i] && oldpath[i] != 47)
**				i--;
**			i--;
**			d->ptcount--;
**		}
**		oldpath = ft_strndup(oldpath, i + 1);
**		error = chdir(ft_strjoinsep(oldpath, newpath, 47));
**	}
**	else
**		error = chdir(newpath);
**	if (error != 0)
**		perror("cd")
**	printf("[%s]\n", ft_strjoinsep(oldpath, newpath, 47));
*/
