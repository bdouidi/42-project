/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:18:13 by idouidi           #+#    #+#             */
/*   Updated: 2020/06/10 18:07:17 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char		*fill_str(char *s1, char *s2, int i, int j)
{
	int	k;

	k = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * j + 1)))
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
		if (((s[i + 1] == 'O' && (s[i] == 'N' || s[i] == 'S')) 
			|| (s[i + 1] == 'E' && s[i] == 'W') || (s[i + 1] == 'A' && s[i] == 'E'))
			&& (s[i + 2] == ' ' || s[i + 2] == '	'))
			return (0);
		else if ((s[i] != 'N' && s[i] != 'W' && s[i] != 'E') &&
			(s[i + 1] == ' ' || s[i + 1] == '\t'))
			return (0);
	}
	return (-1);
}

int			border(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s) - 1;
	if (s[i] == '1' && s[j] == '1')
		return (0);
	if (s[i] == '*' || s[j] == '*')
	{
		while (s[i] && s[i] == '*')
			i++;
		while (s[j] && s[j] == '*')
			j--;
		if (s[i] == '1' && s[j] == '1')
			return (0);
	}
	return (-1);
}
