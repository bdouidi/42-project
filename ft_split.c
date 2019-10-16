/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:11:31 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/15 14:26:30 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			nb++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == c)
			i++;
	}
	return (nb);
}

int		ft_isnotsep(char letter, char c)
{
	if (letter == c)
		return (1);
	return (0);
}

int		ft_lenghtword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_sncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char*) * ft_count_word(s, c))))
		return (NULL);
	while (s[i])
	{
		if (!ft_isnotsep(s[i], c))
		{
			tab[j] = (char *)malloc(sizeof(char) * ft_lenghtword(&s[i], c));
			tab[j] = ft_sncpy(tab[j], &s[i], ft_lenghtword(&s[i], c));
			j++;
			i = i + ft_lenghtword(&s[i], c);
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
