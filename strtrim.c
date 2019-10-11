/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 03:04:37 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/11 04:42:18 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
int		ft_count_set(char const *s1, char const *set)
{
	int	i;
	int j;
	int	stock;

	i = 0;
	j = 0;
	stock = 0;
		while (s1[i])
		{
			while (set[j] && set[j] != s1[i])
				j++;
			if (set[j] == '\0')
				stock++;
			j = 0;
			i++;
		}
	return (stock);

}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	char	*stock;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (!(stock = (char *)malloc(sizeof(char) * ft_count_set(s1, set) + 1)))
		return (NULL);
	while (s1[i])
	{
		while (set[j] && set[j] != s1[i])
			j++;
		if (set[j] == '\0')
		{
			stock[k] = s1[i];
			k++;
		}
		j = 0;
		i++;
	}
	stock[k] = '\0';
	return (stock);
}
