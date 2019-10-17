/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:16:52 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/15 15:40:08 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*stock;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s1[j])
		j++;
	if (!(stock = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (s1[i])
	{
		stock[i] = s1[i];
		i++;
	}
	stock[i] = '\0';
	return (stock);
}
