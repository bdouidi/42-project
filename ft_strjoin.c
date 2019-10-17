/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 01:41:30 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/15 16:14:49 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*stock;
	size_t		count;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
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
