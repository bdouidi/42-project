/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:07:52 by idouidi           #+#    #+#             */
/*   Updated: 2020/05/28 20:04:31 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		leaks(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	return (-1);
}

char	*read_fd(int fd, int ret, char *buf, char *save)
{
	char		*tmp;

	while (!ft_strchr(save, '\n') && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(save, buf)))
			return (NULL);
		free(save);
		save = tmp;
	}
	return (save);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0
		|| read(fd, buf, 0))
		return (-1);
	if (!save[fd])
		if (!ft_strnew(&save[fd]))
			return (leaks(&save[fd]));
	if (!(save[fd] = read_fd(fd, ret, buf, save[fd])))
		return (leaks(&save[fd]));
	while (save[fd][i] != '\n' && save[fd][i] != '\0')
		++i;
	(*line) = save[fd];
	if (!(save[fd] = ft_strdup(save[fd][i] ? save[fd] + i + 1 : save[fd] + i)))
		return (leaks(&save[fd]));
	ret = (*line)[i] == '\n' ? 1 : 0;
	if (ret == 0)
		leaks(&save[fd]);
	(*line)[i + 1] = '\0';
	return (ret);
}
