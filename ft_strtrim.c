/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 03:04:37 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/16 16:26:56 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

int		ft_count_char(char const *s1, char const *set)
{
	int	stock;
	int	start;
	int end;

	stock = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	while (s1[end] && ft_isset(s1[end], set))
		end--;
	if (end < 0)
		return (0);
	stock = end - start + 1;
	return (stock);
}

char	*ft_fillstr(char *ptr, char const *s1, char const *set)
{
	int	stock;
	int	start;
	int end;
	int	i;

	start = 0;
	i = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	while (s1[end] && ft_isset(s1[end], set))
		end--;
	if (end < 0)
		return (0);
	stock = end - start + 1;
	while (stock)
	{
		ptr[i] = s1[start];
		i++;
		start++;
		stock--;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		stock;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	stock = ft_count_char(s1, set);
	if (!(ptr = (char *)malloc(sizeof(char) * (stock + 1))))
		return (NULL);
	if (stock + 1 == 1)
	{
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = ft_fillstr(ptr, s1, set);
	return (ptr);
}
