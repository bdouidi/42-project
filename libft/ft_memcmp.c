/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:15:31 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/26 20:23:57 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*src;

	i = 0;
	dest = (unsigned char *)s1;
	src = (unsigned const char *)s2;
	if (dest == src)
		return (0);
	while (i < (unsigned char)n)
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		else
			i++;
	}
	return (0);
}
