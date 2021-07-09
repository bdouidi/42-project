/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_open_the_door.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:20:08 by user42            #+#    #+#             */
/*   Updated: 2021/07/07 13:21:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_it(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

static int	separate_lines(char **line, char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i += 1;
	*line = ft_substr(str, 0, i);
	if (!line)
	{
		free_it(&str);
		return (-1);
	}
	free_it(&str);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*str;
	char		buf[BUFFER_SIZE + 1];
	int			i;
	char		*tmp;

	str = ft_strdup("");
	tmp = str;
	while (!ft_strchr(str, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			break ;
		buf[i] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		tmp = ft_leak(tmp);
	}
	if (tmp)
		tmp = ft_leak(tmp);
	return (separate_lines(line, str));
}
