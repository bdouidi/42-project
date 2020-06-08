/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:18:13 by idouidi           #+#    #+#             */
/*   Updated: 2020/06/08 18:40:53 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char		*fill_str(char *s1, char *s2, int i, int j)
{
	int	k;

	k = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * j)))
		return (NULL);
	while (i < j)
	{
		s2[k] = s1[i];
		i++;
		k++;
	}
	s2[k] = '\0';
	return (s2);
}

void		leak(char *str)
{
	free(str);
	str = NULL;
}

int			flags(char c)
{
	if (c == 'R' || c == 'F' || c == 'S' || c == 'C' || c == 'N' || c == 'W'
			|| c == 'E')
		return (0);
	return (-1);
}

int			is_flags(char *s, int i)
{
	if (flags(s[i]) == 0)
	{
		if (s[i + 1] == ' ' || s[i + 1] == '	')
			return (0);
		if ((s[i + 1] == 'O' || s[i + 1] == 'E' || s[i + 1] == 'A') &&
				(s[i + 2] == ' ' || s[i + 2] == '	'))
			return (0);
	}
	return (-1);
}