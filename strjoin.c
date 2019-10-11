/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 01:41:30 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/11 03:03:11 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*stock;
	int		count;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	count = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(stock = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (s1[j])
		stock[i++] = s1[j++];
	j = 0;
	while (s2[j])
		stock[i++] = s2[j++];
	stock[i] = '\0';
	return (stock);
}
