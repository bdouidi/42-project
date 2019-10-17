/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:10 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/15 13:54:03 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)s2[i]);
		i++;
	}
	if (((s1[i] && s2[i] == '\0') && i < n)
			|| ((s2[i] && s1[i] == '\0') && i < n))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
