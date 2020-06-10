/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:02:00 by idouidi           #+#    #+#             */
/*   Updated: 2020/06/10 17:14:25 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int		p(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '*')
			return (-1);
		i++;
	}
	return (0);
}

static int		check_m_content(char **m, int i, int j)
{
	if (m[i][j] != '1' && m[i][j] != '2' && m[i][j] != '0' && m[i][j] != 'N'
			&& m[i][j] != 'S' && m[i][j] != 'E' && m[i][j] != 'W'
			&& m[i][j] != '*') 
		return (-1);
	return (0);
}

static int		m_content(char **m, int len, int check)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (m[++i])
	{
		while (m[i][++j])
		{
			if (check_m_content(m, i, j) != 0)
				return (-1);
			if (m[i][j] == 'N' || m[i][j] == 'S' || m[i][j] == 'E' ||
					m[i][j] == 'W')
			{
				if (i == 0 || i == len)
					return (-1);
				check++;
			}
		}
		j = 0;
	}
	if (check != 1)
		return (-1);
	return (0);
}

static int		check_pars_map(char **m, int i, int j, int len)
{
	if (m[i][j] == '*')
	{
		if (i > 0)
			if (m[i][j - 1] && m[i][j + 1] && ((m[i][j - 1] == '2' || m[i][j - 1] == '0' || ft_isalpha(m[i][j - 1])) ||
					(m[i][j + 1] == '2' || m[i][j + 1] == '0' || ft_isalpha(m[i][j + 1])) ||
					(m[i - 1][j] == '2' || m[i - 1][j] == '0' || ft_isalpha(m[i - 1][j])) ||
					(m[i + 1][j] == '2' || m[i + 1][j] == '0' || ft_isalpha(m[i + 1][j]))))
				return (-1);
		if (i == 0 && (m[i + 1][j] == '2' || m[i + 1][j] == '0' || ft_isalpha(m[i + 1][j])))
			return (-1);
		if (i == len && (m[i - 1][j] == '2' || m[i - 1][j] == '0' || ft_isalpha(m[i - 1][j])))
			return (-1);
	}
	return (0);
}

int				pars_map(char **m, int len)
{
	int				i;
	unsigned int	j;
	int				check;

	i = 0;
	j = 0;
	check = 0;
	if (p(m[0]) != 0 || p(m[len]) != 0 || m_content(m, len, check) != 0)
	{
		printf("hey\n");
		return (-1);
	}
	while (m[i])
	{
		if (border(m[i]) != 0)
			return (-1);
		while (m[i][j])
		{
			if (check_pars_map(m, i, j, len) != 0)
			{
				printf("ici\n");
				return (-1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
