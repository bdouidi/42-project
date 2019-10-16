/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:30:35 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/15 19:43:05 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*stock;
	unsigned char		*stock2;
	size_t				i;

	stock = (unsigned char *)src;
	stock2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		stock2[i] = stock[i];
		if ((unsigned char)c == stock[i])
			return ((void *)stock2 + i + 1);
		if ((unsigned char)c == '\0' && (unsigned char)c == stock[i])
			return ((void *)stock2 + i);
		i++;
	}
	return (NULL);
}
