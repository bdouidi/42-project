/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:00:17 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/10 15:19:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	redirection(char *s1, char *s2, t_data *d)
{	
	d->fd_stdin = open(s1, O_RDONLY);
	if (d->fd_stdin < 0)
		printf("%s: No such file or directory\n", s1);
	d->fd_stdout = open(s2, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	dup2(d->fd_stdout, 1);
	if (d->fd_stdin >= 3)
		dup2(d->fd_stdin, 0);
	return (0);
}
